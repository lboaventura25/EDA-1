#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(char vetor[], int indice, int tamanho) {
    if (indice == tamanho) {
        if((vetor[indice] - '0') == 7) return 1;
        else return 0;

    return ((vetor[indice] - '0') == 7 ? 1 : 0) + soma(vetor, indice + 1, tamanho);
}


int main(){
    char vet[13];

    scanf("%[^\n]", vet);

    int soma_digitos = soma(vet, 0 ,strlen(vet) - 1);

    printf("%d\n", soma_digitos);

    return 0;
}