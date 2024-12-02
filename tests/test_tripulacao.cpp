#include "../include/tripulacao.h"
#include <iostream>
using namespace std;

void testeConstrutor() {
    cout << "Teste 1: Criar membros da tripula��o" << endl;
    Tripulacao t1("Jo�o", "Piloto", "12345-6789");
    Tripulacao t2("Maria", "Copiloto", "98765-4321");
    Tripulacao t3("Ana", "Comiss�rio", "55555-6666");

    t1.exibirInformacoes();
    t2.exibirInformacoes();
    t3.exibirInformacoes();
}

void testeSetters() {
    cout << "\nTeste 2: Atualizar dados de membros da tripula��o" << endl;
    Tripulacao t("Carlos", "Piloto", "11111-2222");
    t.exibirInformacoes();

    t.setNome("Carlos Silva");
    t.setCargo("Copiloto");
    t.setTelefone("33333-4444");

    cout << "Ap�s atualiza��es:" << endl;
    t.exibirInformacoes();
}

void testeCodigosUnicos() {
    cout << "\nTeste 3: Garantir que c�digos s�o �nicos" << endl;
    Tripulacao t1("Jo�o", "Piloto", "12345-6789");
    Tripulacao t2("Maria", "Copiloto", "98765-4321");

    if (t1.getCodigo() != t2.getCodigo()) {
        cout << "C�digos �nicos: SUCESSO" << endl;
    } else {
        cout << "C�digos �nicos: FALHA" << endl;
    }
}

void testeDestrutor() {
    cout << "\nTeste 4: Remover membro e liberar c�digo" << endl;

    {
        Tripulacao t("Lucas", "Comiss�rio", "55555-6666");
        t.exibirInformacoes();
        cout << "Membro 'Lucas' criado." << endl;
    }

    cout << "Membro 'Lucas' foi destru�do. C�digo deve estar liberado para reuso." << endl;
}

int main() {
    cout << "Iniciando testes da classe Tripulacao" << endl;

    testeConstrutor();
    testeSetters();
    testeCodigosUnicos();
    testeDestrutor();

    cout << "Todos os testes finalizados." << endl;
    return 0;
}
