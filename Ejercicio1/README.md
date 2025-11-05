DESCIPCION
Este programa demuestra el uso de la llamada al sistema fork() en el sistema operativo Linux. Permite observar cómo se crean dos procesos (padre e hijo) que se ejecutan de manera concurrente, mostrando sus respectivos identificadores PID y PPID.

FUNCIONALIDAD
1. El proceso padre inicia y muestra su PID.  
2. Al ejecutar fork(), se crea un proceso hijo, que es una copia del padre.  
3. El hijo imprime su propio PID y el PID de su padre.  
4. El padre continúa su ejecución de forma independiente, mostrando su PID.  
5. Ambos procesos imprimen un mensaje al finalizar su ejecución.
