#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include "uimoradores.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal)
{
    ui->setupUi(this);

    Logica::Casa casa = Logica::Casa();

    uiMoradores *uiListaMoradores = new uiMoradores( casa.getListaMoradores() );
    ui->areaMoradores->setWidget( uiListaMoradores->getMoradores() );
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

