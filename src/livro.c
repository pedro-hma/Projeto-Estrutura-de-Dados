#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

#define TAM 100
Livro* tabelaLivros[TAM];

int hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % TAM;
}

Livro* buscarLivro(const char* isbn) {
    int h = hash(isbn);
    Livro* atual = tabelaLivros[h];
    while (atual) {
        if (strcmp(atual->isbn, isbn) == 0) return atual;
        atual = atual->prox;
    }
    return NULL;
}

void cadastrarLivro() {
    Livro* novo = malloc(sizeof(Livro));
    printf("ISBN: "); fgets(novo->isbn, 20, stdin); strtok(novo->isbn, "\n");
    printf("Título: "); fgets(novo->titulo, 100, stdin); strtok(novo->titulo, "\n");
    printf("Autor: "); fgets(novo->autor, 100, stdin); strtok(novo->autor, "\n");
    printf("Ano: "); scanf("%d", &novo->ano); getchar();
    printf("Editora: "); fgets(novo->editora, 50, stdin); strtok(novo->editora, "\n");
    printf("Cópias: "); scanf("%d", &novo->copias); getchar();

    int h = hash(novo->isbn);
    novo->prox = tabelaLivros[h];
    tabelaLivros[h] = novo;

    printf("Livro cadastrado com sucesso!\n");
}

void consultarLivro() {
    char isbn[20];
    printf("ISBN do livro: ");
    fgets(isbn, 20, stdin); strtok(isbn, "\n");
    Livro* l = buscarLivro(isbn);
    if (l) {
        printf("Título: %s, Autor: %s, Cópias: %d\n", l->titulo, l->autor, l->copias);
    } else {
        printf("Livro não encontrado.\n");
    }
}

void carregarLivros() {
    FILE* f = fopen("livros.txt", "r");
    if (!f) return;
    while (!feof(f)) {
        Livro* l = malloc(sizeof(Livro));
        if (fscanf(f, "%[^|]|%[^|]|%[^|]|%d|%[^|]|%d\n",
            l->isbn, l->titulo, l->autor, &l->ano, l->editora, &l->copias) == 6) {
            int h = hash(l->isbn);
            l->prox = tabelaLivros[h];
            tabelaLivros[h] = l;
        } else {
            free(l);
        }
    }
    fclose(f);
}

void salvarLivros() {
    FILE* f = fopen("livros.txt", "w");
    for (int i = 0; i < TAM; i++) {
        Livro* l = tabelaLivros[i];
        while (l) {
            fprintf(f, "%s|%s|%s|%d|%s|%d\n",
                l->isbn, l->titulo, l->autor, l->ano, l->editora, l->copias);
            l = l->prox;
        }
    }
    fclose(f);
}
LivroHash* criarTabelaLivros() {
    LivroHash* tabela = malloc(sizeof(LivroHash));
    if (!tabela) {
        return NULL;
    }
    for (int i = 0; i < TAM_HASH_LIVRO; i++) {
        tabela->tabela[i] = NULL;
    }
    return tabela;
}