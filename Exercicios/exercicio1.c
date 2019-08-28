#include <stdio.h>

typedef struct pessoa{
    char Nome[10];
    int Idade;
    float Salario;
}Pessoa;

    void LeiaPessoa(Pessoa *);
    void ImprimaPessoa(Pessoa);

int main() {

    Pessoa x;

    LeiaPessoa(&x);
    ImprimaPessoa(x);

    return 0;
}

void LeiaPessoa(Pessoa *H) {
    printf("Nome: ");
    scanf("%[^\n]", H->Nome);
    printf("Idade: ");
    scanf("%d", &H->Idade);
    printf("Salario: ");
    scanf("%f", &H->Salario);
}

void ImprimaPessoa(Pessoa N) {
    printf("---- DADOS DA PESSOA ----\n");
    printf("Nome: %s\n", N.Nome);
    printf("Idade: %d\n", N.Idade);
    printf("Salario: %.2f\n", N.Salario);
}