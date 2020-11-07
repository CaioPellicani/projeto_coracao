#include "moradores.h"


//Moradores::Moradores( QObject *parent) : QObject(parent){
Moradores::Moradores(){
    QHBoxLayout *layout = new QHBoxLayout();
    QSpacerItem* espaco = new QSpacerItem( 10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);
    QLabel* numero = new QLabel( "Nro" );
    QLabel* nome = new QLabel( "Nome" );
    QLabel* saldo = new QLabel( "Saldo" );
    QLabel* contribuicao = new QLabel( "Constribuição" );

    layout->addWidget( numero );
    //layout->addSpacerItem( espaco );
    layout->addWidget( nome );
    //layout->addSpacerItem( espaco );
    layout->addWidget( saldo );
    layout->addSpacerItem( espaco );

    layout->addWidget( contribuicao );
    layout->addSpacerItem( espaco );

    vertical->addLayout( layout );
}


QWidget* Moradores::getMoradores(){
    for( int i = 0; i < moradores.length(); i++ ){
        vertical->addLayout( moradores[i] );
    }

    resul->setLayout( vertical );
    return resul;
}

void Moradores::gerarCasa( QVector<morador*> casa ){
    for( int i = 0; i < casa.length(); i++ ) {
        this->addUiMorador( casa[i] );
    }
}

void Moradores::addUiMorador( morador* morador ){
    QHBoxLayout *layout = new QHBoxLayout();
    QSpacerItem* espaco = new QSpacerItem( 10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

    QCheckBox* cbxContribuindo = new QCheckBox( morador->nro );
    QLabel* lblNome = new QLabel( morador->nome );
    QLabel* lblSaldo = new QLabel( QLocale().toCurrencyString( morador->saldo ) );
    Botao *btnMudarCotribuicao = new Botao();
    QLabel* lblContribuicao = new QLabel( QLocale().toCurrencyString( morador->contribuicao ) );

    cbxContribuindo->setCheckState( Qt::CheckState( morador->marcacao ) );
    connect(cbxContribuindo, SIGNAL( stateChanged(int) ), btnMudarCotribuicao, SLOT( checkModificado(int) ) );

    layout->addWidget( cbxContribuindo );
    layout->addSpacerItem( espaco );

    layout->addWidget( lblNome );
    layout->addSpacerItem( espaco );

    layout->addWidget( lblSaldo );
    layout->addSpacerItem( espaco );

    btnMudarCotribuicao->setText("+");
    btnMudarCotribuicao->setEnabled( morador->marcacao );
    layout->addWidget(btnMudarCotribuicao);

    layout->addWidget( lblContribuicao );
    layout->addSpacerItem( espaco );

    moradores.push_back( layout );
}

void Moradores::slot(){
   qDebug() << "teste";
}

