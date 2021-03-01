#include "logConta.h"

using namespace Logica;

float Conta::getValor(){ return valor; }
void Conta::setValor( int value){ this->valor = value; }

bool Conta::getCustoFixo(){ return custoFixo; }
void Conta::setCustoFixo( int value){ this->custoFixo = value; }