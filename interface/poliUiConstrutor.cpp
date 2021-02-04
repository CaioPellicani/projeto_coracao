#include "poliUiConstrutor.h"
/*
UiConstrutor::UiConstrutor(){
}

void UiConstrutor::addUiCabecalho(){
    /*rowLytGeral = lytGeral->rowCount();

    lytGeral->addWidget( new QLabel( "Pago" ), rowLytGeral, PAGANDO );
    lytGeral->addWidget( new QLabel( "Nome" ), rowLytGeral, NOME );
    lytGeral->addWidget( new QLabel( "Valor" ), rowLytGeral, VALOR );*//*
}

void UiConstrutor::gerarUiCompleta(){

    for( int i = 0; i < this->listaExterna.length(); i++ ) {
        this->addUiIndividual( this->listaExterna[i] );
    }
}

void UiConstrutor::addUiIndividual( Logica::Unidade* unidade ){
    *//*rowLytGeral = lytGeral->rowCount();

    QCheckBox* cbxPagando = new QCheckBox( );
    cbxPagando->setCheckState( Qt::CheckState( conta->getMarcacao() ) );
    cbxPagando->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    lytGeral->addWidget( cbxPagando, rowLytGeral, PAGANDO );

    QLabel* lblNome = new QLabel();
    lblNome->setText( conta->getNome() );
    lytGeral->addWidget( lblNome, rowLytGeral, NOME );
    
    QLabel* lblValor = new QLabel();
    lblValor->setText( formatoDinheiro( conta->getValor() ) );
    lytGeral->addWidget( lblValor, rowLytGeral, VALOR );*//*
}

QWidget* UiConstrutor::getUi(){
    QWidget *resul = new QWidget();

    resul->setLayout( lytGeral );
    return resul;
}

*/
