#include <frmPrincipal.h>
#include <config.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmPrincipal frmPrincipal;

    frmPrincipal.setWindowTitle( QString( "Caixa da República " ).append( NOME_REPUBLICA ) );
    
    //                                                                                                                                                                                                                                                                                                                                                                                      frmPrincipal.showMaximized();
    frmPrincipal.show();
    return a.exec();
}
