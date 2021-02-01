#include "config.h"

QString formatoDinheiro( float value ){ return QLocale().toCurrencyString( value ); }