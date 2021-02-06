#include "uiContas.h"

uiContas::uiContas( QVector<Logica::Conta *> _listaExterna ):UiConstrutor<Logica::Conta>( _listaExterna ){ 
    qDebug() << "criada essa merda"; 
    this->addUiCabecalho();
    this->gerarUiCompleta();
}

void uiContas::addUiCabecalho(){
    rowLytGeral = lytGeral->rowCount();

    lytGeral->addWidget( new QLabel( "Pago" ), rowLytGeral, PAGANDO );
    lytGeral->addWidget( new QLabel( "Nome" ), rowLytGeral, NOME );
    lytGeral->addWidget( new QLabel( "Valor" ), rowLytGeral, VALOR );
}

void uiContas::gerarUiCompleta(){

    for( int i = 0; i < this->listaExterna.length(); i++ ) {
        this->addUiIndividual( this->listaExterna[i] );
    }
}

void uiContas::addUiIndividual( Logica::Conta * conta ){
    rowLytGeral = lytGeral->rowCount();

    QCheckBox* cbxPagando = new QCheckBox( );
    cbxPagando->setCheckState( Qt::CheckState( conta->getMarcacao() ) );
    cbxPagando->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    lytGeral->addWidget( cbxPagando, rowLytGeral, PAGANDO );

    QLabel* lblNome = new QLabel();
    lblNome->setText( conta->getNome() );
    lytGeral->addWidget( lblNome, rowLytGeral, NOME );
    
    QLabel* lblValor = new QLabel();
    lblValor->setText( formatoDinheiro( conta->getValor() ) );
    lytGeral->addWidget( lblValor, rowLytGeral, VALOR );
}


