#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3 // Se crearán 3 procesos hijos

void hijoHasAlgo(int numero); 

int main ()
{
    int i, pid;
    
    // Bucle para crear los 3 procesos hijos
    for (i = 1; i <= NUM_PROC; i++)
    {
        pid = fork(); // Crea el clon

        switch(pid)
        {
            case -1: // Error
                fprintf(stderr, "Error al crear el proceso hijo %d\n", i);
                exit(1);
            
            case 0: // CÓDIGO DEL HIJO (pid es 0)
                hijoHasAlgo(i); 
                exit(0); // El hijo siempre debe terminar
            
            default: // CÓDIGO DEL PADRE (pid es > 0)
                break; // El padre continúa el bucle creando el siguiente hijo
        }
    }
    
    // El padre espera a todos sus hijos
    printf("\n[PROCESO PADRE PID: %d] Esperando a mis %d hijos...\n", getpid(), NUM_PROC);
    for (i = 1; i <= NUM_PROC; i++) {
        wait(NULL); 
    }
    printf("[PROCESO PADRE PID: %d] Todos los hijos han terminado. Fin del programa.\n", getpid());
    return 0;
}

// Implementación de la función con tareas diferenciadas
void hijoHasAlgo (int numero)
{
    printf ("\n--- HIJO %d (PID: %d | PPID: %d) ---\n", numero, getpid(), getppid());
    
    // Asignación de tarea única
    switch (numero) {
        case 1:
            printf("Tarea 1: Imprimir la serie 1 al 10.\n");
            for (int j = 1; j <= 10; j++) {
                printf("Hijo 1: %d\n", j);
            }
            break;
            
        case 2:
            printf("Tarea 2: Imprimir nombre de la empresa 5 veces.\n");
            for (int j = 0; j < 5; j++) {
                printf("Hijo 2: Eleve Innovation\n");
            }
            break;
            
        case 3:
            printf("Tarea 3: Simular proceso largo (5s) y listar directorio HOME con exec.\n");
            printf("Hijo 3: Durmiendo 5 segundos...\n");
            sleep(5); 
            printf("Hijo 3: Comando ls -l /home/ubuntu ejecutado:\n");
            // Sustituye el programa actual por el comando 'ls'
            execl("/bin/ls", "ls", "-l", "/home/ubuntu", NULL);
            perror("execl falló"); // Solo se ejecuta si execl no pudo sustituir
            break;
    }
    printf("Hijo %d ha terminado su tarea.\n", numero);
}
