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
  * @brief Unidad de salida: almacena datos en cinta y los vuelca a archivo al finalizar.
  * @date Feb 20 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_OUTPUT_UNIT_H
#define PRACTICARAM_INCLUDE_OUTPUT_UNIT_H

#include <iostream>
#include <string>
#include "cinta.h"

/**
 * Clase OutputUnit
 *       Gestiona la salida de datos de la máquina. La salida de datos
 *       viene representada por una cinta de elementos, y para su escritura se dispone de un
 *       cabezal que se mueve a la siguiente posición cada vez que se realiza una operación
 *       de escritura (WRITE).
 */
class OutputUnit {
 public:
  OutputUnit() = default;
  OutputUnit(const std::string& nombre_archivo) : nombre_archivo_{ nombre_archivo } {}
  void EscribirValor(const int);
  void CerrarCinta();
 private:
  Cinta cinta_salida_{};
  size_t cabezal_{};
  std::string nombre_archivo_{};
};

#endif