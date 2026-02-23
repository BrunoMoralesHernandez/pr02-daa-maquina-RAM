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
  * @brief Operando indexado con soporte de índice estático y dinámico
  * @date 2025
  * @version 1.1
  */

#ifndef PRACTICARAM_INCLUDE_OPERANDODINDEXADO_H
#define PRACTICARAM_INCLUDE_OPERANDODINDEXADO_H

#include "operador.h"

class OperandoIndexado : public Operador {
 public:
  OperandoIndexado(size_t registro, size_t offset) : registro_id_(registro), offset_(offset), indice_dinamico_(false) {}
  OperandoIndexado(size_t registro, size_t offset, bool dinamico) : registro_id_(registro), offset_(offset), indice_dinamico_(dinamico) {}
  int GetValor(const MemoriaDatos& datos) override;
  void SetValor(MemoriaDatos& datos, int valor) override;
 private:
  size_t registro_id_;
  size_t offset_;
  bool indice_dinamico_{}; // Nos permite realizaar operaciones como Ri[*j] y realizar algoritmos de ordenacion
};

# endif