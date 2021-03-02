#ifndef WGT_CASA_H
#define WGT_CASA_H

#include <config.h>
#include <logCasa.h>
#include <logMorador.h>
#include <logConta.h>
#include "wgtConta.h"
#include "wgtMorador.h"

class WgtCasa : public QWidget{

private:
    enum{ CONTA, MORADOR };

    Logica::Casa* logica;

    QGridLayout *lytMoradores = new QGridLayout();
    QGridLayout *lytContas = new QGridLayout();

    void limparWgtMoradores();
    
    QWidget* converterLyt_Wgt( QGridLayout *value );
    
public:
    WgtCasa( Logica::Casa* _logica, QWidget *parent = nullptr );

    void gerarMoradores();
    void gerarContas();

    QWidget* getWgtMoradores();
    QGridLayout *getLytMoradores();
    
    QWidget* getWgtContas();
    QGridLayout *getLytContas();

    QWidget* getWgtContas()    { return this->converterLyt_Wgt( lytContas ); }
    QGridLayout *getLytContas() { return this->lytContas; }
};

#endif