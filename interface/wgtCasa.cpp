#include "wgtCasa.h"

QWidget* WgtCasa::getUi( QGridLayout *value ){
    QWidget *resul = new QWidget();

    resul->setLayout( value );
    return resul;
}

void WgtCasa::setListaContas( QVector<Logica::Conta *> value ){ 
    this->listaContas = value; 
    this->gerarUi( CONTA, this->listaContas.length() ); 
}

void WgtCasa::setListaMoradores( QVector<Logica::Morador *> value ){ 
    this->listaMoradores = value; 
    this->gerarUi( MORADOR, this->listaMoradores.length() );
}

void WgtCasa::gerarUi( int tipo, int length ){

    for( int i = 0; i < length; i++ ) {
        switch (tipo){
        case CONTA:
            WgtContas( lytContas, this->listaContas[i] );
            break;
        
        case MORADOR:
            WgtMoradores( lytMoradores, this->listaMoradores[i] );
            break;
        }       
    }
}


