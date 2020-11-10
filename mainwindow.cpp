#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moradores.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QVector<morador*> casa;

    for( int i = 0; i < 5; i++ ){
        casa.push_back( new morador );
        casa[i]->marcacao = MARCADO;
        casa[i]->nro = QString::number( 80 + i );
        casa[i]->nome = "Bixo" + QString::number( i + 1 );
        casa[i]->contribuicao = 700.00;
        casa[i]->saldo = -600.00 + casa[i]->contribuicao;
    }

    Moradores *uiListaMoradores = new Moradores();
    uiListaMoradores->gerarCasa( casa );

    ui->scrollArea->setWidget( uiListaMoradores->getMoradores() );
}

MainWindow::~MainWindow()
{
    delete ui;
}

