#include <iostream>
#include <cassert>
#include "Tripulacao.h"
using namespace std;

int main() {
    // Criando um objeto Tripulacao
    Tripulacao t1(1, "Carlos", "96579876", "Piloto");

    // Testando getters
    assert(t1.getCodigo() == 1);
    assert(t1.getNome() == "Carlos");
    assert(t1.getTelefone() == "96579876");
    assert(t1.getCargo() == "Piloto");

    cout << "Todos os testes passaram com sucesso!" << endl;

    return 0;
}

