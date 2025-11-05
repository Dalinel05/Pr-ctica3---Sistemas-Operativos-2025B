#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    int pid;
    pid = fork ();
    if (pid > 0)
    {
        printf("Soy el proceso padre y espero 60 segundos antes de terminar, de mi hijo no se nada.\n");
        sleep (60);
    }
    else
    {
        exit (0);
    }
    return 0;
}
