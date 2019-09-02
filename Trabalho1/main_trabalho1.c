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
                quant_funcionarios += menu_cadastro(&quant_funcionarios);
                empregado = aloca_funcionario(&empregado[0], quant_funcionarios, &x, &l);
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
                break;
        }

    }

    if(l != 0) {
        for(i = 0; i < quant_funcionarios; i++) {
            free(empregado[i].nome);
        }

        free(empregado);
    }

    return 0;
}