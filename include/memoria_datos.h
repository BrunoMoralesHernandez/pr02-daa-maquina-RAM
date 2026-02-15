#ifndef PRACTICARAM_INCLUDE_MEMORIA_DATOS_H
#define PRACTICARAM_INCLUDE_MEMORIA_DATOS_H

#include <vector>
#include <iostream>

class MemoriaDatos {
 public:
  // Constructor
  MemoriaDatos();
  // Leer
  int Load(const size_t registro, const size_t indice = 0) const;
  // Escrbir
  void Store(const int valor, const size_t registro, const size_t indice = 0);
  // Mostrar memoria
  void MostrarMemoria() const;
 private:
  std::vector<std::vector<int>> datos_;
};

#endif