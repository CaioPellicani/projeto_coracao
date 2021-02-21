#ifndef UI_CONTAS
#define UI_CONTAS

#include <config.h>
#include <logConta.h>

class WgtContas{

private:
    enum{ PAGANDO, NOME, VALOR };       
    QGridLayout *lytGeral;

    void addUiCabecalho();
    void addUiIndividual( Logica::Conta * conta );
    
public:
    WgtContas( QGridLayout *_lytGeral, Logica::Conta *conta, QWidget *parent = nullptr );
};

#endif