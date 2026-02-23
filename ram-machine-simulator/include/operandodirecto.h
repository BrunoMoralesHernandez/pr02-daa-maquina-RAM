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
  * @brief Operando directo (Ri): accede al contenido del registro i.
  * @date Feb 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_OPERANDODIRECTO_H
#define PRACTICARAM_INCLUDE_OPERANDODIRECTO_H

#include "operador.h"

class OperandoDirecto : public Operador {
 public:
 OperandoDirecto(size_t indice_registro) : indice_registro_(indice_registro) {}
  int GetValor(const MemoriaDatos& datos) override;
  void SetValor(MemoriaDatos& datos, int valor) override;
 private:
  size_t indice_registro_;
};

# endif