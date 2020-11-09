#include "tela_contribuicao.h"
#include "ui_tela_contribuicao.h"

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

