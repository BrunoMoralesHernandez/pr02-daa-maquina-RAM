#include "memoria_datos.h"

// Constructor
MemoriaDatos::MemoriaDatos() {
  // Inicializar el Registro 0 (acomulador en 0)
  datos_.push_back(std::vector<int>(1, 0));
}

// Leer
int MemoriaDatos::Load(const size_t registro, const size_t indice) const {
  if (registro >= datos_.size()) {
    throw std::runtime_error("Error: Registro " + std::to_string(registro) + " fuera de rango");
  }
  if (indice >= datos_[registro].size()) {
    throw std::runtime_error("Error: Índice " + std::to_string(indice) + " fuera de rango en registro " + std::to_string(registro));
  }
  return datos_[registro][indice];
}
// Escrbir
void MemoriaDatos::Store(const int valor, const size_t registro, const size_t indice) {
  if (registro >= datos_.size()) {
    size_t tamaño_previo = datos_.size();
    datos_.resize(registro + 1);
    for (size_t i = tamaño_previo; i < datos_.size(); ++i) {
      if (datos_[i].empty()) {
        datos_[i].push_back(0);
      }
    }
  }
  if (indice >= datos_[registro].size()) {
    datos_[registro].resize(indice + 1, 0);
  }
  datos_[registro][indice] = valor;
}
// Mostrar memoria
void MemoriaDatos::MostrarMemoria() const {
  std::cout << "=========== MEMORIA DE DATOS ===========" << std::endl;
  for (size_t i = 0; i < datos_.size(); ++i) {
    std::cout << "Registro R" << i;
    if (i == 0) {
      std::cout << " (Acumulador)";
    }
    std::cout << ": [ ";
    for (size_t j = 0; j < datos_[i].size(); ++j) {
      std::cout << datos_[i][j];
      if (j < datos_[i].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << " ]" << std::endl;
  }
  std::cout << "========================================" << std::endl;
}