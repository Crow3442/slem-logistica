#include <stdio.h>
#include <stdlib.h>
#include "include/locais.h"

int main() {
    system("chcp 65001 > nul");  // Para suportar UTF-8 no terminal do Windows

    Local locais[MAX_LOCAIS];
    int quantidade = 0;

    // Cadastrar dois locais
    cadastrarLocal(locais, &quantidade);
    cadastrarLocal(locais, &quantidade);

    // Listar os locais cadastrados
    listarLocais(locais, quantidade);

    system("pause");  // Use getchar(); getchar(); no Linux/macOS se preferir
    return 0;
}