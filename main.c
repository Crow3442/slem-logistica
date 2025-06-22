#include <stdio.h>
#include <stdlib.h>
#include "includes/defines.h"
#include "includes/locais.h"
#include "includes/veiculos.h"
#include "includes/pedidos.h"

#define ARQ_LOCAIS "data/locais.bin"
#define ARQ_VEICULOS "data/veiculos.bin"
#define ARQ_PEDIDOS "data/pedidos.bin"

int main() {
    Local locais[MAX_LOCAIS];
    int qtdLocais = 0;

    Veiculo veiculos[MAX_VEICULOS];
    int qtdVeiculos = 0;

    Pedido pedidos[MAX_PEDIDOS];
    int qtdPedidos = 0;

    int opcao;

    carregarLocais(locais, &qtdLocais, ARQ_LOCAIS);
    carregarVeiculos(veiculos, &qtdVeiculos, ARQ_VEICULOS);
    carregarPedidos(pedidos, &qtdPedidos, ARQ_PEDIDOS);

    do {
        printf("\n===== MENU PRINCIPAL - SLEM =====\n");
        printf("1.  Cadastrar Local\n");
        printf("2.  Listar Locais\n");
        printf("3.  Atualizar Local\n");
        printf("4.  Remover Local\n");
        printf("5.  Cadastrar Veículo\n");
        printf("6.  Listar Veículos\n");
        printf("7.  Atualizar Veículo\n");
        printf("8.  Remover Veículo\n");
        printf("9.  Cadastrar Pedido\n");
        printf("10. Listar Pedidos\n");
        printf("11. Atualizar Pedido\n");
        printf("12. Remover Pedido\n");
        printf("13. Backup de Dados\n");
        printf("14. Restaurar Dados\n");
        printf("0.  Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: criarLocal(locais, &qtdLocais); break;
            case 2: listarLocais(locais, qtdLocais); break;
            case 3: atualizarLocal(locais, qtdLocais); break;
            case 4: removerLocal(locais, &qtdLocais); break;
            case 5: criarVeiculo(veiculos, &qtdVeiculos, locais, qtdLocais); break;
            case 6: listarVeiculos(veiculos, qtdVeiculos); break;
            case 7: atualizarVeiculo(veiculos, qtdVeiculos, locais, qtdLocais); break;
            case 8: removerVeiculo(veiculos, &qtdVeiculos); break;
            case 9: criarPedido(pedidos, &qtdPedidos, locais, qtdLocais); break;
            case 10: listarPedidos(pedidos, qtdPedidos); break;
            case 11: atualizarPedido(pedidos, qtdPedidos, locais, qtdLocais); break;
            case 12: removerPedido(pedidos, &qtdPedidos); break;
            case 13:
                salvarLocais(locais, qtdLocais, ARQ_LOCAIS);
                salvarVeiculos(veiculos, qtdVeiculos, ARQ_VEICULOS);
                salvarPedidos(pedidos, qtdPedidos, ARQ_PEDIDOS);
                printf("Backup realizado com sucesso!\n");
                break;
            case 14:
                carregarLocais(locais, &qtdLocais, ARQ_LOCAIS);
                carregarVeiculos(veiculos, &qtdVeiculos, ARQ_VEICULOS);
                carregarPedidos(pedidos, &qtdPedidos, ARQ_PEDIDOS);
                printf("Dados restaurados com sucesso!\n");
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}