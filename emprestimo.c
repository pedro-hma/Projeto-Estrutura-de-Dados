#include "livro.h"
#include "usuario.h"

void realizarEmprestimo() { printf("Empréstimo (em desenvolvimento)\n"); }
void realizarDevolucao() { printf("Devolução (em desenvolvimento)\n"); }

void carregarDados() {
    carregarLivros();
    carregarUsuarios();
}

void salvarDados() {
    salvarLivros();
    salvarUsuarios();
}