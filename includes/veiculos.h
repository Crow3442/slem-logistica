#include "defines.h"

#ifndef VEICULOS_H
#define VEICULOS_H

#define MAX_VEICULOS 100
#define TAM_PLACA 10
#define TAM_MODELO 50
#define STATUS_DISPONIVEL 1
#define STATUS_OCUPADO 0

typedef struct {
    char placa[TAM_PLACA];
    char modelo[TAM_MODELO];
    int status;             
    char localAtual[TAM_NOME]; 
} Veiculo;

void criarVeiculo(Veiculo veiculos[], int *qtd, Local locais[], int qtdLocais);
void listarVeiculos(Veiculo veiculos[], int qtd);
void atualizarVeiculo(Veiculo veiculos[], int qtd, Local locais[], int qtdLocais);
void removerVeiculo(Veiculo veiculos[], int *qtd);

int encontrarIndiceVeiculo(Veiculo veiculos[], int qtd, const char placa[]);
void salvarVeiculos(Veiculo veiculos[], int qtd, const char *arquivo);
void carregarVeiculos(Veiculo veiculos[], int *qtd, const char *arquivo);

#endif