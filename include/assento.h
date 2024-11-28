
#ifndef ASSENTO_H
#define ASSENTO_H

#include <string>

class Assento {
private:
    int numero;             // Número do assento
    int codigo_voo;         // Código do voo a que o assento pertence
    std::string status;     // Status do assento: "ocupado" ou "livre"

public:
    // Construtor
    Assento(int numero = 0, int codigo_voo = 0, const std::string& status = "livre");

    // Métodos getters e setters
    int getNumero() const;
    void setNumero(int numero);

    int getCodigoVoo() const;
    void setCodigoVoo(int codigo_voo);

    std::string getStatus() const;
    void setStatus(const std::string& status);

    // Métodos de manipulação
    static void cadastrarAssento(int codigo_voo, int numero);
    static void alterarStatusAssento(int codigo_voo, int numero, const std::string& novo_status);
    static Assento* buscarAssento(int codigo_voo, int numero);
    static void listarAssentos(int codigo_voo);
};

#endif
