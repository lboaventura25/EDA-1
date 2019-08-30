#include <stdio.h>
#include <stdlib.h>
#include "struct_func.h"

void menu_inicial(int *);
int menu_cadastro(int *);
funcionario * aloca_funcionario(funcionario *, int, int *, int *);
void check(funcionario **, int, int);
void le_struct(funcionario *, int);
void set_struct(funcionario *, int, int *);
void lista_funcionarios(funcionario *, int);