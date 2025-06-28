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
    pedidos[qtd].idDestino = 3;
    pedidos[qtd].peso = 3.2f;
    pedidos[qtd].idVeiculo = 1;
    pedidos[qtd].status = ENTREGUE;
    qtd++;

    // Pedido 3: PENDENTE, com veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 3;
    pedidos[qtd].idDestino = 4;
    pedidos[qtd].peso = 8.8f;
    pedidos[qtd].idVeiculo = 2;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 4: EM_ENTREGA
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 4;
    pedidos[qtd].idDestino = 5;
    pedidos[qtd].peso = 12.7f;
    pedidos[qtd].idVeiculo = 3;
    pedidos[qtd].status = EM_ENTREGA;
    qtd++;

    // Pedido 5: ENTREGUE
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 5;
    pedidos[qtd].idDestino = 6;
    pedidos[qtd].peso = 4.0f;
    pedidos[qtd].idVeiculo = 4;
    pedidos[qtd].status = ENTREGUE;
    qtd++;

    // Pedido 6: PENDENTE, sem veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 6;
    pedidos[qtd].idDestino = 7;
    pedidos[qtd].peso = 2.3f;
    pedidos[qtd].idVeiculo = -1;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 7: PENDENTE, com veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 8;
    pedidos[qtd].idDestino = 9;
    pedidos[qtd].peso = 6.5f;
    pedidos[qtd].idVeiculo = 5;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 8: EM_ENTREGA
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 10;
    pedidos[qtd].idDestino = 11;
    pedidos[qtd].peso = 1.2f;
    pedidos[qtd].idVeiculo = 6;
    pedidos[qtd].status = EM_ENTREGA;
    qtd++;

    // Pedido 9: ENTREGUE
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 12;
    pedidos[qtd].idDestino = 13;
    pedidos[qtd].peso = 14.1f;
    pedidos[qtd].idVeiculo = 7;
    pedidos[qtd].status = ENTREGUE;
    qtd++;

    // Pedido 10: PENDENTE, sem veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 14;
    pedidos[qtd].idDestino = 15;
    pedidos[qtd].peso = 7.0f;
    pedidos[qtd].idVeiculo = -1;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 11: PENDENTE, com veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 16;
    pedidos[qtd].idDestino = 17;
    pedidos[qtd].peso = 9.3f;
    pedidos[qtd].idVeiculo = 8;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    // Pedido 12: EM_ENTREGA
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 18;
    pedidos[qtd].idDestino = 19;
    pedidos[qtd].peso = 5.0f;
    pedidos[qtd].idVeiculo = 9;
    pedidos[qtd].status = EM_ENTREGA;
    qtd++;

    // Pedido 13: ENTREGUE
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 19;
    pedidos[qtd].idDestino = 0;
    pedidos[qtd].peso = 11.2f;
    pedidos[qtd].idVeiculo = 10;
    pedidos[qtd].status = ENTREGUE;
    qtd++;

    // Pedido 14: PENDENTE, sem veículo
    pedidos[qtd].ativo = 1;
    pedidos[qtd].idOrigem = 7;
    pedidos[qtd].idDestino = 3;
    pedidos[qtd].peso = 6.7f;
    pedidos[qtd].idVeiculo = -1;
    pedidos[qtd].status = PENDENTE;
    qtd++;

    salvarPedidosEmArquivo(pedidos, qtd);

    return 0;
}