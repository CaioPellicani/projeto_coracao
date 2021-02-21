#ifndef UI_MORADORES_H
#define UI_MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "wgtBotao.h"

class WgtMoradores : public QObject{
    Q_OBJECT
protected:
    enum{ CONTRIBUINDO, NOME, SALDO, CONTRIBUICAO, MUDAR_CONTRIBUICAO };
    QGridLayout *lytGeral;

    void addUiCabecalho();
    void addUiIndividual( Logica::Morador* morador );

public:
    explicit WgtMoradores(  QGridLayout *_lytGeral, Logica::Morador *morador, QWidget *parent = nullptr );

};

#endif // MORADORES_H
