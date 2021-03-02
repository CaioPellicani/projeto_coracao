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
        listaWgtMoradores.push_back( criarMorador( this->logica->getListaMoradores()[i] ) );     
    }
}

WgtMorador* WgtCasa::criarMorador( Logica::Morador* _morador ){
    return new WgtMorador( lytMoradores, _morador, this);
}

void WgtCasa::refreshMoradores(){
    this->limparWgtMoradores();
    this->gerarMoradores();
}

void WgtCasa::limparWgtMoradores(){
    while ( ! listaWgtMoradores.isEmpty() ){
        delete listaWgtMoradores.first();
        listaWgtMoradores.removeFirst();
    }
}

void WgtCasa::gerarContas(){
    for( int i = 0; i < this->logica->getListaContas().length(); i++ ) {
        new WgtConta( lytContas, this->logica->getListaContas()[i], this );     
    }
}

WgtConta* WgtCasa::criarConta( Logica::Conta* _conta ){
    return new WgtConta( lytContas, _conta, this);
}

void WgtCasa::refreshContas(){
    this->limparWgtContas();
    this->gerarContas();
}

void WgtCasa::limparWgtContas(){
    while ( ! listaWgtContas.isEmpty() ){
        delete listaWgtContas.first();
        listaWgtContas.removeFirst();
    }
}

QWidget* WgtCasa::getWgtMoradores() { return this->converterLyt_Wgt( lytMoradores ); }
QWidget* WgtCasa::getWgtContas(){     return this->converterLyt_Wgt( lytContas ); }

QGridLayout* WgtCasa::getLytMoradores() { return this->lytMoradores; }
QGridLayout* WgtCasa::getLytContas(){ return this->lytContas; }


