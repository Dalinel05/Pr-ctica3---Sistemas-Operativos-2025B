#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Ejemplo de fork\n");
    printf("Inicio del proceso padre. PID = %d\n", getpid());

    if (fork() == 0) {
        printf("Inicio de proceso hijo. PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(1);
    } 
    else {
        printf("Continuacion del padre. PID = %d\n", getpid());
        sleep(1);
    }

    printf("Fin del proceso. PID = %d\n", getpid());
    return 0;
}
