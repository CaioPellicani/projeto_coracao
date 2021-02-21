#include "wgtCasa.h"

QWidget* WgtCasa::getUi( QGridLayout *value ){
    QWidget *resul = new QWidget();

    resul->setLayout( value );
    return resul;
}

void WgtCasa::setListaContas( QVector<Logica::Conta *> value ){ 
    this->listaContas = value; 
    this->gerarUi( value ); 
}

void WgtCasa::setListaMoradores( QVector<Logica::Morador *> value ){ 
    this->listaMoradores = value; 
    this->gerarUi( value );
}

void WgtCasa::gerarUi( QVector<Logica::Conta *> lista ){

   for( int i = 0; i < lista.length(); i++ ) {
       WgtContas *ui = new WgtContas( lytContas, lista[i] );
       delete ui;
    }
}

void WgtCasa::gerarUi( QVector<Logica::Morador *> lista ){

   for( int i = 0; i < lista.length(); i++ ) {
       WgtMoradores *ui = new WgtMoradores( lytMoradores, lista[i] );
       delete ui;
    }
}


