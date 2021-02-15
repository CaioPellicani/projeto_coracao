#include "frmPrincipal.h"
#include "ui_frmPrincipal.h"
#include "frmNovoMorador.h"
#include "wgtMoradores.h"
#include "wgtContas.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    casa = Logica::Casa();

    uiMoradores *uiListaMoradores = new uiMoradores( casa.getListaMoradores(), this );
    ui->areaMoradores->setWidget( uiListaMoradores->getUi() );

    uiContas *uiListaContas = new uiContas( casa.getListaContas() );
    ui->areaContas->setWidget( uiListaContas->getUi() );
}

frmPrincipal::~frmPrincipal(){
    casa.salvarEstadoAtual();
    delete ui;
}


void frmPrincipal::on_btnAddMorador_clicked(){
    frmNovoMorador tela( &this->casa, this );
    tela.setWindowTitle( "Novo Morador" );
    tela.exec();
}
