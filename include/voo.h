#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Tripulacao.h"
using namespace std;

class Voo {
private:
    int codigo;
    string data;
    string hora;
    string origem;
    string destino;
    string codigoAviao;
    Tripulacao piloto;
    Tripulacao copiloto;
    vector<Tripulacao> comissarios;
    bool ativo;
    double tarifa;
    vector<int> assentos; // Assentos representados como inteiros (-1 para livre, 1 para ocupado)

public:
    // Construtor
    Voo(int codigo, const string& data, const string& hora,
        const string& origem, const string& destino, const string& codigoAviao,
        Tripulacao piloto, Tripulacao copiloto, double tarifa, int numAssentos);

    // M�todos getters
    int getCodigo() const;
    string getOrigem() const;
    string getDestino() const;
    bool isAtivo() const;

    // M�todos para ativar/desativar o voo
    void ativar();
    void desativar();

    // Verifica se o assento est� dispon�vel
    bool verificarAssentoDisponivel(int numeroAssento) const;

    // Ocupa um assento
    void ocuparAssento(int numeroAssento);

    // Libera um assento
    void liberarAssento(int numeroAssento);

    /* M�todos de salvar e carregar
    void salvar(ofstream& arquivo) const;
    void carregar(ifstream& arquivo);*/
};

#endif

