#include "assento.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>

using namespace std;

vector<Assento> assentos;  

Assento::Assento(int codigoVoo, int numeroAssento)
    : codigoVoo(codigoVoo), numeroAssento(numeroAssento), status(true) {}

int Assento::getCodigoVoo() const {
    return codigoVoo;
}

int Assento::getNumeroAssento() const {
    return numeroAssento;
}

bool Assento::getStatus() const {
    return status;  // True para livre, false para ocupado
}

bool Assento::reservarAssento() {
    if (status) {
        status = false;  // O assento foi reservado
        return true;
    }
    return false;  // O assento já está ocupado
}

// Inicializa os assentos de 0 a 60 para o voo com o código especificado
void Assento::inicializarAssentos(int codigoVoo) {
    for (int i = 0; i <= 60; ++i) {
        Assento novoAssento(codigoVoo, i);
        assentos.push_back(novoAssento);
    }
}

// Busca um assento específico do voo e retorna o objeto do assento
Assento Assento::buscarAssento(int codigoVoo, int numeroAssento) {
    for (const auto& assento : assentos) {
        if (assento.getCodigoVoo() == codigoVoo && assento.getNumeroAssento() == numeroAssento) {
            return assento;
        }
    }
    throw runtime_error("Assento não encontrado.");
}

// Lista todos os assentos de um voo
void Assento::listarAssentos(int codigoVoo) {
    cout << "Assentos para o voo " << codigoVoo << ":\n";
    for (const auto& assento : assentos) {
        if (assento.getCodigoVoo() == codigoVoo) {
            cout << "Assento " << assento.getNumeroAssento() << ": "
                 << (assento.getStatus() ? "Livre" : "Ocupado") << endl;
        }
    }
}
