#include "frmNovoMorador.h"
#include "ui_frmNovoMorador.h"

frmNovoMorador::frmNovoMorador( Logica::Casa * _casa, QWidget *parent ) : PoliDialog(parent), ui(new Ui::frmNovoMorador){
    ui->setupUi(this);
    this->casa = _casa;
    conectar( ui->btnConfirmar );
}

void frmNovoMorador::aceitado(){
    Logica::Morador *morador = new Logica::Morador();
    morador->setMarcacao( MARCADO );
    morador->setNro( QString::number( 100 ) );
    morador->setNome( "Bixo Novo" );
    morador->addContribuicao( 0.00 );
    morador->setCustoMes( 600.00 );

    this->casa->addNovoMorador( morador );

}

frmNovoMorador::~frmNovoMorador()
{
    delete ui;
}


