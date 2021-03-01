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
    this->gerarContas(); 
}

void WgtCasa::setListaMoradores( QVector<Logica::Morador *> value ){ 
    this->listaMoradores = value; 
    this->gerarMoradores();
}

void WgtCasa::gerarMoradores(){
    for( int i = 0; i < this->listaMoradores.length(); i++ ) {
        new WgtMorador( lytMoradores, this->listaMoradores[i], this);     
    }
}

void WgtCasa::gerarContas(){
    for( int i = 0; i < this->listaContas.length(); i++ ) {
        new WgtConta( lytContas, this->listaContas[i], this );     
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

