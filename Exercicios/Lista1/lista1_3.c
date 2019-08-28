#include <stdio.h>
#include <stdlib.h>

int main() {

    int **ptr;
    int N, M, i, j;

    printf("Digite o numero de linhas e colunas, respectivamente: ");
    scanf("%d %d", &N, &M);

        ptr = (int **) malloc(N * sizeof(int *));

    if(ptr == NULL) {
        printf("ERRO\n");
        exit(2);
    }

    for(i = 0; i < N; i++) {
        *(ptr + i) = (int *) malloc(M * sizeof(int));

        if(ptr[i] == NULL) {
            printf("ERRO\n");
            exit(2);
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &ptr[i][j]);
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            printf("%2d\t", ptr[i][j]);
        }
        printf("\n");   
    }

    for(i = 0; i < N; ++i) {
        free(ptr[i]);
    }

    free(ptr);
    return 0;
}