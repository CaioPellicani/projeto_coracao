#include "frmNovoMorador.h"
#include "ui_frmNovoMorador.h"

frmNovoMorador::frmNovoMorador( Logica::Casa * _logica,  WgtCasa * _casa, QWidget *parent ) : PoliDialog(parent), ui(new Ui::frmNovoMorador){
    ui->setupUi(this);
    this->logica = _logica;
    this->casa = _casa;
    conectar( ui->btnConfirmar );
}

void frmNovoMorador::aceitado(){
    Logica::Morador morador = Logica::Morador();
    morador.setMarcacao( MARCADO );
    morador.setID( ui->edtID->text() );
    morador.setApelido( ui->edtApelido->text() );
    morador.addContribuicao( 0.00 );
    morador.setCustoMes( 600.00 );

    if( this->logica->addNovoMorador( &morador ) ){
        WgtMoradores( casa->getLytMoradores(), &morador );
    }
}

frmNovoMorador::~frmNovoMorador()
{
    delete ui;
}


