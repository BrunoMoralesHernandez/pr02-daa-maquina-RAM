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
  * @brief Main - Punto de entrada del simulador RAM
  * @date 2025
  * @version 1.0
  */

#include <iostream>
#include <iomanip>
#include "utilidades.h"
#include "maquina-ram.h"

int main(int argc, char* argv[]) {
  try {
    if (argc < 2) {
      MostrarAyuda();
      return 1;
    }
    OpcinesPrograma opciones = ParseArgs(argc, argv);
    if (opciones.mostrar_ayuda) {
      MostrarAyuda();
      return 0;
    }
    MaquinaRAM maquina(opciones.programa_ram, 
                       opciones.cinta_entrada, 
                       opciones.cinta_salida);
    std::cout << "\nMemoria de Datos:" << std::endl;
    maquina.datos().MostrarMemoria();
    std::cout << "\nEstado de la Máquina:" << std::endl;
    maquina.MostrarEstado();
    // Ejecutamos la maquina
    std::cout << std::endl;
    maquina.Run();
    std::cout << "Ejecucion terminada" << std::endl;
    std::cout << "\nMemoria de Datos:" << std::endl;
    maquina.datos().MostrarMemoria();
    std::cout << "\nEstado de la Máquina:" << std::endl;
    maquina.MostrarEstado();
    std::cout << "Programa ejecutado correctamente" << std::endl;
    std::cout << "Salida guardada en: " << opciones.cinta_salida << std::endl;
    return 0;
  } catch (const std::runtime_error& e) {
    std::cerr << "\nError: " << e.what() << std::endl;
    return 2;
  } catch (const std::exception& e) {
    std::cerr << "Error inesperado: " << e.what() << std::endl;
    return 3;
  }
}