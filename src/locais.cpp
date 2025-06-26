#include "../include/locais.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verifica se o nome digitado é vazio ou contém apenas espaços
int nomeInvalido(const char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isspace(nome[i])) {
            return 0;
        }
    }
    return 1;
}

void cadastrarLocal(Local locais[], int *quantidade) {
    if (*quantidade >= MAX_LOCAIS) {
        printf("Limite de locais atingido!\n");
        return;
    }

    Local novo;
    printf("\n--- Cadastro de Local ---\n");

    // Leitura do nome
    int nomeValido = 0;
    while (!nomeValido) {
        printf("Nome do local: ");
        fgets(novo.nome, MAX_NOME, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';

        if (strlen(novo.nome) == 0 || nomeInvalido(novo.nome)) {
            printf("Nome inválido. Digite algo significativo.\n");
        } else {
            nomeValido = 1;
        }
    }

    // Coordenada X
    int leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada X: ");
        if (scanf("%f", &novo.x) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n');
        }
    }

    // Coordenada Y
    leituraValida = 0;
    while (!leituraValida) {
        printf("Coordenada Y: ");
        if (scanf("%f", &novo.y) == 1) {
            leituraValida = 1;
        } else {
            printf("Valor inválido. Digite um número real.\n");
            while (getchar() != '\n');
        }
    }

    while (getchar() != '\n'); // Limpa buffer final
    novo.ativo = 1;
    locais[*quantidade] = novo;
    (*quantidade)++;

    printf("Local cadastrado com sucesso!\n");
}

void listarLocais(const Local locais[], int quantidade) {
    printf("\n--- Lista de Locais Cadastrados ---\n");

    int encontrados = 0;
    for (int i = 0; i < quantidade; i++) {
        if (locais[i].ativo) {
            printf("ID: %02d | Nome: %-30s | X: %7.2f | Y: %7.2f\n",
                   i, locais[i].nome, locais[i].x, locais[i].y);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum local ativo cadastrado.\n");
    }
}

void atualizarLocal(Local locais[], int quantidade) {
    listarLocais(locais, quantidade);

    printf("\nDigite o ID do local que deseja atualizar: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= quantidade || !locais[id].ativo) {
        printf("ID inválido.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // limpa buffer

    printf("\n--- Atualizar Local ---\n");

    // Atualizar nome
    printf("Novo nome (%s): ", locais[id].nome);
    char novoNome[MAX_NOME];
    fgets(novoNome, MAX_NOME, stdin);
    novoNome[strcspn(novoNome, "\n")] = '\0';
    if (strlen(novoNome) > 0 && !nomeInvalido(novoNome)) {
        strcpy(locais[id].nome, novoNome);
    }

    // Atualizar coordenada X
    printf("Nova coordenada X (%.2f): ", locais[id].x);
    float x;
    if (scanf("%f", &x) == 1) {
        locais[id].x = x;
    }
    while (getchar() != '\n');

    // Atualizar coordenada Y
    printf("Nova coordenada Y (%.2f): ", locais[id].y);
    float y;
    if (scanf("%f", &y) == 1) {
        locais[id].y = y;
    }
    while (getchar() != '\n');

    printf("Local atualizado com sucesso!\n");
}

void excluirLocal(Local locais[], int *quantidade) {
    listarLocais(locais, *quantidade);

    printf("\nDigite o ID do local que deseja excluir: ");
    int id;
    if (scanf("%d", &id) != 1 || id < 0 || id >= *quantidade || !locais[id].ativo) {
        printf("ID inválido.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // limpa buffer

    printf("Tem certeza que deseja excluir o local '%s'? (s/n): ", locais[id].nome);
    char resposta;
    scanf("%c", &resposta);
    while (getchar() != '\n');

    if (resposta == 's' || resposta == 'S') {
        locais[id].ativo = 0;
        printf("Local excluído com sucesso.\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
}

#include <stdio.h>  // já deve estar no topo, mas repita se necessário

void salvarLocaisEmArquivo(const Local locais[], int quantidade) {
    FILE *f = fopen("data/locais.dat", "wb");
    if (f == NULL) {
        printf("Erro ao salvar locais no arquivo.\n");
        return;
    }

    fwrite(locais, sizeof(Local), quantidade, f);
    fclose(f);
    printf("Backup de locais salvo com sucesso.\n");
}

int carregarLocaisDoArquivo(Local locais[]) {
    FILE *f = fopen("data/locais.dat", "rb");
    if (f == NULL) {
        printf("Arquivo locais.dat não encontrado. Nenhum local foi carregado.\n");
        return 0;
    }

    int quantidade = 0;
    while (quantidade < MAX_LOCAIS && fread(&locais[quantidade], sizeof(Local), 1, f) == 1) {
        quantidade++;
    }

    fclose(f);
    printf("Locais carregados do arquivo: %d\n", quantidade);
    return quantidade;
}
