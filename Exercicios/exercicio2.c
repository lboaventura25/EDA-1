#include <stdio.h>

    void ImprimaString(char *);

int main() {
    
    char string[50];
    int aux = 0;

    printf("Digite a String: ");
    scanf("%[^\n]", string);

    ImprimaString(&string[0]);

    return 0;
}

void ImprimaString(char *x) {

    while(*x) {
        printf("%c", *x);
        x++;
    }
    printf("\n");

    x--;

    while(*x) {
        printf("%d\n", x);
        x--;
    }
    printf("\n");
}