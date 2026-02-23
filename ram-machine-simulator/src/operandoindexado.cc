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
  * @brief Implementación de OperandoIndexado (estático y dinámico).
  * @date Feb 2026
  * @version 1.0
  */

#include "operandoindexado.h"

/**
 * @brief Devuelve R[registro_id][j], donde j es offset_ o R[offset_] si dinámico.
 * 
 * @param datos 
 * @return int 
 */
int OperandoIndexado::GetValor(const MemoriaDatos& datos) {
  size_t indice = indice_dinamico_ ? static_cast<size_t>(datos.Load(offset_)) : offset_;
  return datos.Load(registro_id_, indice);
}

/**
 * @brief Almacena valor en R[registro_id][j] con índice estático o dinámico.
 * 
 */
void OperandoIndexado::SetValor(MemoriaDatos& datos, int valor) {
  size_t indice = indice_dinamico_ ? static_cast<size_t>(datos.Load(offset_)) : offset_;
  datos.Store(valor, registro_id_, indice);
}