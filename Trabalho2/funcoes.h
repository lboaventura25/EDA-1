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
int index_of_disciplina(Aluno *, char *);
Aluno * at_pos(List *, int);
Disciplina * at_pos_disciplina(Aluno *, int);
Disciplina * create_disciplina();
Disciplina * menu_cadastra_disciplina();
void push_disciplina(Aluno *, Disciplina *);
void print_list_disciplina(Aluno *);
Disciplina * menu_edita_disciplina(Aluno *);
void edita_disciplina(Disciplina *);
int is_empty_disciplina(Aluno *);
void exclui_disciplina(Aluno *, Disciplina *);
void pop_disciplina(Aluno *);
void pop_index_disciplina(Aluno *, Disciplina *, Disciplina *);

#endif