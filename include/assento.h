#ifndef ASSENTO_H
#define ASSENTO_H

#include <vector>
#include <string>

using namespace std;

class Assento {
private:
    int codigoVoo; // Código do voo ao qual o assento pertence
    int numeroAssento; // Número do assento (1 a 60)
    bool status; // Status do assento (livre ou ocupado)
    
public:
    Assento(int codigoVoo, int numeroAssento);

    // Métodos para acessar os dados do assento
    int getCodigoVoo() const;
    int getNumeroAssento() const;
    bool getStatus() const;

    // Método para reservar o assento
    bool reservarAssento();

    // Método estático para inicializar os assentos de um voo
    static void inicializarAssentos(int codigoVoo);

    // Método estático para buscar um assento
    static Assento buscarAssento(int codigoVoo, int numeroAssento);

    // Método estático para exibir todos os assentos de um voo
    static void listarAssentos(int codigoVoo);
};

#endif

