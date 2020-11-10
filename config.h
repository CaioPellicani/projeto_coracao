#ifndef CONFIG_H
#define CONFIG_H
#include <QValidator>
#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QVector>
#include <QCheckBox>
#include <QLabel>
#include <QSpacerItem>
#include <QToolButton>
#include <QLocale>
#include <QDateTime>

enum { DESMARCADO, PARCIAL_MARCADO, MARCADO };

typedef struct{
    int marcacao;
    QString nro;
    QString nome;
    float saldo;
    float contribuicao;
} morador;

#endif // CONFIG_H
