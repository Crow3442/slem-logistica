#include "../include/pedidos.h"
#include <stdio.h>

void cadastrarPedido(Pedido pedidos[], int *quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    if (*quantidade >= MAX_PEDIDOS) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    Pedido novo;
    printf("\n--- Cadastro de Pedido ---\n");

    // Mostrar locais ativos
    printf("Locais disponíveis:\n");
    for (int i = 0; i < qtdLocais; i++) {
        if (locais[i].ativo) {
            printf("ID %02d: %s\n", i, locais[i].nome);
        }
    }

    // Origem
    printf("Digite o ID do local de origem: ");
    scanf("%d", &novo.idOrigem);
    while (getchar() != '\n');

    // Destino
    printf("Digite o ID do local de destino: ");
    scanf("%d", &novo.idDestino);
    while (getchar() != '\n');

    if (novo.idOrigem < 0 || novo.idOrigem >= qtdLocais || !locais[novo.idOrigem].ativo ||
        novo.idDestino < 0 || novo.idDestino >= qtdLocais || !locais[novo.idDestino].ativo) {
        printf("IDs de origem ou destino inválidos.\n");
        return;
    }

    // Sem veículo atribuído ainda
    novo.idVeiculo = -1;
    novo.status = PENDENTE;
    novo.ativo = 1;

    pedidos[*quantidade] = novo;
    (*quantidade)++;

    printf("Pedido cadastrado com sucesso!\n");
}

void listarPedidos(const Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    printf("\n--- Lista de Pedidos ---\n");
    printf("%-4s | %-20s -> %-20s | %-10s | %s\n", "ID", "Origem", "Destino", "Status", "Veículo");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < quantidade; i++) {
        if (pedidos[i].ativo) {
            const char* nomeOrigem = (pedidos[i].idOrigem >= 0 && pedidos[i].idOrigem < qtdLocais) ? locais[pedidos[i].idOrigem].nome : "Desconhecido";
            const char* nomeDestino = (pedidos[i].idDestino >= 0 && pedidos[i].idDestino < qtdLocais) ? locais[pedidos[i].idDestino].nome : "Desconhecido";

            const char* statusStr = "";
            switch (pedidos[i].status) {
                case PENDENTE: statusStr = "Pendente"; break;
                case EM_ENTREGA: statusStr = "Em entrega"; break;
                case ENTREGUE: statusStr = "Entregue"; break;
            }

            const char* nomeVeiculo = "Não atribuído";
            if (pedidos[i].idVeiculo >= 0 && pedidos[i].idVeiculo < qtdVeiculos && veiculos[pedidos[i].idVeiculo].ativo) {
                nomeVeiculo = veiculos[pedidos[i].idVeiculo].placa;
            }

            printf("%02d   | %-20s -> %-20s | %-10s | %s\n", i, nomeOrigem, nomeDestino, statusStr, nomeVeiculo);
        }
    }
}