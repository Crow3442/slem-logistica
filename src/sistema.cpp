#include <stdio.h>
#include <math.h>
#include "../include/sistema.h"
#include "../include/locais.h"
#include "../include/pedidos.h"
#include "../include/veiculos.h"

/**
 * Calcula a distância euclidiana entre dois locais.
 *
 * @param origem Local de origem.
 * @param destino Local de destino.
 * @return Distância entre os dois locais. Retorna -1.0 em caso de valores inválidos.
 */
float calcularDistancia(Local origem, Local destino) {
    // Tratamento de exceções: coordenadas inválidas
    if (origem.x < 0 || origem.y < 0 || destino.x < 0 || destino.y < 0) {
        return -1.0;
    }

    float dx = origem.x - destino.x;
    float dy = origem.y - destino.y;
    return sqrt(dx * dx + dy * dy);
}

int encontrarVeiculoMaisProximo(const Local locais[], int qtdLocais,
                                const Veiculo veiculos[], int qtdVeiculos,
                                int idOrigem) {
    float menorDistancia = -1;
    int idMaisProximo = -1;

    for (int i = 0; i < qtdVeiculos; i++) {
        if (!veiculos[i].ativo || veiculos[i].status != 1) continue;

        int idLocalAtual = veiculos[i].idLocalAtual;
        if (idLocalAtual < 0 || idLocalAtual >= qtdLocais || !locais[idLocalAtual].ativo) continue;

        float dist = calcularDistancia(locais[idLocalAtual], locais[idOrigem]);
        if (menorDistancia == -1 || dist < menorDistancia) {
            menorDistancia = dist;
            idMaisProximo = i;
        }
    }

    return idMaisProximo;
}

void iniciarEntrega(Pedido pedidos[], int qtdPedidos,
                    Veiculo veiculos[], int qtdVeiculos,
                    Local locais[], int qtdLocais) {
    printf("\n--- Pedidos PENDENTES ---\n");
    int encontrou = 0;
    for (int i = 0; i < qtdPedidos; i++) {
        if (pedidos[i].ativo && pedidos[i].status == PENDENTE) {
            printf("ID %02d: %s -> %s (%.2fkg)\n", i,
                   locais[pedidos[i].idOrigem].nome,
                   locais[pedidos[i].idDestino].nome,
                   pedidos[i].peso);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pedido pendente.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do pedido para iniciar a entrega: ");
    if (scanf("%d", &id) != 1 || id < 0 || id >= qtdPedidos ||
        !pedidos[id].ativo || pedidos[id].status != PENDENTE) {
        printf("ID inválido ou pedido não está pendente.\n");
        while (getchar() != '\n');
        return;
    }

    Pedido* pedido = &pedidos[id];
    int idVeiculo = pedido->idVeiculo;

    if (idVeiculo == -1) {
        idVeiculo = encontrarVeiculoMaisProximo(locais, qtdLocais, veiculos, qtdVeiculos, pedido->idOrigem);
        if (idVeiculo == -1) {
            printf("Nenhum veículo disponível para iniciar a entrega.\n");
            return;
        }
        pedido->idVeiculo = idVeiculo;
        printf("Veículo %s vinculado ao pedido.\n", veiculos[idVeiculo].placa);
    }

    veiculos[idVeiculo].status = 0; // ocupado
    pedido->status = EM_ENTREGA;

    printf("Entrega iniciada com sucesso!\n");
}

void finalizarEntrega(Pedido pedidos[], int qtdPedidos,
                      Veiculo veiculos[], int qtdVeiculos,
                      Local locais[], int qtdLocais) {
    printf("\n--- Pedidos EM ENTREGA ---\n");
    int encontrou = 0;
    for (int i = 0; i < qtdPedidos; i++) {
        if (pedidos[i].ativo && pedidos[i].status == EM_ENTREGA) {
            printf("ID %02d: %s -> %s (%s)\n", i,
                   locais[pedidos[i].idOrigem].nome,
                   locais[pedidos[i].idDestino].nome,
                   (pedidos[i].idVeiculo >= 0 && pedidos[i].idVeiculo < qtdVeiculos)
                    ? veiculos[pedidos[i].idVeiculo].placa : "sem veículo");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pedido em andamento.\n");
        return;
    }

    int id;
    printf("\nDigite o ID do pedido a finalizar: ");
    if (scanf("%d", &id) != 1 || id < 0 || id >= qtdPedidos ||
        !pedidos[id].ativo || pedidos[id].status != EM_ENTREGA) {
        printf("ID inválido ou pedido não está em andamento.\n");
        while (getchar() != '\n');
        return;
    }

    Pedido* pedido = &pedidos[id];
    int idVeiculo = pedido->idVeiculo;
    if (idVeiculo == -1 || idVeiculo >= qtdVeiculos || !veiculos[idVeiculo].ativo) {
        printf("Veículo associado inválido.\n");
        return;
    }

    // Correção: distância de origem até destino
    float distancia = calcularDistancia(
        locais[pedido->idOrigem],
        locais[pedido->idDestino]
    );

    // Atualizações finais
    pedido->status = ENTREGUE;
    veiculos[idVeiculo].status = 1; // disponível
    veiculos[idVeiculo].idLocalAtual = pedido->idDestino;

    printf("\nEntrega finalizada!\n");
    printf("Veículo: %s (%s)\n", veiculos[idVeiculo].placa, veiculos[idVeiculo].modelo);
    printf("Nova posição do veículo: %s\n", locais[pedido->idDestino].nome);
    printf("Distância percorrida: %.2f km\n", distancia);
}