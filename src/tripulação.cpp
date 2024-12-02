#include "../include/tripulacao.h"

int Tripulacao::contadorCodigo = 1;
unordered_set<int> Tripulacao::codigos;

Tripulacao::Tripulacao(string nome, string cargo, string telefone) : nome(nome), cargo(cargo), telefone(telefone) {
    // Garante que o código gerado é único
    while (codigos.find(contadorCodigo) != codigos.end())
    {
        contadorCodigo++;
    }
    codigo = contadorCodigo++;
    codigos.insert(codigo);
}

int Tripulacao::getCodigo() const { return codigo; }
string Tripulacao::getNome() const { return nome; }
string Tripulacao::getCargo() const { return cargo; }
string Tripulacao::getTelefone() const { return telefone; }

void Tripulacao::setNome(const string& novoNome) { nome = novoNome; }
void Tripulacao::setCargo(const string& novoCargo) { cargo = novoCargo; }
void Tripulacao::setTelefone(const string& novoTelefone) { telefone = novoTelefone; }

void Tripulacao::exibirInformacoes() const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "Telefone: " << telefone << endl;
}

Tripulacao::~Tripulacao() {
    codigos.erase(codigo); // Remove o código do conjunto
}
