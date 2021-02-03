#include "logCasa.h"

using namespace Logica;

Casa::Casa(){
    this->getListaMoradoresDB();

}

void Casa::getListaMoradoresDB(){
    for( int i = 0; i < 5; i++ ){
        listaMoradores.push_back( new Morador() );
        listaMoradores[i]->setMarcacao( MARCADO );
        listaMoradores[i]->setNro( QString::number( 80 + i ) );
        listaMoradores[i]->setNome( "Bixo" + QString::number( i + 1 ) );
        listaMoradores[i]->addContribuicao( 700.00 );
        listaMoradores[i]->setCustoMes( 600.00 );
    }
}

void Casa::getListaContasDB(){
    for( int i = 0; i < 5; i++ ){
        listaContas.push_back( new Conta() );
        listaContas[i]->setMarcacao( MARCADO );
        listaContas[i]->setNome( "Conta" + QString::number( i + 1 ) );
        listaContas[i]->setValor( 100.00 );
        listaContas[i]->setCustoFixo( true );
    }
}