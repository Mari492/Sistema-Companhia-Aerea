#include "Reserva.h"
#include <sstream>

using namespace std;

Reserva::Reserva(int codigoVoo, int numeroAssento, int codigoPassageiro)
    : codigoVoo(codigoVoo), numeroAssento(numeroAssento), codigoPassageiro(codigoPassageiro) {}

int Reserva::getCodigoVoo() const { return codigoVoo; }
int Reserva::getNumeroAssento() const { return numeroAssento; }
int Reserva::getCodigoPassageiro() const { return codigoPassageiro; }

/*void Reserva::salvar(ofstream& arquivo) const {
    arquivo << codigoPassageiro << ";"
            << numeroAssento << ";"
            << codigoVoo << ";"
            << confirmada << endl;
}

void Reserva::carregar(ifstream& arquivo) {
    string linha;
    if (getline(arquivo, linha)) {
        stringstream ss(linha);
        string temp;

        getline(ss, temp, ';');
        codigoPassageiro = stoi(temp);

        getline(ss, temp, ';');
        numeroAssento = stoi(temp);

        getline(ss, temp, ';');
        codigoVoo = stoi(temp);

        getline(ss, temp, ';');
        confirmada = stoi(temp);
    }
}*/

