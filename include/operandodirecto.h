#ifndef PRACTICARAM_INCLUDE_OPERANDODIRECTO_H
#define PRACTICARAM_INCLUDE_OPERANDODIRECTO_H

#include "operador.h"

class OperandoDirecto : Operador {
 public:
  OperandoDirecto (int indice_registro);
  int GetValor (const MemoriaDatos& datos) override;
 private:
  int indice_registro_;
};

# endif