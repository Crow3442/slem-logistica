#include "../include/locais.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verifica se o nome digitado é vazio ou contém apenas espaços
int nomeInvalido(const char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isspace(nome[i])) {
            return 0; // válido
        }
    }
    return 1; // inválido
}

void cadastrarLocal(Local locais[], int *quantidade) {
    if (*quantidade >= MAX_LOCAIS) {
        printf("Limite de locais atingido!\n");
        return;
    }

    Local novo;
    printf("\n--- Cadastro de Local ---\n");

    // Leitura do nome com validação
    int nomeValido = 0;
    while (!nomeValido) {
        printf("Nome do local: ");
        fgets(novo.nome, MAX_NOME, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove '\n'

        if (strlen(novo.nome) == 0 || nomeInvalido(novo.nome)) {
            printf("Nome inválido. Digite algo significativo.\n");
        } else {
            nomeValido = 1;
        }
    }

    // Leitura de coordenada X com validação
    int leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada X: ");
        if (scanf("%f", &novo.x) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n'); // limpa o buffer
        }
    }

    // Leitura de coordenada Y com validação
    leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada Y: ");
        if (scanf("%f", &novo.y) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n'); // limpa o buffer
        }
    }

    // Limpa buffer após último scanf
    while (getchar() != '\n');

    novo.ativo = 1;
    locais[*quantidade] = novo;
    (*quantidade)++;

    printf("Local cadastrado com sucesso!\n");
}