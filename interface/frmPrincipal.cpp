#include "frmPrincipal.h"
#include "ui_frmPrincipal.h"
#include "frmNovoMorador.h"
#include "uiMoradores.h"
#include "uiContas.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    //this->on_btnAddMorador_clicked(); //teste

    Logica::Casa casa = Logica::Casa();

    uiMoradores *uiListaMoradores = new uiMoradores( casa.getListaMoradores() );
    ui->areaMoradores->setWidget( uiListaMoradores->getUi() );

    uiContas *uiListaContas = new uiContas( casa.getListaContas() );
    //uiContas *uiListaContas = new uiContas(  );
    ui->areaContas->setWidget( uiListaContas->getUi() );
}

frmPrincipal::~frmPrincipal(){
    delete ui;
}


void frmPrincipal::on_btnAddMorador_clicked(){
    frmNovoMorador tela( this );
    tela.setWindowTitle( "Novo Morador" );
    tela.exec();
}
