#ifndef LOG_CONTA
#define LOG_CONTA

#include <config.h>
#include "logMorador.h"

namespace Logica{

    class Conta{

    private:
        int marcacao;
        QString nome;
        float valor = 0;
        bool custoFixo = true;

    public:
        Conta();
        
        int getMarcacao(){ return marcacao; }
        void setMarcacao( int value){ this->marcacao = value; }

        QString getNome(){ return nome; }
        void setNome( QString value ){ this->nome = value; }

        float getValor(){ return valor; }
        void setValor( int value){ this->valor = value; }

        bool getCustoFixo(){ return custoFixo; }
        void setCustoFixo( int value){ this->custoFixo = value; }

    };
}
#endif