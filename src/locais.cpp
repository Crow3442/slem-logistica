#include "../include/locais.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verifica se o nome digitado é vazio ou contém apenas espaços
int nomeInvalido(const char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isspace(nome[i])) {
            return 0;
        }
    }
    return 1;
}

void cadastrarLocal(Local locais[], int *quantidade) {
    if (*quantidade >= MAX_LOCAIS) {
        printf("Limite de locais atingido!\n");
        return;
    }

    Local novo;
    printf("\n--- Cadastro de Local ---\n");

    // Leitura do nome
    int nomeValido = 0;
    while (!nomeValido) {
        printf("Nome do local: ");
        fgets(novo.nome, MAX_NOME, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';

        if (strlen(novo.nome) == 0 || nomeInvalido(novo.nome)) {
            printf("Nome inválido. Digite algo significativo.\n");
        } else {
            nomeValido = 1;
        }
    }

    // Coordenada X
    int leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada X: ");
        if (scanf("%f", &novo.x) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n');
        }
    }

    // Coordenada Y
    leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada Y: ");
        if (scanf("%f", &novo.y) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n');
        }
    }

    while (getchar() != '\n'); // Limpa buffer final
    novo.ativo = 1;
    locais[*quantidade] = novo;
    (*quantidade)++;

    printf("Local cadastrado com sucesso!\n");
}

void listarLocais(const Local locais[], int quantidade) {
    printf("\n--- Lista de Locais Cadastrados ---\n");

    int encontrados = 0;
    for (int i = 0; i < quantidade; i++) {
        if (locais[i].ativo) {
            printf("ID: %02d | Nome: %-30s | X: %7.2f | Y: %7.2f\n",
                   i, locais[i].nome, locais[i].x, locais[i].y);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum local ativo cadastrado.\n");
    }
}