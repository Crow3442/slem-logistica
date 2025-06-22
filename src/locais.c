#include <stdio.h>
#include <string.h>
#include "locais.h"

void criarLocal(Local locais[], int *qtd) {
    if (*qtd >= MAX_LOCAIS) {
        printf("Limite de locais atingido.\n");
        return;
    }

    Local novo;
    printf("Nome do local: ");
    scanf(" %[^\n]", novo.nome);

    // Verificar duplicidade
    if (encontrarIndiceLocal(locais, *qtd, novo.nome) != -1) {
        printf("Local já cadastrado.\n");
        return;
    }

    printf("Coordenada X: ");
    scanf("%f", &novo.x);
    printf("Coordenada Y: ");
    scanf("%f", &novo.y);

    locais[*qtd] = novo;
    (*qtd)++;
    printf("Local cadastrado com sucesso!\n");
}

void listarLocais(Local locais[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum local cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Locais ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s (%.2f, %.2f)\n", i + 1, locais[i].nome, locais[i].x, locais[i].y);
    }
}

int encontrarIndiceLocal(Local locais[], int qtd, const char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(locais[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void atualizarLocal(Local locais[], int qtd) {
    char nome[TAM_NOME];
    printf("Digite o nome do local a ser atualizado: ");
    scanf(" %[^\n]", nome);

    int indice = encontrarIndiceLocal(locais, qtd, nome);
    if (indice == -1) {
        printf("Local não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", locais[indice].nome);
    printf("Nova coordenada X: ");
    scanf("%f", &locais[indice].x);
    printf("Nova coordenada Y: ");
    scanf("%f", &locais[indice].y);

    printf("Local atualizado com sucesso!\n");
}

void removerLocal(Local locais[], int *qtd) {
    char nome[TAM_NOME];
    printf("Digite o nome do local a ser removido: ");
    scanf(" %[^\n]", nome);

    int indice = encontrarIndiceLocal(locais, *qtd, nome);
    if (indice == -1) {
        printf("Local não encontrado.\n");
        return;
    }

    for (int i = indice; i < (*qtd) - 1; i++) {
        locais[i] = locais[i + 1];
    }

    (*qtd)--;
    printf("Local removido com sucesso!\n");
}

void salvarLocais(Local locais[], int qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "wb");
    if (!f) {
        printf("Erro ao salvar os dados.\n");
        return;
    }
    fwrite(&qtd, sizeof(int), 1, f);
    fwrite(locais, sizeof(Local), qtd, f);
    fclose(f);
}

void carregarLocais(Local locais[], int *qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "rb");
    if (!f) {
        printf("Nenhum dado encontrado.\n");
        return;
    }