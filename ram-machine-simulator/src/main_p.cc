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
  * @brief Main simple para probar el funcionamiento de InputUnit, OutputUnit y Cinta
  * @date 2025
  * @version 1.0
  */

#include <iostream>
#include "utilidades.h"
#include "input_unit.h"
#include "output_unit.h"

int main(int argc, char* argv[]) {
  try {
    // Procesar argumentos de línea de comandos
    OpcinesPrograma opciones = ParseArgs(argc, argv);
    
    if (opciones.mostrar_ayuda) {
      MostrarAyuda();
      return 0;
    }

    std::cout << "=== PRUEBA DE I/O DE LA MÁQUINA RAM ===" << std::endl << std::endl;

    // Crear InputUnit y cargar datos de entrada
    std::cout << "1. Leyendo datos de entrada desde: " << opciones.cinta_entrada << std::endl;
    InputUnit entrada(opciones.cinta_entrada);
    std::cout << "   ✓ Archivo cargado correctamente" << std::endl << std::endl;

    // Crear OutputUnit para escribir salida
    std::cout << "2. Inicializando unidad de salida: " << opciones.cinta_salida << std::endl;
    OutputUnit salida(opciones.cinta_salida);
    std::cout << "   ✓ Unidad de salida lista" << std::endl << std::endl;

    // Leer valores de entrada y escribirlos en salida
    std::cout << "3. Leyendo valores de entrada y escribiendo en salida..." << std::endl;
    int contador = 0;
    try {
      while (true) {
        int valor = entrada.LeerValor();
        std::cout << "   Leído: " << valor;
        salida.EscribirValor(valor);
        std::cout << " → Escrito" << std::endl;
        contador++;
      }
    } catch (const std::runtime_error& e) {
      std::cout << "   " << e.what() << std::endl;
    }
    
    std::cout << std::endl << "   Total de valores procesados: " << contador << std::endl << std::endl;

    // Cerrar la cinta de salida (escribe en fichero)
    std::cout << "4. Escribiendo salida en archivo..." << std::endl;
    salida.CerrarCinta();
    std::cout << "   ✓ Archivo de salida guardado: " << opciones.cinta_salida << std::endl << std::endl;

    std::cout << "=== PRUEBA COMPLETADA EXITOSAMENTE ===" << std::endl;
    return 0;

  } catch (const std::exception& e) {
    std::cerr << "❌ Error: " << e.what() << std::endl;
    return 1;
  }
}