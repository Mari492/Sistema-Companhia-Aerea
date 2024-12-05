#include "Passageiro.h"
#include <iostream>
#include <algorithm>
#include <fstream>

Passageiro::Passageiro(int codigo, const string& nome, const string& endereco,
                       const string& telefone, bool fidelidade)
    : codigo(codigo), nome(nome), endereco(endereco), telefone(telefone),
      fidelidade(fidelidade), pontosFidelidade(0) {}

int Passageiro::getCodigo() const { return codigo; }
string Passageiro::getNome() const { return nome; }
string Passageiro::getEndereco() const { return endereco; }
string Passageiro::getTelefone() const { return telefone; }
bool Passageiro::isFidelidade() const { return fidelidade; }
int Passageiro::getPontosFidelidade() const { return pontosFidelidade; }

void Passageiro::adicionarPontos(int pontos) { pontosFidelidade += pontos; }

