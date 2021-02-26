#include "wgtMorador.h"

WgtMorador::WgtMorador(  QGridLayout *_lytGeral, Logica::Morador *_morador, QWidget *parent ){
    this->lytGeral = _lytGeral;
    this->morador = _morador;

    this->iniciarComponentes();
    this->conectar();
    this->setValores();
    this->addUiIndividual();
}

void WgtMorador::iniciarComponentes(){
    cbxContribuindo     = new QCheckBox( );  
    lblApelido          = new QLabel();
    lblSaldo            = new QLabel();
    lblContribuicao     = new QLabel();
    btnMudarCotribuicao = new QToolButton();

    cbxContribuindo->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );
    btnMudarCotribuicao->setText( "+" );
}

void WgtMorador::conectar(){
    connect( cbxContribuindo, SIGNAL( stateChanged( int ) ), this, SLOT( desabilitarBtn( int ) ) );
    connect( btnMudarCotribuicao, SIGNAL( clicked() )      , this, SLOT( on_btnMudarCotribuicao_clicked()  ) );
}

void WgtMorador::setValores(){
    cbxContribuindo->setCheckState( Qt::CheckState( morador->getMarcacao() ) );
    lblApelido->setText( morador->getID() + " - " + morador->getApelido() );   
    lblSaldo->setText( formatoDinheiro( morador->getSaldo() ) );
    lblContribuicao->setText( formatoDinheiro( morador->getContribuicao() ) );
    btnMudarCotribuicao->setEnabled( morador->getMarcacao() );
}

void WgtMorador::addUiIndividual(){
    int row = lytGeral->rowCount();

    if( row == 1 ){
        this->addUiCabecalho();
        row++;
    }

    lytGeral->addWidget( cbxContribuindo, row, CONTRIBUINDO );
    lytGeral->addWidget( lblApelido, row, NOME );
    lytGeral->addWidget( lblSaldo, row, SALDO );
    lytGeral->addWidget( lblContribuicao, row, CONTRIBUICAO );
    lytGeral->addWidget( btnMudarCotribuicao, row, MUDAR_CONTRIBUICAO );
}

void WgtMorador::addUiCabecalho(){
    int row = lytGeral->rowCount();
    lytGeral->addWidget( new QLabel( "Nome" ), row, NOME );
    lytGeral->addWidget( new QLabel( "Saldo" ), row, SALDO );
    lytGeral->addWidget( new QLabel( "Contribuição" ), row, CONTRIBUICAO );
}

void WgtMorador::atualizar(){
    this->setValores();
}

void WgtMorador::desabilitarBtn( int value ){
    morador->setMarcacao( value );
    btnMudarCotribuicao->setEnabled( value );
}

void WgtMorador::on_btnMudarCotribuicao_clicked(){

    frmContribuicao tela( morador );
    tela.setWindowTitle( morador->getNome() );
    tela.exec();

    this->setValores();
}