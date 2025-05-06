#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "tabelahash.h"

void cadastrarLivro(Livro* tabela[], Livro novo) {
    int index = hashLivro(novo.isbn);
    tabela[index] = (Livro*) malloc(sizeof(Livro));
    if (tabela[index] != NULL) {
        *tabela[index] = novo;
    }
}

Livro* consultarLivro(Livro* tabela[], const char* isbn) {
    int index = hashLivro(isbn);
    return tabela[index];
}

void carregarLivros(Livro* tabela[], const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;

    Livro l;
    while (fscanf(f, "%[^;];%[^;];%d\n", l.isbn, l.titulo, &l.disponivel) == 3) {
        cadastrarLivro(tabela, l);
    }

    fclose(f);
}

void salvarLivros(Livro* tabela[], const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    if (!f) return;

    for (int i = 0; i < 100; i++) {
        if (tabela[i]) {
            fprintf(f, "%s;%s;%d\n", tabela[i]->isbn, tabela[i]->titulo, tabela[i]->disponivel);
        }
    }

    fclose(f);
}

void liberarLivros(Livro* tabela[]) {
    for (int i = 0; i < 100; i++) {
        if (tabela[i]) {
            free(tabela[i]);
        }
    }
}
int livroDisponivel(Livro* livro) {
    if (livro == NULL) return 0;  // Livro inexistente não está disponível
    return livro->disponivel;
}
