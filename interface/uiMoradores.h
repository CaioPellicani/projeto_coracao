#ifndef UI_MORADORES_H
#define UI_MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "tplUiConstrutor.h"
#include "uiBotao.h"

class uiMoradores : public QObject, public UiConstrutor<Logica::Morador>{

protected:
    //QGridLayout *lytGeral = new QGridLayout(); 
    //int rowLytGeral;
    enum{ CONTRIBUINDO, NOME, SALDO, CONTRIBUICAO, MUDAR_CONTRIBUICAO };

    void addUiCabecalho();
    void gerarUiCompleta();
    void addUiIndividual( Logica::Morador* morador );

public:
    uiMoradores( QVector<Logica::Morador*> _listaExterna );
    //QWidget* getUiMoradores();

};

#endif // MORADORES_H
