#ifndef LOG_CASA
#define LOG_CASA

#include <config.h>
#include "logMorador.h"
#include "logConta.h"

class logCasa{
private:
    QVector<logMorador*> listaMoradores;
    QVector<logConta*> listaContas;

    void getListaMoradoresDB();
    void getListaContasDB();

public: 
    logCasa();
    
    QVector<logMorador*> getListaMoradores(){ return listaMoradores; }
    QVector<logConta*> getListaContas(){ return listaContas; }

};


#endif