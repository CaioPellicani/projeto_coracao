#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include "moradores.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal)
{
    ui->setupUi(this);

    QVector<logMorador*> casa;

    for( int i = 0; i < 5; i++ ){ //camada DB
        casa.push_back( new logMorador() );
        casa[i]->setMarcacao( MARCADO );
        casa[i]->setNro( QString::number( 80 + i ) );
        casa[i]->setNome( "Bixo" + QString::number( i + 1 ) );
        casa[i]->setContribuicao( 700.00 );
        casa[i]->setSaldo( casa[i]->getSaldo() -600.00 + casa[i]->getContribuicao() );
    }//camada DB

    Moradores *uiListaMoradores = new Moradores();
    uiListaMoradores->gerarCasa( casa );

    ui->scrollArea->setWidget( uiListaMoradores->getMoradores() );
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

