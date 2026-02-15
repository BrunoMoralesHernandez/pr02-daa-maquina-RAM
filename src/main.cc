#include <iostream>

#include "utilidades.h"
#include "cinta_entrada.h"
#include "cinta_salida.h"
#include "memoria_datos.h"

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
    // Comprobar que lee bien
    entrada.MostrarCinta();

    CintaSalida salida(opciones.cinta_salida);
    // Comprobar que escribe bien
    for (int i = 0; i < 10; ++i) {
      salida.Write(i);
    }

    // Crear memoria de datos
    MemoriaDatos datos;
    // bloque para comprobar que guarda bien
    size_t contador = 0;
    while (!entrada.FinDeCinta()) {
      int actual = entrada.Read();
      datos.Store(actual, contador);
      ++contador;
    }
    datos.MostrarMemoria();

    salida.Cerrar();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}