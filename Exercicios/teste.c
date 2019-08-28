#include <stdio.h>

int main() {

    printf("int = %ld\n", sizeof(int));
    printf("float = %ld\n", sizeof(float));
    printf("double = %ld\n", sizeof(double));
    printf("char = %ld\n", sizeof(char));
    printf("long int = %ld\n", sizeof(long int));
    printf("unsigned int = %ld\n", sizeof(unsigned int));
    printf("int ** = %ld\n", sizeof(int **));

    return 0;
}