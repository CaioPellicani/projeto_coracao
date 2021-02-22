#include "frmNovoMorador.h"
#include "ui_frmNovoMorador.h"

frmNovoMorador::frmNovoMorador( Logica::Casa * _logica,  WgtCasa * _casa, QWidget *parent ) : PoliDialog(parent), ui(new Ui::frmNovoMorador){
    ui->setupUi(this);
    this->logica = _logica;
    this->casa = _casa;
    conectar( ui->btnConfirmar );
}

void frmNovoMorador::aceitado(){

    Logica::Morador* novoMorador = this->logica->novoMorador();

    if( novoMorador != nullptr ){
        novoMorador->setMarcacao( MARCADO );
        novoMorador->setID( ui->edtID->text() );
        novoMorador->setApelido( ui->edtApelido->text() );
        novoMorador->addContribuicao( 5.00 );
        novoMorador->setCustoMes( 600.00 );

        WgtMorador( casa->getLytMoradores(), novoMorador );
    }
}

frmNovoMorador::~frmNovoMorador()
{
    delete ui;
}


