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
