#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "livro.h"
#include "emprestimo.h"

int main() {
    UsuarioHash* tabelaUsuarios = criarTabelaUsuarios();
    LivroHash* tabelaLivros = criarTabelaLivros();

    carregarUsuarios(tabelaUsuarios, "dados/usuarios.txt");
    carregarLivros(tabelaLivros, "dados/livros.txt");

    int opcao;
    do {
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Consultar usuário\n");
        printf("3 - Cadastrar livro\n");
        printf("4 - Consultar livro\n");
        printf("5 - Realizar empréstimo\n");
        printf("6 - Devolver livro\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarUsuario(tabelaUsuarios); break;
            case 2: consultarUsuario(tabelaUsuarios); break;
            case 3: cadastrarLivro(tabelaLivros); break;
            case 4: consultarLivro(tabelaLivros); break;
            case 5: cadastrarEmprestimo(tabelaUsuarios, tabelaLivros); break;
            case 6: devolverLivro(tabelaUsuarios, tabelaLivros); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    salvarUsuarios(tabelaUsuarios, "dados/usuarios.txt");
    salvarLivros(tabelaLivros, "dados/livros.txt");

    liberarUsuarios(tabelaUsuarios);
    liberarLivros(tabelaLivros);

    return 0;
}
