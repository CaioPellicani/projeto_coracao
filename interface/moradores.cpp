#include "moradores.h"

Moradores::Moradores( QVector<logMorador*> casa ){
    rowLytGeral = lytGeral->rowCount();
    lytGeral->addWidget( new QLabel( "Nome" ), rowLytGeral, NOME );
    lytGeral->addWidget( new QLabel( "Saldo" ), rowLytGeral, SALDO );
    lytGeral->addWidget( new QLabel( "Contribuição" ), rowLytGeral, CONTRIBUICAO );

    this->gerarCasa( casa );
}

void Moradores::gerarCasa( QVector<logMorador*> casa ){
    for( int i = 0; i < casa.length(); i++ ) {
        this->addUiMorador( casa[i] );
    }
}

void Moradores::addUiMorador( logMorador* morador ){
    rowLytGeral = lytGeral->rowCount();

    QCheckBox* cbxContribuindo = new QCheckBox( );
    cbxContribuindo->setCheckState( Qt::CheckState( morador->getMarcacao() ) );
    cbxContribuindo->setFixedWidth( 20 );
    lytGeral->addWidget( cbxContribuindo, rowLytGeral, CONTRIBUINDO );

    QLabel* lblNome = new QLabel();
    lblNome->setText( morador->getNro() + " - " + morador->getNome() );
    lytGeral->addWidget( lblNome, rowLytGeral, NOME );
    
    QLabel* lblSaldo = new QLabel();
    lblSaldo->setText( morador->getSaldoString() );
    lytGeral->addWidget( lblSaldo, rowLytGeral, SALDO );

    Botao *btnMudarCotribuicao = new Botao( "+", morador );
    btnMudarCotribuicao->setEnabled( morador->getMarcacao() );
    lytGeral->addWidget(btnMudarCotribuicao, rowLytGeral, MUDAR_CONTRIBUICAO);

    QLabel* lblContribuicao = new QLabel();
    lblContribuicao->setText( morador->getContribuicaoString() );
    lytGeral->addWidget( lblContribuicao, rowLytGeral, CONTRIBUICAO );

    connect( cbxContribuindo,     SIGNAL( stateChanged(int) ),                btnMudarCotribuicao, SLOT( desabilitar( int ) ) );
    connect( btnMudarCotribuicao, SIGNAL( clicked() ),                        btnMudarCotribuicao, SLOT( addContribuicao( ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarSaldo( QString ) ),        lblSaldo,            SLOT( setText( QString ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarContribuicao( QString ) ), lblContribuicao,     SLOT( setText( QString ) ) );
}

QWidget* Moradores::getMoradores(){
    QWidget *resul = new QWidget();

    resul->setLayout( lytGeral );
    return resul;
}



