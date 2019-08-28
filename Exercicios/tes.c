#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i, j, *mat;
    int Nlin, Ncol;

    printf("Digite o número de linhas da matriz:");
    scanf("%d", &Nlin);
    printf("Digite o número de colunas da matriz:");
    scanf("%d", &Ncol);

    mat = (int *)malloc(Nlin * Ncol * sizeof(int));

    for (i = 0; i < Nlin; i++) {
        for (j = 0; j < Ncol; j++) {
            printf("Digite o valor [%d][%d] da matriz:", i, j);
            scanf("%d", mat + (i * Ncol) + j);
        }
    }
    for (i = 0; i < Nlin; i++) {
        for (j = 0; j < Ncol; j++) {
            printf("MAT[%d][%d]: %d \n", i, j, *(mat + (i * Ncol) + j));
        }
    }

    free(mat);
    
    return 0;
}