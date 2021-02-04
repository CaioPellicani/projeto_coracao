#ifndef POLI_UI_CONSTRUTOR_H
#define POLI_UI_CONSTRUTOR_H

#include <config.h>
#include <poliUnidade.h>

template <typename T>
class UiConstrutor{

protected:
    /*QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    
    QVector<T> listaExterna;

    virtual void addUiCabecalho();
    void gerarUiCompleta();
    virtual void addUiIndividual( T * unidade );*/
    
public:
    //UiConstrutor( QVector<T *> _listaExterna ){}
    UiConstrutor( QVector<T *> _listaExterna ){ qDebug() << "essa merda também"; };
    //QWidget* getUi();
};
 
#endif