# Ejecicio 3.1.3 Proceso Hijo sin espera

---

## Objetivo del Ejercicio

[cite_start]El objetivo de este ejercicio es analizar el comportamiento de un programa donde el proceso padre **no espera** a que termine el proceso hijo[cite: 196]. [cite_start]A través de esto, se busca identificar el problema conocido como **proceso huérfano** [cite: 199] [cite_start]y, posteriormente, modificar el código para implementar una sincronización correcta usando `wait()` y así evitar que el hijo quede huérfano[cite: 200, 201].

## Archivos en este Directorio

* [cite_start]`fig3.c`: El código original proporcionado en la guía (Figura 3) [cite: 202-222].
* `fig3_modificado.c`: El código con la solución aplicada (pregunta d).
* `README.md`: Esta explicación.

---

## 1. Análisis del Código Original (`fig3.c`)

[cite_start]El script `fig3.c` crea un proceso hijo usando `fork()`[cite: 208].

* [cite_start]**Código del Padre (`default:`)**: Imprime su PID y el PID del hijo que acaba de crear[cite: 219]. [cite_start]Inmediatamente después, continúa y ejecuta `exit(0)`, terminando su ejecución[cite: 221].
* [cite_start]**Código del Hijo (`case 0:`)**: Imprime su propio PID y el PID de su padre (PPID)[cite: 214].

### Respuestas a las Preguntas (a, b, c)

**a) ¿Cuál es el PID del proceso padre del hijo creado?**
Al ejecutar el programa, el hijo imprime su PPID. Por ejemplo: `Soy el hijo, mi PID es 3452 y mi PPID es 3451`. El PID del padre es **3451** (en este ejemplo).

**b) Verifique a qué proceso corresponde el ID encontrado.**
En la misma salida, el proceso padre imprime: `Soy el padre, mi PID es 3451...`. El PPID reportado por el hijo (`3451`) **corresponde exitosamente** al PID del proceso padre (`3451`).

**c) ¿Cómo se denomina al tipo de proceso hijo?**
[cite_start]Se denomina **Proceso Huérfano (Orphan Process)**[cite: 199].

**¿Por qué?**
El código del padre no tiene ninguna instrucción que lo haga esperar. Debido a que un `printf` es una tarea muy rápida, el proceso padre termina su ejecución (`exit(0)`) **antes** de que el proceso hijo termine la suya. En el instante en que el padre muere, el hijo (que sigue vivo) se queda "huérfano".

> **Nota:** En un sistema operativo tipo UNIX, estos procesos son "adoptados" inmediatamente por el proceso `init` (PID 1) o `systemd`, que se convierte en su nuevo padre. Si tuviéramos un `sleep()` en el hijo, podríamos verificar con el comando `ps` que su PPID cambia a 1.

---

## 2. Solución Aplicada (`fig3_modificado.c`)

**d) Modifique el código... para que el proceso hijo no quede huérfano.**

Para solucionar este problema, debemos asegurarnos de que el padre no muera antes que el hijo.

* **La Modificación:** Se añadió la llamada al sistema `wait(0);` dentro del bloque `default:` (el código del padre).
* **Efecto:** Esta instrucción **pausa la ejecución del padre** y lo pone a dormir hasta que cualquiera de sus procesos hijos (en este caso, el único que creó) termine su ejecución.
* **Demostración:** Al ejecutar la versión modificada, el hijo imprime su PPID (ej. `3455`), y este PPID **sigue siendo el del padre original** durante toda la vida del hijo. El padre solo imprime su mensaje final y termina *después* de que el hijo ha terminado.

## Cómo Compilar y Ejecutar

Puedes compilar y ejecutar ambos programas para ver la diferencia.

**1. Código Original (Problema)**
```bash
# Compilar
gcc fig3.c -o fig3

# Ejecutar (Notarás que la salida puede salir desordenada)
./fig3
