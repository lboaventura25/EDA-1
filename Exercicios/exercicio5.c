#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, *vetor, i, M;
    char string;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &N);

    vetor = (int *) malloc(N * sizeof(int));

    if(vetor == NULL) {
            printf("ERRO\n");
            exit(2);
    }

    for(i = 0; i < N; i++) {
        printf("Digite o vetor[%d]: ", i);
        scanf("%d", (vetor + i));
    }

    printf("-------------\n");

    for(i = 0; i < N; i++) {
        printf("Vetor[%d] = %d\n", i, *(vetor + i));
    }

    printf("-------------\n");
    printf("Deseja digitar mais algum numero? ");
    getchar();
    scanf("%c", &string);
    getchar();
    M = N;

    while(string == 's' || string == 'S') {
        printf("-------------\n");
        ++M;
        vetor = (int *) realloc(vetor, M * sizeof(int));

        if(vetor == NULL) {
            printf("ERRO\n");
            exit(2);
        }

        printf("Digite o numero[%d] = ", M-1);
        scanf("%d", (vetor + (M-1)));

        printf("-------------\n");
        printf("Deseja digitar mais algum numero? ");
        getchar();
        scanf("%c", &string);
        getchar();
    }

    printf("-------------\n");

    for(i = 0; i < M; i++) {
        printf("Vetor[%d] = %d\n", i, *(vetor + i));
    }

    free(vetor);

    return 0;
}