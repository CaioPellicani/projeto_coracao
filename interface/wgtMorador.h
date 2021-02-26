#ifndef UI_MORADORES_H
#define UI_MORADORES_H
#include "config.h"
#include <logMorador.h>
#include "wgtBotao.h"

class WgtMorador : public QObject{
    Q_OBJECT
protected:
    enum{ CONTRIBUINDO, NOME, SALDO, CONTRIBUICAO, MUDAR_CONTRIBUICAO };
    QGridLayout *lytGeral;
    Logica::Morador * morador;

    QCheckBox* cbxContribuindo;
    QLabel* lblApelido;
    QLabel* lblSaldo;
    QLabel* lblContribuicao;
    Botao *btnMudarCotribuicao;

    void iniciarComponentes();
    void conectar();
    void setValores();
    void addUiCabecalho();
    void addUiIndividual();

private slots:


public:
    explicit WgtMorador(  QGridLayout *_lytGeral, Logica::Morador *morador, QWidget *parent = nullptr );

};

#endif // MORADORES_H
