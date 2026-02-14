#ifndef PRACTICARAM_INCLUDE_CINTA_ENTRADA_H
#define PRACTICARAM_INCLUDE_CINTA_ENTRADA_H

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class CintaEntrada {
 public:
  // Constructor
  CintaEntrada(const std::string& nombre_archivo);
  // Leer
  int Read();
  // Comprobar si ya termino la cinta
  bool FinDeCinta() const;
  // Mostrar cinta
  void MostrarCinta() const;
 private:
  std::vector<int> datos_;
  size_t puntero_ = 0;
};

#endif