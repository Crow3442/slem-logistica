#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "locais.h"
#include "veiculos.h"

#define MAX_PEDIDOS 100

// Status possíveis de um pedido
typedef enum {
    PENDENTE,
    EM_ENTREGA,
    ENTREGUE
} StatusPedido;

// Estrutura de Pedido com peso incluído
typedef struct {
    int ativo;             // 1 = ativo, 0 = removido
    int idOrigem;          // índice do vetor de locais
    int idDestino;         // índice do vetor de locais
    float peso;            // peso do item em kg
    int idVeiculo;         // índice do vetor de veículos (-1 se não atribuído)
    StatusPedido status;   // PENDENTE, EM_ENTREGA, ENTREGUE
} Pedido;

// Funções CRUD
void cadastrarPedido(Pedido pedidos[], int* quantidade,
                     const Local locais[], int qtdLocais,
                     const Veiculo veiculos[], int qtdVeiculos);

void listarPedidos(const Pedido pedidos[], int quantidade,
                   const Local locais[], int qtdLocais,
                   const Veiculo veiculos[], int qtdVeiculos);

void atualizarPedido(Pedido pedidos[], int quantidade,
                     const Local locais[], int qtdLocais,
                     const Veiculo veiculos[], int qtdVeiculos);

void excluirPedido(Pedido pedidos[], int quantidade,
                   const Local locais[], int qtdLocais,
                   const Veiculo veiculos[], int qtdVeiculos);

void removerPedido(Pedido pedidos[], int* quantidade); // opcional, se mantiver uso

// Funções de persistência
void salvarPedidosEmArquivo(const Pedido pedidos[], int quantidade);
int carregarPedidosDoArquivo(Pedido pedidos[]);

void salvarPedidos(const Pedido pedidos[], int quantidade, const char* nomeArquivo);
int carregarPedidos(Pedido pedidos[], const char* nomeArquivo);

// Utilitários
int veiculoEmUso(int idVeiculo, const Pedido pedidos[], int qtdPedidos, int idIgnorar);

#endif