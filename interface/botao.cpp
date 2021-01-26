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
    frmContribuicao tela( this );
    tela.setMorador( this_morador );
    tela.setWindowTitle( this_morador->getNome() );
    tela.exec();
    emit atualizarSaldo( QLocale().toCurrencyString( this_morador->getSaldo() ) );
    emit atualizarContribuicao( QLocale().toCurrencyString( this_morador->getContribuicao() ) );
    qDebug() << this_morador->getNome() <<"\nsaldo: " << this_morador->getSaldo() << "\ncontribuicao: " << this_morador->getContribuicao();
}
