#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include <QMainWindow>
#include "config.h"
#include <logCasa.h>
#include <logConta.h>

#include "frmNovoMorador.h"
#include "wgtCasa.h"
#include "wgtMoradores.h"
#include "wgtContas.h"


QT_BEGIN_NAMESPACE
namespace Ui { class frmPrincipal; }
QT_END_NAMESPACE

class frmPrincipal : public QMainWindow
{
    Q_OBJECT

private:
    Logica::Casa logica;
    WgtCasa casa;
public:
    frmPrincipal(QWidget *parent = nullptr);
    ~frmPrincipal();

private slots:
    void on_btnAddMorador_clicked();

private:
    Ui::frmPrincipal *ui;
};
#endif // FRMPRINCIPAL_H
