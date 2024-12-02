#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Função para formatar a data e hora
string obterDataHoraAtual() {
    time_t agora = time(0);
    tm *ltm = localtime(&agora);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
       << " " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min;
    return ss.str();
}

// Classe que representa um voo
class Voo {
public:
    string codigoVoo;
    string dataVoo;
    string horaVoo;
    string origem;
    string destino;
    string codigoAviao;
    string status; // "Ativo" ou "Inativo"
    double tarifa;
    string piloto;
    string copiloto;

    Voo(string cv, string d, string h, string o, string des, string ca, double t, string p, string c)
        : codigoVoo(cv), dataVoo(d), horaVoo(h), origem(o), destino(des), codigoAviao(ca), tarifa(t), status("Inativo"), piloto(p), copiloto(c) {}

    // Função para ativar o voo
    bool ativarVoo() {
        // Verificar se há piloto e copiloto
        if (!piloto.empty() && !copiloto.empty()) {
            status = "Ativo";
            cout << "Voo " << codigoVoo << " ativado com sucesso!" << endl;
            return true;
        } else {
            cout << "Erro: E necessario ter pelo menos um piloto e um copiloto para ativar o voo." << endl;
            return false;
        }
    }

    // Função para exibir informações do voo
    void exibirInformacoes() {
        cout << "Codigo do Voo: " << codigoVoo << endl;
        cout << "Data do Voo: " << dataVoo << " | Hora: " << horaVoo << endl;
        cout << "Origem: " << origem << " | Destino: " << destino << endl;
        cout << "Codigo do Aviao: " << codigoAviao << endl;
        cout << "Status: " << status << endl;
        cout << "Tarifa: R$ " << tarifa << endl;
        cout << "Piloto: " << piloto << endl;
        cout << "Copiloto: " << copiloto << endl;
    }
};

int main() {
    // Criando um voo com piloto e copiloto
    Voo voo1("1234", "2024-11-30", "14:30", "Sao Paulo", "Rio de Janeiro", "A001", 2500.00, "Jurandi Vitor (Piloto)", "Maristela Souza (Copiloto)");

    // Tentar ativar o voo (deve ser possível porque temos piloto e copiloto)
    voo1.ativarVoo();

    // Exibindo informações do voo
    voo1.exibirInformacoes();

    // Criando outro voo (sem piloto ou copiloto)
    Voo voo2("5678", "2024-12-01", "08:00", "Rio de Janeiro", "Minas Gerais", "A002", 5000.00, "", "");

    //Não vai ativar pois faltam o piloto e copiloto
    voo2.ativarVoo();

    // Exibindo informações do voo
    voo2.exibirInformacoes();

//Travar o programa
    cin.get();

    return 0;
}
