#include "logMorador.h"

using namespace Logica;

QString Morador::getApelido(){ return this->apelido; }
void Morador::setApelido( QString value ){ this->apelido = value; }

int Morador::getID(){ return ID; }
void Morador::setID( int value ){ this->ID = value; }

float Morador::getContribuicao(){ return contribuicao; }
void Morador::addContribuicao( float value ){ this->contribuicao += value; }

float Morador::getCustoMes(){ return custoMes; }
void Morador::setCustoMes( float value ){ this->custoMes = value; }

float Morador::getSaldo(){ 
    return contribuicao - custoMes + saldoMesAnterior; 
}

bool Morador::validarEmail( QString email ){
    QRegExp rx( "[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}" );

    return rx.exactMatch( email );
}