#include <stdio.h>

    int fat(int );

int main() {

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("O fatorial de %d eh igual a %d\n", n, fat(n));

    return 0;
}

int fat(int n) {
    if(n <= 1) {
        return 1;
    }
    return n * fat(n - 1);
}