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

#include "operandoindexado.h"

/**
 * @brief 
 * 
 * @param datos 
 * @return int 
 */
int OperandoIndexado::GetValor(const MemoriaDatos& datos) {
  size_t indice = indice_dinamico_ ? datos.Load(offset_) : offset_;
  return datos.Load(registro_id_, indice);
}

/**
 * @brief 
 * 
 */
void OperandoIndexado::SetValor(MemoriaDatos& datos, int valor) {
  size_t indice = indice_dinamico_ ? datos.Load(offset_) : offset_;
  datos.Store(valor, registro_id_, indice);
}