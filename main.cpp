#include <stdio.h>
#include <stdlib.h>
#include "include/locais.h"

int main() {
    Local locais[MAX_LOCAIS];
    int quantidade = 0;

    // Cadastro de um local
    cadastrarLocal(locais, &quantidade);

    // Impressão do local cadastrado para conferência
    printf("\n--- Local Cadastrado ---\n");
    printf("Nome         : %-30s\n", locais[0].nome);
    printf("Coordenada X : %7.2f\n", locais[0].x);
    printf("Coordenada Y : %7.2f\n", locais[0].y);
    printf("Status       : %s\n", locais[0].ativo ? "Ativo" : "Inativo");

    system("pause"); // no Windows
    return 0;
}