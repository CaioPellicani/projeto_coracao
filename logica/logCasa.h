#ifndef LOG_CASA
#define LOG_CASA

#include <config.h>
#include "logMorador.h"
#include "logConta.h"

namespace Logica{
    class logCasa{
    private:
        QVector<logMorador*> listaMoradores;
        QVector<Conta*> listaContas;

        void getListaMoradoresDB();
        void getListaContasDB();

    public:
        logCasa();
        
        QVector<logMorador*> getListaMoradores(){ return listaMoradores; }
        QVector<Conta*> getListaContas(){ return listaContas; }

    };
}


#endif