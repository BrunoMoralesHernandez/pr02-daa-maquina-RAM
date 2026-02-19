#ifndef PRACTICARAM_INCLUDE_OPERANDOINDIRECTO_H
#define PRACTICARAM_INCLUDE_OPERANDOINDIRECTO_H

#include "operador.h"

class OperandoIndirecto : Operador {
 public:
  OperandoIndirecto (const int registro);
  int GetValor (const MemoriaDatos& datos) override;
 private:
  int registro_id_;
};

# endif