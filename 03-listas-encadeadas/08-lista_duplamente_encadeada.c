#include <stdio.h>
#include <stdlib.h>

typedef struct Doubly_list {
    int value;
    struct Doubly_list *previous;
    struct Doubly_list *next;
} Doubly_list;

int length = 0;

int empty_list(Doubly_list *list);

Doubly_list *add(Doubly_list *list, int index, int value){
    if(index < 0 || index > length){
        printf("indice invalido\n");
        exit(1);
    }

    if(index == 0){
        Doubly_list *new_node = (Doubly_list*) malloc(sizeof(Doubly_list));
        if(new_node == NULL){
            printf("falha na alocacao de memoria\n");
            return list;
        }

        // atualiza os dados do meu novo nó.
        new_node->previous = NULL;
        new_node->next = list; // o novo nó aponta para a lista atual.
        new_node->value = value;
        length++;

        // se houver um nó atual, eu referencio o previous dele para o meu novo nó.
        if(!empty_list(list)){
            list->previous = new_node;
        }

        // retorno o novo nó.
        return new_node; 
    }
    list->next = add(list->next, index - 1, value);
    list->next->previous = list; // o previous do novo nó aponta para a lista atual.
    return list;
}

// função para verificar se a lista está vazia.
int empty_list(Doubly_list *list){
    return list == NULL;
}

// função para exibir a lista.
void display_list(Doubly_list *list){
    if(empty_list(list)){
        printf("NULL\n");
        return;
    }
    printf("<- [%d] -> ", list->value);
    display_list(list->next);
}

int main(void)
{
    Doubly_list *list = NULL;
    display_list(list);

    list = add(list, 0, 10);
    list = add(list, 1, 20);
    list = add(list, 2, 30);
    list = add(list, 1, 50);
    list = add(list, 0, 100);

    display_list(list);

    return 0;
}