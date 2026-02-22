#include <iostream>

#include "utilidades.h"
#include "cinta_entrada.h"
#include "cinta_salida.h"
#include "memoria_datos.h"
#include "operandoinmediato.h"
#include "operandodirecto.h"
#include "operandoindirecto.h"
#include "operandoindexado.h"

int main (int argc, char* argv[]) {
  // Comprobar el numero de parametros de entrada
  if (argc < 2) {
    MostrarAyuda();
    return 1;
  } 
  try {
    // Procesar entrada
    OpcinesPrograma opciones = ParseArgs(argc, argv);
    if (opciones.mostrar_ayuda) {
      MostrarAyuda();
      return 0;
    }
    // Leer cinta de entrada
    CintaEntrada entrada(opciones.cinta_entrada);
    // Comprobar que lee bien
    entrada.MostrarCinta();

    CintaSalida salida(opciones.cinta_salida);
    // Comprobar que escribe bien
    for (int i = 0; i < 10; ++i) {
      salida.Write(i);
    }

    // Crear memoria de datos
    MemoriaDatos datos;
    
    // Cargar datos desde la cinta de entrada
    size_t contador = 1;
    while (!entrada.FinDeCinta()) {
      int actual = entrada.Read();
      datos.Store(actual, contador);
      ++contador;
    }
    
    std::cout << "\n========= ESTADO INICIAL DE LA MEMORIA =========" << std::endl;
    datos.MostrarMemoria();
    
    // ========= PRUEBAS DE OPERANDOS =========
    std::cout << "\n========= PRUEBAS DE LOS 4 TIPOS DE OPERANDOS =========" << std::endl;
    
    // 1. OPERANDO INMEDIATO (Constante)
    std::cout << "\n1. OPERANDO INMEDIATO (=42):" << std::endl;
    OperandoInmediato op_inmediato(42);
    int valor_inmediato = op_inmediato.GetValor(datos);
    std::cout << "   Valor obtenido: " << valor_inmediato << std::endl;
    salida.Write(valor_inmediato);
    
    // 2. OPERANDO DIRECTO (Registro R0, R1, R2...)
    std::cout << "\n2. OPERANDO DIRECTO (R0, R1, R2):" << std::endl;
    if (contador > 0) {
      OperandoDirecto op_directo_r0(0);
      int valor_r0 = op_directo_r0.GetValor(datos);
      std::cout << "   R0 = " << valor_r0 << std::endl;
      salida.Write(valor_r0);
    }
    if (contador > 1) {
      OperandoDirecto op_directo_r1(1);
      int valor_r1 = op_directo_r1.GetValor(datos);
      std::cout << "   R1 = " << valor_r1 << std::endl;
      salida.Write(valor_r1);
    }
    if (contador > 2) {
      OperandoDirecto op_directo_r2(2);
      int valor_r2 = op_directo_r2.GetValor(datos);
      std::cout << "   R2 = " << valor_r2 << std::endl;
      salida.Write(valor_r2);
    }
    
    // 3. OPERANDO INDIRECTO (*R1 significa usar el valor de R1 como dirección)
    std::cout << "\n3. OPERANDO INDIRECTO (*R1):" << std::endl;
    // Primero, almacenar un índice en R10 para usarlo como puntero
    datos.Store(2, 10); // R10 = 2 (apunta al registro 2)
    OperandoIndirecto op_indirecto(10);
    try {
      int valor_indirecto = op_indirecto.GetValor(datos);
      std::cout << "   *R10 -> R[" << datos.Load(10) << "] = " << valor_indirecto << std::endl;
      salida.Write(valor_indirecto);
    } catch (const std::exception& e) {
      std::cout << "   Error: " << e.what() << std::endl;
    }
    
    // 4. OPERANDO INDEXADO (R5[2] significa acceder al índice 2 del vector en R5)
    std::cout << "\n4. OPERANDO INDEXADO (R5[índice]):" << std::endl;
    // Crear un vector en R5 con múltiples valores
    datos.Store(100, 5, 0); // R5[0] = 100
    datos.Store(200, 5, 1); // R5[1] = 200
    datos.Store(300, 5, 2); // R5[2] = 300
    datos.Store(400, 5, 3); // R5[3] = 400
    
    std::cout << "   Creado vector en R5: [100, 200, 300, 400]" << std::endl;
    
    // Acceder a diferentes índices
    OperandoIndexado op_indexado_0(5, 0);
    int valor_idx_0 = op_indexado_0.GetValor(datos);
    std::cout << "   R5[0] = " << valor_idx_0 << std::endl;
    salida.Write(valor_idx_0);
    
    OperandoIndexado op_indexado_2(5, 2);
    int valor_idx_2 = op_indexado_2.GetValor(datos);
    std::cout << "   R5[2] = " << valor_idx_2 << std::endl;
    salida.Write(valor_idx_2);
    
    OperandoIndexado op_indexado_3(5, 3);
    int valor_idx_3 = op_indexado_3.GetValor(datos);
    std::cout << "   R5[3] = " << valor_idx_3 << std::endl;
    salida.Write(valor_idx_3);
    
    // Prueba con indexación dinámica (usar valor de un registro como índice)
    datos.Store(1, 11); // R11 = 1 (índice dinámico)
    size_t indice_dinamico = datos.Load(11);
    OperandoIndexado op_indexado_dinamico(5, indice_dinamico);
    int valor_dinamico = op_indexado_dinamico.GetValor(datos);
    std::cout << "   R5[R11] = R5[" << indice_dinamico << "] = " << valor_dinamico << std::endl;
    salida.Write(valor_dinamico);
    
    std::cout << "\n========= ESTADO FINAL DE LA MEMORIA =========" << std::endl;
    datos.MostrarMemoria();
    
    std::cout << "\n========= PRUEBAS COMPLETADAS =========" << std::endl;
    std::cout << "Resultados escritos en: " << opciones.cinta_salida << std::endl;

    salida.Cerrar();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  }

  return 0;
}