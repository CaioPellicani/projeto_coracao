#ifndef POLI_UI_CONSTRUTOR_H
#define POLI_UI_CONSTRUTOR_H

#include <config.h>
#include <poliUnidade.h>

template <typename T>
class UiConstrutor{

protected:
    QGridLayout *lytGeral = new QGridLayout();
    int rowLytGeral;
    
    QVector<T> listaExterna;

    //TODO: Implementar cabeçalho e os controles de cada UI
    void addUiCabecalho();
    void addUiIndividual( T * unidade );
     //TODO: Implementar cabeçalho e os controles de cada UI   

    void gerarUiCompleta(){
        for( int i = 0; i < this->listaExterna.length(); i++ ) {
            this->addUiIndividual( this->listaExterna[i] );
        }
    }


public:
    UiConstrutor( QVector<T *> _listaExterna ){ 
        qDebug() << "essa merda também"; 
    };

    QWidget* getUi(){
        QWidget *resul = new QWidget();

        resul->setLayout( lytGeral );
        return resul;
    }
};

#endif