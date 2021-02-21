#ifndef UI_CONTAS
#define UI_CONTAS

#include <config.h>
#include "tplUiConstrutor.h"
#include <logConta.h>

class uiContas : public UiConstrutor<Logica::Conta>{

private:
    enum{ PAGANDO, NOME, VALOR };

    void addUiCabecalho();
    void gerarUiCompleta();
    void addUiIndividual( Logica::Conta * conta );
    
public:
    uiContas( QVector<Logica::Conta *> _listaExterna, QWidget *parent = nullptr );
};

#endif