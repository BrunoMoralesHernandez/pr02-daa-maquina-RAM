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

#include "cinta.h"

/**
 * @brief Funcion para imprimir los contenidos de la cinta
 * 
 */
void Cinta::MostrarCinta() const {
  std::cout << "Contenido de la cinta: [ ";
  for (size_t i = 0; i < datos_.size(); ++i) {
    std::cout << datos_[i];
    if (i < datos_.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << " ]" << std::endl;
}

/**
 * @brief 
 * 
 * @param os 
 * @param cinta 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Cinta& cinta) {
  for (size_t i = 0; i < cinta.datos_.size(); ++i) {
    os << cinta.datos_[i];
    if (i < cinta.datos_.size() - 1) {
      os << " ";
    }
  }
  os << std::endl;
  return os;
}