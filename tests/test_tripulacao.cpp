#include "../include/tripulacao.h"
#include <iostream>
using namespace std;

void testeConstrutor() {
    cout << "Teste 1: Criar membros da tripulação" << endl;
    Tripulacao t1("João", "Piloto", "12345-6789");
    Tripulacao t2("Maria", "Copiloto", "98765-4321");
    Tripulacao t3("Ana", "Comissário", "55555-6666");

    t1.exibirInformacoes();
    t2.exibirInformacoes();
    t3.exibirInformacoes();
}

void testeSetters() {
    cout << "\nTeste 2: Atualizar dados de membros da tripulação" << endl;
    Tripulacao t("Carlos", "Piloto", "11111-2222");
    t.exibirInformacoes();

    t.setNome("Carlos Silva");
    t.setCargo("Copiloto");
    t.setTelefone("33333-4444");

    cout << "Após atualizações:" << endl;
    t.exibirInformacoes();
}

void testeCodigosUnicos() {
    cout << "\nTeste 3: Garantir que códigos são únicos" << endl;
    Tripulacao t1("João", "Piloto", "12345-6789");
    Tripulacao t2("Maria", "Copiloto", "98765-4321");

    if (t1.getCodigo() != t2.getCodigo()) {
        cout << "Códigos únicos: SUCESSO" << endl;
    } else {
        cout << "Códigos únicos: FALHA" << endl;
    }
}

void testeDestrutor() {
    cout << "\nTeste 4: Remover membro e liberar código" << endl;

    {
        Tripulacao t("Lucas", "Comissário", "55555-6666");
        t.exibirInformacoes();
        cout << "Membro 'Lucas' criado." << endl;
    }

    cout << "Membro 'Lucas' foi destruído. Código deve estar liberado para reuso." << endl;
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
