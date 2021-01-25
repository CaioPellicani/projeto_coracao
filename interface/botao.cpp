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
    tela.setWindowTitle( this_morador->nome );
    tela.exec();
    emit atualizarSaldo( QLocale().toCurrencyString( this_morador->saldo ) );
    emit atualizarContribuicao( QLocale().toCurrencyString( this_morador->contribuicao ) );
    qDebug() << this_morador->nome <<"\nsaldo: " << this_morador->saldo << "\ncontribuicao: " << this_morador->contribuicao;
}
