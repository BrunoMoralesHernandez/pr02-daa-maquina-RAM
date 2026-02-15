#include "memoria_instrucciones.h"

// Constructor
MemoriaInstrucciones::MemoriaInstrucciones() {

}
// Destructor
MemoriaInstrucciones::~MemoriaInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); ++i) {
    delete instrucciones_[i];
  }
  instrucciones_.clear();
}
// Leer
void MemoriaInstrucciones::AñadirInstruccion(Instruccion* inst) {
  instrucciones_.push_back(inst);
}
// Escrbir
Instruccion* MemoriaInstrucciones::ObtenerInstruccion(size_t pc) {
  if (pc >= instrucciones_.size()) {
    throw std::runtime_error("Error: Instrucción fuera de rango. PC=" + std::to_string(pc));
  }
  return instrucciones_[pc];
}

// Mostrar memoria
void MemoriaInstrucciones::MostrarMemoria() const {
  std::cout << "========== MEMORIA DE INSTRUCCIONES ==========" << std::endl;
  for (size_t i = 0; i < instrucciones_.size(); ++i) {
    std::cout << "PC[" << i << "]: ";
    // instrucciones_[i]->Mostrar();
    std::cout << std::endl;
  }
  std::cout << "=============================================" << std::endl;
}