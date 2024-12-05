#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
using namespace std;

class Passageiro {
private:
    int codigo;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontosFidelidade;

public:
    Passageiro(int codigo, const string& nome, const string& endereco,
               const string& telefone, bool fidelidade = false);

    int getCodigo() const;
    string getNome() const;
    string getEndereco() const;
    string getTelefone() const;
    bool isFidelidade() const;
    int getPontosFidelidade() const;

    void adicionarPontos(int pontos);

};

#endif


