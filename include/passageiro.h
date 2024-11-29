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

public:
    Passageiro(int codigo, string nome, string endereco, string telefone);

    int getCodigo() const;
    string getNome() const;
    string getEndereco() const;
    string getTelefone() const;

    void setNome(const string& nome);
    void setEndereco(const string& endereco);
    void setTelefone(const string& telefone);

    void exibirInformacoes() const;
};

#endif
