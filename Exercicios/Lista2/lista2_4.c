#include <stdio.h>

    int conversor(int);

int main() {
    int decimal;

    printf("Digite o numero binario: ");
    scanf("%d", &decimal);

    printf("Decimal = %d -- Binario = %d\n", decimal, conversor(decimal));

    return 0;
}

int conversor(int decimal) {
    if (decimal < 2){
        return decimal;
    }
    return (10 * conversor(decimal / 2)) + decimal % 2;
}