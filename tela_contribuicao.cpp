#include "tela_contribuicao.h"
#include "ui_tela_contribuicao.h"

tela_contribuicao::tela_contribuicao(QWidget *parent ) : QDialog(parent), ui(new Ui::tela_contribuicao){
    ui->setupUi(this);
}

void tela_contribuicao::setMorador(morador *temp_morador)
{
    this_morador = temp_morador;
}

tela_contribuicao::~tela_contribuicao(){
    delete ui;
}

void tela_contribuicao::on_buttonBox_accepted(){
   qDebug() << this_morador->nome;
   QMessageBox::warning( this, this_morador->nome, "Tem Certeza?" );
}


void tela_contribuicao::on_buttonBox_rejected(){
   qDebug() << this_morador->nro;
}
