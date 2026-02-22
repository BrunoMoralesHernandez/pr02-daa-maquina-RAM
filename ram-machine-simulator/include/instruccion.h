/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Diseño y Analisis de Algoritmos 2025-2026
  * 3º Año de Carrera
  * Práctica 2: Experimentación y complejidad computacional -
  *             Patrón Estrategia - Simulador de la máquina RAM
  *
  * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
  * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
  * @brief 
  * @date 
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_H

#include "input_unit.h"
#include "output_unit.h"
#include "memoria_datos.h"

/**
 * Class instruccion
 *       Clase abstracta que define una serie de algoritmos de la familia instrucciones,
 *       Define la interfaz común para todas las instrucciones concretas.
 *       Cada instrucción debe implementar el método execute, que actúa
 *       sobre la memoria de datos, las unidades de entrada/salida y el
 *       contador de programa (pc).
 * 
 */
class Instruccion {
 public:
  virtual ~Instruccion() = default;
  virtual void execute (MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc) = 0;
};

# endif