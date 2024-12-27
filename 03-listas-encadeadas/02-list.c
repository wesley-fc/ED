#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float x;
    float y;
    struct Node *next;
} Node;

// Lista de pontos.
Node *lista_pontos;

// Essa função adiciona no ínicio da lista.
void push_front(float x, float y){
    Node *p = (Node*) malloc(sizeof(Node));
    p->x = x;
    p->y = y;
    // O next do meu novo Node vai apontar para o primeiro elemento da lista.
    p->next = lista_pontos; 

    // O meu novo Node agora se torna o primeiro elemento dá lista.
    lista_pontos = p;
}

// Essa função adiciona no final da lista.
void push_back(float x, float y){
    Node *p = (Node*) malloc(sizeof(Node));
    p->x = x;
    p->y = y;
    // Se p->next não for explicitamente definido como NULL, ele pode conter um valor aleatório, levando 
    // a resultados inesperados.
    p->next = NULL; 

    // Se a lista estiver vazia, o novo nó é o primeiro.
    if(lista_pontos == NULL){
        lista_pontos = p;
        return;
    }

    // Percorre a lista até o último nó.
    Node *temp = lista_pontos;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Conecta o novo nó no final da lista.
    temp->next = p;
}

// Função para mostrar a lista.
void display_list(Node *lista){
    // Recebe o endereço de memória do primeiro nó da lista.
    Node *temp = lista;
    // Caso a lista esteja vazia nada será exibido, pós não entraremos no while.
    while(temp != NULL){
        // Exibe os valores do nó atual.
        printf("(%.2f, %.2f) ", temp->x, temp->y);
        // O nó temporário recebe o próximo nó da lista.
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    push_front(1, 2);
    push_front(3, 4);
    push_front(5, 6);
    
    push_back(7, 8);
    push_back(9, 10);

    display_list(lista_pontos);

    return 0;
}