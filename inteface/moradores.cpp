#include "moradores.h"

//Moradores::Moradores( QObject *parent) : QObject(parent){

Moradores::Moradores(){
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addSpacerItem( espaco( 30 ) );
    layout->addWidget( new QLabel( "Nome" ) );
    layout->addWidget( new QLabel( "Saldo" ) );
    layout->addWidget( new QLabel( "Constribuição" ) );
        layout->addSpacerItem( espaco( 30 ) );
    vertical->addLayout( layout );
}


QWidget* Moradores::getMoradores(){
    for( int i = 0; i < moradores.length(); i++ ){
        vertical->addLayout( moradores[i] );
    }
    resul->setLayout( vertical );
    return resul;
}

void Moradores::gerarCasa( QVector<morador*> casa ){
    for( int i = 0; i < casa.length(); i++ ) {
        this->addUiMorador( casa[i] );
    }
}

void Moradores::addUiMorador( morador* morador ){
    QHBoxLayout *layout = new QHBoxLayout();
    QCheckBox* cbxContribuindo = new QCheckBox( );
    QLabel* lblNome = new QLabel( morador->nro + " - " + morador->nome );
    QLabel* lblSaldo = new QLabel( QLocale().toCurrencyString( morador->saldo ) );
    Botao *btnMudarCotribuicao = new Botao( "+", morador );
    QLabel* lblContribuicao = new QLabel( QLocale().toCurrencyString( morador->contribuicao ) );

    cbxContribuindo->setCheckState( Qt::CheckState( morador->marcacao ) );
    cbxContribuindo->setFixedWidth( 20 );

    layout->addWidget( cbxContribuindo );
    layout->addWidget( lblNome );
    layout->addWidget( lblSaldo );

    //btnMudarCotribuicao->setText("+");
    btnMudarCotribuicao->setEnabled( morador->marcacao );
    layout->addWidget(btnMudarCotribuicao);

    layout->addWidget( lblContribuicao );


    moradores.push_back( layout );

    connect(cbxContribuindo, SIGNAL( stateChanged(int) ), btnMudarCotribuicao, SLOT( desabilitar(int) ) );
    connect(btnMudarCotribuicao,SIGNAL( clicked() ), btnMudarCotribuicao, SLOT( addContribuicao( ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarSaldo( QString ) ), lblSaldo, SLOT( setText( QString ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarContribuicao( QString ) ), lblContribuicao, SLOT( setText( QString ) ) );
}

QSpacerItem *Moradores::espaco(int largura){
    return new QSpacerItem( largura, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
}

