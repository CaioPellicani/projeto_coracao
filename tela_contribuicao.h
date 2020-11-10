#ifndef TELA_CONTRIBUICAO_H
#define TELA_CONTRIBUICAO_H

#include <QDialog>
#include "config.h"

namespace Ui {
class tela_contribuicao;
}

class tela_contribuicao : public QDialog
{
    Q_OBJECT
private:
    typedef struct{
        float valor;
        QDateTime dataHora;
    }valor;

    QVector<valor*> listaValores;

    morador* this_morador;

    void carregarLista();

public:
    explicit tela_contribuicao(QWidget *parent = nullptr );

    void setMorador( morador* temp_morador );

    ~tela_contribuicao();

private slots:
    void aceitado();

    void on_buttonBox_rejected();

    void on_btnAddValor_clicked();

private:
    Ui::tela_contribuicao *ui;
};

#endif // TELA_CONTRIBUICAO_H
