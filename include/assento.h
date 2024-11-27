#ifndef ASSENTO_H
#define ASSENTO_H

#include <string>

class Assento {
private:
    int numeroAssento;        // Número do assento
    std::string codigoVoo;    // Código do voo associado
    bool ocupado;             // Status do assento (ocupado ou livre)

public:
    // Construtores
    Assento();
    Assento(int numero, const std::string& codigo, bool status = false);

    // Getters e Setters
    int getNumeroAssento() const;
    void setNumeroAssento(int numero);

    std::string getCodigoVoo() const;
    void setCodigoVoo(const std::string& codigo);

    bool isOcupado() const;
    void setOcupado(bool status);

    // Outros métodos
    void reservar();
    void liberar();
    std::string statusAssento() const;

    // Destrutor
    ~Assento();
};

#endif // ASSENTO_H
