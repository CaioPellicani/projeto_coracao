#ifndef LOGMORADOR_H
#define LOGMORADOR_H

#include <config.h>


class logMorador{

private:
    int marcacao;
    QString nro;
    QString nome;
    float contribuicao;
    float custoMes;
    float saldo;

public:
    logMorador();

    int getMarcacao(){ return marcacao; }
    void setMarcacao( int value){ this->marcacao = value; }

    QString getNro(){ return nro; }
    void setNro( QString value ){ this->nro = value; }

    QString getNome(){ return nome; }
    void setNome( QString value ){ this->nome = value; }

    float getContribuicao(){ return contribuicao; }
    void setContribuicao( float value ){ this->contribuicao = value; }

    float getCustoMes(){ return custoMes; }
    void setCustoMes( float value ){ this->custoMes = value; }

    float getSaldo(){ return saldo; }
    void setSaldo( float value ){ this->saldo = value; }

};

#endif // LOGMORADORES_H
