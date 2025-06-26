#ifndef LOCAIS_H
#define LOCAIS_H

#define MAX_LOCAIS 100
#define MAX_NOME 100

// Estrutura para representar um local
typedef struct {
    char nome[MAX_NOME];
    float x;
    float y;
    int ativo;  // 1 = ativo, 0 = inativo
} Local;

// Funções CRUD
void cadastrarLocal(Local locais[], int *quantidade);
void listarLocais(const Local locais[], int quantidade);
void atualizarLocal(Local locais[], int quantidade);
void excluirLocal(Local locais[], int *quantidade);

// Funções auxiliares
int encontrarLocalPorNome(const Local locais[], int quantidade, const char nome[]);
int nomeInvalido(const char nome[]);

// Funções de arquivo (backup/restauração)
void salvarLocaisEmArquivo(const Local locais[], int quantidade);
int carregarLocaisDoArquivo(Local locais[]);

#endif