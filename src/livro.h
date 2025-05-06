#ifndef LIVRO_H
#define LIVRO_H
#define TAM_HASH_LIVRO 100

typedef struct Livro {
    char isbn[20];
    char titulo[100];
    char autor[100];
    int ano;
    char editora[50];
    int copias;
    struct Livro* prox;
} Livro;

typedef struct {
    Livro* tabela[TAM_HASH_LIVRO];
} LivroHash;

void cadastrarLivro();
void consultarLivro();
void carregarLivros();
void salvarLivros();
Livro* buscarLivro(const char* isbn);
LivroHash* criarTabelaLivros();
void liberarLivros(LivroHash* tabela);

#endif