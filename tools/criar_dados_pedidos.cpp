#include <stdio.h>
#include <string.h>
#include "../include/pedidos.h"
#include "../include/locais.h"
#include "../include/veiculos.h"

void salvarPedidosEmArquivo(const Pedido pedidos[], int quantidade) {
    FILE *f = fopen("data/pedidos.dat", "wb");
    if (f == NULL) {
        printf("Erro ao salvar pedidos no arquivo.\n");
        return;
    }

    fwrite(pedidos, sizeof(Pedido), quantidade, f);
    fclose(f);
    printf("Arquivo data/pedidos.dat gerado com sucesso com %d pedidos.\n", quantidade);
}

int main() {
    Pedido pedidos[MAX_PEDIDOS];
    int qtd = 0;

    // Pedido 0: PENDENTE, sem veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 0;
    pedidos[qtd].idDestino = 1;
    pedidos[qtd].peso = 10.0f;
    pedidos[qtd].idVeiculo = -1;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 1: EM_ENTREGA, com veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 1;
    pedidos[qtd].idDestino = 2;
    pedidos[qtd].peso = 5.5f;
    pedidos[qtd].idVeiculo = 0;
    pedidos[qtd].status = EM_ENTREGA;
    qtd++;

    // Pedido 2: ENTREGUE, com veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 2;
    pedidos[qtd].idDestino = 0;
    pedidos[qtd].peso = 3.2f;
    pedidos[qtd].idVeiculo = 1;
    pedidos[qtd].status = ENTREGUE;
    qtd++;

    // Pedido 3: PENDENTE, com veículo (ainda não em entrega)
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 3;
    pedidos[qtd].idDestino = 4;
    pedidos[qtd].peso = 8.8f;
    pedidos[qtd].idVeiculo = 2;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 4: EM_ENTREGA, outro veículo e rota
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 4;
    pedidos[qtd].idDestino = 1;
    pedidos[qtd].peso = 12.7f;
    pedidos[qtd].idVeiculo = 3;
    pedidos[qtd].status = EM_ENTREGA;
    qtd++;

    salvarPedidosEmArquivo(pedidos, qtd);

    return 0;
}