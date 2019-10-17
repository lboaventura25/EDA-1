#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "funcoes.h"
#include "structs_trabalho2.h"

void menu_incio(int *opcao) {
    system("clear");
    printf("----------------- MENU INICIAL -----------------\n");
    printf("*            (1) Cadastrar Aluno               *\n");
    printf("*            (2) Listar Alunos                 *\n");
    printf("*            (3) Visualizar Aluno              *\n");
    printf("*            (4) Editar Aluno                  *\n");
    printf("*            (5) Excluir Aluno                 *\n");
    printf("*            (6) Sair do Programa              *\n");
    printf("------------------------------------------------\n");
    printf(":: Digite a opcao desejada --> ");
    scanf("%d", opcao);	
}

void menu_cadastro_aluno(List * list) {
    int qtd = 0;
    
    printf(":::: Digite a quantidade de alunos que deseja cadastrar --> ");
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++) {
        printf("\n----------------------Cadastro de Alunos----------------------\n");
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
        push(list, aluno, 0);
    }

}

Aluno * menu_vizualiza_aluno(List * list) {
    int opcao;
    Aluno * aluno;

    printf("\n<----------------- Selecione a opcao que deseja buscar o aluno ---------------->\n");
    printf("   [1]Buscar pelo nome     [2]Buscar pelo email     [3]Buscar pela matricula\n\n");
    printf(":::--> ");
    scanf("%d", &opcao);
    aluno = buscar_aluno(list, opcao);

    if(aluno) {
        return aluno;
    } else {
        return NULL;
    }
}

void menu_edita_aluno(Aluno * aluno) {
    printf("------------------------------------------------\n");
    printf("Digite o nome do Aluno: ");
    getchar();
    scanf("%[^\n]", aluno->nome);
    printf("Digite a matricula do Aluno: ");
    scanf("%d", &aluno->matricula);
    getchar();
    printf("Digite o email do Aluno: ");
    scanf("%[^\n]", aluno->email);
    edita_nome(aluno->nome, 0);
    edita_nome(aluno->email, 1);
}

Aluno * buscar_aluno(List * list, int opcao) {
    int matricula, index;
    char *buscar;
    Aluno * aluno;
    List * list_aux;
    switch(opcao) {
        case 1:
            buscar = (char *) malloc(50 * sizeof(char));
            printf("::: Digite o nome: ");
            getchar();
            scanf("%[^\n]", buscar);
            edita_nome(buscar, 0);

            list_aux = alunos_parecidos(list, buscar);
            if(list_aux->size == 1) {
                index = index_of(list, buscar, 0);

                if(index != -1000) {
                    aluno = at_pos(list, index);

                    if(aluno != NULL) {
                        free(buscar);

                        pop_aluno(list_aux, 0);
                        free(list_aux);
                        return aluno;
                    }
                }
            } else {
                print_list(list_aux, 0);

                printf("::: Digite o nome completo do Aluno --> ");
                getchar();
                scanf("%[^\n]", buscar);
                edita_nome(buscar, 0);

                aluno = busca_perfeita(list, buscar);

                free(buscar);
                Aluno * aux = list_aux->head;
                while(aux) {
                    pop_aluno(list_aux, 0);
                    aux = aux->next;
                }
                free(list_aux);
                return aluno;
            }

            free(list_aux);
            free(buscar);
            return NULL;
            break;

        case 2:
            buscar = (char *) malloc(50 * sizeof(char));
            printf("::: Digite o email: ");
            getchar();
            scanf("%[^\n]", buscar);
            edita_nome(buscar, 1);

            index = index_of(list, buscar, 0);

            if(index != -1000) {
                aluno = at_pos(list, index);

                if(aluno != NULL) {
                    free(buscar); 
                    return aluno;
                }
            }
            free(buscar);
            return NULL;
            break;

        case 3:
            printf("::: Digite a matricula: ");
            scanf("%d", &matricula);

            index = index_of(list, "EDAEHMASSA", matricula);

            if(index != -1000) {
                aluno = at_pos(list, index);

                if(aluno != NULL) {
                    return aluno;
                }
            }
            return NULL;
            break;
        
        default:
            printf("Opcao invalida!\n");
            sleep(1);
            break;
    }
    return NULL;
}

void pop_aluno(List * list, int i) {
    Aluno * aux = list->head;
    char * nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    list->head = aux->next;
    free(aux->nome);
    free(aux->email);
    free(aux);
    list->size--;

    if(i == 1) {
        printf("**** Aluno(a), %s, excluido(a) com sucesso! ****\n", nome);
        sleep(1.5);
    }
    free(nome);
}

List * alunos_parecidos(List * list, char * buscar) {
    List * list_aux = create_list();
    Aluno * aux = list->head;
    Aluno * aux2;

    while(aux) {
        aux2 = create_aluno();
        if(!strcmp(buscar, aux->nome) || strstr(aux->nome, buscar) != NULL || !strcmp(buscar, aux->email) || strstr(aux->email, buscar) != NULL) {
            strcpy(aux2->nome, aux->nome);
            aux2->matricula = aux->matricula;
            strcpy(aux2->email, aux->email);
            push(list_aux, aux2, 1);
        }
        aux = aux->next;
    }

    return list_aux;
}

Aluno * busca_perfeita(List * list, char * buscar) {
    int index = 0;
    Aluno * aux = list->head;

    if(is_empty(&list)) {
        printf("Lista vazia!\n");
        sleep(1);
        return NULL;
    }

    while(aux != NULL) {
        if(!strcmp(buscar, aux->nome) || !strcmp(buscar, aux->email)) {
            break;
        }
        index++;
        aux = aux->next;
    }

    return at_pos(list, index);
}

void menu_do_aluno(Aluno *aluno) {
    int opcao, i = 0;
    Disciplina * disciplina;
    do {
        system("clear");
        printf("----------------------- Menu do Aluno ----------------------\n");
        print_aluno(aluno, i);
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
                disciplina = menu_cadastra_disciplina();
                push_disciplina(aluno, disciplina);
                break;
            
            case 2:
                print_list_disciplina(aluno);
                break;

            case 3:
                disciplina = menu_edita_disciplina(aluno);
                if(disciplina != NULL)
                        edita_disciplina(disciplina); 
                break;

            case 4:
                disciplina = menu_edita_disciplina(aluno);
                if(disciplina != NULL) 
                        exclui_disciplina(aluno, disciplina);
                break;

            case 5:
                menu_filtrar_disciplinas(aluno);
                break;

            case 6:
                relatorio_geral_aluno(aluno);
                break;

            case 7:
                break;

            default:
                printf("Opcao ivalida!\n");
                sleep(1);
                break;
        }
        i++;
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

void push(List * list, Aluno *aluno, int i) {
    if(list != NULL) {
        aluno->next = list->head;
        list->head = aluno;
        list->size++;
        if(i == 0) {
            printf("**** Aluno, %s, cadastrado com sucesso! ****\n\n", aluno->nome);
            sleep(1.5);
        }
        return;
	}

    printf("### Nao foi possivel cadastrar o Aluno! ###\n");
    sleep(1.5);
}

void push_disciplina(Aluno * aluno, Disciplina * disciplina) {
    if(aluno != NULL) {
        disciplina->next = aluno->lista_disciplinas;
        aluno->lista_disciplinas = disciplina;
        aluno->disciplinas++;
        printf("**** Disciplina, %s, cadastrada com sucesso! ****\n", disciplina->nome);
        sleep(1.5);
        return;
    }

    printf("### Nao foi possivel cadastrar a Disciplina! ###\n");
    sleep(1.5);
}

void print_list(List * list, int i) {
    if(is_empty(&list)) {
        printf("Lista vazia!\n");
        sleep(1);
        return;
    }
    Aluno * aluno = list->head;

    printf("-------------- Lista de Alunos --------------\n");
    while(aluno != NULL) {
        printf("Nome: %s\nMatricula: %d\nE-mail: %s\nHistorico: %d disciplinas\n", aluno->nome, aluno->matricula, aluno->email, aluno->disciplinas);
        printf("-----------------------------------------\n");
        aluno = aluno->next;
    }
    if(i == 1) {
        char * release = (char *) malloc(sizeof(char));
        printf(":: Pressione ENTER para continuar -->");
        getchar();
        scanf("%[^\n]", release);
        getchar();
        free(release);
    }
}

void print_list_disciplina(Aluno * aluno) {
    if(is_empty_disciplina(aluno)) {
        printf("Lista vazia!\n");
        sleep(1);
        return;
    }
    Disciplina * disciplina = aluno->lista_disciplinas;
    
    printf("-------------- Lista de Disciplinas --------------\n");
    while(disciplina != NULL) {
        printf("Nome: %s\nMencao: %s\n", disciplina->nome, disciplina->mencao);
        printf("-----------------------------------------\n");
        disciplina = disciplina->next;
    }
    char * release = (char *) malloc(sizeof(char));
    printf(":: Pressione ENTER para continuar -->");
    getchar();
    scanf("%[^\n]", release);
    getchar();
    free(release);
}

int is_empty_disciplina(Aluno * aluno) {
    if(aluno->disciplinas == 0)
        return 1;
    else
        return 0;
}   

int is_empty(List **list) {
    if((*list)->size == 0)
        return 1;
    else
        return 0;
}

int index_of(List * list, char * buscar, int matricula) {
    int index = 0;
    Aluno * aux = list->head;

    if(is_empty(&list)) {
        printf("Lista vazia!\n");
        sleep(1);
        return -1000;
    }

    while(aux != NULL) {
        if(!strcmp(buscar, aux->nome) || strstr(aux->nome, buscar) != NULL || !strcmp(buscar, aux->email) || strstr(aux->email, buscar) != NULL || matricula == aux->matricula) {
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
	} else {
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

void print_aluno(Aluno * aluno, int i) {
    if(i == 0) {
        char * release = (char *) malloc(sizeof(char));
        printf("<-------------------- Aluno Encontrado -------------------->\n");
        printf("          Nome: %s                                          \n", aluno->nome);
        printf("          Matricula: %d                                     \n", aluno->matricula);
        printf("          E-mail: %s                                        \n", aluno->email);
        printf("          Historico: %d disciplinas                         \n", aluno->disciplinas);
        printf("------------------------------------------------------------\n");
        getchar();
        printf(":: Pressione ENTER para continuar -->");
        scanf("%[^\n]", release);
        getchar();
        free(release);
    } else {
        printf("<-------------------- Aluno Encontrado -------------------->\n");
        printf("          Nome: %s                                          \n", aluno->nome);
        printf("          Matricula: %d                                     \n", aluno->matricula);
        printf("          E-mail: %s                                        \n", aluno->email);
        printf("          Historico: %d disciplinas                         \n", aluno->disciplinas);
        printf("------------------------------------------------------------\n");
    }    
}

Disciplina * create_disciplina() {
    Disciplina * disciplina = (Disciplina *) malloc(sizeof(Disciplina));
    disciplina->nome = (char *) malloc(50 * sizeof(char));
    disciplina->mencao = (char *) malloc(3 * sizeof(char));
    
    return disciplina;
}

Disciplina * menu_cadastra_disciplina() {
        printf("-------------------------------------------\n");
        Disciplina * disciplina = create_disciplina();
        getchar();
        printf("Digite o nome da Disciplina: ");
        scanf("%[^\n]", disciplina->nome);
        edita_nome(disciplina->nome, 2);

        check_mencao(disciplina->mencao);

        return disciplina;
}

void check_mencao(char * mencao) {
        int i = 0;

        while(1) {
                if(i > 0)
                        printf("Mencao invalida! Tente novamente...\n");
                getchar();
                printf("Digite a mencao: ");
                scanf("%[^\n]", mencao);
                
                if((strcmp(mencao, "SS") == 0 || strcmp(mencao, "MS") == 0 || strcmp(mencao, "MM") == 0 || strcmp(mencao, "MI") == 0 || strcmp(mencao, "II") == 0 || strcmp(mencao, "TR") == 0 || strcmp(mencao, "SR") == 0))
                        break;
                i++;
        }
}

void edita_disciplina(Disciplina * disciplina) {
        printf("--------------------------------------------------\n");
        printf("Nome da Disciplina: %s\n", disciplina->nome);
        printf("Digite a nova mencao: ");
        check_mencao(disciplina->mencao);
        printf("--------------------------------------------------\n");
        printf("**** Disciplina, %s, editada com sucesso ****\n", disciplina->nome);
        sleep(1.5);
}

Disciplina * menu_edita_disciplina(Aluno * aluno) {
        char * buscar;
        Disciplina * disciplina;

        buscar = (char *) malloc(50 * sizeof(char));

        printf("::: Digite o nome da disciplina --> ");
        getchar();
        scanf("%[^\n]", buscar);

        edita_nome(buscar, 2);

        int index = index_of_disciplina(aluno, buscar);

        if(index != -1000) {
                disciplina = at_pos_disciplina(aluno, index);

                if(disciplina != NULL) {
                        free(buscar);
                        return disciplina;
                }
        }
        free(buscar);
        return NULL;
}

Disciplina * at_pos_disciplina(Aluno * aluno, int index) {
        int cont = 0;
	Disciplina * aux = aluno->lista_disciplinas;

	if(is_empty_disciplina(aluno) || index < 0 || index >= aluno->disciplinas) {
		printf("***** Disciplina nao encontrada! *****\n");
        sleep(1);
	} else {
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

int index_of_disciplina(Aluno * aluno, char * buscar) {
        int index = 0;
        Disciplina * aux = aluno->lista_disciplinas;
        edita_nome(buscar, 2);

        if(is_empty_disciplina(aluno)) {
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

void exclui_disciplina(Aluno * aluno, Disciplina * disciplina) {
    Disciplina * aux = aluno->lista_disciplinas;
    Disciplina * aux_anterior = aluno->lista_disciplinas;
    int i = 0;

    while(aux != NULL) {
        if(strcmp(aux->nome, disciplina->nome) == 0 && strcmp(aux->mencao, disciplina->mencao) == 0) {
            if(i == 0) {
                pop_disciplina(aluno, 1);
                break;
            } else {
                pop_index_disciplina(aluno, aux_anterior, aux);
            }
        }
        aux_anterior = aux;
        aux = aux->next;
        i++;
    }
}

void pop_disciplina(Aluno * aluno, int i) {
        Disciplina * aux = aluno->lista_disciplinas;
        char * nome = (char *) malloc(50 * sizeof(char));

        strcpy(nome, aux->nome);
        aluno->lista_disciplinas = aux->next;
        free(aux->nome);
        free(aux->mencao);
        free(aux);
        aluno->disciplinas--;

        if(i == 1) {
            printf("**** Disciplina, %s, excluida com sucesso! ****\n", nome);
            sleep(1.5);
        }
        free(nome);
}

void pop_index_disciplina(Aluno * aluno, Disciplina * disciplina_anterior, Disciplina * disciplina_excluir) {
        Disciplina * aux = disciplina_excluir;
        char * nome = (char *) malloc(50 * sizeof(char));

        strcpy(nome, aux->nome);
        disciplina_anterior->next = aux->next;
        free(aux);
        aluno->disciplinas--; 

        printf("**** Disciplina, %s, excluida com sucesso! ****\n", nome);
        sleep(1.5);
        free(nome);
}

void menu_filtrar_disciplinas(Aluno * aluno) {
        char * buscar;
        buscar = (char *) malloc(2 * sizeof(char));
        
        printf("--------------------------------------------------\n");
        getchar();
        printf("::: Digite a mencao que deseja filtrar --> ");
        scanf("%[^\n]", buscar);

        filtra(aluno, buscar);

        free(buscar);
}

void filtra(Aluno * aluno, char * buscar) {
    Disciplina * disciplinas = aluno->lista_disciplinas;

    printf("\n-----------------------------------------------------------------------\n");
    printf("---------------------- Disciplinas com mencao %s ----------------------\n", buscar);

    while(disciplinas) {
        if(!strcmp(disciplinas->mencao, buscar)) {
            printf("Nome da disciplina: %s\n", disciplinas->nome);
            printf("Mencao: %s\n", disciplinas->mencao);
            printf("-----------------------------------------------\n");
        }
        disciplinas = disciplinas->next;
    }
    char * release = (char *) malloc(sizeof(char));
    getchar();
    printf(":: Pressione ENTER para continuar -->");
    scanf("%[^\n]", release);
    getchar();
    free(release);
}

void relatorio_geral_aluno(Aluno * aluno) {
    char * release = (char *) malloc(sizeof(char));
    if(aluno) {
        printf("\n\n-------------- Relatorio Geral do(a) %s --------------\n", aluno->nome);
        printf("*       Total Disciplinas: %d\n", aluno->disciplinas);
        printf("*       Aprovacoes: %d\n", get_aprovacoes(aluno));
        printf("*       Reprovacoes: %d\n", get_reprovacoes(aluno));
        printf("*       Trancamentos: %d\n", get_trancamentos(aluno));
        printf("-----------------------------------------------------------\n");
        printf(":: Pressione ENTER para continuar --> ");
        getchar();
        scanf("%[^\n]", release);
        getchar();
        free(release);
    } else {
        printf("**** Aluno nao existe! ****\n");
        sleep(1.5);
    }
}

int get_aprovacoes(Aluno * aluno) {
    Disciplina * disciplina = aluno->lista_disciplinas;
    int cont = 0;
    
    while(disciplina) {
        if(strcmp(disciplina->mencao, "SS") == 0 || strcmp(disciplina->mencao, "MS") == 0 ||       strcmp(disciplina->mencao, "MM") == 0) {
            cont++;
        }
        disciplina = disciplina->next;
    }
    return cont;
}

int get_reprovacoes(Aluno * aluno) {
    Disciplina * disciplina = aluno->lista_disciplinas;
    int cont = 0;
    
    while(disciplina) {
        if(strcmp(disciplina->mencao, "MI") == 0 || strcmp(disciplina->mencao, "II") == 0 || strcmp(disciplina->mencao, "SR") == 0) {
            cont++;
        }
        disciplina = disciplina->next;
    }
    return cont;
}

int get_trancamentos(Aluno * aluno) {
    Disciplina * disciplina = aluno->lista_disciplinas;
    int cont = 0;
    
    while(disciplina) {
        if(strcmp(disciplina->mencao, "TR") == 0) {
            cont++;
        }
        disciplina = disciplina->next;
    }
    return cont;
}

void edita_nome(char *nome, int x) {
    for(unsigned int H = 0; H < strlen(nome); H++) {
        if(x == 0) {
            if(H == 0 || nome[H-1] == ' ') {	
                    nome[H] = toupper(nome[H]);
            } else if(H > 0) {
                    nome[H] = tolower(nome[H]);
            }
        }
        if(x == 1) {
                nome[H] = tolower(nome[H]);
        }
        if(x == 2) {
                if(H == 0) {
                        nome[H] = toupper(nome[H]);
                } else {
                        nome[H] = tolower(nome[H]);
                }
        }
                nome[strlen(nome)] = '\0';
    }

    nome = (char *) realloc(nome, strlen(nome));
}