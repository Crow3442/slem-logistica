#ifndef SISTEMA_H
#define SISTEMA_H

#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"

// Calcula a distância euclidiana entre dois locais
float calcularDistancia(Local a, Local b);

// Retorna o índice do veículo mais próximo de um local de origem
int encontrarVeiculoMaisProximo(const Local locais[], int qtdLocais,
                                const Veiculo veiculos[], int qtdVeiculos,
                                int idOrigem);

// Inicia uma entrega (atribui veículo e muda status para EM_ENTREGA)
void iniciarEntrega(Pedido pedidos[], int qtdPedidos,
                    Veiculo veiculos[], int qtdVeiculos,
                    Local locais[], int qtdLocais);

// Finaliza uma entrega (muda status para ENTREGUE, libera o veículo)
void finalizarEntrega(Pedido pedidos[], int qtdPedidos,
                      Veiculo veiculos[], int qtdVeiculos,
                      Local locais[], int qtdLocais);

#endif