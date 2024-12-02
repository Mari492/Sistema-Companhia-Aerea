#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Tripulacao {
private:
    static int contadorCodigo;
    static unordered_set<int> codigos;
    int codigo;
    string nome;
    string cargo;
    string telefone;

public:
    Tripulacao(string nome, string cargo, string telefone);

    int getCodigo() const;
    string getNome() const;
    string getCargo() const;
    string getTelefone() const;

    void setNome(const string& nome);
    void setCargo(const string& cargo);
    void setTelefone(const string& telefone);

    void exibirInformacoes() const;

    //M�todos est�ticos para acesso aos membros est�ticos (outras classes poderem acessar)
    static bool validarCodigo(int codigo);
    static void adicionarCodigo(int codigo);
    static void removerCodigo(int codigo);

    ~Tripulacao(); // Libera o c�digo do membro ao ser excluido
};

#endif
