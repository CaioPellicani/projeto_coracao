#ifndef POLI_UNIDADE_H
#define POLI_UNIDADE_H

#include <config.h>
namespace Logica{

    class Unidade{

    public:
        int marcacao;
        QString nome;

    public:

        virtual int getMarcacao(){ return marcacao; }
        virtual void setMarcacao( int value){ this->marcacao = value; }

        virtual QString getNome(){ return nome; }
        virtual void setNome( QString value ){ this->nome = value; }
    };  
}

#endif
