#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcoes.h"
#include "struct_func.h"

void menu_inicial(int *n) {
    system("clear");
    printf("---------------Menu Inicial---------------\n");
    printf("(1) Cadastrar\n");
    printf("(2) Listar\n");
    printf("(3) Editar\n");
    printf("(4) Excluir\n");
    printf("(0) Fechar o programa\n");
    printf(": Qual opcao deseja realizar --->  ");
    scanf("%d", n);
}

int menu_cadastro(int *quant, int *x) {
    *x = *quant;
    printf("---------Modo Cadastro---------\n");
    printf("Digite quantos funcionarios deseja inserir ---> ");
    scanf("%d", quant);

    return *x;
}

funcionario * aloca_funcionario(funcionario *empregado, int quant, int *w, int *block) {
    int i = 0;

    if(*block == 0) {
        funcionario *func;
        func = (funcionario *) malloc(quant * sizeof(funcionario));
        check(&func, i, 0);

        for(i = 0; i < quant; i++) {
            (func[i]).nome = (char *) malloc(35 * sizeof(char));
            (func[i]).email = (char *) malloc(35 * sizeof(char));
            check(&func, i, 1);
        }
        *block = 1;
        return func;
    }
    else {
        empregado = (funcionario *) realloc(empregado, quant * sizeof(funcionario));
        check(&empregado, quant, 0);

        for(i = *w; i < quant; i++) {
            (empregado[i]).nome = (char *) malloc(35 * sizeof(char));
            (empregado[i]).email = (char *) malloc(35 * sizeof(char));
            check(&empregado, i, 1);
        }
    }

    return empregado;
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

void set_struct(funcionario *func, int quant, int *w) {
    int i;
    printf("-------------------------------------------\n");

    for(i = *w; i < quant; i++) {
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
    *w = quant;
    printf("%d Funcionarios Cadastrados com sucesso!\n", quant);
    sleep(1);
}

void lista_funcionarios(funcionario *func, int quant, int fixa) {
    int i, j;
    printf("-----------Lista de Funcionarios-----------\n");

    for(i = fixa; i < quant; i++) {
        printf("%s - %s - %d\n", func[i].nome, func[i].email, func[i].idade);
        for(j = 0; j < (strlen(func[i].nome) + strlen(func[i].email) + 8); j++) {
            printf("-");
        }
        printf("\n");
    }
    sleep(5);
}

int menu_editar(funcionario *func, int quant) {
    printf("---------Modo Edição---------\n");
    printf("(1) Buscar Pelo Indice\n");
    printf("(2) Buscar pelo nome\n");
    printf("(3) Buscar pelo email\n");
    printf(": De qual modo deseja Buscar o funcionario que quer editar --> ");
    int x = -7, tipo = 0;
    char *nome;

    nome = (char *) malloc(35 * sizeof(char));
    if(nome == NULL) {
        printf("ERRO!\n");
        exit(2);
    }

    while(tipo < 1 || tipo > 3) {
        scanf("%d", &tipo);
        int i, j;

        switch(tipo) {
            case 1:
                printf(":: Digite o indice --> ");
                scanf("%d", &x);
                x--;
                break;
            
            case 2:
                printf(":: Digite o nome --> ");
                getchar();
                scanf("%[^\n]", nome);

                for(i = 0; i < quant; i++) {
                    if(strcmp((func[i]).nome, nome) == 0) {
                        x = i;
                        break;
                    }    
                }
                break;

            case 3:
                printf(":: Digite o email --> ");
                getchar();
                scanf("%[^\n]", nome);

                for(i = 0; i < quant; i++) {
                    if(strcmp((func[i]).email, nome) == 0) {
                        x = i;
                        break;
                    }    
                }
                break;

            default:
                printf("Numero invalido. Digite novamente -->");
                break;
        }
    }

    free(nome);
    return x;
}

void edita_funcionario(funcionario *func, int indice) {
    if(indice >= 0) {
        printf("##### FUNCIONARIO ENCONTRADO #####\n");
        sleep(1);
        printf("%s - %s - %d\n", func[indice].nome, func[indice].email, func[indice].idade);

        printf("******EDIÇÃO DO FUNCIONARIO******\n");
        printf("Nome: ");
        getchar();
        scanf("%[^\n]", func[indice].nome);
        printf("Idade: ");
        scanf("%d", &func[indice].idade);
        printf("Email: ");
        getchar();
        scanf("%[^\n]", func[indice].email);
        printf("Funcionario(a), %s editado(a) com sucesso!\n", func[indice].nome);
        sleep(1);
    }
    else {
        printf("##### FUNCIONARIO NAO ENCONTRADO #####\n");
        sleep(1);
    }
}

int menu_excluir(funcionario *func, int quant) {
    printf("---------Modo Excluir---------\n");
    printf("(1) Excluir Pelo Indice\n");
    printf("(2) Exluir pelo nome\n");
    printf(": De qual modo deseja Excluir o funcionario --> ");
    int x = -7, tipo = 0;
    char *nome;

    nome = (char *) malloc(35 * sizeof(char));
    if(nome == NULL) {
        printf("ERRO!\n");
        exit(2);
    }

    while(tipo < 1 || tipo > 2) {
        int i;
        scanf("%d", &tipo);

        switch(tipo) {
            case 1:
                printf(":: Digite o indice --> ");
                scanf("%d", &x);
                x--;
                break;

            case 2:
                printf(":: Digite o nome --> ");
                getchar();
                scanf("%[^\n]", nome);

                for(i = 0; i < quant; i++) {
                    if(strcmp((func[i]).nome, nome) == 0) {
                        x = i;
                        break;
                    }    
                }
                break;

            default:
                printf("Numero invalido. Digite novamente -->");
                break;
        }
    }
    
    free(nome);
    return x;
}

void libera_espaco(funcionario *func, int quant, int l) {
    int i;
    if(l != 0) {
            for(i = 0; i < quant; i++) {
                free((func[i]).nome);
                free((func[i]).email);
            }
            free(func);
    }
}

void * exclui_funcionario(funcionario *func, int *quant, int indice, int *x) {
    int i;

    if(*quant > 1) {
        if(indice >= 0) {
            printf("##### FUNCIONARIO ENCONTRADO #####\n");
            sleep(1);
            *quant -= 1;

            for(i = indice; i < *quant; i++) {
                func[i] = func[i + 1];
            }

            func = (funcionario *) realloc(func, (*quant) * sizeof(funcionario));
            check(&func, *quant, 0);
            printf("##### Funcionario Excluido #####\n");
            *x = *quant;
            sleep(1);
        }
        else {
            printf("##### FUNCIONARIO NAO ENCONTRADO #####\n");
            sleep(1);
        }
        return func;
    }
    else {
        if(indice >= 0) {
            printf("##### FUNCIONARIO ENCONTRADO #####\n");
            sleep(1);
            *quant -= 1;

            for(i = 0; i < *quant; i++) {
                free((func[i]).nome);
                free((func[i]).email);
            }
            free(func);
            printf("##### Funcionario Excluido #####\n");
            *x = *quant;
            sleep(1);
        }
        else {
            printf("##### FUNCIONARIO NAO ENCONTRADO #####\n");
            sleep(1);
        }
    }
}