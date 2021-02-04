#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include "uimoradores.h"
#include "uiContas.h"

frmPrincipal::frmPrincipal(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmPrincipal){
    ui->setupUi(this);

    Logica::Casa casa = Logica::Casa();

    uiMoradores *uiListaMoradores = new uiMoradores( casa.getListaMoradores() );
    ui->areaMoradores->setWidget( uiListaMoradores->getUiMoradores() );

    uiContas *uiListaContas = new uiContas( casa.getListaContas() );
    //uiContas *uiListaContas = new uiContas(  );
    ui->areaContas->setWidget( uiListaContas->getUi() );
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

