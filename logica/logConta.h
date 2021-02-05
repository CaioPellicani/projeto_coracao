#ifndef LOG_CONTA
#define LOG_CONTA

#include <config.h>
#include "logMorador.h"

namespace Logica{

    class Conta : public Unidade{

    private:
        float valor = 0;
        bool custoFixo = true;

    public:

        float getValor(){ return valor; }
        void setValor( int value){ this->valor = value; }

        bool getCustoFixo(){ return custoFixo; }
        void setCustoFixo( int value){ this->custoFixo = value; }

    };
}
#endif