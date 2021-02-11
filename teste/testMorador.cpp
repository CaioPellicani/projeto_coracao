#include <gtest/gtest.h>
#include <config.h>
#include <logMorador.h>

using namespace Logica;

struct tMorador : public testing::Test{
    Morador *morador;
    float saldoAnterior = 0;
    float custoMes = 600;
    float contribuicao = 100.5;

    void TearDown(){ delete morador; }
    void SetUp(){ 
        morador = new Morador(); 
        morador->setCustoMes( this->custoMes );
    }
};

TEST_F( tMorador, CustoMes ){
    EXPECT_EQ( morador->getSaldo(), - this->custoMes);
}

TEST_F( tMorador, addContribuicao ){
    morador->addContribuicao( contribuicao );
    EXPECT_EQ( morador->getSaldo(), ( this->contribuicao - this->custoMes - this->saldoAnterior ) ); 
}

TEST_F( tMorador, validarEmail ){
    QString emailValido[ 3 ] = { 
        "teste@teste.com.br",
        "teste123@teste123.com.br",
        "teste@teste.com",
    };

    for( int i = 0; i < 3; i++ ){
        ASSERT_TRUE( morador->validarEmail( emailValido[i] ) );
        qDebug() << "Exemplo: " << emailValido[i];
    }


    QString emailInvalido[ 6 ] = {
        "teste@.com",
        "@teste.com.br",
        "teste@teste",
        ".@.",
        "teste.teste.com",
        "www.teste.com.br",
    };

    for( int i = 0; i < 6; i++ ){
        ASSERT_FALSE( morador->validarEmail( emailInvalido[i] ) );
        qDebug() << "Exemplo: " << emailInvalido[i];
    }

}
