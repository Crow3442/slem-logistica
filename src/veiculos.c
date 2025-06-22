#include <stdio.h>
#include <string.h>
#include "veiculos.h"
#include "locais.h"

void criarVeiculo(Veiculo veiculos[], int *qtd, Local locais[], int qtdLocais) {
    if (*qtd >= MAX_VEICULOS) {
        printf("Limite de veículos atingido.\n");
        return;
    }

    Veiculo novo;
    printf("Placa do veículo: ");
    scanf(" %[^\n]", novo.placa);

    if (encontrarIndiceVeiculo(veiculos, *qtd, novo.placa) != -1) {
        printf("Veículo com essa placa já existe.\n");
        return;
    }

    printf("Modelo do veículo: ");
    scanf(" %[^\n]", novo.modelo);

    printf("Status (1 = Disponível, 0 = Ocupado): ");
    scanf("%d", &novo.status);

    printf("Nome do local atual: ");
    scanf(" %[^\n]", novo.localAtual);

    if (encontrarIndiceLocal(locais, qtdLocais, novo.localAtual) == -1) {
        printf("Local não encontrado. Cadastre o local primeiro.\n");
        return;
    }

    veiculos[*qtd] = novo;
    (*qtd)++;
    printf("Veículo cadastrado com sucesso!\n");
}

void listarVeiculos(Veiculo veiculos[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Veículos ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Placa: %s | Modelo: %s | Status: %s | Local: %s\n",
            i + 1,
            veiculos[i].placa,
            veiculos[i].modelo,
            veiculos[i].status == STATUS_DISPONIVEL ? "Disponível" : "Ocupado",
            veiculos[i].localAtual
        );
    }
}

int encontrarIndiceVeiculo(Veiculo veiculos[], int qtd, const char placa[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

void atualizarVeiculo(Veiculo veiculos[], int qtd, Local locais[], int qtdLocais) {
    char placa[TAM_PLACA];
    printf("Digite a placa do veículo a ser atualizado: ");
    scanf(" %[^\n]", placa);

    int indice = encontrarIndiceVeiculo(veiculos, qtd, placa);
    if (indice == -1) {
        printf("Veículo não encontrado.\n");
        return;
    }

    printf("Novo modelo: ");
    scanf(" %[^\n]", veiculos[indice].modelo);

    printf("Novo status (1 = Disponível, 0 = Ocupado): ");
    scanf("%d", &veiculos[indice].status);

    printf("Novo local atual: ");
    scanf(" %[^\n]", veiculos[indice].localAtual);

    if (encontrarIndiceLocal(locais, qtdLocais, veiculos[indice].localAtual) == -1) {
        printf("Local não encontrado.\n");
        return;
    }

    printf("Veículo atualizado com sucesso!\n");
}

void removerVeiculo(Veiculo veiculos[], int *qtd) {
    char placa[TAM_PLACA];
    printf("Digite a placa do veículo a ser removido: ");
    scanf(" %[^\n]", placa);

    int indice = encontrarIndiceVeiculo(veiculos, *qtd, placa);
    if (indice == -1) {
        printf("Veículo não encontrado.\n");
        return;
    }

    for (int i = indice; i < (*qtd) - 1; i++) {
        veiculos[i] = veiculos[i + 1];
    }

    (*qtd)--;
    printf("Veículo removido com sucesso!\n");
}

void salvarVeiculos(Veiculo veiculos[], int qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "wb");
    if (!f) {
        printf("Erro ao salvar os dados de veículos.\n");
        return;
    }

    fwrite(&qtd, sizeof(int), 1, f);
    fwrite(veiculos, sizeof(Veiculo), qtd, f);
    fclose(f);
}

void carregarVeiculos(Veiculo veiculos[], int *qtd, const char *arquivo) {
    FILE *f = fopen(arquivo, "rb");
    if (!f) {
        printf("Nenhum dado de veículos encontrado.\n");
        return;
    }

    fread(qtd, sizeof(int), 1, f);
    fread(veiculos, sizeof(Veiculo), *qtd, f);
    fclose(f);
}