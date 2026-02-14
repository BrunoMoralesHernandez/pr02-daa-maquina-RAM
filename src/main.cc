#include <iostream>

#include "utilidades.h"

int main (int argc, char* argv[]) {
  // Comprobar el numero de parametros de entrada
  if (argc < 2) {
    MostrarAyuda();
    return 1;
  } 
  try {
    // Procesar entrada
    OpcinesPrograma opciones = ParseArgs(argc, argv);
    if (opciones.mostrar_ayuda) {
      MostrarAyuda();
      return 0;
    }
    

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}