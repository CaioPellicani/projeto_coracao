#include "logCasa.h"

logCasa::logCasa(){
    this->getListaMoradoresDB();

}

void logCasa::getListaMoradoresDB(){
    for( int i = 0; i < 5; i++ ){
        listaMoradores.push_back( new logMorador() );
        listaMoradores[i]->setMarcacao( MARCADO );
        listaMoradores[i]->setNro( QString::number( 80 + i ) );
        listaMoradores[i]->setNome( "Bixo" + QString::number( i + 1 ) );
        listaMoradores[i]->addContribuicao( 700.00 );
        listaMoradores[i]->setCustoMes( 600.00 );
    }
}

void logCasa::getListaContasDB(){

}