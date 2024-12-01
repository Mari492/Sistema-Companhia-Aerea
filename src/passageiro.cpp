#include "../include/passageiro.h"
#include <iostream>
using namespace std;

int Passageiro::contador = 0;

Passageiro::Passageiro(string nome, string endereco, string telefone, bool fidelidade)
    : nome(nome), endereco(endereco), telefone(telefone), fidelidade(fidelidade), pontosFidelidade(0)
    {
        contador++;
        codigo = contador;

    }

int Passageiro::getCodigo() const { return codigo; }
string Passageiro::getNome() const { return nome; }
string Passageiro::getEndereco() const { return endereco; }
string Passageiro::getTelefone() const { return telefone; }
bool Passageiro::isFidelidade() const { return fidelidade; }
int Passageiro::getPontosFidelidade() const { return pontosFidelidade; }


void Passageiro::setNome(const string& novoNome) { nome = novoNome; }
void Passageiro::setEndereco(const string& novoEndereco) { endereco = novoEndereco; }
void Passageiro::setTelefone(const string& novoTelefone) { telefone = novoTelefone; }

void Passageiro::ativarFidelidade(){
    fidelidade = true;
}

void Passageiro::adicionarPontos(int pontos) {
    if (fidelidade) {
        pontosFidelidade += pontos;
    }
    else {
        cout << "Passageiro nao faz parte do programa de fidelidade. Pontos nao adicionados." << endl;
    }
}

void Passageiro::resetarPontos() {
    pontosFidelidade = 0;
}


void Passageiro::exibirInformacoes() const {
    cout << "Passageiro: " << nome << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Fidelidade: " << (fidelidade ? "Sim" : "Nao") << endl;
    cout << "Pontos de Fidelidade: " << pontosFidelidade << endl;
}
