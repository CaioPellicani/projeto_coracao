#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include <QMainWindow>
#include "config.h"
#include <logMorador.h>
#include <logCasa.h>

QT_BEGIN_NAMESPACE
namespace Ui { class frmPrincipal; }
QT_END_NAMESPACE

class frmPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    frmPrincipal(QWidget *parent = nullptr);
    ~frmPrincipal();

private:
    Ui::frmPrincipal *ui;
};
#endif // FRMPRINCIPAL_H
