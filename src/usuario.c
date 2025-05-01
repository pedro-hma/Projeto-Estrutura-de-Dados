#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "tabelahash.h"
#include "tabelahash.c"

void cadastrarUsuario() {
    void cadastrarUsuario(UsuarioHash* tabela) {
        int id;
        char nome[100];
    
        printf("Digite o ID do usuário: ");
        scanf("%d", &id);
        getchar(); // Limpar buffer do teclado
    
        if (buscarUsuario(tabela, id)) {
            printf("Usuário com esse ID já existe!\n");
            return;
        }
    
        printf("Digite o nome do usuário: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remover \n
    
        Usuario* novo = criarUsuario(id, nome);
        inserirUsuario(tabela, novo);
    
        printf("Usuário cadastrado com sucesso!\n");
    }
    
}
void consultarUsuario(){
    void consultarUsuario(UsuarioHash* tabela) {
        int id;
        printf("Digite o ID do usuário: ");
        scanf("%d", &id);
    
        Usuario* usuario = buscarUsuario(tabela, id);
        if (usuario) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuario->id);
            printf("Nome: %s\n", usuario->nome);
        } else {
            printf("Usuário não encontrado.\n");
        }
    }
    
}
void carregarUsuarios(){
    void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
        FILE* arq = fopen(nomeArquivo, "r");
        if (!arq) {
            return;  // Se o arquivo não existir, apenas retorna
        }
    
        int id;
        char nome[100];
        while (fscanf(arq, "%d;%[^\n]\n", &id, nome) != EOF) {
            Usuario* u = criarUsuario(id, nome);
            inserirUsuario(tabela, u);
        }
    
        fclose(arq);
    }
    
}
void salvarUsuarios(){
    void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo) {
        FILE* arq = fopen(nomeArquivo, "w");
        if (!arq) {
            perror("Erro ao abrir arquivo de usuários");
            return;
        }
    
        for (int i = 0; i < TAM_HASH_USUARIO; i++) {
            Usuario* atual = tabela->tabela[i];
            while (atual) {
                fprintf(arq, "%d;%s\n", atual->id, atual->nome);
                atual = atual->prox;
            }
        }
    
        fclose(arq);
    }
    
}