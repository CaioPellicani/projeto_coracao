#ifndef CONFIG_H
#define CONFIG_H

#include <QApplication>
#include <QCheckBox>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QJsonDocument>
#include <QLabel>
#include <QLocale>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QRegExp>   
#include <QToolButton>
#include <QValidator>
#include <QVector>

enum { DESMARCADO, PARCIAL_MARCADO, MARCADO };

#define NOME_REPUBLICA "Nome_Rep"

QString formatoDinheiro( float value );
QString formatoData( QDateTime value );
QString formatoHora( QDateTime value );

#endif // CONFIG_H
