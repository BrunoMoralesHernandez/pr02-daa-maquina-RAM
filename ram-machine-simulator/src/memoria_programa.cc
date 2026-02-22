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

#include "memoria_programa.h"

/**
 * @brief 
 * 
 * @param instruccion 
 */
void MemoriaPrograma::AgregarInstruccion(std::unique_ptr<Instruccion> instruccion) {
  instrucciones_.push_back(std::move(instruccion));
}

/**
 * @brief 
 * 
 * @param pc 
 * @return Instruccion* 
 */
Instruccion* MemoriaPrograma::ObtenerInstruccion(size_t pc) const {
  if (pc >= instrucciones_.size()) {
    throw std::runtime_error("Error: Instrucción fuera de rango. PC=" + std::to_string(pc));
  }
  return instrucciones_[pc].get();
}

/**
 * @brief 
 * 
 */
void MemoriaPrograma::MostrarMemoria() const {
  for (size_t i = 0; i < instrucciones_.size(); ++i) {
    std::cout << "PC[" << i << "]: ";
    // instrucciones_[i]->Mostrar();
    std::cout << std::endl;
  }
}