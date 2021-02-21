#include "wgtMoradores.h"

WgtMoradores::WgtMoradores(  QGridLayout *_lytGeral, Logica::Morador *morador, QWidget *parent ){
    this->lytGeral = _lytGeral;

    this->addUiIndividual( morador );
}

void WgtMoradores::addUiCabecalho(){
    int row = lytGeral->rowCount();
    lytGeral->addWidget( new QLabel( "Nome" ), row, NOME );
    lytGeral->addWidget( new QLabel( "Saldo" ), row, SALDO );
    lytGeral->addWidget( new QLabel( "Contribuição" ), row, CONTRIBUICAO );
}

void WgtMoradores::addUiIndividual( Logica::Morador* morador ){
    int row = lytGeral->rowCount();

    if( row == 1 ){
        this->addUiCabecalho();
        row++;
    }

    QCheckBox* cbxContribuindo = new QCheckBox( );
    cbxContribuindo->setCheckState( Qt::CheckState( morador->getMarcacao() ) );
    cbxContribuindo->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    lytGeral->addWidget( cbxContribuindo, row, CONTRIBUINDO );

    QLabel* lblNome = new QLabel();
    lblNome->setText( morador->getID() + " - " + morador->getNome() );
    lytGeral->addWidget( lblNome, row, NOME );
    
    QLabel* lblSaldo = new QLabel();
    lblSaldo->setText( formatoDinheiro( morador->getSaldo() ) );
    lytGeral->addWidget( lblSaldo, row, SALDO );

    QLabel* lblContribuicao = new QLabel();
    lblContribuicao->setText( formatoDinheiro( morador->getContribuicao() ) );
    lytGeral->addWidget( lblContribuicao, row, CONTRIBUICAO );

    Botao *btnMudarCotribuicao = new Botao( "+", morador );
    btnMudarCotribuicao->setEnabled( morador->getMarcacao() );
    lytGeral->addWidget(btnMudarCotribuicao, row, MUDAR_CONTRIBUICAO);

    connect( cbxContribuindo,     SIGNAL( stateChanged(int) ),                btnMudarCotribuicao, SLOT( desabilitar( int ) ) );
    connect( btnMudarCotribuicao, SIGNAL( clicked() ),                        btnMudarCotribuicao, SLOT( addContribuicao( ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarSaldo( QString ) ),        lblSaldo,            SLOT( setText( QString ) ) );
    connect( btnMudarCotribuicao, SIGNAL( atualizarContribuicao( QString ) ), lblContribuicao,     SLOT( setText( QString ) ) );
}
