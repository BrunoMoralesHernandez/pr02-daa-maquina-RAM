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
  * @brief Instrucciones de memoria: LOAD (→R0) y STORE (R0→destino).
  * @date Feb 21 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_MEMORIA_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_MEMORIA_H

#include <memory>
#include "operador.h"
#include "instruccion.h"

class InstruccionLOAD : public Instruccion {
 public:
  InstruccionLOAD(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

class InstruccionSTORE : public Instruccion {
 public:   
  InstruccionSTORE(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, size_t& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

#endif