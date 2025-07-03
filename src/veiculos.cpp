#include "../include/veiculos.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void converterPlacaParaMaiusculo(char placa[]) {
    for (int i = 0; placa[i] != '\0'; i++) {
        placa[i] = toupper(placa[i]);
    }
}

/**
 * Procura um veículo no vetor a partir da placa.
 *
 * @param veiculos Vetor de veículos.
 * @param qtdVeiculos Quantidade de veículos no vetor.
 * @param placa Placa do veículo a ser encontrado.
 * @return Índice do veículo se encontrado, -1 caso contrário.
 */
int encontrarVeiculoPorPlaca(const Veiculo veiculos[], int qtdVeiculos, const char* placa) {
    if (veiculos == NULL || placa == NULL || qtdVeiculos <= 0) {
        return -1;
    }
    for (int i = 0; i < qtdVeiculos; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
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
        printf("Placa (formato ABC1234): ");
        fgets(novo.placa, MAX_PLACA, stdin);
        novo.placa[strcspn(novo.placa, "\n")] = '\0';
        converterPlacaParaMaiusculo(novo.placa);

        if (strlen(novo.placa) != 7) {
            printf("A placa deve conter exatamente 7 caracteres.\n");
            continue;
        }

        int formatoCorreto = 1;
        for (int i = 0; i < 3; i++) {
            if (!isalpha(novo.placa[i])) formatoCorreto = 0;
        }
        for (int i = 3; i < 7; i++) {
            if (!isdigit(novo.placa[i])) formatoCorreto = 0;
        }

        if (!formatoCorreto) {
            printf("Placa inválida. Use o formato LLLNNNN (ex: ABC1234).\n");
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

    // Status inicial
    novo.status = 1;

    // Associar local atual
    printf("\n--- Locais disponíveis ---\n");
    for (int i = 0; i < qtdLocais; i++) {
        if (locais[i].ativo) {
            printf("ID %02d: %s\n", i, locais[i].nome);
        }
    }

    printf("Digite o ID do local atual do veículo: ");
    scanf("%d", &novo.idLocalAtual);
    while (getchar() != '\n');

    if (novo.idLocalAtual < 0 || novo.idLocalAtual >= qtdLocais || !locais[novo.idLocalAtual].ativo) {
        printf("ID de local inválido. Cadastro cancelado.\n");
        return;
    }

    novo.ativo = 1;
    veiculos[*quantidade] = novo;
    (*quantidade)++;

    printf("Veículo cadastrado com sucesso!\n");
}

void listarVeiculos(const Veiculo veiculos[], int quantidade, const Local locais[], int qtdLocais) {
    printf("\n--- Lista de Veículos Cadastrados ---\n");
    printf("%-4s | %-8s | %-20s | %-10s | %s\n", "ID", "Placa", "Modelo", "Status", "Local Atual");
    printf("---------------------------------------------------------------\n");

    int encontrados = 0;
    for (int i = 0; i < quantidade; i++) {
        if (veiculos[i].ativo) {
            const char* statusStr = veiculos[i].status ? "Disponível" : "Ocupado";
            const char* nomeLocal = (locais && veiculos[i].idLocalAtual >= 0 &&
                                     veiculos[i].idLocalAtual < qtdLocais &&
                                     locais[veiculos[i].idLocalAtual].ativo)
                ? locais[veiculos[i].idLocalAtual].nome
                : "Local inválido";

            printf("%02d   | %-8s | %-20s | %-10s | %s\n",
                   i, veiculos[i].placa, veiculos[i].modelo, statusStr, nomeLocal);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum veículo cadastrado.\n");
    }
}

void atualizarVeiculo(Veiculo veiculos[], int quantidade, const Local locais[], int qtdLocais) {
    listarVeiculos(veiculos, quantidade, locais, qtdLocais);

    printf("\nDigite o ID do veículo que deseja atualizar: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= quantidade || !veiculos[id].ativo) {
        printf("ID inválido.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("\n--- Atualizar Veículo ---\n");

    // Modelo
    printf("Novo modelo (%s): ", veiculos[id].modelo);
    char novoModelo[MAX_MODELO];
    fgets(novoModelo, MAX_MODELO, stdin);
    novoModelo[strcspn(novoModelo, "\n")] = '\0';
    if (strlen(novoModelo) > 0) {
        strcpy(veiculos[id].modelo, novoModelo);
    }

    // Status
    printf("Novo status (1 = disponível, 0 = ocupado) [%d]: ", veiculos[id].status);
    int status;
    if (scanf("%d", &status) == 1 && (status == 0 || status == 1)) {
        veiculos[id].status = status;
    } else {
        printf("Status inválido. Mantido valor atual.\n");
    }
    while (getchar() != '\n');

    // Novo local
    printf("\n--- Locais disponíveis ---\n");
    for (int i = 0; i < qtdLocais; i++) {
        if (locais[i].ativo) {
            printf("ID %02d: %s\n", i, locais[i].nome);
        }
    }

    printf("Novo ID de local atual (%d): ", veiculos[id].idLocalAtual);
    int novoLocal;
    if (scanf("%d", &novoLocal) == 1 &&
        novoLocal >= 0 && novoLocal < qtdLocais &&
        locais[novoLocal].ativo) {
        veiculos[id].idLocalAtual = novoLocal;
    } else {
        printf("Local inválido. Mantido valor atual.\n");
    }
    while (getchar() != '\n');

    printf("Veículo atualizado com sucesso!\n");
}

void excluirVeiculo(Veiculo veiculos[], int *quantidade) {
    listarVeiculos(veiculos, *quantidade, NULL, 0); 

    printf("\nDigite o ID do veículo que deseja excluir: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= *quantidade || !veiculos[id].ativo) {
        printf("ID inválido ou veículo já está inativo.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Tem certeza que deseja excluir o veículo com placa %s? (s/n): ", veiculos[id].placa);
    char confirmacao;
    scanf("%c", &confirmacao);
    while (getchar() != '\n');

    if (confirmacao == 's' || confirmacao == 'S') {
        veiculos[id].ativo = 0;
        printf("Veículo excluído com sucesso.\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
}

void salvarVeiculosEmArquivo(const Veiculo veiculos[], int quantidade) {
    FILE *f = fopen("data/veiculos.dat", "wb");
    if (f == NULL) {
        printf("Erro ao salvar veículos no arquivo.\n");
        return;
    }

    fwrite(veiculos, sizeof(Veiculo), quantidade, f);
    fclose(f);
    printf("Veículos salvos com sucesso.\n");
}

int carregarVeiculosDoArquivo(Veiculo veiculos[]) {
    FILE *f = fopen("data/veiculos.dat", "rb");
    if (f == NULL) {
        printf("Arquivo veiculos.dat não encontrado. Nenhum veículo carregado.\n");
        return 0;
    }

    int quantidade = 0;
    while (quantidade < MAX_VEICULOS && fread(&veiculos[quantidade], sizeof(Veiculo), 1, f) == 1) {
        quantidade++;
    }

    fclose(f);
    printf("Veículos carregados do arquivo: %d\n", quantidade);
    return quantidade;
}