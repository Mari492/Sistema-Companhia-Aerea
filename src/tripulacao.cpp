#include "Tripulacao.h"

Tripulacao::Tripulacao(int codigo, const string& nome, const string& telefone,
                       const string& cargo)
    : codigo(codigo), nome(nome), telefone(telefone), cargo(cargo) {}

int Tripulacao::getCodigo() const { return codigo; }
string Tripulacao::getNome() const { return nome; }
string Tripulacao::getTelefone() const { return telefone; }
string Tripulacao::getCargo() const { return cargo; }

/*void Tripulacao::salvar(ofstream& arquivo) const {
    arquivo << codigo << ";"
            << nome << ";"
            << telefone << ";"
            << cargo << endl;
}

void Tripulacao::carregar(ifstream& arquivo) {
    string linha;
    if (getline(arquivo, linha)) {
        stringstream ss(linha);
        string temp;

        getline(ss, temp, ';');
        codigo = stoi(temp);

        getline(ss, nome, ';');
        getline(ss, telefone, ';');
        getline(ss, cargo, ';');
    }
}*/
