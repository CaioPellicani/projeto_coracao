#ifndef FRMCONTRIBUICAO_H
#define FRMCONTRIBUICAO_H

#include <logMorador.h>
#include "frmcontribuicao.h"
#include "config.h"

#include "ui_frmcontribuicao.h"

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

    logMorador* this_morador;

    void carregarTabela();

    void inserirValorLista( int tipo );

    void inserirValorTabela( QString nome, QString data, QString hora );

public:
    explicit frmContribuicao( logMorador* temp_morador, QWidget *parent = nullptr );
    ~frmContribuicao();

private slots:
    void aceitado();

    void rejeitado();

    void on_btnInserirValor_clicked();

    void on_btnRetirarValor_clicked();

private:
    Ui::frmContribuicao *ui;
};

#endif // FRMCONTRIBUICAO_H
