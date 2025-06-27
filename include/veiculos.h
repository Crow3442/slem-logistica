#ifndef VEICULOS_H
#define VEICULOS_H

#include "locais.h"

#define MAX_VEICULOS 100
#define MAX_PLACA 10
#define MAX_MODELO 50

typedef struct {
    char placa[MAX_PLACA];       // Identificador único
    char modelo[MAX_MODELO];     // Modelo do veículo
    int status;                  // 1 = disponível, 0 = ocupado
    int idLocalAtual;            // Índice no vetor de locais
    int ativo;                   // 1 = ativo, 0 = inativo
} Veiculo;

// CRUD
void cadastrarVeiculo(Veiculo veiculos[], int *quantidade, const Local locais[], int qtdLocais);
void listarVeiculos(const Veiculo veiculos[], int quantidade, const Local locais[], int qtdLocais);
void atualizarVeiculo(Veiculo veiculos[], int quantidade, const Local locais[], int qtdLocais);
void excluirVeiculo(Veiculo veiculos[], int *quantidade);

// Auxiliares
int encontrarVeiculoPorPlaca(const Veiculo veiculos[], int quantidade, const char placa[]);
void converterPlacaParaMaiusculo(char placa[]);

void salvarVeiculosEmArquivo(const Veiculo veiculos[], int quantidade);
int carregarVeiculosDoArquivo(Veiculo veiculos[]);

#endif