#ifndef LOG_MORADOR_H
#define LOG_MORADOR_H

#include <config.h>
namespace Logica{

    class Morador{

    private:
        int marcacao;
        QString nro;
        QString nome;
        float contribuicao = 0;
        float custoMes = 0;
        float saldoMesAnterior = 0;

    public:
        Morador();

        int getMarcacao(){ return marcacao; }
        void setMarcacao( int value){ this->marcacao = value; }

        QString getNro(){ return nro; }
        void setNro( QString value ){ this->nro = value; }

        QString getNome(){ return nome; }
        void setNome( QString value ){ this->nome = value; }

        float getContribuicao(){ return contribuicao; }
        void addContribuicao( float value ){ this->contribuicao += value; }

        float getCustoMes(){ return custoMes; }
        void setCustoMes( float value ){ this->custoMes = value; }

        float getSaldo(){ return contribuicao - custoMes + saldoMesAnterior; }
    
    };  
}

#endif // LOGMORADORES_H
