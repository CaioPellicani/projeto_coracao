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

void Moradores::gerarCasa( QVector<logMorador*> casa ){
    for( int i = 0; i < casa.length(); i++ ) {
        this->addUiMorador( casa[i] );
    }
}

void Moradores::addUiMorador( logMorador* morador ){
    QHBoxLayout *layout = new QHBoxLayout();
    QCheckBox* cbxContribuindo = new QCheckBox( );
    QLabel* lblNome = new QLabel( morador->getNro() + " - " + morador->getNome() );
    QLabel* lblSaldo = new QLabel( QLocale().toCurrencyString( morador->getSaldo() ) );
    Botao *btnMudarCotribuicao = new Botao( "+", morador );
    QLabel* lblContribuicao = new QLabel( QLocale().toCurrencyString( morador->getContribuicao() ) );

    cbxContribuindo->setCheckState( Qt::CheckState( morador->getMarcacao() ) );
    cbxContribuindo->setFixedWidth( 20 );

    layout->addWidget( cbxContribuindo );
    layout->addWidget( lblNome );
    layout->addWidget( lblSaldo );

    //btnMudarCotribuicao->setText("+");
    btnMudarCotribuicao->setEnabled( morador->getMarcacao() );
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

