#include "frmprincipal.h"
#include <t2.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    t2();
    QApplication a(argc, argv);
    frmPrincipal w;
    w.show();
    return a.exec();
}
