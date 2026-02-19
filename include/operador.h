#ifndef PRACTICARAM_INCLUDE_OPERADOR_H
#define PRACTICARAM_INCLUDE_OPERADOR_H

#include "memoria_datos.h"

class Operador {
 public:
  virtual ~Operador();
  virtual int GetValor (const MemoriaDatos& datos) = 0;
};

# endif