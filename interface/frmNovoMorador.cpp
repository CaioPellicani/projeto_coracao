#include "frmNovoMorador.h"
#include "ui_frmNovoMorador.h"

frmNovoMorador::frmNovoMorador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmNovoMorador)
{
    ui->setupUi(this);
}

frmNovoMorador::~frmNovoMorador()
{
    delete ui;
}
