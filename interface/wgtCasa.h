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

    QGridLayout *lytContas = new QGridLayout();
    QVector<WgtConta*> listaWgtContas;
    WgtConta* criarConta( Logica::Conta* _conta );
    void limparWgtContas();


    QGridLayout *lytMoradores = new QGridLayout();
    QVector<WgtMorador*> listaWgtMoradores;
    WgtMorador* criarMorador( Logica::Morador* _morador );
    void limparWgtMoradores();
    

    QWidget* converterLyt_Wgt( QGridLayout *value );
    
public:
    WgtCasa( Logica::Casa* _logica, QWidget *parent = nullptr );

    QWidget* getWgtMoradores();
    QGridLayout *getLytMoradores();
    void gerarMoradores();
    void refreshMoradores();

    QWidget* getWgtContas();
    QGridLayout *getLytContas();
    void gerarContas();
    void refreshContas();
};

#endif