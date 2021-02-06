#ifndef POLI_UI_CONSTRUTOR_H
#define POLI_UI_CONSTRUTOR_H

#include <config.h>
#include <poliUnidade.h>
template <typename T>
class UiConstrutor{

protected:
    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    
    QVector<T*> listaExterna;

    //TODO: Implementar metodo addUiCabecalho() addUiIndividual gerarUiCompleta()
    

public:
    UiConstrutor( QVector<T *> _listaExterna );
    QWidget* getUi();
};

template<typename T>
UiConstrutor<T>::UiConstrutor( QVector<T *> _listaExterna ){
    this->listaExterna = _listaExterna;    
    this->lytGeral->setMargin( 30 );
};

template<typename T>
QWidget* UiConstrutor<T>::getUi(){
    QWidget *resul = new QWidget();

    resul->setLayout( lytGeral );
    return resul;
}

#endif