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
                alunos = menu_cadastro_aluno();
                push(&list, &alunos);
                break;

            case 2:
                print_list(&list);
                break;

            case 3:
                alunos = menu_vizualiza_aluno(list);
                if(alunos != NULL)
                    menu_do_aluno(alunos);
                break;

            case 4:
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

    if(alunos != NULL) {
        free(alunos);
    }
    if(list != NULL)
        free(list);
    return 0;
}