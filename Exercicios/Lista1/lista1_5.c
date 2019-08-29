#include <stdio.h>
#include <stdlib.h>

    typedef struct Estudante {
        int matricula;
        char *nome;
        int idade;
    } estudante;

    void imprime_dados(estudante *, int);
    void cadastro_aluno(estudante *, int);

int main() {

    int N, i, X;
    estudante *aluno;

    printf("Digite quanto estudantes deseja registrar: ");
    scanf("%d", &N);

    aluno = (estudante *) malloc(N * sizeof(estudante));

    if(aluno == NULL) {
        printf("ERRO!\n");
        exit(2);
    }
    
    for(i = 0; i < N; i++) {
        aluno[i].nome = (char *) malloc(35 * sizeof(char));

        if(aluno[i].nome == NULL) {
            printf("ERRO!\n");
            exit(2);
        }
    }

    printf("------------------------------\n");

    cadastro_aluno(aluno, N);

    printf("------------------------------\n");
    printf("------------------------------\n");

    imprime_dados(&aluno[0], N);

    printf("------------------------------\n");

    printf("Deseja matricular mais quantos alunos? ");
    scanf("%d", &X);

    printf("------------------------------\n");

    aluno = (estudante *) realloc(aluno, (N + X) * sizeof(estudante));

    if(aluno == NULL){
        printf("ERRO!\n");
        exit(2);
    }
    
    for(i = N; i <= X; i++) {
        aluno[i].nome = (char *) malloc(35 * sizeof(char));

        if(aluno[i].nome == NULL) {
            printf("ERRO!\n");
            exit(2);
        }
    }


    cadastro_aluno(&aluno[N], X);

    printf("------------------------------\n");
    printf("-------DADOS DOS ALUNOS-------\n");

    imprime_dados(aluno, (N + X));

    for(i = 0; i < (N + X); i++) {
        free(aluno[i].nome);
    }

    free(aluno);

    return 0;
}

void imprime_dados(estudante *pessoa, int x) {
    int i;

    for(i = 0; i < x; i++) {
        printf("Estudante %d:\nNome: %s\n", i, pessoa[i].nome);
        printf("Matricula: %d\n", pessoa[i].matricula);
        printf("------------------------------\n");
    }
}

void cadastro_aluno(estudante *Aluno,  int y) {
    int i;

    for(i = 0; i < y; i++) {
        printf("Estudante %d:\nMatricula: ", i);
        scanf("%d", &Aluno[i].matricula);
        getchar();
        printf("Nome: ");
        scanf("%[^\n]", Aluno[i].nome);
        getchar();
        printf("Idade: ");
        scanf("%d", &Aluno[i].idade);
    }
}
