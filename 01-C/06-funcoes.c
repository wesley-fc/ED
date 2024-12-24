#include <stdio.h>

/*
    Em C, uma função é um bloco de código que realiza uma tarefa específica.
    Ela pode ser chamada em diferentes partes do programa para evitar repetição de código e melhorar a 
    organização. 

    1. Estrutura de uma função:
        Uma função em C tem três partes principais:
            1. Declaração da função (protótipo): Informa ao compilador o nome, o tipo de retorno e os 
            parâmetros da função. Geralmente, é usada para permitir que a função seja chamada antes de
            sua definição.
            
            2. Definição da função: Contém o código que será executado. Inclui o tipo de retorno, o nome,
            os parâmetros e o corpo da função.

            3. Chamada da função: O local no programa onde a função é chamada.

    2. Tipos de retorno:
        O tipo de retorno indica o tipo de dado que a função devolve ao chamador. Exemplos:
            * void: A função não retorna valor.
            * Tipos básicos como int, float, char etc...
            
    3. Parâmetros:
        Os parâmetros são as entradas fornecidas para a função. Eles podem ser de qualquer tipo básico
        ou composto.

        1. Parâmetros por valor: O valor do argumento é copiado para o parâmetro da função. Alterações 
        no parâmetro não afetam a variável original.

        2. Parâmetros por referência (ponteiros): Se você deseja alterar o valor da variável original, 
        use ponteiros como parâmetros.

    4. Escopo de variáveis:
        As variáveis declaradas dentro de uma função têm escopo local, ou seja, só existem enquanto a 
        função está sendo executada.
    
    5. Funções recursivas:
        Uma função pode chamar a si mesma. Isso é chamado de recursão.
*/
int soma(int num1, int num2); // protótipo da função soma.
float dividir(float num1, float num2); // protótipo da função dividir.
int multiplicar(int x, int y);
void incrementar_valor(int *num);
int fatorial(int n); // protótipo da função fatorial.

int main(void)
{
    int resultado_soma = soma(3, 5);
    float resultado_divisao = dividir(10.0, 5.0);
    float resultado_divisao2 = dividir(10, 0);
    int num = 10;
    int *ponteiro = &num;
    incrementar_valor(ponteiro); // passando o endereço de num como argumento. incrementa em 1.
    incrementar_valor(ponteiro); // passando o endereço de num como argumento. incrementa em 1.
    int fatorial_de_10 = fatorial(10);

    printf("resultado da soma 3 + 5 = %d\n", resultado_soma);
    printf("resultado da divisao 10 / 5 = %.2f\n", resultado_divisao);
    printf("resultado da divisao 10 / 0 = %.2f\n", resultado_divisao2);
    printf("num = %d\n", *ponteiro);
    printf("fatorial de 10 = %d\n", fatorial_de_10);
    
    return 0;
}

// definição da função soma.
int soma(int num1, int num2){
    return num1 + num2;
}

// definição da função dividir.
float dividir(float num1, float num2){
    if (num2 != 0){
        return num1 / num2;
    }
    return 0; // Divisão por zero não é permitida.
}

// definição da função multiplicar.
int multiplicar(int x, int y){
    return x * y;
}

// definição da função incrementar_valor.
void incrementar_valor(int *num){  
    (*num)++; // incrementando o valor de num.
}

// definição da função fatorial.
int fatorial(int n){
    if(n == 0){
        return 1;
    }
    return n * fatorial(n - 1);
}