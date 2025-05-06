#ifndef LIVRO_H
#define LIVRO_H

#define TAM_HASH_LIVRO 100

typedef struct Livro {
    char isbn[20];
    char titulo[100];
    char autor[100];
    int emprestado;
    int disponivel;
    struct Livro* prox;
} Livro;

typedef struct {
    Livro* tabela[TAM_HASH_LIVRO];
} LivroHash;

LivroHash* criarTabelaLivros();
int livroDisponivel(Livro* livro);
int hashLivro(const char* isbn);
void cadastrarLivro(LivroHash* tabela);
void consultarLivro(LivroHash* tabela);
void salvarLivros(LivroHash* tabela, const char* nomeArquivo);
void carregarLivros(LivroHash* tabela, const char* nomeArquivo);
void liberarLivros(LivroHash* tabela);

#endif
