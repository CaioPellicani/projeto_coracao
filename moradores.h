#ifndef MORADORES_H
#define MORADORES_H
#include "config.h"
#include "botao.h"

class Moradores : public QObject
{
    //Q_OBJECT
public:
    //Moradores( QObject *parent = nullptr );
    QVector<QHBoxLayout*> moradores;
    QWidget *resul = new QWidget();
    QVBoxLayout *vertical = new QVBoxLayout();

    Moradores();
    void gerarCasa( QVector<morador*> casa );
    void addUiMorador( morador* morador );
    QWidget* getMoradores();

private slots:
    void slot( );
};

#endif // MORADORES_H
