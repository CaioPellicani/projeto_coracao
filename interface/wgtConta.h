#ifndef UI_CONTAS
#define UI_CONTAS

#include <config.h>
#include <logConta.h>

class WgtConta : public QObject{
    Q_OBJECT
private:
    enum{ PAGANDO, NOME, VALOR };       
    QGridLayout *lytGeral;

    void addUiCabecalho();
    void addUiIndividual( Logica::Conta * conta );

public slots:


public:
    WgtConta( QGridLayout *_lytGeral, Logica::Conta *conta, QWidget *parent = nullptr );
};

#endif