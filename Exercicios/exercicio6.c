#include <stdio.h>
#include <stdlib.h>

int main() {
    int **vetor, linhas, colunas, i, j;

    printf("Digite o numero de linhas desejados: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas desejados: ");
    scanf("%d", &colunas);

    vetor = (int **) malloc(linhas * sizeof(int *));

    if(vetor == NULL) {
        printf("ERRO\n");
        exit(2);
    } 

    for(i = 0; i < linhas; i++) {
        *(vetor + i) = (int *) malloc(colunas * sizeof(int));
    }

    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", *(vetor + i) + j);
        }
    }

    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("%2d ", *(*(vetor + i) + j));
        }
        printf("\n");   
    }

    for(i = 0; i < linhas; ++i) {
        free(*(vetor + i));
    }

    free(vetor);

    return 0; 
}