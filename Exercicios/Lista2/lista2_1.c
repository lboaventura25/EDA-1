#include <stdio.h>

    int expoente(int , int );

int main() {
    int x, n;
    printf("Digite a base: ");
    scanf("%d", &x);
    printf("Digite o expoente: ");
    scanf("%d", &n);
    
    printf("%d^%d = %d\n", x, n, expoente(x, n));

    return 0;
}

int expoente(int x, int n) {
    if(n < 1) {
        return 1;
    }
    return x * expoente(x, n-1);
}