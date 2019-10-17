#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct idade * head;
    struct idade * tail;
    int size;
}List;

typedef struct idade {
    int idade;
    struct idade * next;
    struct idade * previous;
}Idade;

    List * create_List();
    Idade * create_node(int);
    void push(List *, Idade *);
    void print_idades(List *);
    void print_inverso(List *);
    void push_back(List *, Idade *);

int main() {

    List * list = create_List();
    Idade * idade;
    int age;

    do {
        printf("Digite a idade: ");
        scanf("%d", &age);
        if(age >= 0) {
            idade = create_node(age);
            push_back(list, idade);
        } else {
            printf("**** Idade Invalida! ****\n");
        }
    } while(age >= 0);

    print_idades(list);
    print_inverso(list);

    if(list)
        free(list);
    
    return 0;
}

List * create_List() {
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list ->tail = NULL;
    list->size = 0;

    return list;
}

Idade * create_node(int age) {
    Idade * idade = (Idade *) malloc(sizeof(Idade));
    idade->previous = NULL;
    idade->next = NULL;
    idade->idade = age;

    return idade;
}

void push(List * list, Idade * idade) {
    if(idade) {
        if(list->head) {
            idade->next = list->head;
            list->head->previous = idade;
            list->head = idade;
        } else {
            list->head = idade;
            list->tail = idade;
        }
        list->size++;
    } else {
        printf("**** No nao existe! ****\n");
    }
}

void push_back(List * list, Idade * idade) {
    if(idade) {
        if(list->tail) {
            idade->previous = list->tail;
            list->tail->next = idade;
            list->tail = idade;
        } else {
            list->head = idade;
            list->tail = idade;
        }
        list->size++;
    } else {
        printf("**** No nao existe! ****\n");
    }
}

void print_idades(List * list) {
    Idade * aux = list->head;
    int i = 0;
    
    printf("------------------Impressao Normal------------------------\n");
    while(aux != NULL) {
        printf("Idade[%d] --> %d\n", i++, aux->idade);
        aux = aux->next;
    }
}

void print_inverso(List * list) {
    Idade * aux = list->tail;
    int i = 0;
    
    printf("---------------Impressao De tras pra frente---------------\n");
    while(aux != NULL) {
        printf("Idade[%d] --> %d\n", i++, aux->idade);
        aux = aux->previous;
    }
}
