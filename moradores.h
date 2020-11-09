#ifndef MORADORES_H
#define MORADORES_H
#include "config.h"
#include "botao.h"

class Moradores : public QObject
{
public:
    QVector<QHBoxLayout*> moradores;
    QWidget *resul = new QWidget();
    QVBoxLayout *vertical = new QVBoxLayout();

    Moradores();
    void gerarCasa( QVector<morador*> casa );
    void addUiMorador( morador* morador );
    QWidget* getMoradores();

private slots:

};

#endif // MORADORES_H
