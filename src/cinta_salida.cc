#include "cinta_salida.h"

// Constructor
CintaSalida::CintaSalida(const std::string& nombre_archivo) {
  archivo_.open(nombre_archivo);
  if (!archivo_.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo de salida");
  }
}
// Escribir
void CintaSalida::Write(const int dato) {
  if (!archivo_.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo de salida");
  }
  archivo_ << dato << " ";
}
// Comprobar si ya termino la cinta
void CintaSalida::Cerrar() {
  if (archivo_.is_open()) {
    archivo_ << std::endl;
    archivo_.close();
  }
}