#include "botao.h"
#include "tela_contribuicao.h"

Botao::Botao( morador* temp_morador ){
    this_morador = temp_morador;
}

void Botao::desabilitar(int sinal){

    if( sinal == marcado ){
        this->setEnabled( true );
    }
    else if( sinal == desmarcado ){
        this->setEnabled( false );
    }
}

void Botao::addContribuicao( ){
    tela_contribuicao tela( this );
    tela.setMorador( this_morador );
    tela.setWindowTitle( this_morador->nome );
    tela.exec();
}
