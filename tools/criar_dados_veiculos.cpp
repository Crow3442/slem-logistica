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

    strcpy(veiculos[qtd].placa, "ABC1001");
    strcpy(veiculos[qtd].modelo, "Motocicleta Cargo");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 0;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "XYZ2002");
    strcpy(veiculos[qtd].modelo, "Fiorino");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 1;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "DEF3003");
    strcpy(veiculos[qtd].modelo, "Kombi");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 2;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "GHI4004");
    strcpy(veiculos[qtd].modelo, "Van Escolar");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 3;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "JKL5005");
    strcpy(veiculos[qtd].modelo, "Pickup Compacta");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 4;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "MNO6006");
    strcpy(veiculos[qtd].modelo, "Caminhão Leve");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 5;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "PQR7007");
    strcpy(veiculos[qtd].modelo, "Caminhão Baú");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 6;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "STU8008");
    strcpy(veiculos[qtd].modelo, "Sprinter");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 7;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "VWX9009");
    strcpy(veiculos[qtd].modelo, "HR Baú");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 8;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "YZA1010");
    strcpy(veiculos[qtd].modelo, "Saveiro");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 9;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "BHZ1111");
    strcpy(veiculos[qtd].modelo, "Strada");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 10;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "MGX1212");
    strcpy(veiculos[qtd].modelo, "Doblo Cargo");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 11;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "LKM1313");
    strcpy(veiculos[qtd].modelo, "Toro");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 12;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "QWE1414");
    strcpy(veiculos[qtd].modelo, "Hilux");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 13;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "ASD1515");
    strcpy(veiculos[qtd].modelo, "Montana");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 14;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "ZXC1616");
    strcpy(veiculos[qtd].modelo, "Courier");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 15;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "POI1717");
    strcpy(veiculos[qtd].modelo, "Uno Furgão");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 16;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "LKJ1818");
    strcpy(veiculos[qtd].modelo, "Palio Weekend");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 17;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "MNB1919");
    strcpy(veiculos[qtd].modelo, "Civic de Apoio");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 18;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "TRE2020");
    strcpy(veiculos[qtd].modelo, "Gol G6 Logística");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 19;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "VBN2121");
    strcpy(veiculos[qtd].modelo, "Celta Auxiliar");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 0;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "YUI2222");
    strcpy(veiculos[qtd].modelo, "Cargo 1119");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 1;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "IOP2323");
    strcpy(veiculos[qtd].modelo, "Daily Furgão");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 2;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "GHJ2424");
    strcpy(veiculos[qtd].modelo, "S10 Reforçada");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 3;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "WSX2525");
    strcpy(veiculos[qtd].modelo, "Transit Van");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 4;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "EDC2626");
    strcpy(veiculos[qtd].modelo, "Boxer Peugeot");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 5;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "RFV2727");
    strcpy(veiculos[qtd].modelo, "Master Furgão");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 6;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "TGB2828");
    strcpy(veiculos[qtd].modelo, "Kangoo Express");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 7;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "ZHN2929");
    strcpy(veiculos[qtd].modelo, "L200 Logística");
    veiculos[qtd].status = 0;
    veiculos[qtd].idLocalAtual = 8;
    veiculos[qtd].ativo = 1;
    qtd++;

    strcpy(veiculos[qtd].placa, "XCV3030");
    strcpy(veiculos[qtd].modelo, "Sprinter Refrigerada");
    veiculos[qtd].status = 1;
    veiculos[qtd].idLocalAtual = 9;
    veiculos[qtd].ativo = 1;
    qtd++;

    salvarVeiculosEmArquivo(veiculos, qtd);

    return 0;
}