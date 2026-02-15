#ifndef PRACTICARAM_INCLUDE_CINTA_SALIDA_H
#define PRACTICARAM_INCLUDE_CINTA_SALIDA_H

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class CintaSalida {
 public:
  // Constructor
  CintaSalida(const std::string& nombre_archivo);
  // Escribir
  void Write(const int dato);
  // Comprobar si ya termino la cinta
  void Cerrar();
 private:
  std::ofstream archivo_;
};

#endif