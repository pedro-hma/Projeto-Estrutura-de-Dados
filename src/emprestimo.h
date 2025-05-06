#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "usuario.h"
#include "livro.h"

void cadastrarEmprestimo(UsuarioHash* usuarios, LivroHash* livros);
void devolverLivro(UsuarioHash* usuarios, LivroHash* livros);

#endif
