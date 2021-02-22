#ifndef BOTAO_H
#define BOTAO_H
#include "config.h"
#include "frmContribuicao.h"


class Botao : public QToolButton{
    Q_OBJECT
private:
    Logica::Morador* morador;
public:
    Botao( QString texto, Logica::Morador* temp_morador );

public Q_SLOTS:
    void desabilitar(int sinal);
    void addContribuicao();

Q_SIGNALS:
    void atualizarWgt();
};





#endif // BOTAO_H
