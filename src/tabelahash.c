#include <string.h>
#include "tabelahash.h"

// Função de hash para ISBN (baseada em soma de caracteres)
int hashLivro(const char* isbn) {
    int soma = 0;
    for (int i = 0; isbn[i] != '\0'; i++) {
        soma += isbn[i];
    }
    return soma % TAM_HASH_LIVRO;
}

// Função de hash para usuário (ID inteiro)

int hashUsuario(int id) {
    return id % TAM_HASH_USUARIO;
}

