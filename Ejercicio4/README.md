Solución Ejercicio 3.1.4

Título de la Actividad: Creación de un proceso padre y de tres procesos hijos con tareas diferenciadas.

Resumen de la Implementación

El código C fue diseñado para demostrar el control de procesos mediante la función fork() y la ejecución de programas externos mediante exec(). La implementación cumple con la instrucción formal del laboratorio al incluir la línea // #!/bin/bash como un comentario.

El programa usa un bucle for que ejecuta fork() tres veces. El contador del bucle se utiliza para asignar tareas únicas a cada hijo a través de la función hijoHasAlgo().

    Proceso Padre: Espera la creación de los tres hijos y luego utiliza un bucle de wait(NULL) para recoger los estados de finalización de todos los hijos, lo cual es fundamental para prevenir procesos zombis.

    Procesos Hijos: Cada uno realiza una tarea específica y termina inmediatamente con exit(0).

Tareas Asignadas a cada Proceso Hijo

Proceso	Tarea Asignada	Mecanismo Demostrado
Hijo 1	Imprime la serie numérica del 1 al 10.	Demuestra la ejecución concurrente básica.
Hijo 2	Imprime el nombre de la empresa "Eleve Innovation" 5 veces.	Demuestra la ejecución concurrente básica.
Hijo 3	Simula una espera de 5 segundos y lista el directorio /home/ubuntu.	Sustitución de Imagen: Utiliza execl para reemplazar el código C por el binario /bin/ls -l /home/ubuntu.

Instrucciones de Compilación y Ejecución

    Compilar:
    Bash

gcc codigo.c -o codigo

Ejecutar:
Bash

./codigo
