#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
using namespace std;

class Passageiro {
private:
    static int contador;
    int codigo;
    string nome;
    string endereco;
    string telefone;
    bool fidelidade;
    int pontosFidelidade;

public:
    Passageiro(string nome, string endereco, string telefone, bool fidelidade = false);

    int getCodigo() const;
    string getNome() const;
    string getEndereco() const;
    string getTelefone() const;
    bool isFidelidade() const;
    int getPontosFidelidade() const;

    void ativarFidelidade();
    void adicionarPontos(int pontos);
    void resetarPontos();

    void setNome(const string& nome);
    void setEndereco(const string& endereco);
    void setTelefone(const string& telefone);

    void exibirInformacoes() const;
};

#endif
