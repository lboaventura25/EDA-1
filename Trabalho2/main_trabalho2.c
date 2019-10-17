#include "funcoes.h"
#include <unistd.h>

int main() {

    int opcao = -1;
    List * list = NULL;
    Aluno * alunos = NULL;

    list = create_list();

    do {
        menu_incio(&opcao);
            
        switch(opcao) {
            case 1:
                menu_cadastro_aluno(list);
                break;

            case 2:
                print_list(list, 1);
                break;

            case 3:
                alunos = menu_vizualiza_aluno(list);
                if(alunos != NULL)
                    menu_do_aluno(alunos);
                break;

            case 4:
                alunos = menu_vizualiza_aluno(list);
                if(alunos)
                    menu_edita_aluno(alunos);
                break;

            case 5:
                break;

            case 6:
                menu_encerra();
                break;
            
            default:
                printf("Opcao Invalida...\n");
                sleep(1);
                break;
        }

    } while(opcao != 6);

    Aluno * aux;
    Disciplina * disciplina;

    if(list->head) {
        if(list->head->lista_disciplinas) {
            disciplina = list->head->lista_disciplinas;
        }
        else {
            disciplina = NULL;
        }
        aux = list->head;
    }
    else {
        aux = NULL;
    }
    
    while(aux) {
        while(disciplina) {
            pop_disciplina(aux, 0);
            disciplina = disciplina->next;
        }
        pop_aluno(list, 0);
        aux = aux->next;
        if(disciplina)
            disciplina = aux->lista_disciplinas;
    }
    free(list);

    return 0;
}