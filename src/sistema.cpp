#include "Sistema.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Construtor para inicializar os códigos automáticos
Sistema::Sistema()
    : proximoCodigoPassageiro(1), proximoCodigoTripulante(1), proximoCodigoVoo(1) {}

// Cadastrar um novo passageiro
void Sistema::cadastrarPassageiro(const string& nome, const string& endereco,
                                  const string& telefone, bool fidelidade) {
    Passageiro novoPassageiro(proximoCodigoPassageiro++, nome, endereco, telefone, fidelidade);
    passageiros.push_back(novoPassageiro);
    cout << "Passageiro cadastrado com código: " << novoPassageiro.getCodigo() << endl;
}

// Cadastrar tripulante
void Sistema::cadastrarTripulante(const string& nome, const string& telefone,
                                  const string& cargo) {
    Tripulacao novoTripulante(proximoCodigoTripulante++, nome, telefone, cargo);
    tripulantes.push_back(novoTripulante);
    cout << "Tripulante cadastrado com código: " << novoTripulante.getCodigo() << endl;
}

// Cadastrar voo
void Sistema::cadastrarVoo(const string& data, const string& hora,
                           const string& origem, const string& destino,
                           const string& codigoAviao, const Tripulacao& piloto,
                           const Tripulacao& copiloto, double tarifa) {
    const int numAssentos = 100;  // Definindo um número padrão de assentos
    Voo novoVoo(proximoCodigoVoo++, data, hora, origem, destino, codigoAviao, piloto, copiloto, tarifa, numAssentos);
    voos.push_back(novoVoo);
    cout << "Voo cadastrado com código: " << novoVoo.getCodigo() << endl;
}

// Criar reserva
void Sistema::criarReserva(int codigoVoo, int numeroAssento, int codigoPassageiro) {
    auto vooIt = find_if(voos.begin(), voos.end(), [&](const Voo& v) {
        return v.getCodigo() == codigoVoo;
    });

    if (vooIt != voos.end() && vooIt->isAtivo()) {
        // Verificar se o assento já está reservado
        auto reservaIt = find_if(reservas.begin(), reservas.end(), [&](const Reserva& r) {
            return r.getCodigoVoo() == codigoVoo && r.getNumeroAssento() == numeroAssento;
        });

        if (reservaIt == reservas.end()) { // Assento está livre
            reservas.emplace_back(codigoVoo, numeroAssento, codigoPassageiro);
            cout << "Reserva criada com sucesso!" << endl;
        } else { // Assento já reservado
            cout << "Erro: Assento já reservado para este voo!" << endl;
        }
    } else {
        cout << "Voo não encontrado ou inativo!" << endl;
    }
}

// Cancelar reserva e liberar o assento
bool Sistema::cancelarReserva(int codigoVoo, int numeroAssento) {
    for (auto it = reservas.begin(); it != reservas.end(); ++it) {
        if (it->getCodigoVoo() == codigoVoo && it->getNumeroAssento() == numeroAssento) {
            // Liberar o assento no voo correspondente
            for (auto& voo : voos) {
                if (voo.getCodigo() == codigoVoo) {
                    voo.liberarAssento(numeroAssento);
                    break;
                }
            }

            // Remover a reserva do vetor
            reservas.erase(it);
            cout << "Reserva cancelada com sucesso!\n";
            return true;
        }
    }

    cout << "Reserva não encontrada.\n";
    return false;
}


// Listar voos por passageiro
void Sistema::listarVoosPorPassageiro(int codigoPassageiro) const {
    for (const auto& reserva : reservas) {
        if (reserva.getCodigoPassageiro() == codigoPassageiro) {
            cout << "Voo: " << reserva.getCodigoVoo() << ", Assento: "
                 << reserva.getNumeroAssento() << endl;
        }
    }
}

// Pesquisar passageiro por nome
void Sistema::pesquisarPassageiroPorNome(const string& nome) const {
    for (const auto& passageiro : passageiros) {
        if (passageiro.getNome() == nome) {
            cout << "Código: " << passageiro.getCodigo() << ", Nome: " << passageiro.getNome()
                 << ", Fidelidade: " << (passageiro.isFidelidade() ? "Sim" : "Não") << endl;
        }
    }
}

// Pesquisar passageiro por codigo
void Sistema::pesquisarPassageiroPorCodigo(int codigoPassageiro) const {
    for (const auto& passageiro : passageiros) {
        if (passageiro.getCodigo() == codigoPassageiro) {
            cout << "Código: " << passageiro.getCodigo() << ", Nome: " << passageiro.getNome()
                 << ", Fidelidade: " << (passageiro.isFidelidade() ? "Sim" : "Não") << endl;
        }
    }
}

// Pesquisar tripulante por nome
void Sistema::pesquisarTripulantePorNome(const string& nome) const {
    for (const auto& tripulante : tripulantes) {
        if (tripulante.getNome() == nome) {
            cout << "Código: " << tripulante.getCodigo() << ", Nome: " << tripulante.getNome()
                 << ", Cargo: " << tripulante.getCargo() << endl;
        }
    }
}

// Pesquisar tripulante por codigo
void Sistema::pesquisarTripulantePorCodigo(int codigoTripulante) const {
    for (const auto& tripulante : tripulantes) {
        if (tripulante.getCodigo() == codigoTripulante) {
            cout << "Código: " << tripulante.getCodigo() << ", Nome: " << tripulante.getNome()
                 << ", Cargo: " << tripulante.getCargo() << endl;
        }
    }
}

//Salvar todas as informações no arquivo de texto
void Sistema::salvarSistema(const string& arquivo) const {
    ofstream outFile(arquivo);
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo para salvar.\n";
        return;
    }

    // Salvar passageiros
    outFile << passageiros.size() << endl;
    for (const auto& p : passageiros) {
        outFile << p.getCodigo() << " " << p.getNome() << " "
                << p.getEndereco() << " " << p.getTelefone() << " "
                << p.isFidelidade() << " " << p.getPontosFidelidade() << endl;
    }

    // Salvar tripulantes
    outFile << tripulantes.size() << endl;
    for (const auto& t : tripulantes) {
        outFile << t.getCodigo() << " " << t.getNome() << " "
                << t.getTelefone() << " " << t.getCargo() << endl;
    }

    // Salvar voos
    outFile << voos.size() << endl;
    for (const auto& v : voos) {
        outFile << v.getCodigo() << " " << v.getOrigem() << " "
                << v.getDestino() << " " << (v.isAtivo() ? 1 : 0) << endl;
    }

    // Salvar reservas
    outFile << reservas.size() << endl;
    for (const auto& r : reservas) {
        outFile << r.getCodigoVoo() << " " << r.getNumeroAssento() << " "
                << r.getCodigoPassageiro() << endl;
    }

    outFile.close();
    cout << "Sistema salvo com sucesso.\n";
}


// Carregar todas as informações do arquivo de texto
void Sistema::carregarSistema(const string& arquivo) {
    ifstream inFile(arquivo);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo para carregar.\n";
        return;
    }

    passageiros.clear();
    tripulantes.clear();
    voos.clear();
    reservas.clear();

    int qtd;

    // Carregar passageiros
    inFile >> qtd;
    for (int i = 0; i < qtd; ++i) {
        int codigo;
        string nome, endereco, telefone;
        bool fidelidade;
        int pontosFidelidade;

        inFile >> codigo >> nome >> endereco >> telefone >> fidelidade >> pontosFidelidade;
        passageiros.emplace_back(codigo, nome, endereco, telefone, fidelidade);
    }

    // Carregar tripulantes
    inFile >> qtd;
    for (int i = 0; i < qtd; ++i) {
        int codigo;
        string nome, telefone, cargo;

        inFile >> codigo >> nome >> telefone >> cargo;
        tripulantes.emplace_back(codigo, nome, telefone, cargo);
    }

    // Carregar voos
    inFile >> qtd;
    for (int i = 0; i < qtd; ++i) {
        int codigo;
        string origem, destino;
        bool ativo;

        inFile >> codigo >> origem >> destino >> ativo;

        // Apenas atributos necessários para inicializar voos fictícios
        voos.emplace_back(codigo, "", "", origem, destino, "", Tripulacao(0, "", "", ""), Tripulacao(0, "", "", ""), 0.0, 100);
        if (ativo) voos.back().ativar();
    }

    // Carregar reservas
    inFile >> qtd;
    for (int i = 0; i < qtd; ++i) {
        int codigoVoo, numeroAssento, codigoPassageiro;

        inFile >> codigoVoo >> numeroAssento >> codigoPassageiro;
        reservas.emplace_back(codigoVoo, numeroAssento, codigoPassageiro);
    }

    inFile.close();
    cout << "Sistema carregado com sucesso.\n";
}
