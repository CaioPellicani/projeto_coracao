#include "frmContribuicao.h"
#include "ui_frmContribuicao.h"

frmContribuicao::frmContribuicao( Logica::Morador* _morador, QWidget *parent) : PoliDialog(parent),ui(new Ui::frmContribuicao){
    ui->setupUi(this);
    this->morador = _morador;
    logica = Logica::Contribuicao( );

    conectar( ui->btnConfirmar );

    this->carregarTabela();
}

void frmContribuicao::aceitado(){
    morador->addContribuicao( logica.getTotalInserido() );
}

void frmContribuicao::carregarTabela(){
    ui->tblValores->clearContents();
    ui->tblValores->setRowCount( 0 );

    for( int i = 0; i < logica.getLenghtDB(); i++ ){
        this->inserirValorTabela( logica.getDadosDB( i ) ); 
    }
}   

void frmContribuicao::inserirValorLista(){

    if( logica.addDados(ui->dspValor->value(), ui->txtObs->text() ) ){
        this->inserirValorTabela( logica.getDadosTail() );
        ui->dspValor->setValue( 0 );
        ui->btnConfirmar->button(QDialogButtonBox::Ok)->setFocus();
    }
    else{
        QMessageBox::critical( this, "Erro", "Campo Valor NÃO pode ser ZERO !" );
        ui->dspValor->setFocus();
    }
}

void frmContribuicao::inserirValorTabela( Logica::Contribuicao::dados* _dados ){
    int i = ui->tblValores->rowCount();
    ui->tblValores->insertRow( i );
    ui->tblValores->setItem( i, VALOR, new QTableWidgetItem( formatoDinheiro( _dados->valor ) ) );
    ui->tblValores->setItem( i, DATA, new QTableWidgetItem( formatoData( _dados->dataHora ) ) );
    ui->tblValores->setItem( i, HORA, new QTableWidgetItem( formatoHora( _dados->dataHora ) ) );
    ui->tblValores->setItem( i, OBS , new QTableWidgetItem( _dados->obs ) );
}

void frmContribuicao::on_btnInserirValor_clicked(){
    inserirValorLista();
}

frmContribuicao::~frmContribuicao(){
    delete ui;
}
