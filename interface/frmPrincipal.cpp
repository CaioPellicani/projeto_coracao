#include "frmPrincipal.h"
#include "ui_frmPrincipal.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    logica = Logica::Casa();
    casa = new WgtCasa( &logica,  this );

    casa->gerarMoradores();
    ui->areaMoradores->setWidget( casa->getWgtMoradores() );

    casa->gerarContas();
    ui->areaContas->setWidget( casa->getWgtContas() );

    qDebug() << "Contribuição Total" << logica.getContribuicaoTotal();
}

frmPrincipal::~frmPrincipal(){
    logica.salvarEstadoAtual();
    delete ui;
}

void frmPrincipal::on_btnAddMorador_clicked(){
    frmNovoMorador tela( &this->logica, this->casa, this );
    tela.setWindowTitle( "Novo Morador" );
    tela.exec();
    qDebug() << "Contribuição Total" << logica.getContribuicaoTotal();
}
