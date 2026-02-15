#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_H

#include "operador.h"

class Instruccion {
  virtual void execute (Operador& op) = 0;
};

# endif