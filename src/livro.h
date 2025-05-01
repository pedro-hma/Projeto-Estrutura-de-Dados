#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    char isbn[20];
    char titulo[100];
    char autor[100];
    int ano;
    char editora[50];
    int copias;
    struct Livro* prox;
} Livro;

void cadastrarLivro();
void consultarLivro();
void carregarLivros();
void salvarLivros();
Livro* buscarLivro(const char* isbn);
#endif