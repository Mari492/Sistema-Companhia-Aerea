#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Função para formatar a data e hora
string obterDataHoraAtual() {
    time_t agora = time(0);
    tm *ltm = localtime(&agora);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
       << " " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min;
    return ss.str();
}

// Classe que representa um tripulante (piloto, copiloto ou comissário)
class Tripulante {
public:
    string codigo;
    string nome;
    string cargo;

    Tripulante(string c, string n, string ca) : codigo(c), nome(n), cargo(ca) {}
};

// Classe que representa um passageiro
class Passageiro {
public:
    string nome;
    string cpf;
    bool pago;

    Passageiro(string n, string c, bool p) : nome(n), cpf(c), pago(p) {}
};

// Classe que representa um voo
class Voo {
public:
    string codigoVoo;
    string dataVoo;
    string horaVoo;
    string origem;
    string destino;
    string codigoAviao;
    string status; // "Ativo" ou "Inativo"
    double tarifa;
    vector<Tripulante> tripulacao;
    vector<Passageiro> passageiros;

    Voo(string cv, string d, string h, string o, string des, string ca, double t)
        : codigoVoo(cv), dataVoo(d), horaVoo(h), origem(o), destino(des), codigoAviao(ca), tarifa(t), status("Inativo") {}

    // Função para adicionar tripulantes
    void adicionarTripulante(Tripulante t) {
        tripulacao.push_back(t);
    }

    // Função para adicionar passageiros
    void adicionarPassageiro(Passageiro p) {
        passageiros.push_back(p);
    }

    // Função para ativar o voo
    bool ativarVoo() {
        bool temPiloto = false;
        bool temCopiloto = false;

        // Verificar a presença de um piloto e copiloto
        for (auto& t : tripulacao) {
            if (t.cargo == "Piloto") temPiloto = true;
            if (t.cargo == "Copiloto") temCopiloto = true;
        }

        // Se houver um piloto e um copiloto, o voo é ativado
        if (temPiloto && temCopiloto) {
            status = "Ativo";
            cout << "Voo " << codigoVoo << " ativado com sucesso!" << endl;
            return true;
        } else {
            cout << "Erro: É necessario pelo menos um piloto e um copiloto para ativar o voo." << endl;
            return false;
        }
    }

    // Função para exibir informações do voo
    void exibirInformacoes() {
        cout << "Codigo do Voo: " << codigoVoo << endl;
        cout << "Data do Voo: " << dataVoo << " | Hora: " << horaVoo << endl;
        cout << "Origem: " << origem << " | Destino: " << destino << endl;
        cout << "Código do Avião: " << codigoAviao << endl;
        cout << "Status: " << status << endl;
        cout << "Tarifa: R$ " << tarifa << endl;

        // Exibir tripulação
        cout << "Tripulação:" << endl;
        for (auto& t : tripulacao) {
            cout << t.cargo << ": " << t.nome << " (Codigo: " << t.codigo << ")" << endl;
        }

        // Exibir passageiros
        cout << "Passageiros:" << endl;
        for (auto& p : passageiros) {
            cout << "Nome: " << p.nome << " | CPF: " << p.cpf << " | Pago: " << (p.pago ? "Sim" : "Não") << endl;
        }
    }
};

// Classe que representa uma reserva
class Reserva {
public:
    Passageiro passageiro;
    Voo* voo;

    Reserva(Passageiro p, Voo* v) : passageiro(p), voo(v) {}

    // Realiza a reserva
    void realizarReserva() {
        if (voo->status == "Ativo") {
            voo->adicionarPassageiro(passageiro);
            cout << "Reserva realizada com sucesso para " << passageiro.nome << " no voo " << voo->codigoVoo << endl;
        } else {
            cout << "Erro: O voo não está ativo. Nao a reserva." << endl;
        }
    }
};

int main() {
    // Criando alguns tripulantes
    Tripulante piloto("P001", "Carlos Silva", "Piloto");
    Tripulante copiloto("C001", "Ana Souza", "Copiloto");
    Tripulante comissario("CM001", "Mariana Costa", "Comissário");

    // Criando um voo
    Voo voo1("1234", "2024-11-30", "14:30", "São Paulo", "Rio de Janeiro", "A001", 350.50);

    // Adicionando tripulantes ao voo
    voo1.adicionarTripulante(piloto);
    voo1.adicionarTripulante(copiloto);
    voo1.adicionarTripulante(comissario);

    // Tentar ativar o voo (deve ser possível porque temos piloto e copiloto)
    voo1.ativarVoo();

    // Criando alguns passageiros
    Passageiro p1("Joao Oliveira", "123.456.789-00", true);
    Passageiro p2("Maria Santos", "987.654.321-00", false);

    // Realizando as reservas
    Reserva reserva1(p1, &voo1);
    reserva1.realizarReserva();

    Reserva reserva2(p2, &voo1);
    reserva2.realizarReserva();

    // Exibindo informações do voo
    voo1.exibirInformacoes();

    // Criando outro voo sem piloto
    Voo voo2("5678", "2024-12-01", "08:00", "Rio de Janeiro", "Brasília", "A002", 500.00);

    // Adicionando tripulantes (sem piloto)
    voo2.adicionarTripulante(copiloto);
    voo2.adicionarTripulante(comissario);

    // Tentar ativar o voo (não vai funcionar porque falta um piloto)
    voo2.ativarVoo();

    // Pausa o programa até que o usuário pressione Enter
    cin.get();

    return 0;
}
