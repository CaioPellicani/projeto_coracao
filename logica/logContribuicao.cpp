#include "logContribuicao.h"

bool logContribuicao::addDados( float valor, QString obs ){
    if( valor != 0 ){
        dados* novoValor = new dados;

        novoValor->valor = valor;
        novoValor->dataHora = QDateTime::currentDateTime();
        novoValor->obs = obs;
        listaValoresInseridos.push_back( novoValor );

        
        return true;
    }
    else{
        return false;
    }
}

float logContribuicao::getTotalInserido(){
    float result = 0;
    for( int i = 0; i < listaValoresInseridos.length(); i++ ){
        result +=  listaValoresInseridos[i]->valor;
    }   
    return result;
}