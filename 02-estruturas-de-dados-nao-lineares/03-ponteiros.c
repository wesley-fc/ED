#include <stdio.h>

// Protótipo da função dobrar.
void dobrar(int *n);

int main(void)
{   
    /*
        O que é um ponteiro?
            Um ponteiro é uma variável que armazena o endereço de memória de outra variável. Em vez de
            conter diretamente um valor, um ponteiro "aponta" para o local onde o valor está armazenado
            na memória.

            1. Declaração e Inicialização de Ponteiros:
                1.1 Declaração de Ponteiros:
                    tipo *nomePonteiro.

                    1. tipo: o tipo do dado que o ponteiro apontará (Ex: int, float, double, char etc..)
                    2. *: indica que a variável é um ponteiro.

                1.2 Inicialização de Ponteiros:
                    Um ponteiro precisa ser inicializado com o endereço de uma variável.
                        Exemplo:   
                            int valor = 10;
                            int *ponteiro_int = &valor; // O ponteiro armazena o endereço da variável.

            2. Operadores Associados a Ponteiros:
                2.1 * (desreferência ou indirection) Acessa o valor armazenado no endereço apontado 
                    pelo ponteiro.
                        Exemplo:
                            int x = 5;
                            int *ptr = &x;

                            printf("%d", *ptr);

                2.2 & (endereço de) Retorna o endereço de memória de uma variável.
                        Exemplo:
                            int x = 5;
                            printf("%p", &x); // Exibe o endereço de 'x' em hexadecimal.
            
            3. Ponteiros e Funções:
                Ponteiros são amplamente utilizados para passar argumentos por referência, permitindo
                que uma função modifique variáveis do programa principal.

    */
    int valor = 43;
    int *ptr = &valor;

    printf("Endereco de valor: %p\n", ptr); // Endereço de 'valor'.
    printf("Valor de valor: %d\n", *ptr); // Valor armazenado no endereço.

    int numero = 5;

    printf("Antes: %d\n", numero);
    // Passa o endereço de número para a função dobrar.
    dobrar(&numero); // Dobra para 10.
    dobrar(&numero); // Dobra para 20.
    printf("Depois: %d\n", numero);

    return 0;
}

// Definição da função dobrar.
void dobrar(int *n){
    *n = *n * 2; // Dobra o valor no endereço apontado por 'n'.
}