#ifndef ASSENTO_H
#define ASSENTO_H

using namespace std;

class Assento {
private:
    int numero;
    int codigoVoo;
    bool ocupado;

public:
    Assento();
    Assento(int num, int codVoo);

    int getNumero() const;
    bool estaOcupado() const;
    void ocupar();
    void liberar();
};

#endif
