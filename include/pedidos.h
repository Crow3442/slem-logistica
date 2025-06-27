#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "locais.h"
#include "veiculos.h"

#define MAX_PEDIDOS 200

typedef enum {
    PENDENTE = 0,
    EM_ENTREGA = 1,
    ENTREGUE = 2
} StatusPedido;

typedef struct {
    int idOrigem;
    int idDestino;
    int idVeiculo;   // -1 se nenhum veículo atribuído ainda
    StatusPedido status;
    int ativo;       // 1 = ativo, 0 = excluído
} Pedido;

// CRUD
void cadastrarPedido(Pedido pedidos[], int *quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos);
void listarPedidos(const Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos);
void atualizarPedido(Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos);
void excluirPedido(Pedido pedidos[], int *quantidade);

#endif