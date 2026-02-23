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
  * @brief Implementación de LOAD y STORE.
  * @date Feb 20 2026
  * @version 1.0
  */

#include "instrucciones/instruccion_memoria.h"

/**
 * @brief R0 = valor del operando.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionLOAD::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor = operando_->GetValor(datos);
  datos.Store(valor, 0);
  ++pc;
}

/**
 * @brief destino = R0.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionSTORE::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  operando_->SetValor(datos, valor_R0);
  ++pc;
}