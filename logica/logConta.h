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

        float getValor();
        void setValor( int value);

        bool getCustoFixo();
        void setCustoFixo( int value);

    };
}
#endif