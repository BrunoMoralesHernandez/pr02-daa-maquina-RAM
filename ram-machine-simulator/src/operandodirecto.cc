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

#include "operandodirecto.h"

/**
 * @brief 
 * 
 * @param datos 
 * @return int 
 */
int OperandoDirecto::GetValor (const MemoriaDatos& datos) {
  if (indice_registro_ < 0) {
    throw std::runtime_error("Error: Indice de registro directo invalido, valor negativo");
  }
  return datos.Load(indice_registro_);
}

/**
 * @brief 
 * 
 * @param datos 
 * @param valor 
 */
void OperandoDirecto::SetValor(MemoriaDatos& datos, int valor) {
  if (indice_registro_ < 0) {
    throw std::runtime_error("Error: Indice de registro directo invalido, valor negativo");
  }
  datos.Store(valor, indice_registro_);
}