#include "frmcontribuicao.h"


frmContribuicao::frmContribuicao(logMorador* temp_morador, QWidget *parent) : QDialog(parent),ui(new Ui::frmContribuicao){
    ui->setupUi(this);
    this_morador = temp_morador;

    QObject::connect(ui->btnConfirmar, SIGNAL(accepted()), this, SLOT(aceitado()));
    QObject::connect(ui->btnConfirmar, SIGNAL(rejected()), this, SLOT(rejeitado()));

    this->carregarTabela();

}

frmContribuicao::~frmContribuicao(){
    delete ui;
}

void frmContribuicao::aceitado(){
    if( QMessageBox::question( this, this_morador->getNome(), "Tem Certeza?" ) == QMessageBox::Yes ){
        //DB Insert
        qDebug() << "Sim";
        float resul = 0;
        for( int i = 0; i < listaValores.length(); i++ ){
           resul +=  listaValores[i]->valor;
        }
        this_morador->addContribuicao( resul );
        //this_morador->addSaldo( resul );
        accept();
    } else{
        qDebug() << "Não";
    }
}

void frmContribuicao::rejeitado(){
    qDebug() << this_morador->getNro();
    reject();
}

void frmContribuicao::carregarTabela(){\
    ui->tblValores->clearContents();
    ui->tblValores->setRowCount( 0 );
    //while( true ) {
        //DADOS DB
        this->inserirValorTabela( "ValoresDB", "ValoresDB", "ValoresDB" );
    //}
}

void frmContribuicao::inserirValorLista( int tipo ){
    dados* novoValor = new dados;

    if( ui->dspValor->value() != 0 ){
        switch ( tipo ) {
        case INSERIR : novoValor->valor = ui->dspValor->value();
            break;
        case RETIRAR : novoValor->valor = -ui->dspValor->value();
            break;
        }

        novoValor->dataHora = QDateTime::currentDateTime();
        listaValores.push_back( novoValor );
        this->inserirValorTabela( QLocale().toCurrencyString( novoValor->valor ),
                                  novoValor->dataHora.toString( "dd/MM/yyyy" ),
                                  novoValor->dataHora.toString( "hh:mm:ss" ) );
        ui->dspValor->setValue( 0 );
    }
    else{
        QMessageBox::critical( this, "Erro", "Campo NÃO pode estar vazio !" );
        ui->dspValor->setFocus();
        delete novoValor;
    }

}

void frmContribuicao::inserirValorTabela( QString nome, QString data, QString hora ){
    int i = ui->tblValores->rowCount();
    ui->tblValores->insertRow( i );
    ui->tblValores->setItem( i, VALOR, new QTableWidgetItem( nome ) );
    ui->tblValores->setItem( i, DATA, new QTableWidgetItem( data ) );
    ui->tblValores->setItem( i, HORA, new QTableWidgetItem( hora ) );

}

void frmContribuicao::on_btnInserirValor_clicked(){
    inserirValorLista( INSERIR );
}

void frmContribuicao::on_btnRetirarValor_clicked(){
    inserirValorLista( RETIRAR );
}
