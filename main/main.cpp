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
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                // C�digo para cadastrar passageiro
                string nome, endereco, telefone;
                bool fidelidade;
                cout << "Nome: ";
                cin.ignore();  // Limpa o buffer
                getline(cin, nome);
                cout << "Endere�o: ";
                getline(cin, endereco);
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Fidelidade (1-Sim, 0-N�o): ";
                cin >> fidelidade;

                sistema.cadastrarPassageiro(nome, endereco, telefone, fidelidade);
                break;
            }
            case 2: {
                // C�digo para cadastrar tripulante
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
                // C�digo para cadastrar voo
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
                cout << "C�digo Avi�o: ";
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
                    cout << "Erro: Piloto n�o encontrado ou n�o cadastrado!" << endl;
                    break;
                }

                if (copilotoSelecionado.getNome().empty()) {
                    cout << "Erro: Copiloto n�o encontrado ou n�o cadastrado!" << endl;
                    break;
                }

                // Cadastrar o voo se a valida��o for bem-sucedida
                sistema.cadastrarVoo(data, hora, origem, destino, codigoAviao,
                                     pilotoSelecionado, copilotoSelecionado, tarifa);
                break;
            }
            case 4: {
                // C�digo para criar reserva
                int codigoVoo, numeroAssento, codigoPassageiro;
                cout << "C�digo Voo: ";
                cin >> codigoVoo;
                cout << "N�mero Assento: ";
                cin >> numeroAssento;

                // Verifica��o de validade do n�mero do assento
                if (numeroAssento < 1 || numeroAssento > 100) {
                    cout << "Erro: N�mero do assento inv�lido! Deve estar entre 1 e 100." << endl;
                    break; // Sai do case sem tentar criar a reserva
                }

                cout << "C�digo Passageiro: ";
                cin >> codigoPassageiro;


                // Verificar se o passageiro existe antes de criar a reserva
                Passageiro* passageiro = nullptr;

                // Recuperando os passageiros cadastrados
                const vector<Passageiro>& passageiros = sistema.getPassageiros();

                // Procurando pelo passageiro pelo c�digo
                for (auto& p : passageiros) {
                    if (p.getCodigo() == codigoPassageiro) {
                        passageiro = const_cast<Passageiro*>(&p); // Convertendo const para permitir modifica��o
                        break;
                    }
                }

                if (passageiro == nullptr) {
                    cout << "Erro: Passageiro com c�digo " << codigoPassageiro << " n�o encontrado!" << endl;
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
                // C�digo para listar voos por passageiro
                int codigoPassageiro;
                cout << "C�digo Passageiro: ";
                cin >> codigoPassageiro;
                sistema.listarVoosPorPassageiro(codigoPassageiro);
                break;
            }
            case 6: {
                cout << "1. Por Nome\n";
                cout << "2. Por C�digo\n";
                cout << "Escolha uma op��o: ";
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
                    cout << "Digite o c�digo do Passageiro: ";
                    cin >> codigo;
                    sistema.pesquisarPassageiroPorCodigo(codigo);
                }
                else {
                    cout << "Op��o inv�lida.\n";
                }
                break;
            }
            case 7: {
                cout << "1. Por Nome\n";
                cout << "2. Por C�digo\n";
                cout << "Escolha uma op��o: ";
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
                    cout << "Digite o c�digo do Tripulante: ";
                    cin >> codigo;
                    sistema.pesquisarTripulantePorCodigo(codigo);
                } else {
                    cout << "Op��o inv�lida.\n";
                }
                break;
            }
            case 8: {
                // C�digo para mostrar os pontos de fidelidade de um passageiro
                int codigoPassageiro;
                cout << "C�digo do Passageiro: ";
                cin >> codigoPassageiro;

                // Verificar se o passageiro existe
                const auto& passageiros = sistema.getPassageiros();  // Supondo que exista esse m�todo
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
                    cout << "Erro: Passageiro com c�digo " << codigoPassageiro << " n�o encontrado!" << endl;
                }
                break;
            }
            case 9: {
                // Cancelar a reserva
                int codigoVoo, numeroAssento;
                cout << "C�digo do Voo: ";
                cin >> codigoVoo;
                cout << "N�mero do Assento: ";
                cin >> numeroAssento;

                // Chamar o m�todo cancelarReserva
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
                cout << "Op��o inv�lida!\n";
        }
    } while (opcao != 10);

    return 0;
}

