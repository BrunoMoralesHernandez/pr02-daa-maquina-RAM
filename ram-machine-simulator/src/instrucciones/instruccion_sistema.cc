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
  * @brief Implementación de HALT.
  * @date Feb 21 2026
  * @version 1.0
  */

#include "instrucciones/instruccion_sistema.h"

/**
 * @brief Activa halt_flag para detener el ciclo de ejecución.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionHALT::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  halt_flag = true;
}