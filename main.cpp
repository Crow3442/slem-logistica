#include <stdio.h>
#include <stdlib.h>
#include "include/locais.h"
#include "include/veiculos.h"

void menuLocais(Local locais[], int *quantidade) {
    int opcao;
    do {
        printf("\n======= MENU DE LOCAIS =======\n");
        printf("1. Cadastrar local\n");
        printf("2. Listar locais\n");
        printf("3. Atualizar local\n");
        printf("4. Excluir local\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarLocal(locais, quantidade);
                salvarLocaisEmArquivo(locais, *quantidade);
                break;
            case 2:
                listarLocais(locais, *quantidade);
                break;
            case 3:
                atualizarLocal(locais, *quantidade);
                salvarLocaisEmArquivo(locais, *quantidade);
                break;
            case 4:
                excluirLocal(locais, quantidade);
                salvarLocaisEmArquivo(locais, *quantidade);
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);
}

void menuVeiculos(Veiculo veiculos[], int *qtdVeiculos, Local locais[], int qtdLocais) {
    int opcao;
    do {
        printf("\n======= MENU DE VEÍCULOS =======\n");
        printf("1. Cadastrar veículo\n");
        printf("2. Listar veículos\n");
        printf("3. Atualizar veículo\n");
        printf("4. Excluir veículo\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarVeiculo(veiculos, qtdVeiculos, locais, qtdLocais);
                salvarVeiculosEmArquivo(veiculos, *qtdVeiculos);
                break;
            case 2:
                listarVeiculos(veiculos, *qtdVeiculos, locais, qtdLocais);
                break;
            case 3:
                atualizarVeiculo(veiculos, *qtdVeiculos, locais, qtdLocais);
                salvarVeiculosEmArquivo(veiculos, *qtdVeiculos);
                break;
            case 4:
                excluirVeiculo(veiculos, qtdVeiculos);
                salvarVeiculosEmArquivo(veiculos, *qtdVeiculos);
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);
}

int main() {
    system("chcp 65001 > nul");  // Suporte a UTF-8 no terminal (Windows)

    Local locais[MAX_LOCAIS];
    int qtdLocais = carregarLocaisDoArquivo(locais);

    Veiculo veiculos[MAX_VEICULOS];
    int qtdVeiculos = carregarVeiculosDoArquivo(veiculos);

    int opcao;
    do {
        printf("\n======= SISTEMA DE LOGÍSTICA =======\n");
        printf("Seja bem-vindo ao sistema! Escolha o que deseja fazer:\n");
        printf("1. Menu de locais\n");
        printf("2. Menu de veículos\n");
        printf("0. Sair do sistema\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                menuLocais(locais, &qtdLocais);
                break;
            case 2:
                menuVeiculos(veiculos, &qtdVeiculos, locais, qtdLocais);
                break;
            case 0:
                printf("Saindo do sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}