#include "wgtCasa.h"

WgtCasa::WgtCasa( Logica::Casa* _logica, QWidget *parent ){
    this->logica = _logica;
    this->lytContas->setMargin( 30 );
    this->lytMoradores->setMargin( 30 );
}

QWidget* WgtCasa::converterLyt_Wgt( QGridLayout *value ){
    QWidget *resul = new QWidget();

    resul->setLayout( value );
    return resul;
}

void WgtCasa::gerarMoradores(){
    for( int i = 0; i < this->logica->getListaMoradores().length(); i++ ) {
        new WgtMorador( lytMoradores, this->logica->getListaMoradores()[i], this);     
    }
}

void WgtCasa::gerarContas(){
    for( int i = 0; i < this->logica->getListaContas().length(); i++ ) {
        new WgtConta( lytContas, this->logica->getListaContas()[i], this );     
    }
}

QWidget* WgtCasa::getWgtMoradores() { 
    return this->converterLyt_Wgt( lytMoradores ); 
}

QWidget* WgtCasa::getWgtContas(){ 
    return this->converterLyt_Wgt( lytContas ); 
}

QGridLayout* WgtCasa::getLytMoradores() { 
    return this->lytMoradores; 
}

QGridLayout* WgtCasa::getLytContas(){ 
    return this->lytContas; 
}

