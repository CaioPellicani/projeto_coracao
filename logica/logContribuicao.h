#ifndef LOG_CONTRIBUICAO
#define LOG_CONTRIBUICAO

#include <config.h>
#include "logMorador.h"

class logContribuicao{
public:    
    typedef struct{
        float valor;
        QDateTime dataHora;
        QString obs;
    }dados;

private:
    QVector<dados*> listaValoresInseridos;
    QVector<dados*> listaValoresDB;

    logMorador* this_morador;

    bool getDBLista();
    bool addDados( QVector<dados*> *lista, float valor, QDateTime dataHora, QString obs );

public:
    bool addDados( float valor, QString obs );
    dados* getDadosTail(){ return listaValoresInseridos.last(); };
    float getTotalInserido();

    dados* getDadosDB( int posicao ){ return listaValoresDB[posicao]; };
};

#endif