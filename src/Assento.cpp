#include <stdio.h>
#include <string.h>
#include "assento.h"

// Função para cadastrar um assento
void cadastrar_assento(int codigo_voo, int numero) {
    FILE* arquivo = fopen("assentos.bin", "ab"); // Abertura do arquivo em modo append binário
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de assentos.\n");
        return;
    }

    Assento novo_assento;
    novo_assento.codigo_voo = codigo_voo;
    novo_assento.numero = numero;
    strcpy(novo_assento.status, "livre"); // Status inicial é "livre"

    fwrite(&novo_assento, sizeof(Assento), 1, arquivo); // Escreve o assento no arquivo
    fclose(arquivo);
}

// Função para alterar o status de um assento
void alterar_status_assento(int codigo_voo, int numero, const char* novo_status) {
    FILE* arquivo = fopen("assentos.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de assentos.\n");
        return;
    }

    Assento assento;
    while (fread(&assento, sizeof(Assento), 1, arquivo)) {
        if (assento.codigo_voo == codigo_voo && assento.numero == numero) {
            // Encontrou o assento, altera o status
            strcpy(assento.status, novo_status);
            fseek(arquivo, -sizeof(Assento), SEEK_CUR); // Move o ponteiro para o início do assento encontrado
            fwrite(&assento, sizeof(Assento), 1, arquivo); // Atualiza o assento
            break;
        }
    }
    fclose(arquivo);
}

// Função para buscar um assento
Assento* buscar_assento(int codigo_voo, int numero) {
    FILE* arquivo = fopen("assentos.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de assentos.\n");
        return NULL;
    }

    Assento* assento_encontrado = NULL;
    Assento assento;
    while (fread(&assento, sizeof(Assento), 1, arquivo)) {
        if (assento.codigo_voo == codigo_voo && assento.numero == numero) {
            assento_encontrado = (Assento*)malloc(sizeof(Assento));
            *assento_encontrado = assento; // Copia os dados para o retorno
            break;
        }
    }
    fclose(arquivo);
    return assento_encontrado;
}

// Função para listar todos os assentos de um voo
void listar_assentos(int codigo_voo) {
    FILE* arquivo = fopen("assentos.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de assentos.\n");
        return;
    }

    Assento assento;
    printf("Assentos para o voo %d:\n", codigo_voo);
    while (fread(&assento, sizeof(Assento), 1, arquivo)) {
        if (assento.codigo_voo == codigo_voo) {
            printf("Assento %d: %s\n", assento.numero, assento.status);
        }
    }
    fclose(arquivo);
}
