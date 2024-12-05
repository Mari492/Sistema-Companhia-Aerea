#include "Passageiro.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    // Criando um objeto Passageiro
    Passageiro p1(1, "Maria", "34430-320", "987382663", true);

    // Testando getters
    assert(p1.getCodigo() == 1);
    assert(p1.getNome() == "Maria");
    assert(p1.getEndereco() == "34430-320");
    assert(p1.getTelefone() == "987382663");
    assert(p1.isFidelidade() == true);
    assert(p1.getPontosFidelidade() == 0);

    // Testando o método adicionarPontos
    p1.adicionarPontos(10);
    assert(p1.getPontosFidelidade() == 10);

    p1.adicionarPontos(10);
    assert(p1.getPontosFidelidade() == 20);

    cout << "Todos os testes passaram com sucesso!" << endl;

    return 0;
}

