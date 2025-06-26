#include "../include/veiculos.h"
#include <stdio.h>
#include <string.h>

int encontrarVeiculoPorPlaca(const Veiculo veiculos[], int quantidade, const char placa[]) {
    for (int i = 0; i < quantidade; i++) {
        if (veiculos[i].ativo && strcmp(veiculos[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

void cadastrarVeiculo(Veiculo veiculos[], int *quantidade, const Local locais[], int qtdLocais) {
    if (*quantidade >= MAX_VEICULOS) {
        printf("Limite de veículos atingido.\n");
        return;
    }

    Veiculo novo;
    printf("\n--- Cadastro de Veículo ---\n");

    // Placa
    int placaValida = 0;
    while (!placaValida) {
        printf("Placa: ");
        fgets(novo.placa, MAX_PLACA, stdin);
        novo.placa[strcspn(novo.placa, "\n")] = '\0';

        if (strlen(novo.placa) == 0) {
            printf("Placa inválida.\n");
        } else if (encontrarVeiculoPorPlaca(veiculos, *quantidade, novo.placa) != -1) {
            printf("Placa já cadastrada.\n");
        } else {
            placaValida = 1;
        }
    }

    // Modelo
    printf("Modelo: ");
    fgets(novo.modelo, MAX_MODELO, stdin);
    novo.modelo[strcspn(novo.modelo, "\n")] = '\0';

    // Status inicial: disponível
    novo.status = 1;

    // Associar a um local existente
    printf("\n--- Locais disponíveis ---\n");
    for (int i = 0; i < qtdLocais; i++) {
        if (locais[i].ativo) {
            printf("ID %d: %s\n", i, locais[i].nome);
        }
    }

    printf("ID do local atual do veículo: ");
    scanf("%d", &novo.idLocalAtual);
    while (getchar() != '\n');

    if (novo.idLocalAtual < 0 || novo.idLocalAtual >= qtdLocais || !locais[novo.idLocalAtual].ativo) {
        printf("Local inválido. Cadastro cancelado.\n");
        return;
    }

    novo.ativo = 1;
    veiculos[*quantidade] = novo;
    (*quantidade)++;

    printf("Veículo cadastrado com sucesso!\n");
}