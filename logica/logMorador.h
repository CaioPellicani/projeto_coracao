#ifndef LOG_MORADOR_H
#define LOG_MORADOR_H

#include <config.h>
#include "poliUnidade.h"

namespace Logica{

    class Morador : public Unidade{

    private:
        int ID;
        QString apelido;
        float contribuicao = 0;
        float custoMes = 0;
        float saldoMesAnterior = 0;

    public:
        QString getApelido();
        void setApelido( QString value );

        int getID();
        void setID( int value );

        float getContribuicao();
        void addContribuicao( float value );

        float getCustoMes();
        void setCustoMes( float value );

        float getSaldo();

        bool validarEmail( QString email );    
    
    };  
}

#endif // LOGMORADORES_H
