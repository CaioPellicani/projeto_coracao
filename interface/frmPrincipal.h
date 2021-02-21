#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include <QMainWindow>
#include "config.h"
#include <logCasa.h>
#include <logConta.h>

QT_BEGIN_NAMESPACE
namespace Ui { class frmPrincipal; }
QT_END_NAMESPACE

class frmPrincipal : public QMainWindow
{
    Q_OBJECT

private:
    Logica::Casa logica;
public:
    frmPrincipal(QWidget *parent = nullptr);
    ~frmPrincipal();

private slots:
    void on_btnAddMorador_clicked();

private:
    Ui::frmPrincipal *ui;
};
#endif // FRMPRINCIPAL_H
