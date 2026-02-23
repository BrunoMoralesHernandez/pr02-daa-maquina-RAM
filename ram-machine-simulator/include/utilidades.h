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
  * @brief Funciones de utilidad para leer la entradad por parametros
  * @date Feb 2026
  * @version 1.0
  */

#ifndef PRACTICARAM_INCLUDE_UTILIDADES_H
#define PRACTICARAM_INCLUDE_UTILIDADES_H

#include <iostream>
#include <string>

struct OpcinesPrograma {
  bool mostrar_ayuda = false;
  std::string programa_ram;
  std::string cinta_entrada;
  std::string cinta_salida;
};

void MostrarAyuda();
OpcinesPrograma ParseArgs (const int argc, char* argv []);

#endif