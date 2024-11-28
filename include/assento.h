#include <iostream>
#include <fstream>
#include <cstring>
#include "assento.h"

using namespace std;

// Construtor da classe Assento
Assento::Assento(int numero, int codigo_voo, const string& status)
    : numero(numero), codigo_voo(codigo_voo), status(status) {}

// Getters e Setters
int Assento::getNumero() const {
    return numero;
}

void Assento::setNumero(int numero) {
    this->numero = numero;
}

int Assento::getCodigoVoo() const {
    return codigo_voo;
}

void Assento::setCodigoVoo(int codigo_voo) {
    this->codigo_voo = codigo_voo;
}

string Assento::getStatus() const {
    return status;
}

void Assento::setStatus(const string& status) {
    this->status = status;
}

// Métodos Estáticos

void Assento::cadastrarAssento(int codigo_voo, int numero) {
    ofstream arquivo("assentos.bin", ios::binary | ios::app);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de assentos." << endl;
        return;
    }

    Assento novo_assento(numero, codigo_voo, "livre");
    arquivo.write(reinterpret_cast<const char*>(&novo_assento), sizeof(Assento));
    arquivo.close();
}

void Assento::alterarStatusAssento(int codigo_voo, int numero, const string& novo_status) {
    fstream arquivo("assentos.bin", ios::binary | ios::in | ios::out);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de assentos." << endl;
        return;
    }

    Assento assento;
    while (arquivo.read(reinterpret_cast<char*>(&assento), sizeof(Assento))) {
        if (assento.getCodigoVoo() == codigo_voo && assento.getNumero() == numero) {
            assento.setStatus(novo_status);
            arquivo.seekp(-static_cast<int>(sizeof(Assento)), ios::cur);
            arquivo.write(reinterpret_cast<const char*>(&assento), sizeof(Assento));
            break;
        }
    }
    arquivo.close();
}

Assento* Assento::buscarAssento(int codigo_voo, int numero) {
    ifstream arquivo("assentos.bin", ios::binary);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de assentos." << endl;
        return nullptr;
    }

    Assento* assento_encontrado = nullptr;
    Assento assento;
    while (arquivo.read(reinterpret_cast<char*>(&assento), sizeof(Assento))) {
        if (assento.getCodigoVoo() == codigo_voo && assento.getNumero() == numero) {
            assento_encontrado = new Assento(assento.getNumero(), assento.getCodigoVoo(), assento.getStatus());
            break;
        }
    }
    arquivo.close();
    return assento_encontrado;
}

void Assento::listarAssentos(int codigo_voo) {
    ifstream arquivo("assentos.bin", ios::binary);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de assentos." << endl;
        return;
    }

    Assento assento;
    cout << "Assentos para o voo " << codigo_voo << ":\n";
    while (arquivo.read(reinterpret_cast<char*>(&assento), sizeof(Assento))) {
        if (assento.getCodigoVoo() == codigo_voo) {
            cout << "Assento " << assento.getNumero() << ": " << assento.getStatus() << endl;
        }
    }
    arquivo.close();
}
