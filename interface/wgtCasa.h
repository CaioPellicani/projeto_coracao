#ifndef WGT_CASA_H
#define WGT_CASA_H

#include <config.h>
#include <logMorador.h>
#include <logConta.h>
#include "wgtContas.h"
#include "wgtMoradores.h"

class WgtCasa{

private:
    QVector<Logica::Conta *> listaContas;
    QVector<Logica::Morador *> listaMoradores;

    QGridLayout *lytMoradores = new QGridLayout();
    QGridLayout *lytContas = new QGridLayout();

    void gerarUi( QVector<Logica::Conta *> lista );
    void gerarUi( QVector<Logica::Morador *> lista );

    QWidget* getUi( QGridLayout *value );
    
public:
    WgtCasa( QWidget *parent = nullptr ){}

    void setListaMoradores( QVector<Logica::Morador *> value );
    void setListaContas( QVector<Logica::Conta *> value );

    QWidget* getLytMoradores() { return this->getUi( lytMoradores ); }
    QWidget* getLytContas()    { return this->getUi( lytContas ); }
};

#endif