#ifndef FRMNOVOMORADOR_H
#define FRMNOVOMORADOR_H

#include "poliDialog.h"
#include "wgtCasa.h"
#include <logCasa.h>
#include <config.h>

namespace Ui {
class frmNovoMorador;
}

class frmNovoMorador : public PoliDialog
{

private:
    Logica::Casa * logica;
     WgtCasa * casa;
    void aceitado() override;

public:
    explicit frmNovoMorador( Logica::Casa * _logica, WgtCasa * _casa, QWidget *parent = nullptr );
    explicit frmNovoMorador( Logica::Casa * _logica, QWidget *parent = nullptr ){}
    ~frmNovoMorador();


private:
    Ui::frmNovoMorador *ui;
};

#endif // FRMNOVOMORADOR_H
