#include <stdio.h>
#include "../include/pedidos.h"

int main() {
    Pedido exemplos[MAX_PEDIDOS];

    exemplos[0] = {0, 1, 0, PENDENTE, 1};     // válido: com veículo
    exemplos[1] = {1, 2, 1, EM_ENTREGA, 1};   // válido: com veículo
    exemplos[2] = {2, 3, 2, ENTREGUE, 1};     // válido: com veículo
    exemplos[3] = {0, 2, -1, PENDENTE, 1};    // sem veículo
    exemplos[4] = {3, 1, -1, EM_ENTREGA, 1};  // sem veículo, status inválido → útil para testes
    exemplos[5] = {1, 0, 1, ENTREGUE, 1};     // outro com entregue

    FILE *arquivo = fopen("data/pedidos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de pedidos.\n");
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        fwrite(&exemplos[i], sizeof(Pedido), 1, arquivo);
    }

    fclose(arquivo);
    printf("Arquivo de pedidos gerado com sucesso.\n");

    return 0;
}