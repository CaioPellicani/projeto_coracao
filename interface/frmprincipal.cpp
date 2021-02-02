#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include "uimoradores.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal)
{
    ui->setupUi(this);

    QVector<logMorador*> casa;

    for( int i = 0; i < 5; i++ ){
        casa.push_back( new logMorador() );
        casa[i]->setMarcacao( MARCADO );
        casa[i]->setNro( QString::number( 80 + i ) );
        casa[i]->setNome( "Bixo" + QString::number( i + 1 ) );
        casa[i]->addContribuicao( 700.00 );
        casa[i]->setCustoMes( 600.00 );
    }

    uiMoradores *uiListaMoradores = new uiMoradores( casa );
    ui->areaMoradores->setWidget( uiListaMoradores->getMoradores() );
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

