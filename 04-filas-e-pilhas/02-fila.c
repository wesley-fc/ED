#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int senha;
    struct Fila *next_item;
} Fila;

int empty_fila(Fila *fila){
    return fila == NULL;
}

// função para adicionar um elemento ao final da fila.
Fila *enqueue(Fila *tail, int senha){
    if(empty_fila(tail)){
        Fila *new_item = (Fila*) malloc(sizeof(Fila));
        new_item->senha = senha;
        new_item->next_item = NULL;
        tail = new_item;   

        return tail;
    }
    
    Fila *new_item = (Fila*) malloc(sizeof(Fila));
    new_item->senha = senha;
    new_item->next_item = NULL;
    tail->next_item = new_item;
    tail = new_item;
    return tail;
}

// função para remover um elemento do começo.
Fila *dequeue(Fila *fila){
    if(empty_fila(fila)){
        printf("fila vazia\n");
        return fila;
    }
    Fila *new_fila = fila->next_item;
    free(fila);
    return new_fila;
}

// função para exibir a fila.
void display_fila(Fila *fila){
    if(empty_fila(fila)){
        printf("NULL\n");
        return;
    }
    printf("[%d] -> ", fila->senha);
    display_fila(fila->next_item);
}

int main(void)
{  
    Fila *fila_head = NULL;
    Fila *fila_tail = NULL;

    fila_tail = enqueue(fila_tail, 10);
    fila_head = fila_tail;
    fila_tail = enqueue(fila_tail, 20);
    fila_tail = enqueue(fila_tail, 30);
    fila_tail = enqueue(fila_tail, 40);   

    display_fila(fila_head);

    fila_head = dequeue(fila_head);
    fila_head = dequeue(fila_head); 

    display_fila(fila_head);

    return 0;
}