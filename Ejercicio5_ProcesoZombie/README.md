## 3.1.5 Código para verificar la creación de un proceso zombie ###

Este programa ilustra cómo se crea un proceso zombie intencionalmente. Un proceso zombie es un proceso que ha terminado su ejecución, pero cuya entrada en la tabla de procesos del sistema operativo persiste porque su proceso padre no ha llamado a wait() para recolectar su estado de salida.

### Explicación ###

fork(): Crea un proceso hijo.

Proceso Hijo (else): El proceso hijo ejecuta inmediatamente exit(0) para terminar.

Proceso Padre (if (pid > 0)): El padre imprime un mensaje y entra en un estado de suspensión por 60 segundos (sleep(60)).

El sistema operativo mantiene la información de terminación del hijo aun este proceso haya finalizado por la función exit(0), identificándolo con el estado Z (zombie) en la tabla de procesos.  