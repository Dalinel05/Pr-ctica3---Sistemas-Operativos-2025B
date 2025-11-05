### 3.2.1  Proceso hijo que realice una tarea usando execl ###

Este programa demuestra la forma correcta de crear un proceso hijo, asignarle una nueva tarea (un comando externo) y asegurar que el proceso padre espere su finalización, evitando así la creación de procesos zombies.

### Explicación ###

* fork(): El proceso padre crea un proceso hijo.

* Proceso Hijo (case 0): El hijo ejecuta execvp("ls", {"ls", "-l", NULL}).

* execvp() reemplaza completamente el código del proceso hijo con el código del comando externo (ls -l). La salida de este comando se imprime en la terminal.

* Proceso Padre (main): El padre llama a wait(0).

* El Mecanismo: wait(0) detiene al padre hasta que el hijo termina. Esto garantiza que el estado de terminación del hijo se recoja inmediatamente.

Al finalizar el proceso hijo reemplazó su código original con el código del comando ls -l y ejecutó el listado, por ultimo el padre termina la ejecución imprimiendo el PID del hijo.