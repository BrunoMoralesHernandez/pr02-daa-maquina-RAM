#include "operandodirecto.h"

OperandoDirecto::OperandoDirecto (int indice_registro) : indice_registro_(indice_registro) {}
int OperandoDirecto::GetValor (const MemoriaDatos& datos) {
  return datos.Load(indice_registro_);
}