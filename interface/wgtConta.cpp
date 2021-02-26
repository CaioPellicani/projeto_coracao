#include "wgtConta.h"

WgtConta::WgtConta( QGridLayout *_lytGeral, Logica::Conta *conta, QWidget *parent ){ 
    this->lytGeral = _lytGeral;

    this->addUiIndividual( conta );
}

void WgtConta::addUiCabecalho(){
    int row = 0;

    lytGeral->addWidget( new QLabel( "Pago" ), row, PAGANDO );
    lytGeral->addWidget( new QLabel( "Nome" ), row, NOME );
    lytGeral->addWidget( new QLabel( "Valor" ), row, VALOR );
}

void WgtConta::addUiIndividual( Logica::Conta * conta ){
    int row = lytGeral->rowCount();
    
    if( row == 1 ){
        this->addUiCabecalho();
        row++;
    }

    QCheckBox* cbxPagando = new QCheckBox();
    lytGeral->addWidget( cbxPagando, row, PAGANDO );
    cbxPagando->setCheckState( Qt::CheckState( conta->getMarcacao() ) );
    cbxPagando->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    QLabel* lblNome = new QLabel();
    lblNome->setText( conta->getNome() );
    lytGeral->addWidget( lblNome, row, NOME );
    
    QLabel* lblValor = new QLabel();
    lblValor->setText( formatoDinheiro( conta->getValor() ) );
    lytGeral->addWidget( lblValor, row, VALOR );
}

