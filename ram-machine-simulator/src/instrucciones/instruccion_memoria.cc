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

#include "instruccion_memoria.h"

/**
 * @brief 
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionLOAD::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) {
  int valor = operando_->GetValor(datos);
  datos.Store(valor, 0);
  ++pc;
}

/**
 * @brief 
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionSTORE::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  operando_->SetValor(datos, valor_R0);
  ++pc;
}