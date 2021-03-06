#ifndef LOG_CASA
#define LOG_CASA

#include <config.h>
#include "logMorador.h"
#include "logConta.h"

namespace Logica{
    
    class Casa{
    private:
        QVector<Morador*> listaMoradores;
        QVector<Conta*> listaContas;

        void getListaMoradoresDB();
        void getListaContasDB();

    public:
        Casa();
        
        QVector<Morador*> getListaMoradores();
        QVector<Conta*> getListaContas();

        Morador* novoMorador();
        bool insertNovoMorador( Morador *novoMorador );
        void inserir( Morador* novoMorador );

        float getContribuicaoTotal();

        void salvarEstadoAtual();

    };
}


#endif