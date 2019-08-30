#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "struct_func.h"

void menu_inicial(int *n) {
    printf("---------------Menu Inicial---------------\n");
    printf("(1) Cadastrar\n");
    printf("(2) Listar\n");
    printf("(3) Editar\n");
    printf("(4) Excluir\n");
    printf(": Qual opcao deseja realizar --->  ");
    scanf("%d", n);
}

int menu_cadastro(int *quant) {
    int x = *quant;
    printf("---------Modo Cadastro---------\n");
    printf("Digite quantos funcionarios deseja inserir ---> ");
    scanf("%d", quant);

    return x;
}

funcionario * aloca_funcionario(int quant) {
    int i = 0;
    funcionario *func;
    func = (funcionario *) malloc(quant * sizeof(funcionario));
    check(&func, i, 0);

    for(i = 0; i < quant; i++) {
        (func[i]).nome = (char *) malloc(35 * sizeof(char));
        (func[i]).email = (char *) malloc(35 * sizeof(char));
        check(&func, i, 1);
    }

    return func;
}

void check(funcionario **confere, int ind, int x) {
    if((*confere + ind)->nome == NULL && x == 1) {
        if((*confere + ind)->email == NULL) {
            printf("ERRO\n");
            exit(2);
        }
    }
    if((*confere) == NULL && x == 0) {
        printf("ERRO\n");
        exit(2);
    }
}

void set_struct(funcionario *func, int quant) {
    int i;
    printf("-------------------------------------------\n");

    for(i = 0; i < quant; i++) {
        printf("***CADASTRO DO FUNCIONARIO[%d]***\n", i+1);
        printf("Nome: ");
        getchar();
        scanf("%[^\n]", func[i].nome);
        printf("Idade: ");
        scanf("%d", &func[i].idade);
        printf("Email: ");
        getchar();
        scanf("%[^\n]", func[i].email);
    }
}

