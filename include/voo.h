#ifndef VOOSSEGURO_H
#define VOOSSEGURO_H

#include <string>
#include <vector>
using namespace std;

// Classe que representa um tripulante (piloto, copiloto ou comissário)
class Tripulante {
private:
    string codigo;
    string nome;
    string cargo;

public:
    // Construtor
    Tripulante(string c, string n, string ca);

    // Métodos de acesso (getters)
    string getCodigo();
    string getNome();
    string getCargo();
};

// Classe que representa um passageiro
class Passageiro {
private:
    string nome;
    string cpf;
    bool pago;

public:
    // Construtor
    Passageiro(string n, string c, bool p);

    // Métodos de acesso
    string getNome();
    string getCpf();
    bool isPago();
};

// Classe que representa um voo
class Voo {
private:
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

public:
    // Construtor
    Voo(string cv, string d, string h, string o, string des, string ca, double t);

    // Funções para adicionar tripulantes e passageiros
    void adicionarTripulante(Tripulante t);
    void adicionarPassageiro(Passageiro p);

    // Função para ativar o voo
    bool ativarVoo();

    // Função para exibir informações do voo
    void exibirInformacoes();

    // Função para obter o código do voo
    string getCodigoVoo();
};

// Classe que representa uma reserva
class Reserva {
private:
    Passageiro passageiro;
    Voo* voo;

public:
    // Construtor
    Reserva(Passageiro p, Voo* v);

    // Realiza a reserva
    void realizarReserva();
};

#endif // VOOSSEGURO_H
''
