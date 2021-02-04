#ifndef LOG_MORADOR_H
#define LOG_MORADOR_H

#include <config.h>
#include "poliUnidade.h"

namespace Logica{

    class Morador : public Unidade{

    private:
        QString nro;
        float contribuicao = 0;
        float custoMes = 0;
        float saldoMesAnterior = 0;

    public:

        QString getNro(){ return nro; }
        void setNro( QString value ){ this->nro = value; }

        float getContribuicao(){ return contribuicao; }
        void addContribuicao( float value ){ this->contribuicao += value; }

        float getCustoMes(){ return custoMes; }
        void setCustoMes( float value ){ this->custoMes = value; }

        float getSaldo(){ return contribuicao - custoMes + saldoMesAnterior; }
    
    };  
}

#endif // LOGMORADORES_H
