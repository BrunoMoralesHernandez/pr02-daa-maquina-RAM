#ifndef PRACTICARAM_INCLUDE_OPERANDOINMEDIATO_H
#define PRACTICARAM_INCLUDE_OPERANDOINMEDIATO_H

#include "operador.h"

class OperandoInmediato : Operador {
 public:
  OperandoInmediato (int valor);
  int GetValor (const MemoriaDatos& datos) override;
 private:
  int valor_;
};

# endif