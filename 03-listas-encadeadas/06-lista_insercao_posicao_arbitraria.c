#include <stdio.h>
#include <stdlib.h>

/*
    para trabalharmos com inserção em uma posição específica precisamos criar uma variável length
    para determinar o tamanho da nossa lista.
 
    - quando a lista está vazia, podemos apenas inserir no índice 0. (começo da lista)
    - inserção em qualquer ponto da lista.
    - inserção no começo da lista.s
    - inserção no final da lista.
*/ 
typedef struct List {
    float x;
    float y;
    struct List *next;
} List;
// tamanho da nossa lista.
int length = 0;

int empty_list(List *list){
    return list == NULL;
}

// índice inválido: índice menor que 0, índice maior que o tamanho da lista.
// caso base: indice igual a 0
List *add(List *list, int index, float x, float y){
    // index > length nos permite adicionar um novo elemento ao final da lista
    // exemplo: [1] -> [2] -> [3], posso adicionar um elemento 4 ao final da lista
    // [1] -> [2] -> [3] -> [4].
    if(index < 0 || index > length){ 
        printf("indice invalido\n");
        exit(1); // termina o programa caso o índice seja inválido.
    }
    
    if(index == 0){
        List *new_node = (List*) malloc(sizeof(List));
        if (new_node == NULL) {
            printf("falha na alocação de memoria!\n");
            return list;
        }
        new_node->x = x;
        new_node->y = y;
        new_node->next = list;
        length++; // incrementa o tamanho da lista a cada inserção.
        return new_node;
    }
    list->next = add(list->next, index - 1, x, y); 
    return list;
}

void display_list(List *list){
    if(empty_list(list)){
        printf("null\n");
        return;
    }
    printf("(%.2f, %.2f) ", list->x, list->y);
    display_list(list->next);
}

void free_list(List *list){
    if(empty_list(list)){
        return;
    }
    free_list(list->next);
    free(list);
}

int main(void)
{
    List *lista_pontos = NULL;

    display_list(lista_pontos);
    printf("numero de elementos na lista: %d\n", length);

    // adicionando elementos na lista.
    lista_pontos = add(lista_pontos, 0, 10, 0);
    lista_pontos = add(lista_pontos, 1, 20, 0);    
    lista_pontos = add(lista_pontos, 2, 30, 0);
    
    display_list(lista_pontos);
    printf("numero de elementos na lista: %d\n", length);

    // liberando a memória.
    free_list(lista_pontos);

    return 0;
}