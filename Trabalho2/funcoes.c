#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcoes.h"
#include "structs_trabalho2.h"

void menu_incio(int *opcao) {
    system("clear");
    printf("----------------- MENU INICIAL -----------------\n");
    printf("*            (1) Cadastrar Aluno               *\n");
    printf("*            (2) Listar Alunos                 *\n");
    printf("*            (3) Vizualizar Aluno              *\n");
    printf("*            (4) Editar Aluno                  *\n");
    printf("*            (5) Excluir Aluno                 *\n");
    printf("*            (6) Sair do Programa              *\n");
    printf("------------------------------------------------\n");
    printf(":: Digite a opcao desejada --> ");
    scanf("%d", opcao);
}

Aluno * menu_cadastro_aluno() {
    printf("\n------------------------------------------------\n");
    getchar();
    Aluno * aluno = create_aluno();
    printf("Digite o nome do Aluno: ");
    scanf("%[^\n]", aluno->nome);
    printf("Digite a matricula do Aluno: ");
    scanf("%d", &aluno->matricula);
    getchar();
    printf("Digite o email do Aluno: ");
    scanf("%[^\n]", aluno->email);
    edita_nome(aluno->nome, 0);
    edita_nome(aluno->email, 1);
    
    return aluno;
}

Aluno * menu_vizualiza_aluno(List * list) {
    int opcao;
    char *buscar;
    Aluno * aluno;

    printf("\n<----------- Selecione a opcao que deseja buscar o aluno ---------->\n");
    printf("[1]Buscar pelo nome     [2]Buscar pelo email     [3]Buscar pelo indice\n\n");
    printf(":::--> ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            buscar = (char *) malloc(50 * sizeof(char));
            printf("Digite o nome: ");
            getchar();
            scanf("%[^\n]", buscar);
            edita_nome(buscar, 0);

            int index = index_of(list, buscar);

            if(index != -1000) {
                aluno = at_pos(list, index);

                if(aluno != NULL) {
                    return aluno;
                }
            }
            return NULL;
            break;

        case 2:
            break;

        case 3:
            break;
        
        default:
            printf("Opcao invalida!\n");
            sleep(1);
            break;
    }
    return NULL;
}

void menu_do_aluno(Aluno *aluno) {
    int opcao;
    do {
        system("clear");
        printf("----------------------- Menu do Aluno ----------------------\n");
        print_aluno(aluno);
        printf("*       (1) Cadastrar disciplina                           *\n");
        printf("*       (2) Listar disciplinas do Aluno                    *\n");
        printf("*       (3) Editar disciplina do Aluno                     *\n");
        printf("*       (4) Excluir disciplina do Aluno                    *\n");
        printf("*       (5) Filtrar disciplinas por mencao                 *\n");
        printf("*       (6) Apresentar relatório geral do Aluno            *\n");
        printf("*       (7) Voltar ao menu principal                       *\n");
        printf("------------------------------------------------------------\n");
        printf("\n::: Digite a opcao desejada --> ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                break;
            
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            default:
                printf("Opcao ivalida!\n");
                sleep(1);
                break;
        }
    } while(opcao != 7);
}

void menu_encerra() {
    printf("\n\n\n\tEncerrando o Programa....\n");
    sleep(1.5);
}

List * create_list() {
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;

    return list;
}

Aluno * create_aluno() {
    Aluno * aluno = (Aluno *) malloc(sizeof(Aluno));
    aluno->nome = (char *) malloc(50 * sizeof(char));
    aluno->email = (char *) malloc(50 * sizeof(char));
    aluno->disciplinas = 0;
    aluno->lista_disciplinas = NULL;

    return aluno;
}

void push(List ** list, Aluno **aluno) {
	if(list != NULL) {
		(*aluno)->next = (*list)->head;
		(*list)->head = (*aluno);
		(*list)->size++;
	}

    printf("**** Aluno, %s, cadastrado com sucesso! ****\n", (*aluno)->nome);
    sleep(1.5);
}

void print_list(List **list) {
	if(is_empty(list)) {
		printf("Lista vazia!\n");
        sleep(1);
		return;
	}
	Aluno * aluno = (*list)->head;

    printf("-------------- Lista de Alunos --------------\n");
	while(aluno != NULL) {
		printf("Nome: %s\nMatricula: %d\nE-mail: %s\nHistorico: %d disciplinas\n", aluno->nome, aluno->matricula, aluno->email, aluno->disciplinas);
		printf("-----------------------------------------\n");
        aluno = aluno->next;
	}
    sleep(2);
}

int is_empty(List **list) {
	if((*list)->size == 0)
		return 1;
	else
		return 0;
}

int index_of(List * list, char * buscar) {
    int index = 0;
    Aluno * aux = list->head;

    if(is_empty(&list)) {
        printf("Lista vazia!\n");
        sleep(1);
        return -1000;
    }

    while(aux != NULL) {
        if(!strcmp(buscar, aux->nome) || strstr(aux->nome, buscar) != NULL) {
				break;
		}
		index++;
		aux = aux->next;
    }

    return index;
}

Aluno * at_pos(List *list, int index) {
	int cont = 0;
	Aluno *aux = list->head;

	if(is_empty(&list) || index < 0 || index >= list->size) {
		printf("***** Aluno nao encontrado! *****\n");
        sleep(1);
	}
	else {
		while(aux != NULL) {
			if(cont == index) {
				return aux;
			}
			cont++;
			aux = aux->next;
		}
	}
	return NULL;
}

void print_aluno(Aluno * aluno) {
    printf("<-------------------- Aluno Encontrado -------------------->\n");
    printf("          Nome: %s                                          \n", aluno->nome);
    printf("          Matricula: %d                                     \n", aluno->matricula);
    printf("          E-mail: %s                                        \n", aluno->email);
    printf("          Historico: %d disciplinas                         \n", aluno->disciplinas);
    printf("------------------------------------------------------------\n");
    sleep(1.5);    
}

Disciplina * create_disciplina() {
    Disciplina * disciplina = (Disciplina *) malloc(sizeof(Disciplina));
    disciplina->nome = (char *) malloc(50 * sizeof(char));
    
    return disciplina;
}

void edita_nome(char *nome, int x) {
    for(unsigned int H = 0; H < strlen(nome); H++) {
        if(x == 0) {
            if(H == 0 || nome[H-1] == ' ') {	
                nome[H] = toupper(nome[H]);
            }
            else if(H > 0) {
                nome[H] = tolower(nome[H]);
            }
        }
        if(x == 1) {
            nome[H] = tolower(nome[H]);
        }
        nome[strlen(nome)] = '\0';
	}

    nome = (char *) realloc(nome, strlen(nome));
}