#include "frmcontribuicao.h"

frmContribuicao::frmContribuicao( Logica::logMorador* _morador, QWidget *parent) : QDialog(parent),ui(new Ui::frmContribuicao){
    ui->setupUi(this);
    this->morador = _morador;
    logica = Logica::logContribuicao( );

    this->conectar();
    this->carregarTabela();
}

void frmContribuicao::conectar(){
    QObject::connect(ui->btnConfirmar, SIGNAL(accepted()), this, SLOT(aceitado()));
    QObject::connect(ui->btnConfirmar, SIGNAL(rejected()), this, SLOT(rejeitado()));
}

void frmContribuicao::carregarTabela(){
    ui->tblValores->clearContents();
    ui->tblValores->setRowCount( 0 );

    for( int i = 0; i < logica.getLenghtDB(); i++ ){
        this->inserirValorTabela( logica.getDadosDB( i ) ); 
    }
}   

void frmContribuicao::inserirValorLista(){
    dados* novoValor = new dados;

    if( logica.addDados(ui->dspValor->value(), ui->txtObs->text() ) ){
        this->inserirValorTabela( logica.getDadosTail() );
        ui->dspValor->setValue( 0 );
    }
    else{
        QMessageBox::critical( this, "Erro", "Campo Valor NÃO pode ser ZERO !" );
        ui->dspValor->setFocus();
        delete novoValor;
    }
}

void frmContribuicao::inserirValorTabela( Logica::logContribuicao::dados* _dados ){
    int i = ui->tblValores->rowCount();
    ui->tblValores->insertRow( i );
    ui->tblValores->setItem( i, VALOR, new QTableWidgetItem( formatoDinheiro( _dados->valor ) ) );
    ui->tblValores->setItem( i, DATA, new QTableWidgetItem( _dados->dataHora.toString( "dd/MM/yyyy" ) ) );
    ui->tblValores->setItem( i, HORA, new QTableWidgetItem( _dados->dataHora.toString( "hh:mm:ss" ) ) );
    ui->tblValores->setItem( i, OBS , new QTableWidgetItem( _dados->obs ) );
}

void frmContribuicao::on_btnInserirValor_clicked(){
    inserirValorLista();
}

void frmContribuicao::aceitado(){
    if( QMessageBox::question( this, morador->getNome(), "Tem Certeza?" ) == QMessageBox::Yes ){
        morador->addContribuicao( logica.getTotalInserido() );
        accept();
    } 
}

void frmContribuicao::rejeitado(){
    qDebug() << morador->getNro();
    reject();
}

frmContribuicao::~frmContribuicao(){
    delete ui;
}
