#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moradores.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<morador*> casa;
    casa.push_back( new morador );
    casa[0]->marcacao = desmarcado;
    casa[0]->nro = "64";
    casa[0]->nome = "P´-Ga-T-Ta";
    casa[0]->saldo = 0.00;
    casa[0]->contribuicao = 700.00;

    casa.push_back( new morador );
    casa[1]->marcacao = marcado;
    casa[1]->nro = "65";
    casa[1]->nome = "Fófatóba";
    casa[1]->saldo = -780.00;
    casa[1]->contribuicao = 0.00;


    Moradores *teste = new Moradores();
    teste->gerarCasa( casa );

    ui->scrollArea->setWidget( teste->getMoradores() );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actAd_Morador_triggered()
{

    /*QMessageBox Mensagem;
    Mensagem.setWindowTitle( "Ola" );
    Mensagem.setInformativeText( "Testando" );
    Mensagem.setText( "Ola, estou treinando" );
    Mensagem.exec();*/

    //QMessageBox::information(this, "Ola", "Aprendendo");
    //QMessageBox::question(this,"Ola", "Aprendendo");
    QMessageBox msgBox;
    msgBox.setText(tr("Confirm?"));
    //msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
    msgBox.addButton(tr("Não"), QMessageBox::NoRole);
    msgBox.defaultButton();
    msgBox.setDefaultButton( msgBox.addButton(tr("Sim"), QMessageBox::YesRole) );

    int i = msgBox.exec();

    if( i == QMessageBox::Yes ){
        QMessageBox::information(this,"Ola", "Aprendendo");
    }
    else{
        QMessageBox::information(this,"Triste", tr("Sad"), QMessageBox::Yes);
    }

}

void MainWindow::on_actionFechar_triggered()
{
    qDebug() << "Programa Encerrado";
    QApplication::exit();
}

void MainWindow::on_pushButton_clicked()
{

}
