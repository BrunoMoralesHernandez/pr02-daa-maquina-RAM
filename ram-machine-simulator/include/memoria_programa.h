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
  * @brief Almacén inmutable de instrucciones del programa cargado.
  * @date Feb 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_MEMORIA_INSTRUCCIONES_H
#define PRACTICARAM_INCLUDE_MEMORIA_INSTRUCCIONES_H

#include <iostream>
#include <vector>
#include <memory> // Uso de punteros inteligentes los cuales nos ahorran el tener que limpiar manualmente
                  // std::unique_ptr<> y std::make_unique<>()
#include "instruccion.h"

/** 
 * Clase MemoriaInstrucciones
 *       Guarda el conjunto de instrucciones de un programa. Esta
 *       memoria no es modificable.
 * 
 */
class MemoriaPrograma {
 public:
  MemoriaPrograma() = default;
  ~MemoriaPrograma() = default;
  MemoriaPrograma(const MemoriaPrograma&) = delete;
  MemoriaPrograma& operator=(const MemoriaPrograma&) = delete;
  MemoriaPrograma(MemoriaPrograma&&) = default;
  MemoriaPrograma& operator=(MemoriaPrograma&&) = default;
  void AgregarInstruccion(std::unique_ptr<Instruccion>);
  Instruccion* ObtenerInstruccion(size_t) const;
  size_t Tamano() const { return instrucciones_.size(); }
  void MostrarMemoria() const;
 private:
  std::vector<std::unique_ptr<Instruccion>> instrucciones_;
};

#endif