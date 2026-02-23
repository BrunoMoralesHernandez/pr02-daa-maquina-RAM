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
  * @brief Implementación de OutputUnit: escritura en cinta y volcado a archivo.
  * @date Feb 20 2026 
  * @version 1.0
  */

#include <iostream>
#include <fstream>
#include "output_unit.h"

/**
 * @brief Escribe el valor cargado en la cinta de salida y avanza el cabezal.
 * 
 * @param valor 
 */
void OutputUnit::EscribirValor(const int valor) {
  cinta_salida_.Agregar(valor);
  ++cabezal_;
} 

/**
 * @brief Cierra la cinta y escribe todos los datos en el archivo
 * 
 * Abre el archivo de salida especificado en el constructor,
 * escribe todos los valores de la cinta separados por espacios,
 * y cierra el archivo.
 * 
 * @throws std::runtime_error Si no se puede abrir el archivo de salida
 */
void OutputUnit::CerrarCinta() {
  std::ofstream archivo_salida(nombre_archivo_);
  if (!archivo_salida.is_open()) {
    throw std::runtime_error("Error: No se pudo abrir el archivo de salida '" + nombre_archivo_ + "'");
  }
  // Escribir todos los valores de la cinta
  archivo_salida << cinta_salida_;  // Nueva línea al final
  archivo_salida.close();
}