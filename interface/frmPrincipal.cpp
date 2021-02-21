#include "frmPrincipal.h"
#include "ui_frmPrincipal.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    logica = Logica::Casa();
    casa = WgtCasa( this );

    casa.setListaMoradores( logica.getListaMoradores() );
    ui->areaMoradores->setWidget( casa.getWgtMoradores() );

    casa.setListaContas( logica.getListaContas() );
    ui->areaContas->setWidget( casa.getWgtContas() );
}

frmPrincipal::~frmPrincipal(){
    logica.salvarEstadoAtual();
    delete ui;
}


void frmPrincipal::on_btnAddMorador_clicked(){
    frmNovoMorador tela( &this->logica, &this->casa, this );
    tela.setWindowTitle( "Novo Morador" );
    tela.exec();
}
