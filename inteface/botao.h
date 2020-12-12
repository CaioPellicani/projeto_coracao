#ifndef BOTAO_H
#define BOTAO_H
#include "config.h"
#include <QToolButton>
#include <QObject>

class Botao : public QToolButton{
    Q_OBJECT
private:
    morador* this_morador;
public:
    Botao( QString texto, morador* temp_morador );

public Q_SLOTS:
    void desabilitar(int sinal);
    void addContribuicao();

Q_SIGNALS:
    void atualizarSaldo( QString novoSaldo );
    void atualizarContribuicao( QString novaContribuicao );
};





#endif // BOTAO_H
