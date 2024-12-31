#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int value;
    struct List *next;
} List;

int length = 0;

// função para adicionar elementos na lista.
List *add_index(List *list, int index, int value){
    if(index < 0 || index > length){
        printf("indice invalido\n");
        exit(1);
    }
    if(index == 0){
        List *new_node = (List*) malloc(sizeof(List));
        if(new_node == NULL){
            printf("falha na alocação de memoria!\n");
            return list;
        }
        new_node->value = value;
        new_node->next = list;
        length++;
        return new_node;
    }
    list->next = add_index(list->next, index - 1, value);
    return list;
}

// checa se a lista está vazia ou não.
int empty_list(List *list){
    return list == NULL;
}

// função para deletar um determinado índice da minha lista.
List *delete_index(List *list, int index){
    // verificação de índice válido.
    // índice negativo não é válido.
    // índice maior ou igual a quantidade de elementos na minha lista não é válido.
    if(index < 0 || index >= length){
        printf("indice invalido: %d (tamanho da lista %d)\n", index, length);
        return list;
    }

    if(index == 0){
        List *prox = list->next;
        free(list);
        length--; // decrementa o tamanho da lista.
        return prox;
    }
    list->next = delete_index(list->next, index - 1);
    return list;
}

// função para exibir a lista.
void display_list(List *list){
    if(empty_list(list)){
        printf("null\n");
        return;
    }
    printf("[%d] -> ", list->value);
    display_list(list->next);
}

int main(void)
{
    List *list_inteiros = NULL;
    // imprime a lista vazia.
    display_list(list_inteiros);

    // insere elementos na lista.
    list_inteiros = add_index(list_inteiros, 0, 10);
    list_inteiros = add_index(list_inteiros, 1, 20);
    list_inteiros = add_index(list_inteiros, 2, 30);
    list_inteiros = add_index(list_inteiros, 0, 0);

    display_list(list_inteiros);

    // deleta o elemento do índice 2.
    list_inteiros = delete_index(list_inteiros, 2);
    display_list(list_inteiros);

    // deleta o elemento do índice 0.
    list_inteiros = delete_index(list_inteiros, 0);
    display_list(list_inteiros);

    // deleta o elemento do índice 1.
    list_inteiros = delete_index(list_inteiros, 1);
    display_list(list_inteiros);

    
    // deleta o elemento do índice 0.
    list_inteiros = delete_index(list_inteiros, 0);
    display_list(list_inteiros);    
    
    // deleta o elemento do índice 0. (não existe mais índice 0)
    list_inteiros = delete_index(list_inteiros, 0);
    display_list(list_inteiros);    

    return 0;
}