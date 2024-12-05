#include <iostream>
#include <cassert>
#include "Assento.h"
using namespace std;

int main() {
    // Criando um objeto Assento
    Assento a1;
    assert(a1.getNumero() == 0);
    assert(a1.estaOcupado() == false);

    // Criando um objeto Assento com o numero do assento e codigo do voo
    Assento a2(12, 101);
    assert(a2.getNumero() == 12);
    assert(a2.estaOcupado() == false);

    // Testando o método ocupar
    a2.ocupar();
    assert(a2.estaOcupado() == true);

    // Testando o método liberar
    a2.liberar();
    assert(a2.estaOcupado() == false);

    cout << "Todos os testes passaram com sucesso!" << endl;

    return 0;
}
