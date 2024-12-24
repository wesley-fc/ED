#include <stdio.h>

/*
    - A tipagem de C é estática e fortemente tipada, o que significa que:
        1. Estática: o tipo de cada variável é definido em tempo de compilação e não pode ser alterado
                     durante a execução do programa. isso implica que precisamos declarar o tipo da 
                     variável antes de usá-la.

        2. Fortemente tipada: C não permite misturar tipos sem conversão explícita (ou implícita, mas
                              controlada pelo compilador). No entanto, como C é uma linguagem de "baixo
                              nível", é possível realizar conversões entre tipos diferentes (type casting)
                              o que pode gerar problemas se feito de forma inadequada.

    - Principais tipos de dados em C:
        1. Tipos básicos:
            - int: números inteiros (4 bytes na maioria dos sistemas modernos).
            - float: números de ponto flutuante com precisão simples (4 bytes).
            - double: números de ponto flutuante com precisão dupla (8 bytes).
            - char: caracteres individuais (1 byte, geralmente armazenando um código ASCII).
            - void: ausência de tipo, usado principalmente para funções que não retornam valor.
*/

int idade = 20; // declarando variável do tipo int. (essa variável é de escopo global)

int main(void)
{
    float altura = 1.82;
    double peso = 130.00;
    char genero = 'M';
    
    // %d é um especificador de formato para valores inteiros.
    printf("o valor da variavel 'idade'  = %d\n", idade); 
    // %f é um especificador de formato para valores ponto flutuante de precisão simples.
    printf("o valor da variavel 'altura' = %f\n", altura);
    // %lf é um especificador de formato para valores ponto flutuante de precisão dupla.
    // podemos delimitar a quantidade casas decimais a serem exibidas tanto no %f quanto no %lf.
    printf("o valor da variavel 'peso'   = %.2lf\n", peso);
    // %c é um especificador de formato para valores do tipo caractere.
    printf("o valor da variavel 'genero' = %c\n", genero);

    return 0;
}