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
  * @brief Implementación de OperandoDirecto.
  * @date Feb 2026
  * @version 1.0
  */

#include "operandodirecto.h"

/**
 * @brief Devuelve datos_[indice_registro][0].
 * 
 * @param datos 
 * @return int 
 */
int OperandoDirecto::GetValor (const MemoriaDatos& datos) {
  return datos.Load(indice_registro_);
}

/**
 * @brief Almacena valor en datos_[indice_registro][0]. 
 * 
 * @param datos 
 * @param valor 
 */
void OperandoDirecto::SetValor(MemoriaDatos& datos, int valor) {
  datos.Store(valor, indice_registro_);
}