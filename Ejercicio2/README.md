DESCRIPCION
Este programa implementa la comunicación entre un proceso padre y un proceso hijo mediante el uso de un pipe.  
El objetivo es que el padre incremente una variable 10 veces en pasos de 10, y el hijo reciba dichos valores y los registre en un archivo de texto llamado 'valores.txt'.

FUNCIONALIDAD 
1. Se crea un pipe que permite la comunicación entre los dos procesos.
2. El proceso padre:
   - Incrementa una variable en pasos de 10.
   - Envía cada valor al proceso hijo mediante el pipe con 'write()'.
3. El proceso hijo:
   - Lee los valores enviados por el padre usando 'read()'.
   - Escribe los valores recibidos en un archivo llamado 'valores.txt' usando 'fprintf()'.
4. Finalmente, el padre cierra su extremo del pipe y espera a que el hijo termine con 'wait()'.
