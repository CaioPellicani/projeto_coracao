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
        QString getApelido(){ return this->apelido; }
        void setApelido( QString value ){ this->apelido = value; }

        int getID(){ return ID; }
        void setID( int value ){ this->ID = value; }

        float getContribuicao(){ return contribuicao; }
        void addContribuicao( float value ){ this->contribuicao += value; }

        float getCustoMes(){ return custoMes; }
        void setCustoMes( float value ){ this->custoMes = value; }

        float getSaldo(){ return contribuicao - custoMes + saldoMesAnterior; }

        bool validarEmail( QString email );    
    
    };  
}

#endif // LOGMORADORES_H
