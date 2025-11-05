#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];    
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        close(fd[1]); // el hijo no escribe
        FILE *out = fopen("valores.txt", "w");
        if (!out) {
            perror("fopen valores.txt");
            close(fd[0]);
            return 1;
        }

        int valor;
        ssize_t n;
        while ((n = read(fd[0], &valor, sizeof(int))) > 0) {
            if (n == sizeof(int)) {
                fprintf(out, "%d\n", valor);
                fflush(out);
            }
        }

        fclose(out);
        close(fd[0]);
        _exit(0);
    } else {
        close(fd[0]); 
        int valor = 0;
        for (int i = 0; i < 10; i++) {
            valor += 10; 
            if (write(fd[1], &valor, sizeof(int)) == -1) {
                perror("write");
                break;
            }
            printf("Padre (%d) envió: %d\n", getpid(), valor);
        }
        close(fd[1]);   
        wait(NULL);  
    }
    return 0;
}
