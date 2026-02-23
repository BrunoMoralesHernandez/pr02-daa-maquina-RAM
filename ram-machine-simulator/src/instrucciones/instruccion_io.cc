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
  * @brief Implementación de READ y WRITE.
  * @date Feb 21 2026
  * @version 1.0
  */

#include "instrucciones/instruccion_io.h"

/**
 * @brief Lee el siguiente valor de la cinta de entrada y lo almacena en el operando.
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionREAD::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_cinta = entrada.LeerValor();
  operando_->SetValor(datos, valor_cinta);
  ++pc;
}

/**
 * @brief Escribe el valor del operando en la cinta de salida. 
 * 
 * @param datos 
 * @param entrada 
 * @param salida 
 * @param pc 
 */
void InstruccionWRITE::execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) {
  int valor_escribir = operando_->GetValor(datos);
  salida.EscribirValor(valor_escribir);
  ++pc;
}