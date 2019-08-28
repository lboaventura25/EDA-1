#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr;
    int N, i, indice;
    char string;

    printf("Digite o tamanho vo vetor: ");
    scanf("%d", &N);

    ptr = (int *) malloc(N*sizeof(int));

    if(ptr == NULL) {
        printf("ERRO\n");
        exit(2);
    }

    for(i = 0; i < N; i++) {
        printf("Digite o elemento do vetor[%d]: ", i);
        scanf("%d", (ptr + i));
    }

    printf("------------------------------\n");

    for(i = 0; i < N; i++) {
        printf("Vetor[%d]: %d\n", i,*(ptr + i));
    }

    printf("------------------------------\n");

    getchar();
    printf("Deseja remover algum elemento do vetor? [S/n]\nR: ");
    scanf("%c", &string);

    if(string == 'S' || string == 's') {
        printf("Qual indice deseja remover: ");
        scanf("%d", &indice);
        N--;

        for(i = indice; i < N; i++) {
            *(ptr + i) = *(ptr + (i + 1));
        }

        ptr = (int *) realloc(ptr, N*sizeof(int));

        if(ptr == NULL) {
            printf("ERRO\n");
            exit(2);
        }
    }

    printf("------------------------------\n");

    for(i = 0; i < N; i++) {
        printf("Vetor[%d]: %d\n", i, *(ptr + i));
    }

    free(ptr);
    return 0;
}