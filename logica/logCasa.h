#ifndef LOG_CASA
#define LOG_CASA

#include <config.h>
#include "logMorador.h"

class logCasa{
private:
    QVector<logMorador*> listaMoradores;
    void getListaDB();


public: 
    logCasa();
    
    QVector<logMorador*> getListaMoradores(){ return listaMoradores; }

};


#endif