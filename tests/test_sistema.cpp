#include <iostream>
#include <cassert>
#include "Sistema.h"
#include "Passageiro.h"
#include "Tripulacao.h"
#include "Voo.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "Portuguese");

    // Criando o sistema
    Sistema sistema;

    // Testando o cadastro de passageiro
    sistema.cadastrarPassageiro("João", "12345-678", "987741234", true);
    assert(sistema.getPassageiros().size() == 1);
    assert(sistema.getPassageiros()[0].getNome() == "João");

    // Testando o cadastro de tripulante
    sistema.cadastrarTripulante("Carlos", "987741235", "Piloto");
    sistema.cadastrarTripulante("Ana", "987741258", "Copiloto");
    assert(sistema.getTripulantes().size() == 2);
    assert(sistema.getTripulantes()[0].getNome() == "Carlos");
    assert(sistema.getTripulantes()[1].getCargo() == "Copiloto");

    // Testando o cadastro de voo
    Tripulacao piloto = sistema.getTripulantes()[0];
    Tripulacao copiloto = sistema.getTripulantes()[1];
    sistema.cadastrarVoo("27/12/2024", "14:30", "São Paulo", "Rio de Janeiro", "123", piloto, copiloto, 450.00);// Tarifa R$450
    assert(sistema.getTripulantes().size() == 2); // Confirmar que o sistema mantém os tripulantes

    // Testando a criação de reserva
    sistema.criarReserva(1, 0, 1); // Código do voo, número do assento, código do passageiro
    cout << "Todos os testes passaram com sucesso!" << endl;

    return 0;
}
