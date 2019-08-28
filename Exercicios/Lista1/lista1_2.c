#include <stdio.h>
#include <stdlib.h>

int main() {

    char **ptr;
    int N, i, j;

    printf("Digite quantos nomes deseja digitar: ");
    scanf("%d", &N);
    printf("------------------------------\n");

    ptr = (char **) malloc(N * sizeof(char *));

    if(ptr == NULL) {
        printf("ERRO\n");
        exit(2);
    }

    for(i = 0; i < N; i++) {
        *(ptr + i) = (char *) malloc(12 * sizeof(char));

        if((ptr + i) == NULL) {
            printf("ERRO\n");
            exit(2);
        }
    }

    for(i = 0; i < N; i++) {
        getchar();
        printf("Digite o nome: ");
        scanf("%[^\n]", ptr[i]);
    }

    printf("------------------------------\n");
    printf("Elementos: %d\n", N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < 12; j++) {
            if(ptr[i][j] == '\0') {
                break;
            }
            printf("%c", ptr[i][j]);
        }
        if(i == (N-1)) {
            printf("\n");
            break;
        }
        printf(", ");
    }

    for(i = 0; i < N; ++i) {
        free(ptr[i]);
    }

    free(ptr);

    return 0;
}