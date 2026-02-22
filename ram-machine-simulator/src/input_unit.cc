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

#include <iostream>
#include <fstream>
#include "input_unit.h"

/**
 * @brief Construct a new Input Unit:: Input Unit object
 * 
 * @param nombre_archivo 
 */
InputUnit::InputUnit(const std::string& nombre_archivo) {
  std::ifstream archivo_entrada(nombre_archivo);
  if (!archivo_entrada.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo de entrada '" + nombre_archivo + "'");
  }
  int valor;
  while (archivo_entrada >> valor) {
    cinta_entrada_.Agregar(valor);
  }
  archivo_entrada.close();
  if (cinta_entrada_.Tamano() == 0) {
    throw std::runtime_error("Error: El archivo está vacío");
  }
}

/**
 * @brief Lee el valor al que apunta el cabezal, lo devuelve y avanza el cabezar
 * @return Valor
 */
int InputUnit::LeerValor() {
  if (cabezal_ >= cinta_entrada_.Tamano()) {
    throw std::runtime_error("Error: Fin de cinta");
  }
  // Leo el actual y avanzo el cabezal
  return cinta_entrada_.Leer(cabezal_++);
}