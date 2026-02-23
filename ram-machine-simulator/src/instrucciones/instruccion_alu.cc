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

#include "instrucciones/instruccion_alu.h"

/**
 * @brief 
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionADD::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  int resultado = valor_R0 + operando_->GetValor(datos);
  datos.Store(resultado, 0);
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
void InstruccionSUB::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  int resultado = valor_R0 - operando_->GetValor(datos);
  datos.Store(resultado, 0);
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
void InstruccionMUL::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  int resultado = valor_R0 * operando_->GetValor(datos);
  datos.Store(resultado, 0);
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
void InstruccionDIV::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  int valor_operando = operando_->GetValor(datos);
  if (valor_operando == 0) {
    throw std::runtime_error("Error: División por cero");
  }
  int resultado = valor_R0 / valor_operando;
  datos.Store(resultado, 0);
  ++pc;
}