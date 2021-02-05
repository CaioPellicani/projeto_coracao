#include "uiMoradores.h"

uiMoradores::uiMoradores( QVector<Logica::Morador*> listaExterna ){
    this->lytGeral->setMargin( 30 ); 
    this->addUiCabecalho();
    this->gerarUiCompleta( listaExterna );
}

void uiMoradores::addUiCabecalho(){
    rowLytGeral = lytGeral->rowCount();
    lytGeral->addWidget( new QLabel( "Nome" ), rowLytGeral, NOME );
    lytGeral->addWidget( new QLabel( "Saldo" ), rowLytGeral, SALDO );
    lytGeral->addWidget( new QLabel( "Contribuição" ), rowLytGeral, CONTRIBUICAO );
}

void uiMoradores::gerarUiCompleta( QVector<Logica::Morador*> listaExterna ){
    for( int i = 0; i < listaExterna.length(); i++ ) {
        this->addUiIndividual( listaExterna[i] );
    }
}

void uiMoradores::addUiIndividual( Logica::Morador* morador ){
    rowLytGeral = lytGeral->rowCount();

    QCheckBox* cbxContribuindo = new QCheckBox( );
    cbxContribuindo->setCheckState( Qt::CheckState( morador->getMarcacao() ) );
    cbxContribuindo->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    lytGeral->addWidget( cbxContribuindo, rowLytGeral, CONTRIBUINDO );

    QLabel* lblNome = new QLabel();
    lblNome->setText( morador->getNro() + " - " + morador->getNome() );
    lytGeral->addWidget( lblNome, rowLytGeral, NOME );
    
    QLabel* lblSaldo = new QLabel();
    lblSaldo->setText( formatoDinheiro( morador->getSaldo() ) );
    lytGeral->addWidget( lblSaldo, rowLytGeral, SALDO );

    QLabel* lblContribuicao = new QLabel();
    lblContribuicao->setText( formatoDinheiro( morador->getContribuicao() ) );
    lytGeral->addWidget( lblContribuicao, rowLytGeral, CONTRIBUICAO );

    Botao *btnMudarCotribuicao = new Botao( "+", morador );
    btnMudarCotribuicao->setEnabled( morador->getMarcacao() );
    lytGeral->addWidget(btnMudarCotribuicao, rowLytGeral, MUDAR_CONTRIBUICAO);

    connect( cbxContribuindo,     SIGNAL( stateChanged(int) ),                btnMudarCotribuicao, SLOT( desabilitar( int ) ) );
    connect( btnMudarCotribuicao, SIGNAL( clicked() ),                        btnMudarCotribuicao, SLOT( addContribuicao( ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarSaldo( QString ) ),        lblSaldo,            SLOT( setText( QString ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarContribuicao( QString ) ), lblContribuicao,     SLOT( setText( QString ) ) );
}

QWidget* uiMoradores::getUiMoradores(){
    QWidget *resul = new QWidget();

    resul->setLayout( lytGeral );
    return resul;
}



