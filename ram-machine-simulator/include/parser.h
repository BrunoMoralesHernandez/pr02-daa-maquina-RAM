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
  * @brief Parser para cargar programas RAM
  * @date 2025
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_PARSER_H
#define PRACTICARAM_INCLUDE_PARSER_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "operador.h"
#include "memoria_programa.h"

enum class Token {
  ADD, SUB, MUL, DIV,
  LOAD, STORE,
  READ, WRITE,
  JUMP, JZERO, JGTZ,
  HALT,
  DESCONOCIDA
};

/**
 * @class Parser
 * @brief Parser de programas RAM
 *
 * Carga un archivo .ram y genera MemoriaPrograma con instrucciones.
 * 
 * Validaciones en tiempo de parseo:
 * - LOAD: Rechaza operandos inmediatos
 * - STORE: Rechaza operandos inmediatos y R0
 * - READ: Rechaza operandos inmediatos y R0
 * - WRITE: Rechaza R0
 * - JUMP/JZERO/JGTZ: Solo aceptan direcciones válidas
 * - HALT: No acepta operandos
 * - DIV: Acepta operandos pero valida en ejecución
 */
class Parser {
 public:
  Parser() = default;
  MemoriaPrograma ParsearPrograma(const std::string&);
  private:
  // Métodos principales
  std::unique_ptr<Instruccion> ParsearLinea(const std::string&, int);
  // Token y validación
  Token IdentificarToken(const std::string&);
  void ValidarOperando(Token, const std::string&, int);
  // Creación de instrucciones y operandos
  std::unique_ptr<Instruccion> CrearInstruccion(Token, std::unique_ptr<Operador>, int);
  std::unique_ptr<Operador> CrearOperando(const std::string&, int);
  // Procesamiento de líneas
  std::vector<std::string> DividirLineas(const std::string&);
  std::vector<std::string> LimpiarTodasLineas(const std::vector<std::string>&, size_t = 0);
  std::string LimpiarLinea(const std::string&);
  // Mapeo de etiquetas
  void MapearEtiquetas(const std::vector<std::string>&);
  std::vector<std::string> ReemplazarEtiquetas(const std::vector<std::string>&);
  // Auxiliares para operandos
  std::string IdentificarTipoOperando(const std::string&);
  int ExtraerRegistro(const std::string&);
  int ExtraerIndice(const std::string&);
  
  // Estructura de datos
  std::unordered_map<std::string, int> etiquetas_;
};

#endif
