#include <stdio.h>
#include <string.h>
#include "emprestimo.h"

void cadastrarEmprestimo(UsuarioHash* usuarios, LivroHash* livros) {
    int id;
    char isbn[20];
    printf("ID do usuário: ");
    scanf("%d", &id);
    getchar();
    printf("ISBN do livro: ");
    fgets(isbn, 20, stdin); isbn[strcspn(isbn, "\n")] = 0;

    Usuario* u = usuarios->tabela[hashUsuario(id)];
    while (u && u->id != id) u = u->prox;
    if (!u) { printf("Usuário não encontrado.\n"); return; }

    Livro* l = livros->tabela[hashLivro(isbn)];
    while (l && strcmp(l->isbn, isbn) != 0) l = l->prox;
    if (!l) { printf("Livro não encontrado.\n"); return; }

    if (l->emprestado) {
        printf("Livro já está emprestado.\n");
    } else {
        l->emprestado = 1;
        u->livrosEmprestados++;
        printf("Empréstimo realizado!\n");
    }
}

void devolverLivro(UsuarioHash* usuarios, LivroHash* livros) {
    int id;
    char isbn[20];
    printf("ID do usuário: ");
    scanf("%d", &id);
    getchar();
    printf("ISBN do livro: ");
    fgets(isbn, 20, stdin); isbn[strcspn(isbn, "\n")] = 0;

    Usuario* u = usuarios->tabela[hashUsuario(id)];
    while (u && u->id != id) u = u->prox;
    if (!u) { printf("Usuário não encontrado.\n"); return; }

    Livro* l = livros->tabela[hashLivro(isbn)];
    while (l && strcmp(l->isbn, isbn) != 0) l = l->prox;
    if (!l) { printf("Livro não encontrado.\n"); return; }

    if (!l->emprestado) {
        printf("Livro já está disponível.\n");
    } else {
        l->emprestado = 0;
        u->livrosEmprestados--;
        printf("Livro devolvido com sucesso!\n");
    }
}
