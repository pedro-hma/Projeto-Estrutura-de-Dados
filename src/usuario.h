#ifndef USUARIO_H
#define USUARIO_H

#define TAM_HASH_USUARIO 100

typedef struct Usuario {
    int id;
    char nome[100];
    int livrosEmprestados;
    struct Usuario* prox;
} Usuario;

typedef struct {
    Usuario* tabela[TAM_HASH_USUARIO];
} UsuarioHash;

UsuarioHash* criarTabelaUsuarios();
int hashUsuario(int id);
void cadastrarUsuario(UsuarioHash* tabela);
void consultarUsuario(UsuarioHash* tabela);
void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void liberarUsuarios(UsuarioHash* tabela);

#endif
