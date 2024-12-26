#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto {
    float x;
    float y;
} Ponto;

int main(void)
{   
    /*
        A alocação dinâmica em C é uma técnica que permite gerenciar a memória em tempo de execução,
        ao contrário da alocação estática, que ocorre em tempo de compilação. Isso é útil para criar
        programas mais flexíveis, especialmente quando o tamanho dos dados não é conhecido previamente.

        Principais funções para alocação dinâmica: A biblioteca padrão do C fornece algumas funções para
                                                   manipular a memória dinâmica. Essas funções estão 
                                                   disponíveis no cabeçalho stdlib.h

            1. Malloc.
                * Aloca um bloco de memória contígua de um tamanho específico.
                * A memória alocada não é inicializada.
                
                Exemplo:
                    int *ptr = (int*) malloc(5 * sizeof(int)); // Aloca espaço para 5 inteiros.
                    // verifica se a alocação foi bem sucedida. 
                    if(ptr == NULL){
                        printf("Falha na alocação de memória.\n");
                        exit(1);
                    } 

            2. Free.
                * Libera um bloco de memória previamente alocado.
                * Deve sempre ser usado para evitar vazamento de memória.

                Exemplo:
                    free(ptr); // Libera a memória alocada.
                    ptr = NULL; // Evita ponteiro pendente.
    */
    // A função sizeof calcula o tamanho de um Ponto na memória, em bytes.
    // A função malloc aloca esse espaço na memória e retorna um ponteiro para o início do bloco alocado.
    // sizeof faz um casting para converter o ponteiro genérico (`void*` retornado pelo malloc) 
    // para um ponteiro para Ponto (`Ponto*`).
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));

    // NULL é uma constante padrão que representa um ponteiro inválido ou nulo. Em termos simples
    // "Nenhum endereço válido", quando malloc, calloc ou realloc não consegue alocar o espaço de
    // memória solicitado, ela retorna NULL para indicar que a alocação falhou.
    if(p == NULL){
        printf("Erro na alocacao\n");
        exit(1); // Encerra o programa.
    }

    // Acessando os membros desse Ponto.
    printf("Digite o valor do ponto X: ");
    scanf("%f", &p->x);

    printf("Digite o valor do ponto Y: ");
    scanf("%f", &p->y);

    // Exibindo os valores.
    printf("p->x: %.2f\n", p->x);
    printf("p->y: %.2f\n", p->y);

    free(p); // Libera a memória alocada.
    p = NULL; // Evita ponteiro pendente.

    return 0;
}