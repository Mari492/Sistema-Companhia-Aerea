#include "Voo.h"
#include <iostream>

using namespace std;

// Construtor
Voo::Voo(int codigo, const string& data, const string& hora,
         const string& origem, const string& destino, const string& codigoAviao,
         Tripulacao piloto, Tripulacao copiloto, double tarifa, int numAssentos)
    : codigo(codigo), data(data), hora(hora), origem(origem), destino(destino),
      codigoAviao(codigoAviao), piloto(piloto), copiloto(copiloto), tarifa(tarifa), ativo(true) {
    assentos.resize(numAssentos, -1); // -1 indica que o assento est� livre
}


// M�todos getters
int Voo::getCodigo() const {
    return codigo;
}

string Voo::getOrigem() const {
    return origem;
}

string Voo::getDestino() const {
    return destino;
}

bool Voo::isAtivo() const {
    return ativo;
}

// M�todos para ativar/desativar o voo
void Voo::ativar() {
    ativo = true;
}

void Voo::desativar() {
    ativo = false;
}

// Verificar se o assento est� dispon�vel
bool Voo::verificarAssentoDisponivel(int numeroAssento) const {
    return numeroAssento >= 0 && numeroAssento < assentos.size() && assentos[numeroAssento] == -1;
}

// Ocupa o assento (marcando como ocupado)
void Voo::ocuparAssento(int numeroAssento) {
    if (numeroAssento >= 0 && numeroAssento < assentos.size() && assentos[numeroAssento] == -1) {
        assentos[numeroAssento] = 1; // Marca o assento como ocupado
        cout << "Assento " << numeroAssento << " ocupado com sucesso.\n";
    } else {
        cout << "N�mero de assento inv�lido ou j� ocupado.\n";
    }
}

// Libera o assento (marcando como livre)
void Voo::liberarAssento(int numeroAssento) {
    if (numeroAssento >= 0 && numeroAssento < assentos.size()) {
        assentos[numeroAssento] = -1; // Marca o assento como livre
        cout << "Assento " << numeroAssento << " liberado com sucesso.\n";
    } else {
        cout << "Assento n�o encontrado no voo.\n";
    }
}

/*void Voo::salvar(ofstream& arquivo) const {
    arquivo << codigo << ";"
            << data << ";"
            << hora << ";"
            << origem << ";"
            << destino << ";"
            << codigoAviao << ";"
            << piloto.getCodigo() << ";"
            << copiloto.getCodigo() << ";"
            << tarifa << ";"
            << numAssentos << endl;
}

void Voo::carregar(ifstream& arquivo) {
    string linha;
    if (getline(arquivo, linha)) {
        stringstream ss(linha);
        string temp;

        getline(ss, temp, ';');
        codigo = stoi(temp);

        getline(ss, data, ';');
        getline(ss, hora, ';');
        getline(ss, origem, ';');
        getline(ss, destino, ';');
        getline(ss, codigoAviao, ';');

        getline(ss, temp, ';');
        int codigoPiloto = stoi(temp);
        piloto.setCodigo(codigoPiloto);

        getline(ss, temp, ';');
        int codigoCopiloto = stoi(temp);
        copiloto.setCodigo(codigoCopiloto);

        getline(ss, temp, ';');
        tarifa = stod(temp);

        getline(ss, temp, ';');
        numAssentos = stoi(temp);
    }
}*/
