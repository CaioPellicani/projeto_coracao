#include "config.h"

QString formatoDinheiro( float value ){ return QLocale().toCurrencyString( value ); }

QString formatoData( QDateTime value ){ return value.toString( "dd/MM/yyyy" ); }

QString formatoHora( QDateTime value ){ return value.toString( "hh:mm:ss" ); }