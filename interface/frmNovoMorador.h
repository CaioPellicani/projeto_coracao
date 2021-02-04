#ifndef FRMNOVOMORADOR_H
#define FRMNOVOMORADOR_H

#include <QDialog>

namespace Ui {
class frmNovoMorador;
}

class frmNovoMorador : public QDialog
{
    Q_OBJECT

public:
    explicit frmNovoMorador(QWidget *parent = nullptr);
    ~frmNovoMorador();

private:
    Ui::frmNovoMorador *ui;
};

#endif // FRMNOVOMORADOR_H
