#ifndef FRMCONTRIBUICAO_H
#define FRMCONTRIBUICAO_H

#include <QDialog>
#include "config.h"

namespace Ui {
class frmContribuicao;
}

class frmContribuicao : public QDialog
{
    Q_OBJECT
private:
    enum{ VALOR, DATA, HORA };
    enum{ INSERIR, RETIRAR };
    typedef struct{
        float valor;
        QDateTime dataHora;
    }dados;

    QVector<dados*> listaValores;

    morador* this_morador;

    void carregarTabela();

    void inserirValorLista( int tipo );

    void inserirValorTabela( QString nome, QString data, QString hora );

public:
    explicit frmContribuicao(QWidget *parent = nullptr);
    ~frmContribuicao();

    void setMorador( morador* temp_morador );

private slots:
    void aceitado();

    void rejeitado();

    void on_btnInserirValor_clicked();

    void on_btnRetirarValor_clicked();

private:
    Ui::frmContribuicao *ui;
};

#endif // FRMCONTRIBUICAO_H
