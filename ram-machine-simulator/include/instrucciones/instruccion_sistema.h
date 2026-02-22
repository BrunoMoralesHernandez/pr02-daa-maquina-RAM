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

#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_SISTEMA_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_SISTEMA_H

#include <memory>
#include "operador.h"
#include "instruccion.h"

class InstruccionHALT : public Instruccion {
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) override;
};

#endif