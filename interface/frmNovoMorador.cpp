#include "frmNovoMorador.h"
#include "ui_frmNovoMorador.h"

frmNovoMorador::frmNovoMorador( Logica::Casa * _casa, QWidget *parent ) : PoliDialog(parent), ui(new Ui::frmNovoMorador){
    ui->setupUi(this);
    this->casa = _casa;
    conectar( ui->btnConfirmar );
}

void frmNovoMorador::aceitado(){
    casa->addNovoMorador();
}

frmNovoMorador::~frmNovoMorador()
{
    delete ui;
}


