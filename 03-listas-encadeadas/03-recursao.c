#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int element;
    struct List *next;
} List;

// verifica se é uma lista vazia
int empty(List *list){
    return list == NULL;
}

// adicionando no começo da lista.
List *append(List *list, int element){
    List* new_node = (List*) malloc(sizeof(List));
    // verifica se a alocação de memória foi bem sucedida.
    if (new_node == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        return NULL; 
    }
    new_node->element = element;
    new_node->next = list;
    list = new_node;
    return list;
}


// adiciona um elemento no fim da lista
List *push_list(List *list, int element){
    // quando chegamos numa lista vazia, criamos um novo nó e o retornamos.
    if(empty(list)){
        List *new_node = (List*) malloc(sizeof(List)); 
        // verifica se a alocação de memória foi bem sucedida.
        if (new_node == NULL) {
            fprintf(stderr, "Erro ao alocar memoria\n");
            return NULL; 
        }
        new_node->element = element;
        new_node->next = NULL;
        return new_node;
    }

    // chamada recursiva para chegarmos ao final da lista (NULL).
    List *result = push_list(list->next, element);
    // verifica se não houve alguma falha de alocação durante a execução da recursão.
    if (result == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        return NULL; 
    }

    list->next = result;
    return list; 
}

// remove um elemento do ínicio da lista.
List *drop_head(List *list){
    // Se for uma lista vazia retornamos NULL.
    if(empty(list)){
        return NULL;
    }

    // atribuo o próximo nó para o meu new_list.
    List *new_list = list->next;
    free(list); // libero a memória do nó do começo da lista.
    return new_list;
}

// mudar o elemento do ínicio da lista.
List *change_head(List *list, int element){
    // se for uma lista vazia retornamos NULL.
    if(empty(list)){
        return NULL;
    }

    // atualizando o elemento do começo da lista.
    list->element = element;
    return list; // retornamos a lista.
}

// exibe todos os elementos da lista.
void display_list(List *list){
    if(empty(list)){
        printf("\n");
        return;
    }
    printf("%d ", list->element);
    display_list(list->next);
}

void free_list(List *list){
    if(list->next == NULL){
        return;
    }
    // percorre até o último nó da lista.
    free_list(list->next);
    free(list); // libera a memória do nó atual.
}

int main(void)
{
    // Uma lista encadeada é uma estrutura de dados recursiva.
    // A forma natural de tratar problemas recursivos é com recursão.
    // Cada parte de uma lista encadeada é uma sub-lista.  
    // Todas as operações no primeiro elemento da lista (topo) são O(1).
    // Todas as operações no restante da lista são O(n).
    List *list = NULL; // lista vazia.

    list = append(list, 10);
    display_list(list);

    list = append(list, 20);
    display_list(list);
    
    list = append(list, 30);
    display_list(list);
    
    list = drop_head(list);
    display_list(list);

    list = push_list(list, 50);
    display_list(list);

    list = push_list(list, 60);
    display_list(list);

    list = push_list(list, 70);
    display_list(list);

    list = change_head(list, 90);
    display_list(list);

    free_list(list);

    return 0;
}