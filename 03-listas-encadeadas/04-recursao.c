#include <stdio.h>

/*
    Funções recursivas são funções que chamam a si mesmas durante sua execução. elas são uma ferramenta
    poderosa em programação, usadas para resolver problemas que podem ser decompostos em sub problemas
    menores de estrutura semelhante ao original.

    A recursão funciona com dois componentes principais:
        1. Caso base: É a condição que termina a recursão. Sem um caso base, a função continuaria 
           chamando a si mesma indefinidamente, causando um erro de "estouro de pilha" (stack overflow).

        2. Chamada recursiva: É o momento em que a função chama a si mesma, resolvendo uma parte do 
                              do problema e delegando o restante à próxima chamada.

*/
int potencia(int base, int expoente){
    if(expoente == 1){
        return base;
    }
    return base * potencia(base, expoente - 1);
}

int main(void)
{
    printf("%d\n", potencia(2, 3));
    return 0;
}