#include "cinta_entrada.h"

// Constructor

CintaEntrada::CintaEntrada(const std::string& nombre_archivo) {
  std::ifstream archivo_entrada(nombre_archivo);
  if (!archivo_entrada.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo de entrada '" + nombre_archivo + "'");
  }
  int valor;
  while (archivo_entrada >> valor) {
    datos_.push_back(valor);
  }

  archivo_entrada.close();
  if (datos_.empty()) {
    throw std::runtime_error("Error: El archivo de entrada está vacío");
  }
}

// Leer

int CintaEntrada::Read() {
  if (FinDeCinta()) {
    throw std::runtime_error("Error: Fin de cinta de entrada alcanzado");
  }
  return datos_[puntero_++];
}

// Comprobar si ya termino la cinta

bool CintaEntrada::FinDeCinta() const {
  return puntero_ >= datos_.size();
}

// Mostrar contenido de la cinta
void CintaEntrada::MostrarCinta() const {
  std::cout << "Contenido de la cinta: [ ";
  for (size_t i = 0; i < datos_.size(); ++i) {
    if (i == puntero_) {
      std::cout << "*"; // Marca la posición actual
    }
    std::cout << datos_[i];
    if (i < datos_.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << " ]" << std::endl;
  std::cout << "Posición actual: " << puntero_ << "/" << datos_.size() << std::endl;
}