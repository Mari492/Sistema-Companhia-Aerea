#include "../include/tripulacao.h"

int Tripulacao::contadorCodigo = 1;
unordered_set<int> Tripulacao::codigos;

Tripulacao::Tripulacao(string nome, string cargo, string telefone) : nome(nome), cargo(cargo), telefone(telefone) {
    // Garante que o c�digo gerado � �nico
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

// M�todos est�ticos
bool Tripulacao::validarCodigo(int codigo) {
    return codigos.find(codigo) != codigos.end();
}

void Tripulacao::adicionarCodigo(int codigo) {
    codigos.insert(codigo);
}

void Tripulacao::removerCodigo(int codigo) {
    codigos.erase(codigo);
}

Tripulacao::~Tripulacao() {
    codigos.erase(codigo); // Remove o c�digo do conjunto
}
