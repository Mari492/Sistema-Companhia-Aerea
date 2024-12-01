#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



// Struct que representa cada membro da tripula��o
struct Funcionario {
    int identificador;
    string apelido;
    string contato;
    string funcao;
};


// Classe para gerenciar o sistema
class SistemaVooSeguro {
private:
    vector<Funcionario> listaFuncionarios; // Armazena os membros da tripula��o
    int idAtual;                           // Gera identificadores �nicos


    // Fun��o para validar os cargos
    bool validarFuncao(const string& funcao) {
        return funcao == "piloto" || funcao == "copiloto" || funcao == "comiss�rio";
    }


    // Fun��o para verificar a duplica��o de ID
    bool verificarDuplicidade(int id) {
        return any_of(listaFuncionarios.begin(), listaFuncionarios.end(),
                      [id](const Funcionario& func) { return func.identificador == id; });
    }



public:
    SistemaVooSeguro() : idAtual(1) {}

    // Fun��o para adicionar um novo funcion�rio
    void registrarFuncionario() {
        Funcionario novo;
        cout << "Deseja gerar o identificador automaticamente? (1-Sim, 0-N�o): ";
        int escolha;
        cin >> escolha;
        if (escolha == 1) {
            novo.identificador = idAtual++;
        } else {
            cout << "Digite um identificador �nico: ";
            cin >> novo.identificador;
            while (verificarDuplicidade(novo.identificador)) {
                cout << "Identificador j� em uso. Digite outro: ";
                cin >> novo.identificador;
            }
        }
        cin.ignore(); // Limpar o buffer
        cout << "Digite o nome do funcion�rio: ";
        getline(cin, novo.apelido);
        cout << "Digite o telefone do funcion�rio: ";
        getline(cin, novo.contato);
        do {
            cout << "Digite a fun��o do funcion�rio (piloto, copiloto, comiss�rio): ";
            getline(cin, novo.funcao);
            if (!validarFuncao(novo.funcao)) {
                cout << "Fun��o inv�lida! Escolha entre 'piloto', 'copiloto' ou 'comiss�rio'.\n";
            }
        } while (!validarFuncao(novo.funcao));
        listaFuncionarios.push_back(novo);
        cout << "Funcion�rio registrado com sucesso!\n";
    }

    // Fun��o para listar todos os funcion�rios
    void exibirFuncionarios() {
        if (listaFuncionarios.empty()) {
            cout << "Nenhum funcion�rio cadastrado.\n";
            return;
        }

        cout << "Funcion�rios registrados:\n";
        for (const auto& func : listaFuncionarios) {
            cout << "ID: " << func.identificador
                 << ", Nome: " << func.apelido
                 << ", Telefone: " << func.contato
                 << ", Fun��o: " << func.funcao << '\n';
        }
    }

    // Fun��o para atualizar informa��es de um funcion�rio
    void atualizarFuncionario() {
        cout << "Digite o identificador do funcion�rio que deseja atualizar: ";
        int id;
        cin >> id;
        auto it = find_if(listaFuncionarios.begin(), listaFuncionarios.end(),
                          [id](const Funcionario& func) { return func.identificador == id; });

        if (it != listaFuncionarios.end()) {
            cin.ignore(); // Limpar o buffer
            cout << "Digite o novo nome (atual: " << it->apelido << "): ";
            getline(cin, it->apelido);
            cout << "Digite o novo telefone (atual: " << it->contato << "): ";
            getline(cin, it->contato);
            do {
                cout << "Digite a nova fun��o (atual: " << it->funcao << "): ";
                getline(cin, it->funcao);
                if (!validarFuncao(it->funcao)) {
                    cout << "Fun��o inv�lida! Escolha entre 'piloto', 'copiloto' ou 'comiss�rio'.\n";
                }
            } while (!validarFuncao(it->funcao));
            cout << "Dados do funcion�rio atualizados com sucesso!\n";
        } else {
            cout << "Funcion�rio com identificador " << id << " n�o encontrado.\n";
        }
    }

    // Fun��o para remover um funcion�rio
    void excluirFuncionario() {
        cout << "Digite o identificador do funcion�rio que deseja remover: ";
        int id;
        cin >> id;
        auto it = remove_if(listaFuncionarios.begin(), listaFuncionarios.end(),
                            [id](const Funcionario& func) { return func.identificador == id; });
        if (it != listaFuncionarios.end()) {
            listaFuncionarios.erase(it, listaFuncionarios.end());
            cout << "Funcion�rio removido com sucesso!\n";
        } else {
            cout << "Funcion�rio com identificador " << id << " n�o encontrado.\n";
        }
    }
};



int main() {
    setlocale(LC_ALL, "");
    SistemaVooSeguro sistema;
    int opcao;

    do {
        cout << "\n--- Sistema de Gerenciamento da Tripula��o ---\n";
        cout << "1. Registrar novo funcion�rio\n";
        cout << "2. Exibir funcion�rios cadastrados\n";
        cout << "3. Atualizar informa��es de um funcion�rio\n";
        cout << "4. Excluir cadastro de funcion�rio\n";
        cout << "5. Sair\n";
        cout << "Escolha uma das op��es acima: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                sistema.registrarFuncionario();
                break;
            case 2:
                sistema.exibirFuncionarios();
                break;
            case 3:
                sistema.atualizarFuncionario();
                break;
            case 4:
                sistema.excluirFuncionario();
                break;
            case 5:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
