#ifndef PRACTICARAM_INCLUDE_INSTRUCCION_H
#define PRACTICARAM_INCLUDE_INSTRUCCION_H

#include "maquina-ram.h"

class Instruccion {
  virtual void execute (MaquinaRAM& maquina) = 0;
};

# endif