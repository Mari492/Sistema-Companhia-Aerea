#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Passageiro.h"
#include "Tripulacao.h"
#include "Voo.h"
#include "Reserva.h"
using namespace std;

class Sistema {
private:
    vector<Passageiro> passageiros;
    vector<Tripulacao> tripulantes;
    vector<Voo> voos;
    vector<Reserva> reservas;

    int proximoCodigoPassageiro;
    int proximoCodigoTripulante;
    int proximoCodigoVoo;

public:
    Sistema();

    void cadastrarPassageiro(const string& nome, const string& endereco,
                             const string& telefone, bool fidelidade);
    void cadastrarTripulante(const string& nome, const string& telefone,
                             const string& cargo);
    void cadastrarVoo(const string& data, const string& hora,
                      const string& origem, const string& destino,
                      const string& codigoAviao, const Tripulacao& piloto,
                      const Tripulacao& copiloto, double tarifa);

    void criarReserva(int codigoVoo, int numeroAssento, int codigoPassageiro);
    bool cancelarReserva(int codigoVoo, int numeroAssento);
    void listarVoosPorPassageiro(int codigoPassageiro) const;
    void pesquisarPassageiroPorNome(const string& nome) const;
    void pesquisarTripulantePorNome(const string& nome) const;
    void pesquisarPassageiroPorCodigo(int codigoPassageiro) const;
    void pesquisarTripulantePorCodigo(int codigoTripulante) const;

    //permitir o acesso aos tripulantes cadastrados
    const vector<Tripulacao>& getTripulantes() const {
        return tripulantes;
    }

    //permitir o acesso aos passageiros cadastrados
    const vector<Passageiro>& getPassageiros() const {
        return passageiros;
    }

    // Métodos para salvar e carregar o sistema em arquivo
    void salvarSistema(const string& arquivo) const;
    void carregarSistema(const string& arquivo);

};


#endif
