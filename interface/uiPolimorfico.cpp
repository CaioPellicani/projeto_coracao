#include "uiPolimorfico.h"

uiPolimorfico::uiPolimorfico( QVector<void *> listaExterna ){

}

void uiPolimorfico::begin(){
    this->addUiCabecalho();
    this->gerarUiCompleta();
}


void uiPolimorfico::addUiCabecalho(){
    rowLytGeral = lytGeral->rowCount();
    /* 
    TODO:
    lytGeral->addWidget( new QLabel( "NOME CAMPO" ), rowLytGeral, INT REFERENTE A COLUNA );
    */
}

void uiPolimorfico::gerarUiCompleta(){
    for( int i = 0; i < this->listaExterna.length(); i++ ) {
        this->addUiIndividual( this->listaExterna[i] );
    }
}

void uiPolimorfico::addUiIndividual( void * fonteDados ){
    //#TODO: implementar construção grafica de cada linha da lista de UIs
}

QWidget* uiPolimorfico::getUi(){
    QWidget *resul = new QWidget();

    resul->setLayout( lytGeral );
    return resul;
}



