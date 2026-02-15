#ifndef PRACTICARAM_INCLUDE_MEMORIA_INSTRUCCIONES_H
#define PRACTICARAM_INCLUDE_MEMORIA_INSTRUCCIONES_H

#include <vector>
#include <iostream>

#include "instruccion.h"

class MemoriaInstrucciones {
 public:
  // Constructor
  MemoriaInstrucciones();
  // Destructor
  ~MemoriaInstrucciones();
  // Leer
  void AñadirInstruccion(Instruccion* inst);
  // Escrbir
  Instruccion* ObtenerInstruccion(size_t pc);
  // Mostrar memoria
  void MostrarMemoria() const;
 private:
  std::vector<Instruccion*> instrucciones_;
};

#endif