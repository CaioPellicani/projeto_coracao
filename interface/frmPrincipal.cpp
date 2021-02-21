#include "frmPrincipal.h"
#include "ui_frmPrincipal.h"
#include "frmNovoMorador.h"
#include "wgtCasa.h"
#include "wgtMoradores.h"
#include "wgtContas.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    logica = Logica::Casa();
    WgtCasa casa = WgtCasa( this );

    casa.setListaMoradores( logica.getListaMoradores() );
    ui->areaMoradores->setWidget( casa.getLytMoradores() );

    casa.setListaContas( logica.getListaContas() );
    ui->areaContas->setWidget( casa.getLytContas() );
}

frmPrincipal::~frmPrincipal(){
    logica.salvarEstadoAtual();
    delete ui;
}


void frmPrincipal::on_btnAddMorador_clicked(){
    frmNovoMorador tela( &this->logica, this );
    tela.setWindowTitle( "Novo Morador" );
    tela.exec();
    qDebug() << logica.getListaMoradores().last()->getNome();
}
