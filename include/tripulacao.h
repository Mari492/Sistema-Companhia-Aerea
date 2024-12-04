#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <string>
using namespace std;

class Tripulacao {
private:
    int codigo;
    string nome;
    string telefone;
    string cargo;

public:
    Tripulacao(int codigo, const string& nome, const string& telefone,
               const string& cargo);

    int getCodigo() const;
    string getNome() const;
    string getTelefone() const;
    string getCargo() const;

    /* Métodos de salvar e carregar
    void salvar(ofstream& arquivo) const;
    void carregar(ifstream& arquivo);*/
};

#endif


