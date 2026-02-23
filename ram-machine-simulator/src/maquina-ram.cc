/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Diseño y Analisis de Algoritmos 2025-2026
  * 3º Año de Carrera
  * Práctica 2: Experimentación y complejidad computacional -
  *             Patrón Estrategia - Simulador de la máquina RAM
  *
  * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
  * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
  * @brief 
  * @date 
  * @version 1.0
  */

#include <iostream>
#include <fstream>
#include "maquina-ram.h"
#include "parser.h"

/**
 * @brief 
 * 
 * @param fichero_programa 
 * @param fichero_entrada 
 * @param fichero_salida 
 */
MaquinaRAM::MaquinaRAM(const std::string& fichero_programa, const std::string& fichero_entrada,
  const std::string& fichero_salida) : pc_{0}, halt_flag_{false}, entrada_{fichero_entrada}, salida_ {fichero_salida} {
  Parser parser;
  instrucciones_ = parser.ParsearPrograma(fichero_programa);
  // Verificar que el programa no esté vacío
  if (instrucciones_.Tamano() == 0) {
    throw std::runtime_error("Error: Programa vacío");
  }
}

/**
 * @brief run() - Ejecuta el programa
 *
 * Bucle principal que:
 * 1. Obtiene instrucción en PC
 * 2. Ejecuta instrucción (pasa referencias a datos, I/O y PC)
 * 3. Repite hasta HALT o fin del programa
 *
 * Cada instrucción es responsable de:
 * - Modificar datos según su operación
 * - Incrementar PC (o saltar con JUMP)
 * - Llamar a halt() si es HALT
 */
void MaquinaRAM::Run() {  
  size_t instrucciones_ejecutadas = 0;
  while (!halt_flag_ && pc_ < instrucciones_.Tamano()) {
    try {
      // Obtener instrucción actual
      Instruccion* instruccion = instrucciones_.ObtenerInstruccion(pc_);
      if (instruccion == nullptr) {
        throw std::runtime_error("Instrucción nula en PC=" + std::to_string(pc_));
      }
      // Ejecutar instrucción
      instruccion->execute(datos_, entrada_, salida_, pc_, halt_flag_);
      instrucciones_ejecutadas++;
    } catch (const std::runtime_error& e) {
      std::cerr << "Error en ejecución (PC=" << pc_ << "): " << e.what() << std::endl;
      break;
    }
  }
  // Finalización
  if (halt_flag_) {
    std::cout << "Programa terminado con HALT" << std::endl;
  } else if (pc_ >= instrucciones_.Tamano()) {
    std::cout << "Programa terminado (fin de instrucciones)" << std::endl;
  }
  std::cout << "Total de instrucciones ejecutadas: " << instrucciones_ejecutadas << std::endl;
  // Guardar salida
  salida_.CerrarCinta();
}

/**
 * @brief 
 * 
 */
void MaquinaRAM::MostrarEstado() const {
  std::cout << "PC: " << pc_ << std::endl;
  std::cout << "HALT: " << (halt_flag_ ? "true" : "false") << std::endl;
  std::cout << "Instrucciones en memoria: " << instrucciones_.Tamano() << std::endl;
}