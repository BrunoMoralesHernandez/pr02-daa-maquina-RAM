#include "operandoinmediato.h"

OperandoInmediato::OperandoInmediato (int valor) : valor_(valor) {}
int OperandoInmediato::GetValor (const MemoriaDatos& datos) {
  return valor_;
}