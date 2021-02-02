#ifndef BOTAO_H
#define BOTAO_H
#include "config.h"
#include "frmcontribuicao.h"


class Botao : public QToolButton{
    Q_OBJECT
private:
    logMorador* morador;
public:
    Botao( QString texto, logMorador* temp_morador );

public Q_SLOTS:
    void desabilitar(int sinal);
    void addContribuicao();

Q_SIGNALS:
    void atualizarSaldo( QString novoSaldo );
    void atualizarContribuicao( QString novaContribuicao );
};





#endif // BOTAO_H
