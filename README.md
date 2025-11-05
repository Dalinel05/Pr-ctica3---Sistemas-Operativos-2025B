# 🖥️ Práctica 3 – Sistemas Operativos 2025B  

![C](https://img.shields.io/badge/language-C-blue.svg)
![status](https://img.shields.io/badge/status-active-success.svg)
![platform](https://img.shields.io/badge/platform-Linux%20%7C%20UNIX-lightgrey.svg)
![license](https://img.shields.io/badge/license-academic-blue.svg)

---

## Descripción  

Este repositorio contiene el desarrollo de la **Práctica 3** de la materia **Sistemas Operativos** (ciclo 2025B).  
Incluye ejercicios implementados en **lenguaje C** enfocados en la **creación y manejo de procesos**, uso de las funciones del sistema operativo como `system()` y `exec()`, y observación del comportamiento de procesos hijos y zombies.  

> El objetivo es comprender cómo el sistema operativo gestiona los procesos y cómo un programa puede invocar, reemplazar o coordinar otros procesos.

---

## Estructura del repositorio  

**Práctica3---Sistemas-Operativos-2025B/**  
│  
├── **Ejercicio1/**  
│  └─ Código del *Ejercicio 1*  
│  
├── **Ejercicio2/**  
│  └─ Código del *Ejercicio 2*  
│  
├── **Ejercicio3_ProcesoHijoSinEspera/**  
│  └─ Ejemplo de proceso hijo sin espera  
│  
├── **Ejercicio5_ProcesoZombie/**  
│  └─ Demostración de proceso zombie  
│  
├── **Ejercicio6_Exec/**  
│  └─ Uso de funciones `exec()`  
│  
├── **Ejercicio7_System/**  
│  └─ Uso de la función `system()`  
│  
└──  **README.md**  
  └─ Descripción general del proyecto  

---

## ⚙️ Requisitos  

Antes de ejecutar los programas, asegúrate de tener:

- Conocimientos básicos de C y de procesos en sistemas UNIX/Linux  
- Sistema operativo **Linux** o similar  
- Compilador **gcc** instalado  
  ```bash
  sudo apt install gcc

Instalación y ejecución

Clonar el repositorio

git clone https://github.com/Dalinel05/Pr-ctica3---Sistemas-Operativos-2025B.git
cd Pr-ctica3---Sistemas-Operativos-2025B


Entrar al ejercicio deseado

cd Ejercicio6_Exec


Compilar el programa

gcc nombre_archivo.c -o nombre_ejecutable


Ejecutar

./nombre_ejecutable


Dependiendo del ejercicio, puede que el programa requiera permisos especiales o argumentos adicionales.

Ejercicios incluidos

Ejercicio 1	Introducción a procesos	Creación básica de procesos en C

Ejercicio 2	Comunicación básica	Sincronización entre procesos

Ejercicio 3 – Proceso Hijo Sin Espera	Control de procesos	Creación de un proceso hijo sin espera de finalización

Ejercicio 5 – Proceso Zombie	Procesos huérfanos y zombies	Demostración de cómo se genera un proceso zombie

Ejercicio 6 – Exec	Sustitución de procesos	Uso de la familia de funciones exec() para ejecutar otros programas

Ejercicio 7 – System	Invocación de comandos	Uso de system() para ejecutar comandos del sistema operativo
