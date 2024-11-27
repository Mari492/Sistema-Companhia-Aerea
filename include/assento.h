#ifndef ASSENTO_H
#define ASSENTO_H

// Definição de estrutura para representar um assento
typedef struct {
    int numero;        // Número do assento
    int codigo_voo;    // Código do voo a que o assento pertence
    char status[10];   // Status do assento: "ocupado" ou "livre"
} Assento;

// Funções para manipulação de assentos
void cadastrar_assento(int codigo_voo, int numero);
void alterar_status_assento(int codigo_voo, int numero, const char* novo_status);
Assento* buscar_assento(int codigo_voo, int numero);
void listar_assentos(int codigo_voo);

#endif
