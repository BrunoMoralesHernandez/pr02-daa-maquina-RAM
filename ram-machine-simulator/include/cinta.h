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

#ifndef PRACTICARAM_INCLUDE_CINTA_H
#define PRACTICARAM_INCLUDE_CINTA_H

#include <iostream>
#include <vector>

/**
 * Class Cinta
 *       Clase que representa las cintas de lectura y escritura,
 *       su funcion es almacenar los datos, es una clase generica.
 */
class Cinta {
 public:
  // Constructor
  Cinta() = default;
  // Metodos auxiliares
  void Agregar(int valor) { datos_.push_back(valor); }
  int Leer(size_t indice) const { return datos_[indice]; } 
  size_t Tamano() const { return datos_.size(); }
  void MostrarCinta() const;
  friend std::ostream& operator<<(std::ostream& os, const Cinta& cinta);
 private:
  std::vector<int> datos_;
};

#endif