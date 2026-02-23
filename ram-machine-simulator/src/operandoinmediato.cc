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
  * @brief Implementación de OperandoInmediato.
  * @date Feb 2026
  * @version 1.0
  */

#include "operandoinmediato.h"

/**
 * @brief Devuelve la constante almacenada en valor_. Ignora datos. 
 * 
 * @param datos 
 * @return int 
 */
int OperandoInmediato::GetValor(const MemoriaDatos& datos) {
  return valor_;
}

/**
 * @brief No permitido: lanza excepción. No se puede escribir en un inmediato.
 * 
 * @param datos 
 * @param valor 
 */
void OperandoInmediato::SetValor(MemoriaDatos& datos, int valor) {
  throw std::runtime_error("Error: No se puede escribir en operando inmediato (=valor)");
}