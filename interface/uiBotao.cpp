#include "uiBotao.h"

Botao::Botao( QString texto, Logica::Morador* _morador ){
    this->setText( texto );
    morador = _morador;
}

void Botao::desabilitar(int sinal){

    if( sinal == MARCADO ){
        this->setEnabled( true );
    }
    else if( sinal == DESMARCADO ){
        this->setEnabled( false );
    }
}

void Botao::addContribuicao( ){
    frmContribuicao tela( morador, this );
    tela.setWindowTitle( morador->getNome() );
    tela.exec();

    emit atualizarSaldo( formatoDinheiro( morador->getSaldo() ) );
    emit atualizarContribuicao( formatoDinheiro( morador->getContribuicao() ) );
    
    qDebug() << morador->getNome()  
             << "\nsaldo: " << formatoDinheiro( morador->getSaldo() ) 
             << "\ncontribuicao: "  << formatoDinheiro( morador->getContribuicao() );
}
