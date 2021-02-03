#ifndef MORADORES_H
#define MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "botao.h"

class uiMoradores : public QObject{

private:
    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    enum{ CONTRIBUINDO, NOME, SALDO, MUDAR_CONTRIBUICAO, CONTRIBUICAO };
    
    void gerarCasa( QVector<Logica::logMorador*> casa );
    void addUiMorador( Logica::logMorador* morador );

public:
    uiMoradores( QVector<Logica::logMorador*> casa );
    QWidget* getMoradores();

private Q_SLOTS:
};

#endif // MORADORES_H
