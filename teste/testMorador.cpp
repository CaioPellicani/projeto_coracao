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
    QStringList emailValido = {
        "simple@example.com",
        "very.common@example.com",
        "disposable.style.email.with+symbol@example.com",
        "other.email-with-hyphen@example.com",
        "fully-qualified-domain@example.com",
        "user.name+tag+sorting@example.com",
        "user.name@example.com",
        "x@example.com",
        "example-indeed@strange-example.com",
    };

    for( int i = 0; i < emailValido.size(); i++ ){
        ASSERT_TRUE( morador->validarEmail( emailValido[i] ) );
        //qDebug() << "Exemplo: " << emailValido[i];
    }


    QStringList emailInvalido = {
        "Abc.example.com",
        "A@b@c@example.com",
        "a\"b(c)d,e:f;g<h>i[j\\k]l@example.com",
        "just\"not\"right@example.com",     
        "this is\"not\\allowed@example.com",
        "this\\ still\\\"not\\\\allowed@example.com",
        "1234567890123456789012345678901234567890123456789012345678901234+x@example.com"
        "i_like_underscore@but_its_not_allowed_in_this_part.example.com",
    };

    for( int i = 0; i < emailInvalido.size(); i++ ){
        ASSERT_FALSE( morador->validarEmail( emailInvalido[i] ) );
        //qDebug() << "Exemplo: " << emailInvalido[i];
    }

}
