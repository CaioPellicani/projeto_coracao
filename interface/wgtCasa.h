#ifndef WGT_CASA_H
#define WGT_CASA_H

#include <config.h>
#include <logMorador.h>
#include <logConta.h>
#include "wgtConta.h"
#include "wgtMorador.h"

class WgtCasa{

private:
    enum{ CONTA, MORADOR };

    QVector<Logica::Conta *> listaContas;
    QVector<Logica::Morador *> listaMoradores;

    QGridLayout *lytMoradores = new QGridLayout();
    QGridLayout *lytContas = new QGridLayout();

    void gerarUi( int tipo, int length );

    QWidget* converterLyt_Wgt( QGridLayout *value );
    
public:
    WgtCasa( QWidget *parent = nullptr ){}

    void setListaMoradores( QVector<Logica::Morador *> value );
    void setListaContas( QVector<Logica::Conta *> value );

    QWidget* getWgtMoradores() { return this->converterLyt_Wgt( lytMoradores ); }
    QGridLayout *getLytMoradores() { return this->lytMoradores; }
    
    QWidget* getWgtContas()    { return this->converterLyt_Wgt( lytContas ); }
    QGridLayout *getLytContas() { return this->lytContas; }
};

#endif