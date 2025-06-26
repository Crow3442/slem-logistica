#include <stdio.h>
#include <string.h>
#include "../include/locais.h"

void gerarLocaisDeExemplo(Local locais[], int *qtd) {
    strcpy(locais[0].nome, "Praça Sete de Setembro");
    locais[0].x = 10.0; locais[0].y = 20.0; locais[0].ativo = 1;

    strcpy(locais[1].nome, "Estação Central do Metrô");
    locais[1].x = 15.5; locais[1].y = 22.3; locais[1].ativo = 1;

    strcpy(locais[2].nome, "Shopping Cidade");
    locais[2].x = 12.8; locais[2].y = 19.7; locais[2].ativo = 1;

    strcpy(locais[3].nome, "Mercado Central");
    locais[3].x = 18.0; locais[3].y = 25.2; locais[3].ativo = 1;

    strcpy(locais[4].nome, "Savassi");
    locais[4].x = 25.0; locais[4].y = 18.0; locais[4].ativo = 1;

    strcpy(locais[5].nome, "Universidade FUMEC");
    locais[5].x = 27.5; locais[5].y = 15.5; locais[5].ativo = 1;

    strcpy(locais[6].nome, "PUC Minas - Coração Eucarístico");
    locais[6].x = 30.0; locais[6].y = 28.0; locais[6].ativo = 1;

    strcpy(locais[7].nome, "Mineirão");
    locais[7].x = 35.0; locais[7].y = 32.0; locais[7].ativo = 1;

    *qtd = 8;
}

void salvarLocaisEmArquivo(const Local locais[], int quantidade) {
    FILE *f = fopen("data/locais.dat", "wb");
    if (f == NULL) {
        printf("Erro ao salvar locais no arquivo.\n");
        return;
    }

    fwrite(locais, sizeof(Local), quantidade, f);
    fclose(f);
    printf("Arquivo data/locais.dat gerado com sucesso com %d locais.\n", quantidade);
}

int main() {
    Local locais[MAX_LOCAIS];
    int qtd = 0;

    gerarLocaisDeExemplo(locais, &qtd);
    salvarLocaisEmArquivo(locais, qtd);

    return 0;
}