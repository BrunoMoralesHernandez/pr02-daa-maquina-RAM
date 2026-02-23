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
  * @brief Implementación del Parser
  * @date 2025
  * @version 1.0
  */

#include "parser.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "instrucciones/instruccion_alu.h"
#include "instrucciones/instruccion_memoria.h"
#include "instrucciones/instruccion_io.h"
#include "instrucciones/instruccion_control.h"
#include "instrucciones/instruccion_sistema.h"
#include "operandoinmediato.h"
#include "operandodirecto.h"
#include "operandoindirecto.h"
#include "operandoindexado.h"

MemoriaPrograma Parser::ParsearPrograma(const std::string& fichero) {
  // 1. Dividir líneas
  auto lineas = DividirLineas(fichero);
  // 2. Primera pasada: limpiar y mapear etiquetas
  auto lineas_limpias_v0 = LimpiarTodasLineas(lineas, 0);
  MapearEtiquetas(lineas_limpias_v0);
  // 3. Segunda pasada: procesar instrucciones
  auto lineas_limpias_v1 = LimpiarTodasLineas(lineas, 1);
  // 4. Reemplazar etiquetas por =indice
  auto lineas_reemplazadas = ReemplazarEtiquetas(lineas_limpias_v1);
  MemoriaPrograma programa;
  int numero_linea = 0;
  for (const auto& linea : lineas_reemplazadas) {
    numero_linea++;
    try {
      auto instruccion = ParsearLinea(linea, numero_linea);
      programa.AgregarInstruccion(std::move(instruccion));
    } catch (const std::exception& e) {
      throw std::runtime_error(std::string(e.what()));
    }
  }
  return programa;
}

/**
 * @brief 
 * 
 * @param nombre_fichero 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Parser::DividirLineas(const std::string& nombre_fichero) {
  std::ifstream fichero_RAM(nombre_fichero);
  if (!fichero_RAM.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el fichero");
  }
  std::vector<std::string> fichero_dividido{};
  std::string linea{};
  while (getline(fichero_RAM, linea)) {
    fichero_dividido.push_back(linea);
  }
  return fichero_dividido;
}

/**
 * @brief 
 * 
 * @param linea 
 * @return std::string 
 */
std::string Parser::LimpiarLinea(const std::string& linea) {
  // Primero buscamos comentario, si los hay los borramos, si no seguimos
  size_t posicion = linea.find('#');
  std::string sin_comentario = (posicion != std::string::npos) ? linea.substr(0, posicion) 
                               : linea;
  //Buscar inicio y fin (trim)
  size_t inicio = sin_comentario.find_first_not_of(" \t\r\n");
  size_t fin = sin_comentario.find_last_not_of(" \t\r\n");
  if (inicio == std::string::npos) return "";  // Vacía
  return sin_comentario.substr(inicio, fin - inicio + 1);
}

/**
 * @brief 
 * 
 * @param lineas 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Parser::LimpiarTodasLineas(const std::vector<std::string>& lineas, size_t iteracion) {
  std::vector<std::string> lineas_limpias;
  for (const auto& linea : lineas) {
    std::string limpia = LimpiarLinea(linea);
    // Si es segunda iteración (iteracion == 1), eliminar etiquetas
    if (iteracion == 1 && limpia.find(':') != std::string::npos) {
      limpia = limpia.substr(limpia.find(':') + 1);
      limpia = LimpiarLinea(limpia);  // Limpia espacios después de ':'
    }
    if (limpia != "") lineas_limpias.push_back(limpia);
  }
  return lineas_limpias;
}

/**
 * @brief 
 * 
 * @return oid 
 */
void Parser::MapearEtiquetas(const std::vector<std::string>& programa) {
  for (size_t i{0}; i < programa.size(); ++i) {
    std::string linea = programa[i];
    if (linea.find(':') != std::string::npos) {
      etiquetas_.insert({linea.substr(0, linea.find(':')), i});
    }
  }
}


std::string Parser::IdentificarTipoOperando(const std::string& operando_str) {
  if (operando_str.empty()) {
    return "vacio";
  }
  if (operando_str[0] == '=') {
    return "inmediato";
  }
  if (operando_str[0] == '*') {
    return "indirecto";
  }
  if (operando_str.find('[') != std::string::npos) {
    size_t posicion_index = operando_str.find('[');
    if (operando_str[posicion_index + 1] == '*') {
      return "indexado_dinamico";
    }
    return "indexado";
  }
  return "directo";
}

int Parser::ExtraerRegistro(const std::string& operando_str) {
  std::string temp = operando_str;
  // Eliminar prefijos
  if (!temp.empty() && (temp[0] == '=' || temp[0] == '*')) {
    temp = temp.substr(1);
  }
  // Eliminar indexado
  size_t pos_corchete = temp.find('[');
  if (pos_corchete != std::string::npos) {
    temp = temp.substr(0, pos_corchete);
  }
  try {
    return std::stoi(temp);
  } catch (...) {
    throw std::runtime_error("Error: Registro inválido en operando '" + operando_str + "'");
  }
}

int Parser::ExtraerIndice(const std::string& operando_str) {
  size_t inicio = operando_str.find('[');
  size_t fin = operando_str.find(']');
  if (inicio == std::string::npos || fin == std::string::npos) {
    throw std::runtime_error("Error: Formato indexado inválido '" + operando_str + "'");
  }
  std::string indice_str = operando_str.substr(inicio + 1, fin - inicio - 1);
  if (!indice_str.empty() && indice_str[0] == '*') {
    indice_str = indice_str.substr(1);
  }
  try {
    return std::stoi(indice_str);
  } catch (...) {
    throw std::runtime_error("Error: Índice inválido en operando '" + operando_str + "'");
  }
}

void Parser::ValidarOperando(Token token, const std::string& operando_str, int numero_linea) {
  if (operando_str.empty() && token != Token::HALT) {
    throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                            ": Instrucción requiere operando");
  }
  std::string tipo = IdentificarTipoOperando(operando_str);
  // STORE: Rechaza inmediatos y R0
  if (token == Token::STORE) {
    if (tipo == "inmediato") {
      throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                              ": STORE no puede usar operandos inmediatos (=valor)");
    }
    if (tipo == "directo") {
      int reg = ExtraerRegistro(operando_str);
      if (reg == 0) {
        throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                                ": STORE no puede usar R0");
      }
    }
  }
  // READ: Rechaza inmediatos y R0
  if (token == Token::READ) {
    if (tipo == "inmediato") {
      throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                              ": READ no puede usar operandos inmediatos (=valor)");
    }
    if (tipo == "directo") {
      int reg = ExtraerRegistro(operando_str);
      if (reg == 0) {
        throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                                ": READ no puede usar R0");
      }
    }
  }
  // WRITE: Rechaza R0
  if (token == Token::WRITE) {
    if (tipo == "directo") {
      int reg = ExtraerRegistro(operando_str);
      if (reg == 0) {
        throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                                ": WRITE no puede usar R0");
      }
    }
  }
  // HALT: No acepta operandos
  if (token == Token::HALT) {
    if (!operando_str.empty()) {
      throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                              ": HALT no acepta operandos");
    }
  }
}

std::unique_ptr<Operador> Parser::CrearOperando(const std::string& operando_str, int numero_linea) {
  std::string tipo = IdentificarTipoOperando(operando_str);
  try {
    if (tipo == "inmediato") {
      int valor = std::stoi(operando_str.substr(1));
      return std::make_unique<OperandoInmediato>(valor);
    }
    if (tipo == "directo") {
      int registro = ExtraerRegistro(operando_str);
      return std::make_unique<OperandoDirecto>(registro);
    }
    if (tipo == "indirecto") {
      int registro = ExtraerRegistro(operando_str);
      return std::make_unique<OperandoIndirecto>(registro);
    }
    if (tipo == "indexado") {
      int registro = ExtraerRegistro(operando_str);
      int indice = ExtraerIndice(operando_str);
      return std::make_unique<OperandoIndexado>(registro, indice);
    }
    if (tipo == "indexado_dinamico") {
      int registro = ExtraerRegistro(operando_str);
      int indice = ExtraerIndice(operando_str);
      return std::make_unique<OperandoIndexado>(registro, indice, true);
    }
    if (tipo == "vacio") {
      return nullptr;
    }
  } catch (const std::exception& e) {
    throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                            ": " + std::string(e.what()));
  }
  throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                          ": Tipo de operando desconocido '" + operando_str + "'");
}

std::vector<std::string> Parser::ReemplazarEtiquetas(const std::vector<std::string>& lineas) {
  std::vector<std::string> lineas_reemplazadas;
  
  for (const auto& linea : lineas) {
    std::istringstream iss(linea);
    std::string token, operando;
    
    iss >> token >> operando;
    
    // Si el operando no es un número y no es un operando especial (=, *, [)
    // entonces intenta reemplazarlo por una etiqueta
    if (!operando.empty() && 
        operando[0] != '=' && 
        operando[0] != '*' && 
        operando.find('[') == std::string::npos) {
      
      // Verificar si es un número
      bool es_numero = true;
      for (char c : operando) {
        if (!std::isdigit(c)) {
          es_numero = false;
          break;
        }
      }
      
      // Si no es número, buscar en etiquetas
      if (!es_numero && etiquetas_.find(operando) != etiquetas_.end()) {
        int indice_linea = etiquetas_[operando];
        operando = "=" + std::to_string(indice_linea);
      }
    }
    
    // Reconstruir línea con operando reemplazado
    std::string linea_reemplazada = token;
    if (!operando.empty()) {
      linea_reemplazada += " " + operando;
    }
    
    lineas_reemplazadas.push_back(linea_reemplazada);
  }
  
  return lineas_reemplazadas;
}

std::unique_ptr<Instruccion> Parser::CrearInstruccion(Token token, 
                                                      std::unique_ptr<Operador> operando,
                                                      int numero_linea) {
  try {
    switch (token) {
      case Token::ADD:
        return std::make_unique<InstruccionADD>(std::move(operando));
      
      case Token::SUB:
        return std::make_unique<InstruccionSUB>(std::move(operando));
      
      case Token::MUL:
        return std::make_unique<InstruccionMUL>(std::move(operando));
      
      case Token::DIV:
        return std::make_unique<InstruccionDIV>(std::move(operando));
      
      case Token::LOAD:
        return std::make_unique<InstruccionLOAD>(std::move(operando));
      
      case Token::STORE:
        return std::make_unique<InstruccionSTORE>(std::move(operando));
      
      case Token::READ:
        return std::make_unique<InstruccionREAD>(std::move(operando));
      
      case Token::WRITE:
        return std::make_unique<InstruccionWRITE>(std::move(operando));
      
      case Token::JUMP:
        return std::make_unique<InstruccionJUMP>(std::move(operando));
      
      case Token::JZERO:
        return std::make_unique<InstruccionJZERO>(std::move(operando));
      
      case Token::JGTZ:
        return std::make_unique<InstruccionJGTZ>(std::move(operando));
      
      case Token::HALT:
        return std::make_unique<InstruccionHALT>();
      
      case Token::DESCONOCIDA:
        throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                                ": Token desconocido");
    }
  } catch (const std::exception& e) {
    throw std::runtime_error(std::string(e.what()));
  }
  
  throw std::runtime_error("Error línea " + std::to_string(numero_linea) + 
                          ": Error al crear instrucción");
}

std::unique_ptr<Instruccion> Parser::ParsearLinea(const std::string& linea, int numero_linea) {
  std::istringstream iss(linea);
  std::string token_str, operando_str;
  iss >> token_str >> operando_str;
  // Convertir a mayúsculas
  std::transform(token_str.begin(), token_str.end(), token_str.begin(), ::toupper);
  // Identificar token
  Token token = IdentificarToken(token_str);
  try {
    // Validar operando según token
    ValidarOperando(token, operando_str, numero_linea);
    // Crear operando
    auto operando = CrearOperando(operando_str, numero_linea);
    // Crear y retornar instrucción
    return CrearInstruccion(token, std::move(operando), numero_linea);
  } catch (const std::exception& e) {
    throw std::runtime_error(std::string(e.what()));
  }
}

Token Parser::IdentificarToken(const std::string& token_str) {
  if (token_str == "ADD") return Token::ADD;
  if (token_str == "SUB") return Token::SUB;
  if (token_str == "MUL") return Token::MUL;
  if (token_str == "DIV") return Token::DIV;
  if (token_str == "LOAD") return Token::LOAD;
  if (token_str == "STORE") return Token::STORE;
  if (token_str == "READ") return Token::READ;
  if (token_str == "WRITE") return Token::WRITE;
  if (token_str == "JUMP") return Token::JUMP;
  if (token_str == "JZERO") return Token::JZERO;
  if (token_str == "JGTZ") return Token::JGTZ;
  if (token_str == "HALT") return Token::HALT;
  return Token::DESCONOCIDA;
}