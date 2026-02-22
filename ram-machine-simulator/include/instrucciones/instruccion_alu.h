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

#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_ALU_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_ALU_H

#include <memory>
#include "operador.h"
#include "instruccion.h"

class InstruccionADD : public Instruccion {
 public:
  InstruccionADD(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

class InstruccionSUB : public Instruccion {
 public:
  InstruccionSUB(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

class InstruccionMUL : public Instruccion {
 public:
  InstruccionMUL(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

class InstruccionDIV : public Instruccion {
 public:
  InstruccionDIV(std::unique_ptr<Operador> operando) : operando_{std::move(operando)} {} 
  void execute(MemoriaDatos& datos, InputUnit& entrada, OutputUnit& salida, int& pc, bool& halt_flag) override;
 private:
  std::unique_ptr<Operador> operando_;
};

#endif