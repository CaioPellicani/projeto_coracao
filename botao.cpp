#include "botao.h"

Botao::Botao()
{

}

void Botao::teste(){
    qDebug() << "teste";
}

void Botao::checkModificado(int sinal){

    if( sinal == marcado ){
        //qDebug() << "marcado";
        this->setEnabled( true );
    }
    else if( sinal == desmarcado ){
        //qDebug() << "marcado";
        this->setEnabled( false );
    }
}
