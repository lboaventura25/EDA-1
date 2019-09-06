#include <stdio.h>
#include <stdlib.h>

    int soma_array(int *, int);

int main() {

    int *array;
    int n, i;

    printf("Digite quantos elementos tem o array: ");
    scanf("%d", &n);

    array = (int *) calloc(n, sizeof(int));
    if(array == NULL) {
        printf("ERRO!\n");
        exit(2);
    }

    for(i = 0; i < n; i++) {
        printf("Digite o número[%d]: ", i);
        scanf("%d", (array + i));
    }
    printf("------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("%d", *(array + i));
        if((i + 1) == n) {
            printf(" = ");
            break;
        }
        printf(" + ");
    }
    printf("%d\n", soma_array(array, n-1));

    free(array);
    return 0;
}

int soma_array(int *array, int quant) {
    if(quant == 0) {
        return array[quant];
    }
    return array[quant] + soma_array(array, quant -1);
}