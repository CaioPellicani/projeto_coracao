#ifndef FRMCONTRIBUICAO_H
#define FRMCONTRIBUICAO_H

#include "poliDialog.h"
#include <logMorador.h>
#include <logContribuicao.h>
#include "config.h"



namespace Ui {
class frmContribuicao;
}

class frmContribuicao : public PoliDialog
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

    void aceitado() override;

    void carregarTabela();
    void limparTabela();

    void inserirValorLista();

    void inserirValorTabela( Logica::Contribuicao::dados* _dados );
    void inserirValorTabela( QString nome, QString data, QString hora, QString obs );

public:
    explicit frmContribuicao( Logica::Morador* _morador, QWidget *parent = nullptr );
    ~frmContribuicao();

private slots:
    void on_btnInserirValor_clicked();

private:
    Ui::frmContribuicao *ui;
};

#endif
