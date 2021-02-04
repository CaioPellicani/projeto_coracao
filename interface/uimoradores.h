#ifndef UI_MORADORES_H
#define UI_MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "botao.h"

class uiMoradores : public QObject{

protected:
    QGridLayout *lytGeral = new QGridLayout();
    
    int rowLytGeral;
    enum{ CONTRIBUINDO, NOME, SALDO, MUDAR_CONTRIBUICAO, CONTRIBUICAO };

    void addUiCabecalho();
    void gerarUiCompleta( QVector<Logica::Morador*> casa );
    void addUiIndividual( Logica::Morador* morador );

public:
    uiMoradores( QVector<Logica::Morador*> casa );
    QWidget* getUiMoradores();

};

#endif // MORADORES_H
