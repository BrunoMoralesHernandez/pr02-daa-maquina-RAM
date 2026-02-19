#include "operandoindexado.h"

OperandoIndexado::OperandoIndexado (int registro, int offset) : registro_id_(registro), offset_(offset) {}
int OperandoIndexado::GetValor (const MemoriaDatos& datos) {
  return datos.Load(registro_id_, offset_);
}