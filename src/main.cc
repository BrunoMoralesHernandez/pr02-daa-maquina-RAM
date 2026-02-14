#include <iostream>

#include "utilidades.h"
#include "cinta_entrada.h"

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
    // Leer cinta de entrada
    CintaEntrada entrada(opciones.cinta_entrada);
    entrada.MostrarCinta();

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}