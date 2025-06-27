#include <stdio.h>
#include <string.h>
#include "../include/veiculos.h"

void salvarVeiculosEmArquivo(const Veiculo veiculos[], int quantidade) {
    FILE *f = fopen("data/veiculos.dat", "wb");
    if (f == NULL) {
        printf("Erro ao salvar veículos no arquivo.\n");
        return;
    }

    fwrite(veiculos, sizeof(Veiculo), quantidade, f);
    fclose(f);
    printf("Arquivo data/veiculos.dat gerado com sucesso com %d veículos.\n", quantidade);
}

int main() {
    Veiculo veiculos[MAX_VEICULOS];
    int qtd = 0;

    strcpy(veiculos[qtd].placa, "ABC1234");
    strcpy(veiculos[qtd].modelo, "Caminhão Médio");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 0;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "XYZ5678");
    strcpy(veiculos[qtd].modelo, "Van Pequena");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 2;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "DEF9012");
    strcpy(veiculos[qtd].modelo, "Motocicleta");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 5;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "GHI3456");
    strcpy(veiculos[qtd].modelo, "Caminhão Baú");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 3;
    veiculos[qtd].ativo = 1;
    qtd++;

    salvarVeiculosEmArquivo(veiculos, qtd);

    return 0;
}