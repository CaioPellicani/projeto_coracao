#include "logContribuicao.h"

using namespace Logica;

Contribuicao::Contribuicao( Morador* _morador ){
    this->morador = _morador;
    this->getDBLista();   
}

void Contribuicao::concluir(){
    morador->addContribuicao( this->getTotalInserido() );
    this->insertDB();
}

Contribuicao::dados* Contribuicao::getDadosDB( int posicao ){ 
    return listaValoresDB[posicao]; 
}

int Contribuicao::getLenghtDB(){ 
    return listaValoresDB.size(); 
}

Contribuicao::dados* Contribuicao::getDadosTail(){ 
    return listaValoresInseridos.last(); 
};

bool Contribuicao::addDados( float valor, QString obs ){
   return this->addDados( &this->listaValoresInseridos, valor, QDateTime::currentDateTime(), obs );
} //usado em testes 

bool Contribuicao::addDados( QVector<dados*> *lista, float valor, QDateTime dataHora, QString obs ){

    if( valor != 0 ){
        lista->push_back( new dados );
        lista->last()->valor = valor;
        lista->last()->dataHora = dataHora;
        lista->last()->obs = obs;   
        return true;
    }
    return false;
}

float Contribuicao::getTotalInserido(){
    float result = 0;
    for( int i = 0; i < listaValoresInseridos.length(); i++ ){
        result +=  listaValoresInseridos[i]->valor;
    }   
    return result;
}

bool Contribuicao::getDBLista(){
    this->addDados( &this->listaValoresDB, 10.0, QDateTime::currentDateTime(), "teste1" );
    this->addDados( &this->listaValoresDB, 20.0, QDateTime::currentDateTime(), "teste2" );
    return true;
}

bool Contribuicao::insertDB(){

    for( int i = 0; i < this->listaValoresInseridos.size(); i++ ){
    qDebug() << "insert: " << listaValoresInseridos[i]->valor;
    }
    return true;
}
