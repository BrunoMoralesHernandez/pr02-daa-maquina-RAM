#ifndef PRACTICARAM_INCLUDE_UTILIDADES_H
#define PRACTICARAM_INCLUDE_UTILIDADES_H

#include <iostream>
#include <string>

struct OpcinesPrograma {
  bool mostrar_ayuda = false;
  std::string programa_ram;
  std::string cinta_entrada;
  std::string cinta_salida;
};

void MostrarAyuda();
OpcinesPrograma ParseArgs (const int argc, char* argv []);

#endif