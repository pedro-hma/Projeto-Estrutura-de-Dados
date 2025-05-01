#include <stdio.h>
#include "livro.h"
#include "usuario.h"
#include "emprestimo.h"

int main() {
    int opcao;

    carregarDados(); // Carrega arquivos para memória

    do {
        printf("\n===== Sistema de Biblioteca =====\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Realizar Empréstimo\n");
        printf("4. Realizar Devolução\n");
        printf("5. Consultar Livro\n");
        printf("6. Consultar Usuário\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: cadastrarLivro(); break;
            case 2: cadastrarUsuario(); break;
            case 3: realizarEmprestimo(); break;
            case 4: realizarDevolucao(); break;
            case 5: consultarLivro(); break;
            case 6: consultarUsuario(); break;
        }
    } while (opcao != 0);

    salvarDados(); // Salva alterações nos arquivos
    return 0;
}