#include <iostream>
#include <cassert>
#include "Reserva.h"
using namespace std;

int main() {
    // Criando um objeto Reserva
    Reserva reserva1(1, 12, 20);

    // Testando getters
    assert(reserva1.getCodigoVoo() == 1);
    assert(reserva1.getNumeroAssento() == 12);
    assert(reserva1.getCodigoPassageiro() == 20);

    cout << "Todos os testes passaram com sucesso!" << endl;

    return 0;
}
