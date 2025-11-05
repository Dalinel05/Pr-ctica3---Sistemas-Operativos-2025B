#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Crear un proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("fork falló");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Código del proceso hijo
 
       printf("Proceso hijo (PID: %d) ejecutando 'ps aux'...\n", getpid());
        int resultado = system("ps aux");
        if (resultado == -1) {
            perror("system falló");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS); // Terminar el proceso hijo
    } else {
        // Código del proceso padre
        printf("Proceso padre (PID: %d) esperando al hijo...\n", getpid());
        wait(NULL); // Esperar a que el hijo termine
        printf("Proceso hijo terminado.\n");
    }

    return 0;
}

