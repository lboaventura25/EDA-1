#include <stdio.h>

double expoente(double , int);

int main() {
    int x, n;
    double novo_x;

    scanf("%d", &x);
    scanf("%d", &n);

    if(x == 0) {
        printf("indefinido\n");
    } else {
        novo_x = (double) x;

        if(n < 0 && n != 0) {
            novo_x = 1.0 / x;
            n *= -1;
        }

        printf("%.3lf\n", expoente(novo_x, n));
    }

    return 0;
}

double expoente(double x, int n) {
    if(n < 1) {
        return 1;
    }
    return x * expoente(x, (n-1));
}