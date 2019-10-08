#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include "structs_trabalho2.h"

void menu_incio(int *);
Aluno * menu_cadastro_aluno();
void menu_encerra();
Aluno * menu_vizualiza_aluno(List * list);
void menu_do_aluno(Aluno *);
List * create_list();
Aluno * create_aluno();
void push(List **, Aluno **);
void print_list(List **);
void print_aluno(Aluno *);
int is_empty(List **);
void edita_nome(char *, int);
int index_of(List *, char *);
Aluno * at_pos(List *, int);
Disciplina * create_disciplina();

#endif