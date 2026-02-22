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

#ifndef PRACTICARAM_INCLUDE_OPERADOR_H
#define PRACTICARAM_INCLUDE_OPERADOR_H

#include "memoria_datos.h"

class Operador {
 public:
  virtual ~Operador() = default;
  virtual int GetValor (const MemoriaDatos& datos) = 0;
};

# endif