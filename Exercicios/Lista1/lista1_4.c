#include <stdio.h>
#include <stdlib.h>

double media(int *, double *, int);

int main() {

    int *pesos;
    double *notas, M;
    int N, i;

    printf("Digite a quantidade de notas que deseja inserir: ");
    scanf("%d", &N);

    pesos = (int *) malloc(N * sizeof(int));
    notas = (double *) malloc(N * sizeof(double));

    if(pesos == NULL || notas == NULL) {
        printf("ERRO!\n");
        exit(2);
    }
    printf("------------------------------\n");

    for(i = 1; i <= N; i++) {
        printf("Digite o peso da nota %d: ", i);
        scanf("%d", &pesos[i - 1]);
    }

    for(i = 1; i <= N; i++) {
        printf("Digite a nota %d: ", i);
        scanf("%lf", &notas[i - 1]);
    }

    M = media(pesos, notas, N);

    printf("------------------------------\n");
    printf("A media do aluno eh %.2lf\n", M);

    free(pesos);
    free(notas);

    return 0;
}

double media(int *Pesos, double *Notas, int n) {

    int i, pesos = 0;
    double soma = 0;

    for(i = 1; i <= n; i++) {
        soma += (double)(Pesos[i - 1] * Notas[i - 1]);
        pesos += Pesos[i - 1];
    }

    if(pesos != 10) {
        printf("Erro\n");
        return 0.0;
    }
    soma /= pesos;

    return soma;
}