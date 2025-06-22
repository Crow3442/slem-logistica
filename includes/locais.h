#include "defines.h"

#ifndef LOCAIS_H
#define LOCAIS_H

#define MAX_LOCAIS 100
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    float x;
    float y;
} Local;

void criarLocal(Local locais[], int *qtd);
void listarLocais(Local locais[], int qtd);
void atualizarLocal(Local locais[], int qtd);
void removerLocal(Local locais[], int *qtd);

int encontrarIndiceLocal(Local locais[], int qtd, const char nome[]);
void salvarLocais(Local locais[], int qtd, const char *arquivo);
void carregarLocais(Local locais[], int *qtd, const char *arquivo);

int encontrarIndiceLocal(Local locais[], int qtd, const char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(locais[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

#endif