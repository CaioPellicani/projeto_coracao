#include "tela_contribuicao.h"
#include "ui_tela_contribuicao.h"
#include <QException>

void tela_contribuicao::carregarLista(){
    ui->lstValores->clear();
    for( int i = 0; i < listaValores.length(); i ++ ){
        ui->lstValores->addItem( QLocale().toCurrencyString( listaValores[i]->valor ) + " - " +
                                 listaValores[i]->dataHora.toString( "dd/MM/yyyy - hh:mm:ss" )
        );
    }
}

tela_contribuicao::tela_contribuicao(QWidget *parent) : QDialog(parent), ui(new Ui::tela_contribuicao){
    ui->setupUi(this);
    QObject::connect(ui->btnConfirmar, SIGNAL(accepted()), this, SLOT(aceitado()));
    QObject::connect(ui->btnConfirmar, SIGNAL(rejected()), this, SLOT(on_buttonBox_rejected()));
}

void tela_contribuicao::setMorador(morador *temp_morador)
{
    this_morador = temp_morador;
}

tela_contribuicao::~tela_contribuicao(){
    delete ui;
}

void tela_contribuicao::aceitado()
{
    if( QMessageBox::question( this, this_morador->nome, "Tem Certeza?" ) == QMessageBox::Yes ){
        //DB Insert
        qDebug() << "Sim";
        accept();
    }
    qDebug() << "Não";
}

void tela_contribuicao::on_buttonBox_rejected(){
   qDebug() << this_morador->nro;
   reject();
}


void tela_contribuicao::on_btnAddValor_clicked(){
    QValidator *validator = new QDoubleValidator;
    ui->txtValor->setValidator( validator );
    valor* novoValor = new valor;

    if( ui->txtValor->text() != "" ){
        novoValor->valor = ui->txtValor->text().toFloat();
        novoValor->dataHora = QDateTime::currentDateTime();
        if( novoValor->valor != 0 ){
            listaValores.push_back( novoValor );
            this->carregarLista();
        }
        else{
            QMessageBox::critical( this, "Erro", "Inserir Valor Numérico !" );
            ui->txtValor->setFocus();
            delete novoValor;
        }
    }

    else{
        QMessageBox::critical( this, "Erro", "Campo NÃO pode estar vazio !" );
        ui->txtValor->setFocus();
        delete novoValor;
    }
}


