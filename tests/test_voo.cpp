#include <iostream>
#include <cassert>
#include "Voo.h"
#include "Tripulacao.h"
using namespace std;

int main() {
    // Criando objetos Tripulacao para piloto e copiloto
    Tripulacao piloto(1, "Carlos", "987564123", "Piloto");
    Tripulacao copiloto(2, "Ana", "976745567", "Copiloto");

    // Criando um objeto Voo
    Voo voo1(1, "27/12/2024", "14:30", "São Paulo", "Rio de Janeiro", "123", piloto, copiloto, 500.00, 10); //Tarifa R$ 500 e número de assentos = 10

    // Testando getters
    assert(voo1.getCodigo() == 1);
    assert(voo1.getOrigem() == "São Paulo");
    assert(voo1.getDestino() == "Rio de Janeiro");
    assert(voo1.isAtivo() == true);

    // Testando ativar/desativar voo
    voo1.desativar();
    assert(voo1.isAtivo() == false);

    voo1.ativar();
    assert(voo1.isAtivo() == true);

    // Testando ocupação e liberação de assentos
    assert(voo1.verificarAssentoDisponivel(0) == true);
    voo1.ocuparAssento(0);
    assert(voo1.verificarAssentoDisponivel(0) == false);

    voo1.liberarAssento(0);
    assert(voo1.verificarAssentoDisponivel(0) == true);

    // Tentativa de ocupar um assento inválido
    voo1.ocuparAssento(11); // Fora do intervalo, máx = 10

    cout << "Teste simples para Voo passou com sucesso!" << endl;

    return 0;
}

