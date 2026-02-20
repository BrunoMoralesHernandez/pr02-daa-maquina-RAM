#ifndef PRACTICARAM_INCLUDE_MAQUINA_RAM_H
#define PRACTICARAM_INCLUDE_MAQUINA_RAM_H

#include <string>

#include "memoria_datos.h"
#include "memoria_instrucciones.h"
#include "cinta_entrada.h"
#include "cinta_salida.h"

class MaquinaRAM {
 public:
  // Constructor
  MaquinaRAM (const std::string& fichero_programa, const std::string& fichero_entrada, 
              const std::string& fichero_salida);
  void run ();
  // Getter
  MemoriaDatos& getMemoriaDatos();
  MemoriaPrograma& getMemoriaPrograma();
  CintaEntrada& getCintaEntrada();
  CintaSalida& getCintaSalida();
  int getPC() const;
  // Setter
  void setPC(int nuevaLinea);
  // Metodos auxiliares
  void incrementarPC();
  void halt();
 private:
  int pc_;
  bool halt_flag_;
  MemoriaDatos datos_;
  MemoriaInstrucciones instrucciones_;
  CintaEntrada cinta_entrada_;
  CintaSalida cinta_entrada_;  
};

# endif