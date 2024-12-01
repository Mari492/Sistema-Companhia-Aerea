#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



// Struct que representa cada membro da tripulação
struct Funcionario {
    int identificador;
    string apelido;
    string contato;
    string funcao;
};


// Classe para gerenciar o sistema
class SistemaVooSeguro {
private:
    vector<Funcionario> listaFuncionarios; // Armazena os membros da tripulação
    int idAtual;                           // Gera identificadores únicos


    // Função para validar os cargos
    bool validarFuncao(const string& funcao) {
        return funcao == "piloto" || funcao == "copiloto" || funcao == "comissário";
    }


    // Função para verificar a duplicação de ID
    bool verificarDuplicidade(int id) {
        return any_of(listaFuncionarios.begin(), listaFuncionarios.end(),
                      [id](const Funcionario& func) { return func.identificador == id; });
    }



public:
    SistemaVooSeguro() : idAtual(1) {}

    // Função para adicionar um novo funcionário
    void registrarFuncionario() {
        Funcionario novo;
        cout << "Deseja gerar o identificador automaticamente? (1-Sim, 0-Não): ";
        int escolha;
        cin >> escolha;
        if (escolha == 1) {
            novo.identificador = idAtual++;
        } else {
            cout << "Digite um identificador único: ";
            cin >> novo.identificador;
            while (verificarDuplicidade(novo.identificador)) {
                cout << "Identificador já em uso. Digite outro: ";
                cin >> novo.identificador;
            }
        }
        cin.ignore(); // Limpar o buffer
        cout << "Digite o nome do funcionário: ";
        getline(cin, novo.apelido);
        cout << "Digite o telefone do funcionário: ";
        getline(cin, novo.contato);
        do {
            cout << "Digite a função do funcionário (piloto, copiloto, comissário): ";
            getline(cin, novo.funcao);
            if (!validarFuncao(novo.funcao)) {
                cout << "Função inválida! Escolha entre 'piloto', 'copiloto' ou 'comissário'.\n";
            }
        } while (!validarFuncao(novo.funcao));
        listaFuncionarios.push_back(novo);
        cout << "Funcionário registrado com sucesso!\n";
    }

    // Função para listar todos os funcionários
    void exibirFuncionarios() {
        if (listaFuncionarios.empty()) {
            cout << "Nenhum funcionário cadastrado.\n";
            return;
        }

        cout << "Funcionários registrados:\n";
        for (const auto& func : listaFuncionarios) {
            cout << "ID: " << func.identificador
                 << ", Nome: " << func.apelido
                 << ", Telefone: " << func.contato
                 << ", Função: " << func.funcao << '\n';
        }
    }

    // Função para atualizar informações de um funcionário
    void atualizarFuncionario() {
        cout << "Digite o identificador do funcionário que deseja atualizar: ";
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
                cout << "Digite a nova função (atual: " << it->funcao << "): ";
                getline(cin, it->funcao);
                if (!validarFuncao(it->funcao)) {
                    cout << "Função inválida! Escolha entre 'piloto', 'copiloto' ou 'comissário'.\n";
                }
            } while (!validarFuncao(it->funcao));
            cout << "Dados do funcionário atualizados com sucesso!\n";
        } else {
            cout << "Funcionário com identificador " << id << " não encontrado.\n";
        }
    }

    // Função para remover um funcionário
    void excluirFuncionario() {
        cout << "Digite o identificador do funcionário que deseja remover: ";
        int id;
        cin >> id;
        auto it = remove_if(listaFuncionarios.begin(), listaFuncionarios.end(),
                            [id](const Funcionario& func) { return func.identificador == id; });
        if (it != listaFuncionarios.end()) {
            listaFuncionarios.erase(it, listaFuncionarios.end());
            cout << "Funcionário removido com sucesso!\n";
        } else {
            cout << "Funcionário com identificador " << id << " não encontrado.\n";
        }
    }
};



int main() {
    setlocale(LC_ALL, "");
    SistemaVooSeguro sistema;
    int opcao;

    do {
        cout << "\n--- Sistema de Gerenciamento da Tripulação ---\n";
        cout << "1. Registrar novo funcionário\n";
        cout << "2. Exibir funcionários cadastrados\n";
        cout << "3. Atualizar informações de um funcionário\n";
        cout << "4. Excluir cadastro de funcionário\n";
        cout << "5. Sair\n";
        cout << "Escolha uma das opções acima: ";
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
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
