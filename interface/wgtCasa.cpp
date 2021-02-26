#include "wgtCasa.h"

WgtCasa::WgtCasa( QWidget *parent ){
    this->lytContas->setMargin( 30 );
    this->lytMoradores->setMargin( 30 );
}

QWidget* WgtCasa::converterLyt_Wgt( QGridLayout *value ){
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
            new WgtConta( lytContas, this->listaContas[i], this);
            break;
        
        case MORADOR:
            new WgtMorador( lytMoradores, this->listaMoradores[i], this );
            break;
        }       
    }
}


