#ifndef USUARIO_H
#define USUARIO_H

#define TAM_HASH_USUARIO 100

typedef struct Usuario {
    int id;
    char nome[100];
    struct Usuario* prox;
} Usuario;

typedef struct {
    Usuario* tabela[TAM_HASH_USUARIO];
} UsuarioHash;

// Prototótipos das funções
UsuarioHash* criarTabelaUsuarios();
Usuario* criarUsuario(int id, const char* nome);
void inserirUsuario(UsuarioHash* tabela, Usuario* usuario);
Usuario* buscarUsuario(UsuarioHash* tabela, int id);
void salvarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void carregarUsuarios(UsuarioHash* tabela, const char* nomeArquivo);
void cadastrarUsuario(UsuarioHash* tabela);
void consultarUsuario(UsuarioHash* tabela);
void liberarUsuarios(UsuarioHash* tabela);

#endif
