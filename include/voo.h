#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include <stdexcept>
#include "../include/tripulacao.h"

using namespace std;

class Voo {
private:
    int codigo;
    string data;
    string hora;
    string origem;
    string destino;
    int codigoAviao;
    int codigoPiloto;
    int codigoCopiloto;
    vector<int> codigoComissarios;
    bool status;
    double tarifa;

    // Método para validar tripulação mínima
    bool validarTripulacao() const;

public:
    Voo(int codigo, string data, string hora, string origem, string destino,
        int codigoAviao, int codigoPiloto, int codigoCopiloto,
        vector<int> codigoComissarios, double tarifa);

    int getCodigo() const;
    string getData() const;
    string getHora() const;
    string getOrigem() const;
    string getDestino() const;
    int getCodigoAviao() const;
    int getCodigoPiloto() const;
    int getCodigoCopiloto() const;
    vector<int> getCodigoComissarios() const;
    bool getStatus() const;
    double getTarifa() const;

    void setData(const string& novaData);
    void setHora(const string& novaHora);
    void setOrigem(const string& novaOrigem);
    void setDestino(const string& novoDestino);
    void setTarifa(double novaTarifa);
    void setStatus(bool novoStatus);

    void exibirInformacoes() const;

    // Métodos de persistência
    void salvarEmArquivo() const;
    static Voo carregarVoo(int codigo);
    static void listarVoos();
};

#endif
