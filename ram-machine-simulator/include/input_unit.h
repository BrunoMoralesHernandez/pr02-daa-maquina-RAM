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
  * @brief Unidad de entrada: carga datos desde archivo y gestiona el cabezal de lectura.
  * @date Feb 20 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_INPUT_UNIT_H
#define PRACTICARAM_INCLUDE_INPUT_UNIT_H

#include <iostream>
#include <string>
#include "cinta.h"

/**
 * Clase InputUnit
 *       Gestiona la entrada de datos de la máquina. La entrada de
 *       datos viene representada por una cinta de elementos, y para su lectura se dispone
 *       de un cabezal que se mueve a la siguiente posición cada vez que se realiza una
 *       operación de lectura (READ).
 */
class InputUnit {
 public:
  InputUnit() = default;
  InputUnit(const std::string&);
  int LeerValor();
 private:
  Cinta cinta_entrada_{};
  size_t cabezal_{};
};

#endif