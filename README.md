# Simulador de Máquina RAM (RAM Machine Simulator)

## Descripción del Proyecto
Este proyecto consiste en la implementación de un simulador para una **Máquina de Acceso Aleatorio (RAM)**, un modelo computacional teórico utilizado para el análisis de la complejidad de algoritmos.

El simulador interpreta y ejecuta programas escritos en un lenguaje ensamblador específico, manipulando una memoria de datos y cintas de entrada/salida. El diseño del software ha sido construido desde cero utilizando **C++**, siguiendo estrictamente el paradigma de **Programación Orientada a Objetos (POO)** y principios de arquitectura de software robusta (SOLID, Patrón Estrategia).

### Características Destacadas (Extensiones APTO+)
Este simulador implementa la **Extensión de la Máquina RAM** descrita en la práctica:
* **Registros como Vectores Dinámicos:** Capacidad para manejar estructuras de datos complejas mediante direccionamiento indexado (Sintaxis `R1[2]` o `i[j]`).
* **Memoria Dinámica:** Gestión de la memoria de datos (`DataMemory`) mediante estructuras que se redimensionan automáticamente (vector de vectores), permitiendo el uso de registros "infinitos" bajo demanda.
* **Análisis de Complejidad:** El simulador cuenta el número de instrucciones ejecutadas para realizar estudios empíricos de coste computacional.

---

## Diseño y Arquitectura

El proyecto se ha estructurado para maximizar la cohesión y minimizar el acoplamiento:

### 1. Patrón Strategy (Instrucciones)
Cada instrucción de la máquina RAM (`ADD`, `SUB`, `JUMP`, etc.) se ha modelado como una clase independiente que implementa una interfaz común `Instruction`. Esto permite añadir nuevas operaciones sin modificar el núcleo de la máquina.

### 2. Polimorfismo en Operandos
Se ha diseñado una jerarquía de clases para gestionar los 4 tipos de operandos soportados:
* **Inmediato/Constante:** Valor literal (ej: `=5`).
* **Directo:** Acceso a registro (ej: `5` o `R5`).
* **Indirecto:** Puntero a registro (ej: `*5`).
* **Indexado (Extensión):** Acceso a posición de vector dentro de un registro (ej: `5[2]` o `R5[2]`).

### 3. Arquitectura de Memoria
Separación estricta de responsabilidades:
* **ProgramMemory:** Almacena las instrucciones del programa (solo lectura).
* **DataMemory:** Estructura dinámica (`std::vector<std::vector<int>>`) que gestiona los registros $R_0 \dots R_n$.

---

## Compilación y Uso

### Requisitos
* Compilador C++ moderno (g++ / clang).
* Sistema operativo Linux/Unix o Windows.

### Compilación