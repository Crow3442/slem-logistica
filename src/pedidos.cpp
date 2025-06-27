#include "../include/pedidos.h"
#include <stdio.h>

int veiculoEmUso(int idVeiculo, const Pedido pedidos[], int qtdPedidos, int idIgnorar) {
    for (int i = 0; i < qtdPedidos; i++) {
        if (i == idIgnorar) continue;
        if (pedidos[i].ativo &&
            pedidos[i].idVeiculo == idVeiculo &&
            pedidos[i].status == EM_ENTREGA) {
            return 1;
        }
    }
    return 0;
}

void cadastrarPedido(Pedido pedidos[], int *quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    if (*quantidade >= MAX_PEDIDOS) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    Pedido novo;
    novo.ativo = 1;
    novo.status = PENDENTE;
    novo.idVeiculo = -1;

    printf("\n--- Cadastro de Pedido ---\n");

    printf("Locais disponíveis:\n");
    for (int i = 0; i < qtdLocais; i++) {
        if (locais[i].ativo)
            printf("ID %02d: %s\n", i, locais[i].nome);
    }

    int origemValida = 0;
    while (!origemValida) {
        printf("Digite o ID do local de origem: ");
        if (scanf("%d", &novo.idOrigem) == 1 &&
            novo.idOrigem >= 0 && novo.idOrigem < qtdLocais && locais[novo.idOrigem].ativo) {
            origemValida = 1;
        } else {
            printf("Origem inválida. Tente novamente.\n");
            while (getchar() != '\n');
        }
    }

    int destinoValido = 0;
    while (!destinoValido) {
        printf("Digite o ID do local de destino (≠ origem): ");
        if (scanf("%d", &novo.idDestino) == 1 &&
            novo.idDestino >= 0 && novo.idDestino < qtdLocais &&
            locais[novo.idDestino].ativo && novo.idDestino != novo.idOrigem) {
            destinoValido = 1;
        } else {
            printf("Destino inválido. Tente novamente.\n");
            while (getchar() != '\n');
        }
    }

    while (getchar() != '\n');
    pedidos[*quantidade] = novo;
    (*quantidade)++;

    printf("Pedido cadastrado com sucesso!\n");
}

void listarPedidos(const Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    printf("\n--- Lista de Pedidos ---\n");
    printf("%-4s | %-20s -> %-20s | %-10s | %s\n", "ID", "Origem", "Destino", "Status", "Veículo");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < quantidade; i++) {
        if (pedidos[i].ativo) {
            const char* nomeOrigem = (pedidos[i].idOrigem >= 0 && pedidos[i].idOrigem < qtdLocais) ? locais[pedidos[i].idOrigem].nome : "Desconhecido";
            const char* nomeDestino = (pedidos[i].idDestino >= 0 && pedidos[i].idDestino < qtdLocais) ? locais[pedidos[i].idDestino].nome : "Desconhecido";
            const char* statusStr = pedidos[i].status == PENDENTE ? "Pendente" :
                                    pedidos[i].status == EM_ENTREGA ? "Em entrega" : "Entregue";
            const char* nomeVeiculo = (pedidos[i].idVeiculo >= 0 && pedidos[i].idVeiculo < qtdVeiculos && veiculos[pedidos[i].idVeiculo].ativo)
                                       ? veiculos[pedidos[i].idVeiculo].placa : "Não atribuído";

            printf("%02d   | %-20s -> %-20s | %-10s | %s\n", i, nomeOrigem, nomeDestino, statusStr, nomeVeiculo);
        }
    }
}

void atualizarPedido(Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    listarPedidos(pedidos, quantidade, locais, qtdLocais, veiculos, qtdVeiculos);

    printf("\nDigite o ID do pedido que deseja atualizar: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= quantidade || !pedidos[id].ativo) {
        printf("ID inválido.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    Pedido original = pedidos[id];
    Pedido novo = original;

    int finalizado = 0;
    while (!finalizado) {
        int continuar = 1;
        while (continuar) {
            printf("\nQual informação deseja alterar?\n");
            printf("1. Origem\n2. Destino\n3. Veículo\n4. Status\n0. Cancelar alterações\nEscolha: ");
            int escolha;
            scanf("%d", &escolha);
            while (getchar() != '\n');

            switch (escolha) {
                case 1: {
                    if (novo.status == ENTREGUE) {
                        printf("Não é possível alterar a origem de um pedido já entregue.\n");
                        break;
                    }

                    printf("\nLocais disponíveis para origem:\n");
                    for (int i = 0; i < qtdLocais; i++) {
                        if (locais[i].ativo && i != novo.idOrigem && i != novo.idDestino) {
                            printf("ID %02d: %s\n", i, locais[i].nome);
                        }
                    }

                    int nova;
                    do {
                        printf("Digite o novo ID de origem: ");
                        if (scanf("%d", &nova) == 1 &&
                            nova >= 0 && nova < qtdLocais &&
                            locais[nova].ativo &&
                            nova != novo.idOrigem &&
                            nova != novo.idDestino) {
                            novo.idOrigem = nova;
                            break;
                        } else {
                            printf("Origem inválida ou igual ao valor atual/destino.\n");
                            while (getchar() != '\n');
                        }
                    } while (1);
                    break;
                }
                case 2: {
                    if (novo.status == ENTREGUE) {
                        printf("Não é possível alterar o destino de um pedido já entregue.\n");
                        break;
                    }

                    printf("\nLocais disponíveis para destino:\n");
                    for (int i = 0; i < qtdLocais; i++) {
                        if (locais[i].ativo && i != novo.idDestino && i != novo.idOrigem) {
                            printf("ID %02d: %s\n", i, locais[i].nome);
                        }
                    }

                    int nova;
                    do {
                        printf("Digite o novo ID de destino: ");
                        if (scanf("%d", &nova) == 1 &&
                            nova >= 0 && nova < qtdLocais &&
                            locais[nova].ativo &&
                            nova != novo.idDestino &&
                            nova != novo.idOrigem) {
                            novo.idDestino = nova;
                            break;
                        } else {
                            printf("Destino inválido ou igual ao valor atual/origem.\n");
                            while (getchar() != '\n');
                        }
                    } while (1);
                    break;
                }
                case 3: {
                    printf("\nVeículos disponíveis:\n");
                    for (int i = 0; i < qtdVeiculos; i++) {
                        if (veiculos[i].ativo && veiculos[i].status == 1 &&
                            !veiculoEmUso(i, pedidos, quantidade, id) &&
                            i != novo.idVeiculo) {
                            printf("ID %02d: %s (%s)\n", i, veiculos[i].placa, veiculos[i].modelo);
                        }
                    }

                    int v;
                    do {
                        printf("Digite o ID do novo veículo (-1 para remover): ");
                        if (scanf("%d", &v) == 1 &&
                            (v == -1 || (v >= 0 && v < qtdVeiculos &&
                                         veiculos[v].ativo && veiculos[v].status == 1 &&
                                         !veiculoEmUso(v, pedidos, quantidade, id) &&
                                         v != novo.idVeiculo))) {
                            novo.idVeiculo = v;
                            break;
                        } else {
                            printf("Veículo inválido, em uso ou igual ao atual.\n");
                            while (getchar() != '\n');
                        }
                    } while (1);
                    break;
                }
                case 4: {
                    int s;
                    do {
                        printf("Status atual: %d\n", novo.status);
                        printf("Novo status (0=PENDENTE, 1=EM_ENTREGA, 2=ENTREGUE): ");
                        if (scanf("%d", &s) == 1 && s >= 0 && s <= 2) {
                            if (s == EM_ENTREGA && novo.idVeiculo == -1) {
                                printf("Não é possível iniciar entrega sem veículo atribuído.\n");
                            } else if (s == ENTREGUE && novo.status != EM_ENTREGA) {
                                printf("Só é possível concluir entrega se já estiver EM ENTREGA.\n");
                            } else if (s != novo.status) {
                                novo.status = (StatusPedido)s;
                                break;
                            } else {
                                printf("Novo status é igual ao atual.\n");
                            }
                        } else {
                            printf("Status inválido.\n");
                        }
                        while (getchar() != '\n');
                    } while (1);
                    break;
                }
                case 0:
                    printf("Alterações canceladas.\n");
                    return;
                default:
                    printf("Opção inválida.\n");
            }

            printf("\nDeseja alterar mais alguma coisa? (1=sim / 0=não): ");
            scanf("%d", &continuar);
            while (getchar() != '\n');
        }

        // Mostrar resumo final
        printf("\n--- Resumo final do pedido ---\n");
        printf("Origem : %s\n", locais[novo.idOrigem].nome);
        printf("Destino: %s\n", locais[novo.idDestino].nome);
        printf("Veículo: %s\n", (novo.idVeiculo == -1) ? "Nenhum" : veiculos[novo.idVeiculo].placa);
        printf("Status : %s\n", novo.status == PENDENTE ? "PENDENTE" :
                                   novo.status == EM_ENTREGA ? "EM ENTREGA" : "ENTREGUE");

        int decisao;
        do {
            printf("\nDeseja:\n1. Confirmar alterações\n2. Alterar mais\n3. Cancelar\nEscolha: ");
            scanf("%d", &decisao);
            while (getchar() != '\n');

            if (decisao == 1) {
                pedidos[id] = novo;
                printf("Alterações aplicadas com sucesso.\n");
                finalizado = 1;
            } else if (decisao == 2) {
                break; // volta para o loop principal sem apagar dados
            } else if (decisao == 3) {
                printf("Alterações canceladas.\n");
                finalizado = 1;
            } else {
                printf("Opção inválida.\n");
            }
        } while (decisao < 1 || decisao > 3);
    }
}

void excluirPedido(Pedido pedidos[], int quantidade, const Local locais[], int qtdLocais, const Veiculo veiculos[], int qtdVeiculos) {
    listarPedidos(pedidos, quantidade, locais, qtdLocais, veiculos, qtdVeiculos);

    printf("\nDigite o ID do pedido que deseja excluir: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= quantidade || !pedidos[id].ativo) {
        printf("ID inválido ou pedido inativo.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (pedidos[id].status == ENTREGUE) {
        printf("Não é permitido excluir pedidos já entregues.\n");
        return;
    }

    // Mostrar resumo do pedido
    const char* nomeOrigem = locais[pedidos[id].idOrigem].nome;
    const char* nomeDestino = locais[pedidos[id].idDestino].nome;
    const char* nomeVeiculo = (pedidos[id].idVeiculo >= 0 &&
                               pedidos[id].idVeiculo < qtdVeiculos &&
                               veiculos[pedidos[id].idVeiculo].ativo)
                               ? veiculos[pedidos[id].idVeiculo].placa
                               : "Não atribuído";
    const char* statusStr = pedidos[id].status == PENDENTE ? "Pendente" :
                            pedidos[id].status == EM_ENTREGA ? "Em entrega" : "Entregue";

    printf("\n--- Resumo do Pedido ---\n");
    printf("Origem : %s\n", nomeOrigem);
    printf("Destino: %s\n", nomeDestino);
    printf("Veículo: %s\n", nomeVeiculo);
    printf("Status : %s\n", statusStr);

    printf("\nTem certeza que deseja excluir este pedido? (1=sim / 0=não): ");
    int confirmar;
    scanf("%d", &confirmar);
    while (getchar() != '\n');

    if (confirmar == 1) {
        pedidos[id].ativo = 0;
        printf("Pedido excluído com sucesso.\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
}

int carregarPedidosDoArquivo(Pedido pedidos[]) {
    FILE *arquivo = fopen("dados/pedidos.dat", "rb");
    if (arquivo == NULL) {
        return 0; // Arquivo ainda não existe
    }

    int i = 0;
    while (i < MAX_PEDIDOS && fread(&pedidos[i], sizeof(Pedido), 1, arquivo) == 1) {
        i++;
    }

    fclose(arquivo);
    return i; // Retorna a quantidade de pedidos lida
}

void salvarPedidosEmArquivo(const Pedido pedidos[], int quantidade) {
    FILE *arquivo = fopen("dados/pedidos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de pedidos para escrita.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fwrite(&pedidos[i], sizeof(Pedido), 1, arquivo);
    }

    fclose(arquivo);
}
