#ifndef PRACTICARAM_INCLUDE_OPERANDODINDEXADO_H
#define PRACTICARAM_INCLUDE_OPERANDODINDEXADO_H

#include "operador.h"

class OperandoIndexado : Operador {
 public:
  OperandoIndexado (int registro, int offset);
  int GetValor (const MemoriaDatos& datos) override;
 private:
  int registro_id_;
  int offset_;
};

# endif