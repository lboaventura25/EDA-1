#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int idade;
    struct node * next;
}Node;

typedef struct queue {
    Node * front, * rear;
    int size;
}Queue;

Queue * create_queue() {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    int size = 0;
    return queue;
}

Node * create_node() {
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    printf("::: Digite a idade --> ");
    scanf("%d", &node->idade);
    return node;
}

void enqueue(Queue * queue, Node * node) {
    if(node) {
        if(queue->rear == NULL) {
            node->next = queue->rear;
            queue->front = queue->rear = node;
            queue->size++;
        } else {
            queue->rear->next = node;
            queue->rear = node;
            queue->size++;
        }
    }
}

void dequeue(Queue * queue) {
    if(queue->front != NULL) {
        Node * aux = queue->front;
        queue->front = aux->next;
        if(queue->front == NULL)
            queue->rear = NULL;
        queue->size--;
        free(aux);
    } else {
        printf("Lista Vazia!\n");
    }
}

void print(Queue * queue) {
    Node * aux = queue->front;
    int i = 0;
    while(aux) {
        printf("Elemento[%d]: %d\n", i+1, aux->idade);
        aux = aux->next;
        i++;
    }
    printf("------------------------------------------\n");
}

int main() {
    int i;
    Queue * queue = create_queue();
    Node * node;
    for(i = 0; i < 10; i++) {
        node = create_node();
        enqueue(queue, node);
    }

    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);

    return 0;
}