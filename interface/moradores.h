#ifndef MORADORES_H
#define MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "botao.h"

class Moradores : public QObject{

private:
    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    enum{ CONTRIBUINDO, NOME, SALDO, MUDAR_CONTRIBUICAO, CONTRIBUICAO };
    
    void gerarCasa( QVector<logMorador*> casa );
    void addUiMorador( logMorador* morador );

public:
    Moradores( QVector<logMorador*> casa );
    QWidget* getMoradores();

private Q_SLOTS:
};

#endif // MORADORES_H
