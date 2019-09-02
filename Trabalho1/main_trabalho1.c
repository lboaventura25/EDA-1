#include <stdio.h>
#include <stdlib.h>
#include "struct_func.h"
#include "funcoes.h"

int main() {
    funcionario *empregado;
    int N = -1, i, x = 0, l = 0;
    int indice = 0, fixa = 0;
    int quant_funcionarios = 0;

    while(N != 0) {
        menu_inicial(&N);

        switch(N) {
            case 1:
                printf("Quant = %d ==== x = %d\n", quant_funcionarios, x);
                quant_funcionarios += menu_cadastro(&quant_funcionarios, &x);
                printf("Quant = %d ==== x = %d\n", quant_funcionarios, x);
                empregado = aloca_funcionario(&empregado[0], quant_funcionarios, &x, &l);
                printf("Quant = %d ==== x = %d\n", quant_funcionarios, x);
                set_struct(&empregado[0], quant_funcionarios, &x);
                break;
            
            case 2:
                lista_funcionarios(empregado, quant_funcionarios, fixa);
                break; 

            case 3:
                indice = menu_editar(empregado, quant_funcionarios);
                edita_funcionario(empregado, indice);
                break;

            case 4:
                indice = menu_excluir(empregado, quant_funcionarios);
                empregado = (funcionario *) exclui_funcionario(empregado, &quant_funcionarios, indice, &x);
                break;
        }

    }

    libera_espaco(empregado, quant_funcionarios, l);
    return 0;
}