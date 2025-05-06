#include <string.h>
#include "tabelahash.h"

// Função de hash para ISBN (baseada em soma de caracteres)
    int hashLivro(const char *isbn) {
        int hash = 0;
        while (*isbn)
            hash += *isbn++;
        return hash % 100;
    }

// Função de hash para usuário (ID inteiro)

int hashUsuario(int id) {
    return id % 100;
}