#ifndef MORADORES_H
#define MORADORES_H
#include "config.h"
#include "botao.h"

class Moradores : public QObject{

private:
    QSpacerItem *espaco( int largura );


public:
    QVector<QHBoxLayout*> moradores;
    QWidget *resul = new QWidget();
    QVBoxLayout *vertical = new QVBoxLayout();

    Moradores();
    void gerarCasa( QVector<morador*> casa );
    void addUiMorador( morador* morador );
    QWidget* getMoradores();

private Q_SLOTS:
};

#endif // MORADORES_H
