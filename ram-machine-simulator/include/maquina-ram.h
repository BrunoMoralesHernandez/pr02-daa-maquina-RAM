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

#ifndef PRACTICARAM_INCLUDE_MAQUINA_RAM_H
#define PRACTICARAM_INCLUDE_MAQUINA_RAM_H

#include <iostream>
#include <string>
#include "input_unit.h"
#include "output_unit.h"
#include "memoria_datos.h"
#include "memoria_programa.h"

class MaquinaRAM {
 public:
  MaquinaRAM (const std::string&, const std::string&, const std::string&);
  void Run ();
  // Getters
  MemoriaDatos& datos() { return datos_; }
  MemoriaPrograma& instrucciones() { return instrucciones_; }
  InputUnit& getCintaEntrada() { return entrada_; }
  OutputUnit& getCintaSalida() { return salida_; }
  size_t pc() const { return pc_; }
  // Metodos auxiliares
  void IncrementarPC() { ++pc_; };
  void halt() { halt_flag_ = true; };
  void MostrarEstado() const;
 private:
  size_t pc_{};
  bool halt_flag_{false};
  MemoriaDatos datos_{};
  MemoriaPrograma instrucciones_{};
  InputUnit entrada_{};
  OutputUnit salida_{};  
};

# endif