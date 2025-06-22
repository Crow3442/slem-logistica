#include "defines.h"
#include "util.h"


#ifndef PEDIDOS_H
#define PEDIDOS_H

#define MAX_PEDIDOS 100

typedef struct {
    int id;
    char origem[TAM_NOME];
    char destino[TAM_NOME];
    float peso;
} Pedido;

void criarPedido(Pedido pedidos[], int *qtd, Local locais[], int qtdLocais);
void listarPedidos(Pedido pedidos[], int qtd);
void atualizarPedido(Pedido pedidos[], int qtd, Local locais[], int qtdLocais);
void removerPedido(Pedido pedidos[], int *qtd);

int encontrarIndicePedido(Pedido pedidos[], int qtd, int id);
void salvarPedidos(Pedido pedidos[], int qtd, const char *arquivo);
void carregarPedidos(Pedido pedidos[], int *qtd, const char *arquivo);

simularEntrega(pedidos, qtdPedidos, veiculos, qtdVeiculos, locais, qtdLocais);



#endif
