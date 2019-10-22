#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    float nota;
    struct node * next;
}Node;

typedef struct list{
    Node * head;
    int size;
}List;

List * create_list();
Node * create_node(float nota);
void push(List * list, Node * node);
void print_list(List * list);
bool is_empty(List * list);
void pop(List * list);
Node * at_pos(List * list, int indice);
int index_of_nota(List * list, float nota);
void insert(List * list, Node * node, int index);
void pop_list(List * list);

int main(){
    float nota;
    int num;
    List * list = create_list();
    Node * aux;
    do{
        printf("Digite uma nota: ");
        scanf("%f", &nota);
        aux = create_node(nota);
        push(list, aux);
    }while(nota >= 0);
    print_list(list);
    
    printf("-------------------------\n");
    printf("Digite quantos elementos deseja remover:");
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        pop(list);
    }
    print_list(list);
    printf("Digite um indice que deseja pesquisar:");
    scanf("%d", &num);
    aux = at_pos(list, num);
    if(aux != NULL){
        printf("Posicao: %d\n", num);
        printf("Nota: %.2f\n", aux->nota);
    }else{
        printf("Indice inexistente!\n");
    }
    printf("-------------------------------------------\n");
    printf("Digite a nota que deseja o indice: ");
    scanf("%f", &nota);
    num = index_of_nota(list, nota);
    if(num >= 0) {
        printf("Indice encontrado eh %d\n", num);
    } else {
        printf("Nota inexistente!\n");
    }
    printf("Digite a nova nota: ");
    scanf("%f", &nota);
    aux = create_node(nota);
    printf("Digite a posicao que deseja inserir a nota: ");
    scanf("%d", &num);
    insert(list, aux, num);
    print_list(list);

    pop_list(list);

    return 0;
}

List * create_list(){
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

Node * create_node(float nota){
    if(nota >= 0){
        Node * node = (Node *) malloc(sizeof(Node));
        node->nota = nota;
        return node;
    }else{
        return NULL;
    }
}

void push(List * list, Node * node){
    if(node != NULL){
        node->next = list->head;
        list->head = node;
        list->size ++;
    }
}

void print_list(List * list){
    if(is_empty(list)){
        printf("Lista Vazia!\n");
        return;
    }
    Node * aux = list->head;
    while(aux != NULL){
        printf("%.2f\n", aux->nota);
        aux = aux->next;
    }
}

bool is_empty(List * list){
    if(list->size == 0){
        return true;
    }else{
        return false;
    }
}

void pop(List * list){
    if(is_empty(list)){
        return;
    }
    Node * aux = list->head;
    list->head = aux->next;
    free(aux);
    list->size--;
}

Node * at_pos(List * list, int indice){
    if(is_empty(list) || indice >= list->size){
        printf("Entrada invalida!\n");
    }else{
        int i=0;
        Node * aux = list->head;
        while(aux != NULL){
            if(i == indice){
                return aux;
            }
            i++;
            aux = aux->next;
        }
    }
    return NULL;
}

int index_of_nota(List * list, float nota) {
    int i = 0, cont = 0, x, h;
    Node * aux = list->head;
    float notala;
    int * notas = (int *) malloc(list->size * sizeof(char));

    while(aux) {
        if(aux->nota == nota) {
            notas[cont] = i;
            cont++;
        }
        i++;
        aux = aux->next;
    }
    for(h = 0; h < cont; h++) {
        i = 0;
        aux = list->head;
        while(aux) {
            if(notas[h] == i)
                printf("(%d) Nota: %.2f\n", h, aux->nota);
            aux = aux->next;
            i++;
        }
    }

    if(cont > 0) {
        printf("Escolha qual nota voce deseja: ");
        scanf("%d", &x);
    }

    for(h = 0; h < cont; h++) {
        if(h == x) {
            notala = notas[h];
            free(notas);
            return notala;
        }
    }
    free(notas);
    return -1;
}

void insert(List * list, Node * node, int index) {
    Node * aux = list->head;
    Node * aux_anterior = aux;
    int i = 0;

    if(index < list->size) {
        while(aux) {
            if(i == index) {
                if(is_empty(list)) {
                    push(list, node);
                } else {
                    node->next = aux;
                    aux_anterior->next = node;
                    list->size++;
                }
            }
            i++;
            aux_anterior = aux;
            aux = aux->next;
        }
    } else {
        printf("Indice invalido!\n");
    }
}

void pop_list(List * list) {
    Node * aux = list->head;

    while(aux) {
        pop(list);
        aux = aux->next;
    }
    free(list);
}