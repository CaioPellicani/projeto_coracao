#ifndef CONFIG_H
#define CONFIG_H

#include <QCheckBox>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLocale>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QToolButton>
#include <QValidator>
#include <QVector>

enum { DESMARCADO, PARCIAL_MARCADO, MARCADO };

QString formatoDinheiro( float value );

#endif // CONFIG_H
