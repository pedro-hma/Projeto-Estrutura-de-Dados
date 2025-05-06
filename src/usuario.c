#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "tabelahash.h"

void cadastrarUsuario(Usuario* tabela[], Usuario novo) {
    int index = hashUsuario(novo.id);
    tabela[index] = (Usuario*) malloc(sizeof(Usuario));
    if (tabela[index] != NULL) {
        *tabela[index] = novo;
    }
}

Usuario* consultarUsuario(Usuario* tabela[], int id) {
    int index = hashUsuario(id);
    return tabela[index];
}

void carregarUsuarios(Usuario* tabela[], const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;

    Usuario u;
    while (fscanf(f, "%d;%[^;\n]\n", &u.id, u.nome) == 2) {
        cadastrarUsuario(tabela, u);
    }

    fclose(f);
}

void salvarUsuarios(Usuario* tabela[], const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    if (!f) return;

    for (int i = 0; i < 100; i++) {
        if (tabela[i]) {
            fprintf(f, "%d;%s\n", tabela[i]->id, tabela[i]->nome);
        }
    }

    fclose(f);
}

void liberarUsuarios(Usuario* tabela[]) {
    for (int i = 0; i < 100; i++) {
        if (tabela[i]) {
            free(tabela[i]);
        }
    }
}
