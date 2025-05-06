#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int hashUsuario(int id) {
    return id % TAM_HASH_USUARIO;
}

UsuarioHash* criarTabelaUsuarios() {
    UsuarioHash* tabela = malloc(sizeof(UsuarioHash));
    for (int i = 0; i < TAM_HASH_USUARIO; i++)
        tabela->tabela[i] = NULL;
    return tabela;
}

void cadastrarUsuario(UsuarioHash* tabela) {
    Usuario* u = malloc(sizeof(Usuario));
    printf("ID do usuário: ");
    scanf("%d", &u->id);
    getchar();
    printf("Nome: ");
    fgets(u->nome, 100, stdin);
    u->nome[strcspn(u->nome, "\n")] = 0;
    u->livrosEmprestados = 0;
    u->prox = NULL;

    int pos = hashUsuario(u->id);
    u->prox = tabela->tabela[pos];
    tabela->tabela[pos] = u;
    printf("Usuário cadastrado!\n");
}

void consultarUsuario(UsuarioHash* tabela) {
    int id;
    printf("ID do usuário: ");
    scanf("%d", &id);
    int pos = hashUsuario(id);
    Usuario* atual = tabela->tabela[pos];
    while (atual != NULL && atual->id != id)
        atual = atual->prox;
    if (atual)
        printf("Nome: %s | Livros emprestados: %d\n", atual->nome, atual->livrosEmprestados);
    else
        printf("Usuário não encontrado.\n");
}

void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "w");
    for (int i = 0; i < TAM_HASH_USUARIO; i++) {
        Usuario* atual = tabela->tabela[i];
        while (atual) {
            fprintf(f, "%d;%s;%d\n", atual->id, atual->nome, atual->livrosEmprestados);
            atual = atual->prox;
        }
    }
    fclose(f);
}

void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) return;
    Usuario u;
    char linha[200];
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d;%[^;];%d", &u.id, u.nome, &u.livrosEmprestados);
        Usuario* novo = malloc(sizeof(Usuario));
        *novo = u;
        novo->prox = tabela->tabela[hashUsuario(u.id)];
        tabela->tabela[hashUsuario(u.id)] = novo;
    }
    fclose(f);
}

void liberarUsuarios(UsuarioHash* tabela) {
    for (int i = 0; i < TAM_HASH_USUARIO; i++) {
        Usuario* atual = tabela->tabela[i];
        while (atual) {
            Usuario* tmp = atual;
            atual = atual->prox;
            free(tmp);
        }
    }
    free(tabela);
}
