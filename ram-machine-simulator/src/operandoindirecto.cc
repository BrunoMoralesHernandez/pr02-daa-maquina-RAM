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
  * @brief Implementación de OperandoIndirecto.
  * @date Feb 2026 
  * @version 1.0
  */

#include "operandoindirecto.h"

/**
 *  @brief Devuelve R[R[registro_id]]: doble indirección.
 * 
 * @param datos 
 * @return int 
 */
int OperandoIndirecto::GetValor (const MemoriaDatos& datos) {
  size_t registro = static_cast<size_t>(datos.Load(registro_id_));
  return datos.Load(registro);
}

/**
 * @brief Almacena valor en R[R[registro_id]].
 * 
 * @param datos 
 * @param valor 
 */
void OperandoIndirecto::SetValor(MemoriaDatos& datos, int valor) {
  size_t registro = static_cast<size_t>(datos.Load(registro_id_));
  datos.Store(valor, registro);
}