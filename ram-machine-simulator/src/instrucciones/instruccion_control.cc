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
  * @brief Implementación de JUMP, JZERO y JGTZ.
  * @date Feb 21 2026
  * @version 1.0
  */

#include "instrucciones/instruccion_control.h"


/**
 * @brief Salta incondicionalmente a la dirección del operando. 
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionJUMP::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int salto_pc = operando_->GetValor(datos);
  pc = static_cast<size_t>(salto_pc);
}

/**
 * @brief Salta si R0 == 0, si no avanza al siguiente.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionJZERO::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  if (valor_R0 == 0) {
    int salto_pc = operando_->GetValor(datos);
    pc = static_cast<size_t>(salto_pc);
  } else {
    ++pc;
  }
}

/**
 * @brief Salta si R0 > 0, si no avanza al siguiente.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionJGTZ::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_R0 = datos.Load(0);
  if (valor_R0 > 0) {
    int salto_pc = operando_->GetValor(datos);
    pc = static_cast<size_t>(salto_pc);
  } else {
    ++pc;
  }
}