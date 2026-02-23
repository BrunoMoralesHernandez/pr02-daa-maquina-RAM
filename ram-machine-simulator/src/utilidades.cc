#include "utilidades.h"

/**
 * Muestra el mensaje de ayuda y uso del programa.
 * Se debe invocar cuando el usuario introduce argumentos incorrectos.
 */
void MostrarAyuda() {
  std::cout << "            Simulador de Máquina RAM (RAM Simulator)           " << std::endl;
  std::cout << "Uso correcto:" << std::endl;
  std::cout << "  ./ram_sim -p <programa_ram> -e <cinta_entrada> -s <cinta_salida>" << std::endl;
  std::cout << std::endl;
  std::cout << "Opciones:" << std::endl;
  std::cout << "  -h, --help               : Muestra este mensaje de ayuda" << std::endl;
  std::cout << "  -p, --programa <archivo> : Fichero con el código fuente del programa (.ram)" << std::endl;
  std::cout << "                             Formato: Instrucciones RAM (ADD, LOAD, JUMP...)" << std::endl;
  std::cout << "  -e, --entrada <archivo>  : Fichero con los datos de entrada (.tape)" << std::endl;
  std::cout << "                             Formato: Enteros separados por espacios" << std::endl;
  std::cout << "  -s, --salida <archivo>   : Fichero donde se guardará la salida (.tape)" << std::endl;
  std::cout << std::endl;
  std::cout << "Ejemplo de ejecución:" << std::endl;
  std::cout << "  ./ram_sim -p test/bubblesort.ram -e test/input.tape -s test/output.tape" << std::endl;
}

OpcinesPrograma ParseArgs(const int argc, char* argv[]) {
  OpcinesPrograma opciones;
  for (int i = 1; i < argc; ++i) {
    std::string actual = std::string(argv[i]);
    if (actual == "-h" || actual == "--help") {
      opciones.mostrar_ayuda = true;
      break;
    } else if (actual == "-p" || actual == "--programa") {
      if (i + 1 < argc) {
        opciones.programa_ram = std::string(argv[++i]);
      } else {
        throw std::runtime_error("Error: No se indico el nombre del fichero");
      }
    } else if (actual == "-e" || actual == "--entrada") {
      if (i + 1 < argc) {
        opciones.cinta_entrada = std::string(argv[++i]);
      } else {
        throw std::runtime_error("Error: No se indico el nombre del fichero");
      }
    } else if (actual == "-s" || actual == "--salida") {
      if (i + 1 < argc) {
        opciones.cinta_salida = std::string(argv[++i]);
      } else {
        throw std::runtime_error("Error: No se indico el nombre del fichero");
      }
    } else {
      std::cerr << "Error: argumento invalido" << std::endl;
    }
  }
  // Solo validar archivos si no se solicita ayuda
  if (!opciones.mostrar_ayuda && opciones.cinta_entrada == opciones.cinta_salida) {
    throw std::runtime_error("Error fatal: El archivo de entrada y salida no pueden ser el mismo.");
  }
  return opciones;
}
