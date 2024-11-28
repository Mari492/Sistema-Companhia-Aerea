#include "../include/passageiro.h"
#include <iostream>
using namespace std;


Passageiro::Passageiro(int codigo, string nome, string endereco, string telefone)
    : codigo(codigo), nome(nome), endereco(endereco), telefone(telefone) {}

int Passageiro::getCodigo() const { return codigo; }
string Passageiro::getNome() const { return nome; }
string Passageiro::getEndereco() const { return endereco; }
string Passageiro::getTelefone() const { return telefone; }

void Passageiro::setNome(const string& novoNome) { nome = novoNome; }
void Passageiro::setEndereco(const string& novoEndereco) { endereco = novoEndereco; }
void Passageiro::setTelefone(const string& novoTelefone) { telefone = novoTelefone; }

void Passageiro::exibirInformacoes() const {
    cout << "Passageiro: " << nome << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Telefone: " << telefone << endl;
}
