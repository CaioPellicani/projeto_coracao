#ifndef UI_CONTAS
#define UI_CONTAS

#include <config.h>
#include <logConta.h>

class uiContas{

private:
    enum{ PAGANDO, NOME, VALOR };

    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    
    QVector<Logica::Conta *> listaExterna;

    void addUiCabecalho();
    void gerarUiCompleta();
    void addUiIndividual( Logica::Conta * fonteDados );
    
public:
    uiContas( QVector<Logica::Conta *> _listaExterna );
    QWidget* getUi();


};

#endif