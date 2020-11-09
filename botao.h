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
    Botao( morador* temp_morador );

public Q_SLOTS:
    void desabilitar(int sinal);
    void addContribuicao();
    //void addContribuicao( morador* morador);

Q_SIGNALS:
};





#endif // BOTAO_H
