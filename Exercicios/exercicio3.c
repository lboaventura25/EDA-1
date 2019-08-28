#include <stdio.h>

    void imprime_array_elemento(int *, int);

int main() {

    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N;
    
    printf("Qual elemento deseja imprimir: ");
    scanf("%d", &N);
    printf("----------------\n");

    imprime_array_elemento(array, N);

    return 0;
}

void imprime_array_elemento(int *ptr_array, int elemento) {
    printf("O valor do indice digitado eh %d\n", *(ptr_array + elemento));
}