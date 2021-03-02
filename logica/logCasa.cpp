#include "logCasa.h"

using namespace Logica;

Casa::Casa(){
    this->getListaMoradoresDB();
    this->getListaContasDB();
}

QVector<Morador*> Casa::getListaMoradores(){ 
    return listaMoradores; 
}

QVector<Conta*> Casa::getListaContas(){ 
    return listaContas; 
}

void Casa::Casa::getListaMoradoresDB(){
    for( int i = 0; i < 5; i++ ){
        listaMoradores.push_back( new Morador() );
        listaMoradores[i]->setMarcacao( MARCADO );
        listaMoradores[i]->setID( 80 + i );
        listaMoradores[i]->setApelido( "Bixo" + QString::number( i + 1 ) );
        listaMoradores[i]->addContribuicao( 700.00 );
        listaMoradores[i]->setCustoMes( 600.00 );
    }
    qDebug() << "Moradores Extraidos do DB";
}

void Casa::getListaContasDB(){
    for( int i = 0; i < 5; i++ ){
        listaContas.push_back( new Conta() );
        listaContas[i]->setMarcacao( DESMARCADO );
        listaContas[i]->setNome( "Conta" + QString::number( i + 1 ) );
        listaContas[i]->setValor( 100.00 );
        listaContas[i]->setCustoFixo( true );
    }
    qDebug() << "Contas Extraidos do DB";
}

float Casa::getContribuicaoTotal(){
    
    float result = 0;
    for( int i = 0; i < this->listaMoradores.length(); i++ ){
        result += this->listaMoradores[i]->getContribuicao();
    }
    return result;
}

Morador* Casa::novoMorador(){ 
    Morador* novoMorador = new Morador();
    listaMoradores.push_back( novoMorador );

    return novoMorador;
}

void Casa::inserir( Morador* novoMorador ){ 
    int pos = 0;

    for( int i = 0; i < listaMoradores.size(); i++ ){
        if( listaMoradores[pos]->getID() < novoMorador->getID() ){
            pos++;
        }
    }
    listaMoradores.insert( pos, novoMorador );
    
    this->insertNovoMorador( novoMorador );
}

bool Casa::insertNovoMorador( Morador *novoMorador ){
    qDebug() << "insert de " << novoMorador->getApelido() << " no DB";
    return true;
}

void Casa::salvarEstadoAtual(){ 
    qDebug() << "salvarEstadoAtual"; 
}