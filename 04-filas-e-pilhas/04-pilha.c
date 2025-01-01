#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int element;
    struct Stack *prox;
} Stack;

// checa se a pilha está vazia.
int empty_stack(Stack *pilha){
    return pilha == NULL;
}

Stack *push(Stack *pilha, int element){
    Stack *new_node = (Stack*) malloc(sizeof(Stack));
    if(new_node == NULL){
        printf("falha na alocacao\n");
    }
    new_node->element = element;
    new_node->prox = pilha; 
    return new_node;
}

Stack *pop(Stack *pilha){
    // verifica se a pilha está vazia.
    if(empty_stack(pilha)){
        printf("pilha vazia, nao e possivel remover elementos.\n");
        return pilha;
    }
    // caso exista um elemento no topo.
    Stack *temp = pilha; // recebe a referência do elemento no topo
    pilha = pilha->prox; // o topo da minha pilha se torna o próximo elemento.
    free(temp); // libero a memória do antigo elemento do topo.
    return pilha;
}

void display_stack(Stack *pilha){
    if(empty_stack(pilha)){
        printf("NULL\n");
        return;
    }
    printf("[%d] -> ", pilha->element);
    display_stack(pilha->prox);
}

int main(void)
{
    Stack *pilha = NULL;

    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);
    display_stack(pilha);
    
    // remove o 30.
    pilha = pop(pilha);
    display_stack(pilha);
    
    // remove o 20.
    pilha = pop(pilha);
    display_stack(pilha);

    // remove o 10.
    pilha = pop(pilha);    
    display_stack(pilha);

    // tenta remover um elemento de uma pilha vazia.
    pilha = pop(pilha);    

    return 0;
}