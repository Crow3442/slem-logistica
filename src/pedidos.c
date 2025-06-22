#include <stdio.h>
#include <string.h>
#include "pedidos.h"
#include "locais.h"
#include "veiculos.h"
#include "util.h"


void simularEntrega(Pedido pedidos[], int qtdPedidos, Veiculo veiculos[], int qtdVeiculos, Local locais[], int qtdLocais) {
    int id;
    printf("Digite o ID do pedido a ser entregue: ");
    scanf("%d", &id);

    int indicePedido = encontrarIndicePedido(pedidos, qtdPedidos, id);
    if (indicePedido == -1) {
        printf("Pedido não encontrado.\n");
        return;
    }

    Pedido pedido = pedidos[indicePedido];

    int indiceOrigem = encontrarIndiceLocal(locais, qtdLocais, pedido.origem);
    int indiceDestino = encontrarIndiceLocal(locais, qtdLocais, pedido.destino);

    if (indiceOrigem == -1 || indiceDestino == -1) {
        printf("Erro: origem ou destino não foram encontrados nos locais cadastrados.\n");
        return;
    }

    float menorDistancia = -1;
    int indiceVeiculoEscolhido = -1;

    for (int i = 0; i < qtdVeiculos; i++) {
        if (veiculos[i].status == STATUS_DISPONIVEL) {
            int indiceLocalVeiculo = encontrarIndiceLocal(locais, qtdLocais, veiculos[i].localAtual);
            if (indiceLocalVeiculo != -1) {
                float d = calcularDistancia(locais[indiceLocalVeiculo], locais[indiceOrigem]);
                if (menorDistancia == -1 || d < menorDistancia) {
                    menorDistancia = d;
                    indiceVeiculoEscolhido = i;
                }
            }
        }
    }

    if (indiceVeiculoEscolhido == -1) {
        printf("Nenhum veículo disponível para entrega.\n");
        return;
    }

    Veiculo *v = &veiculos[indiceVeiculoEscolhido];

    int indiceAtual = encontrarIndiceLocal(locais, qtdLocais, v->localAtual);
    float d1 = calcularDistancia(locais[indiceAtual], locais[indiceOrigem]);
    float d2 = calcularDistancia(locais[indiceOrigem], locais[indiceDestino]);
    float total = d1 + d2;

    printf("\n--- Simulação de Entrega ---\n");
    printf("Veículo: %s (%s)\n", v->placa, v->modelo);
    printf("Origem: %s\n", pedido.origem);
    printf("Destino: %s\n", pedido.destino);
    printf("Distância total: %.2f\n", total);

    v->status = STATUS_OCUPADO;
    printf("Entrega em andamento...\n");

    v->status = STATUS_DISPONIVEL;
    strcpy(v->localAtual, pedido.destino);

    printf("Entrega finalizada. Veículo agora está disponível em %s.\n", v->localAtual);
}