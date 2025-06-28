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

    strcpy(locais[8].nome, "Palácio das Artes");
    locais[8].x = 13.0; locais[8].y = 17.0; locais[8].ativo = 1;

    strcpy(locais[9].nome, "Praça da Liberdade");
    locais[9].x = 16.5; locais[9].y = 21.0; locais[9].ativo = 1;

    strcpy(locais[10].nome, "Rodoviária de BH");
    locais[10].x = 14.0; locais[10].y = 24.0; locais[10].ativo = 1;

    strcpy(locais[11].nome, "Lagoa da Pampulha");
    locais[11].x = 38.0; locais[11].y = 35.0; locais[11].ativo = 1;

    strcpy(locais[12].nome, "BH Shopping");
    locais[12].x = 40.0; locais[12].y = 15.0; locais[12].ativo = 1;

    strcpy(locais[13].nome, "Zoológico de BH");
    locais[13].x = 42.0; locais[13].y = 34.0; locais[13].ativo = 1;

    strcpy(locais[14].nome, "UFMG - Campus Pampulha");
    locais[14].x = 33.0; locais[14].y = 30.0; locais[14].ativo = 1;

    strcpy(locais[15].nome, "Hospital das Clínicas");
    locais[15].x = 19.0; locais[15].y = 23.0; locais[15].ativo = 1;

    strcpy(locais[16].nome, "Parque Municipal");
    locais[16].x = 13.5; locais[16].y = 20.5; locais[16].ativo = 1;

    strcpy(locais[17].nome, "Praça Raul Soares");
    locais[17].x = 17.0; locais[17].y = 22.5; locais[17].ativo = 1;

    strcpy(locais[18].nome, "Feira Hippie (Av. Afonso Pena)");
    locais[18].x = 11.5; locais[18].y = 18.5; locais[18].ativo = 1;

    strcpy(locais[19].nome, "Alto Vera Cruz");
    locais[19].x = 22.0; locais[19].y = 16.0; locais[19].ativo = 1;

    *qtd = 20;
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