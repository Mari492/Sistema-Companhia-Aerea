#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Sistema sistema;

    //Carregar dados do sistema
    sistema.carregarSistema("sistema.txt");

    int opcao;
    do {
        cout << "\n=== Sistema de Gerenciamento de Voos ===\n";
        cout << "1. Cadastrar Passageiro\n";
        cout << "2. Cadastrar Tripulante\n";
        cout << "3. Cadastrar Voo\n";
        cout << "4. Criar Reserva\n";
        cout << "5. Listar Voos por Passageiro\n";
        cout << "6. Pesquisar Passageiro\n";
        cout << "7. Pesquisar Tripulante\n";
        cout << "8. Mostrar Pontos de Fidelidade de Passageiro" << endl;
        cout << "9. Cancelar reserva" << endl;
        cout << "10. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                // Código para cadastrar passageiro
                string nome, endereco, telefone;
                bool fidelidade;
                cout << "Nome: ";
                cin.ignore();  // Limpa o buffer
                getline(cin, nome);
                cout << "Endereço: ";
                getline(cin, endereco);
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Fidelidade (1-Sim, 0-Não): ";
                cin >> fidelidade;

                sistema.cadastrarPassageiro(nome, endereco, telefone, fidelidade);
                break;
            }
            case 2: {
                // Código para cadastrar tripulante
                string nome, telefone, cargo;
                cout << "Nome: ";
                cin.ignore();  // Limpa o buffer
                getline(cin, nome);
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Cargo: ";
                getline(cin, cargo);

                sistema.cadastrarTripulante(nome, telefone, cargo);
                break;
            }
            case 3: {
                // Código para cadastrar voo
                string data, hora, origem, destino, codigoAviao, nomePiloto, nomeCopiloto;
                double tarifa;

                cout << "Data (DD/MM/AAAA): ";
                cin.ignore();  // Limpa o buffer
                getline(cin, data);
                cout << "Hora (HH:MM): ";
                getline(cin, hora);
                cout << "Origem: ";
                getline(cin, origem);
                cout << "Destino: ";
                getline(cin, destino);
                cout << "Código Avião: ";
                getline(cin, codigoAviao);
                cout << "Nome Piloto: ";
                getline(cin, nomePiloto);
                cout << "Nome Copiloto: ";
                getline(cin, nomeCopiloto);
                cout << "Tarifa: ";
                cin >> tarifa;

                // Verificar se o piloto e copiloto existem
                const auto& tripulantes = sistema.getTripulantes();
                Tripulacao pilotoSelecionado(0, "", "", "");   // Armazena o piloto encontrado
                Tripulacao copilotoSelecionado(0, "", "", ""); // Armazena o copiloto encontrado

                for (const auto& tripulante : tripulantes) {
                    if (tripulante.getNome() == nomePiloto && tripulante.getCargo() == "Piloto") {
                        pilotoSelecionado = tripulante;
                    }
                    if (tripulante.getNome() == nomeCopiloto && tripulante.getCargo() == "Copiloto") {
                        copilotoSelecionado = tripulante;
                    }
                }

                if (pilotoSelecionado.getNome().empty()) {
                    cout << "Erro: Piloto não encontrado ou não cadastrado!" << endl;
                    break;
                }

                if (copilotoSelecionado.getNome().empty()) {
                    cout << "Erro: Copiloto não encontrado ou não cadastrado!" << endl;
                    break;
                }

                // Cadastrar o voo se a validação for bem-sucedida
                sistema.cadastrarVoo(data, hora, origem, destino, codigoAviao,
                                     pilotoSelecionado, copilotoSelecionado, tarifa);
                break;
            }
            case 4: {
                // Código para criar reserva
                int codigoVoo, numeroAssento, codigoPassageiro;
                cout << "Código Voo: ";
                cin >> codigoVoo;
                cout << "Número Assento: ";
                cin >> numeroAssento;

                // Verificação de validade do número do assento
                if (numeroAssento < 1 || numeroAssento > 100) {
                    cout << "Erro: Número do assento inválido! Deve estar entre 1 e 100." << endl;
                    break; // Sai do case sem tentar criar a reserva
                }

                cout << "Código Passageiro: ";
                cin >> codigoPassageiro;


                // Verificar se o passageiro existe antes de criar a reserva
                Passageiro* passageiro = nullptr;

                // Recuperando os passageiros cadastrados
                const vector<Passageiro>& passageiros = sistema.getPassageiros();

                // Procurando pelo passageiro pelo código
                for (auto& p : passageiros) {
                    if (p.getCodigo() == codigoPassageiro) {
                        passageiro = const_cast<Passageiro*>(&p); // Convertendo const para permitir modificação
                        break;
                    }
                }

                if (passageiro == nullptr) {
                    cout << "Erro: Passageiro com código " << codigoPassageiro << " não encontrado!" << endl;
                    break;  // Sai do case sem tentar criar a reserva
                }

                // Criar a reserva
                sistema.criarReserva(codigoVoo, numeroAssento, codigoPassageiro);

                // Adicionar 10 pontos de fidelidade ao passageiro
                passageiro->adicionarPontos(10);

                cout << "Reserva criada com sucesso! O passageiro " << passageiro->getNome()
                     << " agora tem " << passageiro->getPontosFidelidade() << " pontos de fidelidade." << endl;
                break;
            }
            case 5: {
                // Código para listar voos por passageiro
                int codigoPassageiro;
                cout << "Código Passageiro: ";
                cin >> codigoPassageiro;
                sistema.listarVoosPorPassageiro(codigoPassageiro);
                break;
            }
            case 6: {
                cout << "1. Por Nome\n";
                cout << "2. Por Código\n";
                cout << "Escolha uma opção: ";
                int escolha;
                cin >> escolha;

                if (escolha == 1) {
                    string nome;
                    cout << "Digite o nome do Passageiro: ";
                    cin.ignore();  // Limpa o buffer
                    getline(cin, nome);
                    sistema.pesquisarPassageiroPorNome(nome);
                }
                else if (escolha == 2) {
                    int codigo;
                    cout << "Digite o código do Passageiro: ";
                    cin >> codigo;
                    sistema.pesquisarPassageiroPorCodigo(codigo);
                }
                else {
                    cout << "Opção inválida.\n";
                }
                break;
            }
            case 7: {
                cout << "1. Por Nome\n";
                cout << "2. Por Código\n";
                cout << "Escolha uma opção: ";
                int escolha;
                cin >> escolha;

                if (escolha == 1) {
                    string nome;
                    cout << "Digite o nome do Tripulante: ";
                    cin.ignore();  // Limpa o buffer
                    getline(cin, nome);
                    sistema.pesquisarTripulantePorNome(nome);
                } else if (escolha == 2) {
                    int codigo;
                    cout << "Digite o código do Tripulante: ";
                    cin >> codigo;
                    sistema.pesquisarTripulantePorCodigo(codigo);
                } else {
                    cout << "Opção inválida.\n";
                }
                break;
            }
            case 8: {
                // Código para mostrar os pontos de fidelidade de um passageiro
                int codigoPassageiro;
                cout << "Código do Passageiro: ";
                cin >> codigoPassageiro;

                // Verificar se o passageiro existe
                const auto& passageiros = sistema.getPassageiros();  // Supondo que exista esse método
                bool passageiroEncontrado = false;

                for (const auto& passageiro : passageiros) {
                    if (passageiro.getCodigo() == codigoPassageiro) {
                        passageiroEncontrado = true;
                        cout << "Passageiro: " << passageiro.getNome() << endl;
                        cout << "Pontos de Fidelidade: " << passageiro.getPontosFidelidade() << endl;
                        break;
                    }
                }

                if (!passageiroEncontrado) {
                    cout << "Erro: Passageiro com código " << codigoPassageiro << " não encontrado!" << endl;
                }
                break;
            }
            case 9: {
                // Cancelar a reserva
                int codigoVoo, numeroAssento;
                cout << "Código do Voo: ";
                cin >> codigoVoo;
                cout << "Número do Assento: ";
                cin >> numeroAssento;

                // Chamar o método cancelarReserva
                if (sistema.cancelarReserva(codigoVoo, numeroAssento)) {
                    cout << "Reserva cancelada com sucesso!\n";
                }
                break;
            }
            case 10:
                // Salvar dados antes de sair
                sistema.salvarSistema("sistema.txt");
                cout << "Dados salvos. Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 10);

    return 0;
}

