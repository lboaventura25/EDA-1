#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
	float notas;
	struct no *next;
}node;

typedef struct lista {
	node *head;
	int size;
}list;

	list * create_list();
	void push(list *, node *);
	void pop(list *);
	int is_empty(list *);
	void print_list(list *);
	void imprime_tracejado();
	node * at_pos(list *, int );

int main() {

	list *List;
	node *Node;
	node *aux;
	float notas = 0;
	int excluir;

	List = create_list();

	while(notas >= 0) {
		printf("Adicione a nota %d: ", List->size);
		scanf("%f", &notas);

		if(notas >= 0) {
			Node = (node *) malloc(sizeof(node));
			Node->notas = notas;
			push(List, Node);
		}
	}

	imprime_tracejado();
	print_list(List);
	imprime_tracejado();

	printf("Digite o numero que deseja pesquisar: ");
	scanf("%d", &excluir);

	aux = at_pos(List, excluir);
	
	printf("Numero %d = %.2f\n", excluir, aux->notas);

	printf("Digite quantas notas deseja excluir: ");
	scanf("%d", &excluir);

	for(int i = 0; i < excluir; i++) {
		pop(List);
	}

	print_list(List);
	
	while(List->head != NULL) {
		pop(List);
		// printf("----------- QUANT = %d\n", List->size);
	}

	free(List);
	return 0;
}

list * create_list() {
	list * List = (list *) malloc(sizeof(list));
	List->head = NULL;
	List->size = 0;

	return List;
}

void push(list *List, node *Node) {
	if(Node != NULL) {
		Node->next = List->head;
		List->head = Node;
		List->size++;
	}
}

void pop(list *List) {
	if(is_empty(List)) {
		printf("Lista vazia!\n");
		return;
	}
	
	node * aux = List->head;
	List->head = aux->next;
	free(aux);
	List->size--;
}

int is_empty(list *List) {
	if(List->size == 0)
		return 1;
	else
		return 0;
}

void print_list(list *List) {
	if(is_empty(List)) {
		printf("Lista vazia!\n");
		return;
	}
	node *pointer = List->head;

	while(pointer != NULL) {
		printf("Nota = %.2f\n", pointer->notas);
		pointer = pointer->next;
	}
}

node * at_pos(list *List, int index) {
	int cont = 0;
	node *aux = List->head;

	if(is_empty(List) || index < 0 || index >= List->size) {
		printf("Lista vazia!\n");
	}
	else {
		while(aux != NULL) {
			if(cont == index) {
				return aux;
			}
			cont++;
			aux = aux->next;
		}
	}
	return NULL;
}

void imprime_tracejado() {
	printf("----------------------------------------\n");
}