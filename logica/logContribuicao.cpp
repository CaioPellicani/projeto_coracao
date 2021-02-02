#include "logContribuicao.h"

logContribuicao::logContribuicao( ){
    this->getDBLista();
}

bool logContribuicao::addDados( float valor, QString obs ){
   return this->addDados( &this->listaValoresInseridos, valor, QDateTime::currentDateTime(), obs );
}

bool logContribuicao::addDados( QVector<dados*> *lista, float valor, QDateTime dataHora, QString obs ){

    if( valor != 0 ){
        dados* novoValor = new dados;

        novoValor->valor = valor;
        novoValor->dataHora = dataHora;
        novoValor->obs = obs;
        lista->push_back( novoValor );
        
        return true;
    }
    return false;
}

float logContribuicao::getTotalInserido(){
    float result = 0;
    for( int i = 0; i < listaValoresInseridos.length(); i++ ){
        result +=  listaValoresInseridos[i]->valor;
    }   
    return result;
}

bool logContribuicao::getDBLista(){
    this->addDados( &this->listaValoresDB, 10.0, QDateTime::currentDateTime(), "teste1" );
    this->addDados( &this->listaValoresDB, 20.0, QDateTime::currentDateTime(), "teste2" );
    return true;
}