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

#ifndef PRACTICARAM_INCLUDE_MEMORIA_DATOS_H
#define PRACTICARAM_INCLUDE_MEMORIA_DATOS_H

#include <vector>
#include <iostream>

/**
 * Clase MemoriaDatos
 *       Posee una serie de registros indexados R0, R1, R2, …, Rn para
 *       almacenar datos. El registro R0 es un registro especial llamado acumulador, el cual
 *       ayuda en la realización de operaciones aritméticas, lógicas y de control.
 * 
 */
class MemoriaDatos {
 public:
  MemoriaDatos();
  int Load(const size_t registro, const size_t indice = 0) const;
  void Store(const int valor, const size_t registro, const size_t indice = 0);
  void MostrarMemoria() const;
 private:
  std::vector<std::vector<int>> datos_;
};

#endif