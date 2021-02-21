#ifndef FRMNOVOMORADOR_H
#define FRMNOVOMORADOR_H

#include "poliDialog.h"
#include <logCasa.h>
#include <config.h>

namespace Ui {
class frmNovoMorador;
}

class frmNovoMorador : public PoliDialog
{

private:
    Logica::Casa * casa;
    void aceitado() override;

public:
    explicit frmNovoMorador( Logica::Casa * _casa, QWidget *parent = nullptr );
    ~frmNovoMorador();


private:
    Ui::frmNovoMorador *ui;
};

#endif // FRMNOVOMORADOR_H
