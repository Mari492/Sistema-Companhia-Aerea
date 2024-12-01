#include <iostream>
#include "../include/passageiro.h"
using namespace std;

// Teste construtor
void testeConstrutor() {
    Passageiro p("Lucia Helena", "Rua A", "98765-4321");
    cout << "Testando construtor" << endl;
    if (p.getNome() == "Lucia Helena" &&
        p.getEndereco() == "Rua A" && p.getTelefone() == "98765-4321") {
        cout << "Construtor: SUCESSO" << endl;
    }
    else{
        cout << "Construtor: FALHA" << endl;
    }

    //Verifica o código
    if (p.getCodigo() > 0) {
        cout << "Código gerado automaticamente: SUCESSO" << endl;
        }
    else{
        cout << "Código gerado automaticamente: FALHA" << endl;
        }
}

// Teste setters e getters
void testeSettersEGetters() {
    Passageiro p("Mariana Tavares", "Rua B", "11111-2222");
    cout << "Testando setters e getters" << endl;

    p.setNome("Mariana Tavares");
    p.setEndereco("Rua C");
    p.setTelefone("33333-4444");

    if (p.getNome() == "Mariana Tavares" && p.getEndereco() == "Rua C" &&
        p.getTelefone() == "33333-4444") {
        cout << "Setters e Getters: SUCESSO" << endl;
    }
    else{
        cout << "Setters e Getters: FALHA" << endl;
    }
}

// Teste exibirInformacoes
void testeExibirInformacoes() {
    Passageiro p("Diego Albuquerque", "Rua D", "55555-6666");
    cout << "Testando exibirInformacoes" << endl;
    p.exibirInformacoes();
}

// Teste strings vazias
void testeStringsVazias() {
    Passageiro p("", "", "");
    cout << "Testando strings vazias" << endl;
    p.exibirInformacoes();
}

// Teste com múltiplas atualizações
void testeMultiplasAtualizacoes() {
    Passageiro p("Teste", "Teste", "Teste");
    p.setNome("Atualizado 1");
    p.setNome("Atualizado 2");
    cout << "Testando multiplas atualizacoes no nome" << endl;
    p.exibirInformacoes();
}

// Teste sequência de códigos
void testeSequenciaDeCodigos() {
    Passageiro p1("Passageiro 1", "Endereco 1", "11111-1111");
    Passageiro p2("Passageiro 2", "Endereco 2", "22222-2222");

    cout << "Testando sequencia de codigos" << endl;
    if (p2.getCodigo() == p1.getCodigo() + 1) {
        cout << "Sequencia de codigos: SUCESSO" << endl;
    } else {
        cout << "Sequencia de códigos: FALHA" << endl;
    }
}

int main() {
    cout << "Iniciando testes da classe Passageiro" << endl;

    testeConstrutor();
    testeSettersEGetters();
    testeExibirInformacoes();
    testeStringsVazias();
    testeMultiplasAtualizacoes();
    testeSequenciaDeCodigos();

    cout << "Todos os testes finalizados." << endl;
    return 0;
}
