#include <stdio.h>
#include <stdlib.h>
#include "include/locais.h"

int main() {
    system("chcp 65001 > nul");  // Suporte UTF-8 no Windows

    Local locais[MAX_LOCAIS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n======= MENU DE LOCAIS =======\n");
        printf("1. Cadastrar local\n");
        printf("2. Listar locais\n");
        printf("3. Atualizar local\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpa buffer

        switch (opcao) {
            case 1:
                cadastrarLocal(locais, &quantidade);
                break;
            case 2:
                listarLocais(locais, quantidade);
                break;
            case 3:
                atualizarLocal(locais, quantidade);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}