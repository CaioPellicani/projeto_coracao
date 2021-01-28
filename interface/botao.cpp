#include "botao.h"

Botao::Botao( QString texto, logMorador* temp_morador ){
    this->setText( texto );
    this_morador = temp_morador;
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
    frmContribuicao tela( this_morador, this );
    tela.setWindowTitle( this_morador->getNome() );
    tela.exec();

    emit atualizarSaldo( this_morador->getSaldoString() );
    emit atualizarContribuicao( this_morador->getContribuicaoString() );
    
    qDebug() << this_morador->getNome() <<"\nsaldo: " << this_morador->getSaldoString() << "\ncontribuicao: " << this_morador->getContribuicaoString();
}
