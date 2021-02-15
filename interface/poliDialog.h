#ifndef POLI_DIALOG_H
#define POLI_DIALOG_H

#include <QDialog>
#include <config.h>

class PoliDialog : public QDialog
{
    Q_OBJECT

private:
    QString cabecalho;
    QString pergunta;

protected:   
    virtual void aceitado() { qDebug() << "aceitado";  }
    virtual void rejeitado(){ qDebug() << "rejeitado"; }
    virtual void cancelado(){ qDebug() << "cancelado"; }

    void conectar( QDialogButtonBox *btnConfirmar, QString _cabecalho, QString _pergunta ){
        this->cabecalho = _cabecalho;
        this->pergunta = _pergunta;

        QObject::connect( btnConfirmar, SIGNAL( accepted() ), this, SLOT( foiAceito() ) );
        QObject::connect( btnConfirmar, SIGNAL( rejected() ), this, SLOT( foiRejeitado() ) );
    }

    void conectar( QDialogButtonBox *btnConfirmar ){
        conectar( btnConfirmar, "Ação", "Tem Certeza?" );
    }

public:
    explicit PoliDialog( QWidget *parent = nullptr ){}
    ~PoliDialog(){}

private slots:
    void foiAceito(){
        if( QMessageBox::question( this, this->cabecalho, this->pergunta ) == QMessageBox::Yes ){
            this->aceitado();
            accept();
        }
        else{
            this->cancelado();
        }
    }
    void foiRejeitado(){
        this->rejeitado();
        reject();
    }
};

#endif