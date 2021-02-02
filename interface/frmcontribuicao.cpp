#include "frmcontribuicao.h"

frmContribuicao::frmContribuicao(logMorador* _morador, QWidget *parent) : QDialog(parent),ui(new Ui::frmContribuicao){
    ui->setupUi(this);
    this->morador = _morador;
    logica = logContribuicao( );

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
        QMessageBox::critical( this, "Erro", "Campo NÃO pode estar vazio !" );
        ui->dspValor->setFocus();
        delete novoValor;
    }
}

void frmContribuicao::inserirValorTabela( QString nome, QString data, QString hora, QString obs ){
    int i = ui->tblValores->rowCount();
    ui->tblValores->insertRow( i );
    ui->tblValores->setItem( i, VALOR, new QTableWidgetItem( nome ) );
    ui->tblValores->setItem( i, DATA, new QTableWidgetItem( data ) );
    ui->tblValores->setItem( i, HORA, new QTableWidgetItem( hora ) );
    ui->tblValores->setItem( i, OBS , new QTableWidgetItem( obs ) );
}

void frmContribuicao::inserirValorTabela( logContribuicao::dados* _dados ){
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
