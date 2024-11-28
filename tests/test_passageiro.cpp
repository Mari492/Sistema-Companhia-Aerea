#include <iostream>
#include "../include/passageiro.h"
using namespace std;

// Teste construtor
void testeConstrutor() {
    Passageiro p(101, "Lucia Helena", "Rua A", "98765-4321");
    cout << "Testando construtor" << endl;
    if (p.getCodigo() == 101 && p.getNome() == "Lucia Helena" &&
        p.getEndereco() == "Rua A" && p.getTelefone() == "98765-4321") {
        cout << "Construtor: SUCESSO" << endl;
    } else {
        cout << "Construtor: FALHA" << endl;
    }
}

// Teste setters e getters
void testeSettersEGetters() {
    Passageiro p(202, "Mariana Tavares", "Rua B", "11111-2222");
    cout << "Testando setters e getters" << endl;

    p.setNome("Mariana Tavares");
    p.setEndereco("Rua C");
    p.setTelefone("33333-4444");

    if (p.getNome() == "Mariana Tavares" && p.getEndereco() == "Rua C" &&
        p.getTelefone() == "33333-4444") {
        cout << "Setters e Getters: SUCESSO" << endl;
    } else {
        cout << "Setters e Getters: FALHA" << endl;
    }
}

// Teste exibirInformacoes
void testeExibirInformacoes() {
    Passageiro p(303, "Diego Albuquerque", "Rua D", "55555-6666");
    cout << "Testando exibirInformacoes" << endl;
    p.exibirInformacoes();
}

// Teste strings vazias
void testeStringsVazias() {
    Passageiro p(0, "", "", "");
    cout << "Testando strings vazias" << endl;
    p.exibirInformacoes();
}

// Teste com valores negativos
void testeValoresNegativos() {
    Passageiro p(-1, "Fulano", "Sem endereço", "Sem telefone");
    cout << "Testando valores negativos" << endl;
    p.exibirInformacoes();
}

// Teste com múltiplas atualizações
void testeMultiplasAtualizacoes() {
    Passageiro p(404, "Teste", "Teste", "Teste");
    p.setNome("Atualizado 1");
    p.setNome("Atualizado 2");
    cout << "Testando múltiplas atualizacoes no nome" << endl;
    p.exibirInformacoes();
}

int main() {
    cout << "Iniciando testes da classe Passageiro" << endl;

    testeConstrutor();
    testeSettersEGetters();
    testeExibirInformacoes();
    testeStringsVazias();
    testeValoresNegativos();
    testeMultiplasAtualizacoes();

    cout << "Todos os testes finalizados." << endl;
    return 0;
}
