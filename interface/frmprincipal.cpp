#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include "moradores.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal)
{
    ui->setupUi(this);

    QVector<logMorador*> casa;

    for( int i = 0; i < 5; i++ ){ //camada DB
        casa.push_back( new logMorador() );
        casa[i]->marcacao = MARCADO;
        casa[i]->nro = QString::number( 80 + i );
        casa[i]->nome = "Bixo" + QString::number( i + 1 );
        casa[i]->contribuicao = 700.00;
        casa[i]->saldo = -600.00 + casa[i]->contribuicao;
    }//camada DB

    Moradores *uiListaMoradores = new Moradores();
    uiListaMoradores->gerarCasa( casa );

    ui->scrollArea->setWidget( uiListaMoradores->getMoradores() );
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

