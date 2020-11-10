#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moradores.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QVector<morador*> casa;

    for( int i = 0; i < 5; i++ ){
        casa.push_back( new morador );
        casa[i]->marcacao = marcado;
        casa[i]->nro = QString::number( 80 + i );
        casa[i]->nome = "Bixo" + QString::number( i + 1 );
        casa[i]->contribuicao = 700.00;
        casa[i]->saldo = -600.00 + casa[i]->contribuicao;
    }

    Moradores *teste = new Moradores();
    teste->gerarCasa( casa );

    ui->scrollArea->setWidget( teste->getMoradores() );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actAd_Morador_triggered(){
}

void MainWindow::on_actionFechar_triggered()
{
    qDebug() << "Programa Encerrado";
    QApplication::exit();
}

