#ifndef LOCAIS_H
#define LOCAIS_H

#define MAX_LOCAIS 100
#define MAX_NOME 100

// Estrutura para representar um local
typedef struct {
    char nome[MAX_NOME];  // Identificador único
    float x;              // Coordenada X
    float y;              // Coordenada Y
    int ativo;            // 1 = ativo, 0 = inativo (exclusão lógica)
} Local;

// CRUD
void cadastrarLocal(Local locais[], int *quantidade);
void listarLocais(const Local locais[], int quantidade);
void atualizarLocal(Local locais[], int quantidade);
void excluirLocal(Local locais[], int *quantidade);

// Auxiliar
int encontrarLocalPorNome(const Local locais[], int quantidade, const char nome[]);
int nomeInvalido(const char nome[]);

#endif