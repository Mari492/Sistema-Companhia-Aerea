#include <iostream>
#include "../include/Voo.h"
#include "../include/Tripulacao.h"

using namespace std;

void testeCriarVooValido() {
    cout << "Teste 1: Criar um voo com tripulação válida\n" << endl;

    // Criar tripulação
    Tripulacao piloto("Carlos", "Piloto", "11111-2222");
    Tripulacao copiloto("Tiago", "Copiloto", "33333-4444");
    Tripulacao comissario("Julia", "Comissário", "55555-6666");

    // Criar voo
    vector<int> comissarios = { comissario.getCodigo() };
    Voo voo1(101, "01/12/2024", "14:30", "São Paulo", "Rio de Janeiro", 123, piloto.getCodigo(), copiloto.getCodigo(), comissarios, 350.0);

    // Exibir informações
    voo1.exibirInformacoes();

    // Verificar status
    cout << "\nStatus do Voo: " << (voo1.getStatus() ? "Ativo" : "Inativo") << endl;

    // Salvar no arquivo
    voo1.salvarEmArquivo();
}

void testeCriarVooInvalido() {
    cout << "\nTeste 2: Criar um voo sem piloto\n" << endl;

    // Criar tripulação
    Tripulacao copiloto("Lucas", "Copiloto", "33333-4444");

    // Criar voo sem piloto
    vector<int> comissarios = {};
    Voo voo2(102, "02/12/2024", "16:00", "Belo Horizonte", "Salvador", 124, -1, copiloto.getCodigo(), comissarios, 400.0);

    // Exibir informações
    voo2.exibirInformacoes();

    // Verificar status
    cout << "\nStatus do Voo: " << (voo2.getStatus() ? "Ativo" : "Inativo") << endl;

    // Salvar no arquivo
    voo2.salvarEmArquivo();
}

void testeCarregarVoo() {
    cout << "\nTeste 3: Carregar voo do arquivo\n" << endl;

    try {
        Voo vooCarregado = Voo::carregarVoo(101); // Código do voo salvo no teste 1
        vooCarregado.exibirInformacoes();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void testeListarVoos() {
    cout << "\nTeste 4: Listar todos os voos\n" << endl;
    Voo::listarVoos();
}

void testeAtualizarVoo() {
    cout << "\nTeste 5: Atualizar informações do voo\n" << endl;

    try {
        Voo vooCarregado = Voo::carregarVoo(101); // Código do voo salvo no teste 1

        // Atualizar dados
        vooCarregado.setData("03/12/2024");
        vooCarregado.setHora("18:00");
        vooCarregado.setDestino("Brasília");
        vooCarregado.setTarifa(450.0);
        vooCarregado.setStatus(false);

        cout << "Informações atualizadas:\n";
        vooCarregado.exibirInformacoes();

        // Salvar novamente
        vooCarregado.salvarEmArquivo();
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

int main() {

    setlocale(LC_ALL,"");

    cout << "Iniciando testes da classe Voo\n" << endl;

    testeCriarVooValido();
    testeCriarVooInvalido();
    testeCarregarVoo();
    testeListarVoos();
    testeAtualizarVoo();

    cout << "\nTodos os testes finalizados." << endl;
    return 0;
}
