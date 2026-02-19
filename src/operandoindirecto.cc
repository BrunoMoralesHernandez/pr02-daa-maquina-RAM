#include "operandoindirecto.h"

OperandoIndirecto::OperandoIndirecto (const int registro) : registro_id_(registro) {}
int OperandoIndirecto::GetValor (const MemoriaDatos& datos) {
  int registro = datos.Load(registro_id_);
  return datos.Load(registro);
}