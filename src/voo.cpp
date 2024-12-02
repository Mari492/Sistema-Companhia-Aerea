#include "voo.h"
#include "tripulacao.h"
#include <fstream>
#include <iostream>
#include <sstream>

Voo::Voo(int codigo, string data, string hora, string origem, string destino,
         int codigoAviao, int codigoPiloto, int codigoCopiloto,
         vector<int> codigoComissarios, double tarifa)
    : codigo(codigo), data(data), hora(hora), origem(origem), destino(destino),
      codigoAviao(codigoAviao), codigoPiloto(codigoPiloto), codigoCopiloto(codigoCopiloto),
      codigoComissarios(codigoComissarios), tarifa(tarifa) {
    status = validarTripulacao();
}

//Método para validar tripulação mínima usando Tripulacao
bool Voo::validarTripulacao() const {
    if (!Tripulacao::validarCodigo(codigoPiloto) ||
        !Tripulacao::validarCodigo(codigoCopiloto)) {
        return false; // Piloto ou copiloto não são válidos
    }

    for (int comissario : codigoComissarios) {
        if (!Tripulacao::validarCodigo(comissario)) {
            return false; // Algum comissário não é válido
        }
    }

    return true; // Tripulação válida
}

int Voo::getCodigo() const { return codigo; }
string Voo::getData() const { return data; }
string Voo::getHora() const { return hora; }
string Voo::getOrigem() const { return origem; }
string Voo::getDestino() const { return destino; }
int Voo::getCodigoAviao() const { return codigoAviao; }
int Voo::getCodigoPiloto() const { return codigoPiloto; }
int Voo::getCodigoCopiloto() const { return codigoCopiloto; }
vector<int> Voo::getCodigoComissarios() const { return codigoComissarios; }
bool Voo::getStatus() const { return status; }
double Voo::getTarifa() const { return tarifa; }

void Voo::setData(const string& novaData) { data = novaData; }
void Voo::setHora(const string& novaHora) { hora = novaHora; }
void Voo::setOrigem(const string& novaOrigem) { origem = novaOrigem; }
void Voo::setDestino(const string& novoDestino) { destino = novoDestino; }
void Voo::setTarifa(double novaTarifa) { tarifa = novaTarifa; }
void Voo::setStatus(bool novoStatus) { status = novoStatus; }

void Voo::exibirInformacoes() const {
    cout << "Código do Voo: " << codigo << endl;
    cout << "Data: " << data << endl;
    cout << "Hora: " << hora << endl;
    cout << "Origem: " << origem << endl;
    cout << "Destino: " << destino << endl;
    cout << "Código do Avião: " << codigoAviao << endl;
    cout << "Código do Piloto: " << codigoPiloto << endl;
    cout << "Código do Copiloto: " << codigoCopiloto << endl;
    cout << "Comissários: ";
    for (int comissario : codigoComissarios) {
        cout << comissario << " ";
    }
    cout << endl;
    cout << "Status: " << (status ? "Ativo" : "Inativo") << endl;
    cout << "Tarifa: " << tarifa << endl;
}

// Persistência em arquivo
void Voo::salvarEmArquivo() const {
    ofstream arquivo("voos.txt", ios::app);
    if (!arquivo) {
        throw runtime_error("Erro ao abrir o arquivo para salvar o voo.");
    }
    arquivo << codigo << "|" << data << "|" << hora << "|" << origem << "|"
            << destino << "|" << codigoAviao << "|" << codigoPiloto << "|"
            << codigoCopiloto << "|";
    for (size_t i = 0; i < codigoComissarios.size(); ++i) {
        arquivo << codigoComissarios[i];
        if (i != codigoComissarios.size() - 1) arquivo << ",";
    }
    arquivo << "|" << status << "|" << tarifa << "\n";
    arquivo.close();
}

// Carregar um voo a partir do arquivo
Voo Voo::carregarVoo(int codigoBusca) {
    ifstream arquivo("voos.txt");
    if (!arquivo) {
        throw runtime_error("Erro ao abrir o arquivo para carregar o voo.");
    }
    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string item;
        vector<string> campos;
        while (getline(ss, item, '|')) {
            campos.push_back(item);
        }
        if (stoi(campos[0]) == codigoBusca) {
            vector<int> comissarios;
            stringstream ssComissarios(campos[7]);
            string comissario;
            while (getline(ssComissarios, comissario, ',')) {
                comissarios.push_back(stoi(comissario));
            }
            return Voo(stoi(campos[0]), campos[1], campos[2], campos[3], campos[4],
                       stoi(campos[5]), stoi(campos[6]), stoi(campos[7]),
                       comissarios, stod(campos[9]));
        }
    }
    throw runtime_error("Voo não encontrado.");
}

// Listar todos os voos
void Voo::listarVoos() {
    ifstream arquivo("voos.txt");
    if (!arquivo) {
        throw runtime_error("Erro ao abrir o arquivo para listar os voos.");
    }
    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
    arquivo.close();
}
