#include <stdio.h>
#include <stdlib.h>
#include "include/locais.h"
#include "include/veiculos.h"
#include "include/pedidos.h"
#include "include/sistema.h"

// ======================== MENUS ========================

void menuLocais(Local locais[], int *quantidade) {
    int opcao;
    do {
        printf("\n========= MENU DE LOCAIS =========\n");
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
                break;
            default:
                printf("Opção inválida.\n");
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
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

void menuPedidos(Pedido pedidos[], int *qtdPedidos, Local locais[], int qtdLocais, Veiculo veiculos[], int qtdVeiculos) {
    int opcao;
    do {
        printf("\n========= MENU DE PEDIDOS =========\n");
        printf("1. Cadastrar pedido\n");
        printf("2. Listar pedidos\n");
        printf("3. Atualizar pedido\n");
        printf("4. Excluir pedido\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarPedido(pedidos, qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                salvarPedidosEmArquivo(pedidos, *qtdPedidos);
                break;
            case 2:
                listarPedidos(pedidos, *qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                break;
            case 3:
                atualizarPedido(pedidos, *qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                salvarPedidosEmArquivo(pedidos, *qtdPedidos);
                break;
            case 4:
                excluirPedido(pedidos, *qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                salvarPedidosEmArquivo(pedidos, *qtdPedidos);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

void menuEntregas(Pedido pedidos[], int *qtdPedidos, Local locais[], int qtdLocais, Veiculo veiculos[], int qtdVeiculos) {
    int opcao;
    do {
        printf("\n======= MENU DE ENTREGAS =======\n");
        printf("1. Iniciar entrega\n");
        printf("2. Finalizar entrega\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                iniciarEntrega(pedidos, *qtdPedidos, veiculos, qtdVeiculos, locais, qtdLocais);
                salvarPedidosEmArquivo(pedidos, *qtdPedidos);
                salvarVeiculosEmArquivo(veiculos, qtdVeiculos);
                break;
            case 2:
                finalizarEntrega(pedidos, *qtdPedidos, veiculos, qtdVeiculos, locais, qtdLocais);
                salvarPedidosEmArquivo(pedidos, *qtdPedidos);
                salvarVeiculosEmArquivo(veiculos, qtdVeiculos);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

// ======================== MAIN ========================

int main() {
    Local locais[MAX_LOCAIS];
    Veiculo veiculos[MAX_VEICULOS];
    Pedido pedidos[MAX_PEDIDOS];

    int qtdLocais = carregarLocaisDoArquivo(locais);
    int qtdVeiculos = carregarVeiculosDoArquivo(veiculos);
    int qtdPedidos = carregarPedidosDoArquivo(pedidos);

    int opcao;
    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Gerenciar locais\n");
        printf("2. Gerenciar veículos\n");
        printf("3. Gerenciar pedidos\n");
        printf("4. Gerenciar entregas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                menuLocais(locais, &qtdLocais);
                break;
            case 2:
                menuVeiculos(veiculos, &qtdVeiculos, locais, qtdLocais);
                break;
            case 3:
                menuPedidos(pedidos, &qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                break;
            case 4:
                menuEntregas(pedidos, &qtdPedidos, locais, qtdLocais, veiculos, qtdVeiculos);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}