#ifndef UI_MORADORES_H
#define UI_MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "frmContribuicao.h"

class WgtMorador : public QWidget{
    Q_OBJECT
private:
    enum{ CONTRIBUINDO, NOME, SALDO, CONTRIBUICAO, MUDAR_CONTRIBUICAO };
    QGridLayout *lytGeral;
    Logica::Morador * morador;

    QCheckBox* cbxContribuindo;
    QLabel* lblApelido;
    QLabel* lblSaldo;
    QLabel* lblContribuicao;
    QToolButton *btnMudarCotribuicao;

    void iniciarComponentes();
    void conectar();
    void setValores();
    void addUiIndividual();

private slots:
    void atualizar();
    void desabilitarBtn( int value );
    void on_btnMudarCotribuicao_clicked();

public:
    explicit WgtMorador(  QGridLayout *_lytGeral, Logica::Morador *morador, QWidget *parent = nullptr );
    void addUiCabecalho();

};

#endif // MORADORES_H
