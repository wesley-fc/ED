#include <stdio.h>

int main(void)
{
    /*
        Entrada de dados em C é feita geralmente utilizando a função scanf, que permite ao programa ler
        valores do teclado e armazená-los em variáveis.

        sintaxe:
            scanf("formato", &variavel);
        
            1. Formato: define o tipo de dado a ser lido (%d para int, %f float, %lf para doubles, %c
                        para char etc...)
            
            2. &variavel: o endereço da variável onde o valor lido será armazenado. A exceção é para 
                          strings onde o uso do & não é necessário. 
    */
    int idade;
    float altura;
    char genero;

    printf("digite sua idade: ");
    // o operador & é o operador de endereço em C. Ele retorna o endereço de memória de uma variável.
    scanf("%d", &idade); 

    printf("digite sua altura em metros(use . como separador): ");
    scanf("%f", &altura);

    printf("informe seu genero, digite M para masculino ou F para feminino: ");
    // o espaço antes do %c serve para ignorar caracteres que possam ter ficado no buffer do teclado.
    scanf(" %c", &genero); 

    printf("sua idade e: %d\n", idade);
    printf("sua altura e: %.2f\n", altura);
    printf("seu genero e: %c", genero);

    return 0;
}