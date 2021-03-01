#ifndef LOG_CONTRIBUICAO
#define LOG_CONTRIBUICAO

#include <config.h>
#include "logMorador.h"
namespace Logica{

    class Contribuicao{
    public:  
        Contribuicao();  
        
        typedef struct{
            float valor;
            QDateTime dataHora;
            QString obs;
        }dados;

    private:
        QVector<dados*> listaValoresInseridos;
        QVector<dados*> listaValoresDB;

        Morador* morador;

        bool getDBLista();
        bool addDados( QVector<dados*> *lista, float valor, QDateTime dataHora, QString obs );

    public:
        bool addDados( float valor, QString obs );
        dados* getDadosTail();
        float getTotalInserido();

        dados* getDadosDB( int posicao );
        int getLenghtDB();
    };
}

#endif