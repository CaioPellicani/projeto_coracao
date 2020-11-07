#ifndef BOTAO__H
#define BOTAO__H

#include <QObject>
#include <QToolButton>

class botao_ : public QToolButton{
    Q_OBJECT
public:
    explicit botao_(QToolButton *parent = nullptr);

signals:

};

#endif // BOTAO__H
