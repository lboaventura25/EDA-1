#include <stdio.h>

    void altera_string(char *, char);
    void imprime_string(char *);

int main() {

    char string[50];
    char n;

    printf("Digite a string: ");
    scanf("%[^\n]", string);
    getchar();
    scanf("%c", &n);

    altera_string(string, n);
    imprime_string(string);

    return 0;
}

void altera_string(char *ptr, char x) {

    if(x == 'C') {
        while(*ptr != '\0') {
            *ptr = *ptr + 1;
            ptr++;
        }
    }
    else {
        while(*ptr != '\0') {
            *ptr = *ptr - 1;
            ptr++;
        }
    }
}

void imprime_string(char *ptr) {
    int i = 0;
    while(*(ptr + i) != '\0') {
        printf("%c", *(ptr + i));
        ++i;
    }
    printf("\n");
}