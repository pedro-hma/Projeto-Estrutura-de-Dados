#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "tabelahash.h"

int hashLivro(const char* isbn) {
    int soma = 0;
    for (int i = 0; isbn[i] != '\0'; i++) soma += isbn[i];
    return soma % TAM_HASH_LIVRO;
}

LivroHash* criarTabelaLivros() {
    LivroHash* tabela = malloc(sizeof(LivroHash));
    for (int i = 0; i < TAM_HASH_LIVRO; i++)
        tabela->tabela[i] = NULL;
    return tabela;
}

void cadastrarLivro(LivroHash* tabela) {
    Livro* l = malloc(sizeof(Livro));
    printf("ISBN: ");
    fgets(l->isbn, 20, stdin); l->isbn[strcspn(l->isbn, "\n")] = 0;
    printf("Título: ");
    fgets(l->titulo, 100, stdin); l->titulo[strcspn(l->titulo, "\n")] = 0;
    printf("Autor: ");
    fgets(l->autor, 100, stdin); l->autor[strcspn(l->autor, "\n")] = 0;
    l->emprestado = 0;
    l->prox = NULL;

    int pos = hashLivro(l->isbn);
    l->prox = tabela->tabela[pos];
    tabela->tabela[pos] = l;
    printf("Livro cadastrado!\n");
}

void consultarLivro(LivroHash* tabela) {
    char isbn[20];
    printf("ISBN: ");
    fgets(isbn, 20, stdin); isbn[strcspn(isbn, "\n")] = 0;

    int pos = hashLivro(isbn);
    Livro* atual = tabela->tabela[pos];
    while (atual && strcmp(atual->isbn, isbn) != 0)
        atual = atual->prox;

    if (atual)
        printf("Título: %s | Autor: %s | %s\n", atual->titulo, atual->autor, atual->emprestado ? "Emprestado" : "Disponível");
    else
        printf("Livro não encontrado.\n");
}

void salvarLivros(LivroHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    for (int i = 0; i < TAM_HASH_LIVRO; i++) {
        Livro* atual = tabela->tabela[i];
        while (atual) {
            fprintf(f, "%s;%s;%s;%d\n", atual->isbn, atual->titulo, atual->autor, atual->emprestado);
            atual = atual->prox;
        }
    }
    fclose(f);
}

void carregarLivros(LivroHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;
    Livro l;
    char linha[256];
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^;];%[^;];%[^;];%d", l.isbn, l.titulo, l.autor, &l.emprestado);
        Livro* novo = malloc(sizeof(Livro));
        *novo = l;
        novo->prox = tabela->tabela[hashLivro(l.isbn)];
        tabela->tabela[hashLivro(l.isbn)] = novo;
    }
    fclose(f);
}

void liberarLivros(LivroHash* tabela) {
    for (int i = 0; i < TAM_HASH_LIVRO; i++) {
        Livro* atual = tabela->tabela[i];
        while (atual) {
            Livro* tmp = atual;
            atual = atual->prox;
            free(tmp);
        }
    }
    free(tabela);
}
