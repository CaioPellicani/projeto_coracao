#ifndef BOTAO_H
#define BOTAO_H
#include "config.h"
#include <QToolButton>
#include <QObject>

class Botao : public QToolButton{
    Q_OBJECT
public:
    Botao();
    void teste();

public Q_SLOTS:
    void checkModificado(int sinal);
};

#endif // BOTAO_H
