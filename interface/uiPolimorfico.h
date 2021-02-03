#ifndef UI_POLIMORFICO_H
#define UI_POLIMORFICO_H

#include <config.h>


class uiPolimorfico{

protected:
    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    
    QVector<void *> listaExterna;
    
    void begin();
    virtual void addUiCabecalho();
    void gerarUiCompleta();
    virtual void addUiIndividual( void *fonteDados );

public:
    uiPolimorfico( QVector<void *>  listaExterna );
    QWidget* getUi();

};

#endif