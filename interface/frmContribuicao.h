#ifndef FRMCONTRIBUICAO_H
#define FRMCONTRIBUICAO_H

#include <logMorador.h>
#include <logContribuicao.h>
#include "config.h"

#include "ui_frmContribuicao.h"

namespace Ui {
class frmContribuicao;
}

class frmContribuicao : public QDialog
{
    Q_OBJECT
private:
    enum{ VALOR, DATA, HORA, OBS };

    Logica::Contribuicao logica;

    typedef struct{
        float valor;
        QDateTime dataHora;
        QString obs;
    }dados;

    QVector<dados*> listaValores;

    Logica::Morador* morador;

    void carregarTabela();

    void inserirValorLista();

    void inserirValorTabela( Logica::Contribuicao::dados* _dados );
    void inserirValorTabela( QString nome, QString data, QString hora, QString obs );

    void conectar();

public:
    explicit frmContribuicao( Logica::Morador* _morador, QWidget *parent = nullptr );
    ~frmContribuicao();

private slots:
    void aceitado();
    void rejeitado();
    void on_btnInserirValor_clicked();

private:
    Ui::frmContribuicao *ui;
};

#endif
