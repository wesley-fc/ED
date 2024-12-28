#include <stdio.h>
#include <string.h> // biblioteca com funções para manipulação de strings.
#include <stdlib.h>

/*
    Melhorar a forma como pensamos em recursão envolve desenvolver uma compreensão sólida de como ela
    funciona e praticar boas abordagens sistemáticas para resolver problemas recursivos.

    1. Conceito da divisão e conquista:
        * Divida o problema maior em subproblemas menores, que têm a mesma estrutura do problema original.
        * Pense na solução como um processo iterativo: resolva o menor problema possível primeiro (caso
          base) e use-o como base para resolver problemas maiores.

    2. Foco no caso base:
        * O caso base é fundamental para evitar loops infinitos. Pense:
            - Qual o menor problema que pode ser resolvido diretamente? 
            - Quando a recursão deve parar?
                // praticar identificar e escrever o caso base antes de pensar nas chamadas recursivas. 

    3. Visualize a pilha de execução:
        * Ao chamar uma função recursiva, o programa mantém o estado de cada chamada em uma "pilha".
        * Visualizar a pilha pode ajudar a entender o fluxo.
          - O que acontece primeiro?
          - O que é armazenado ?
          - Quando as chamadas começam a "desempilhar" e resolver o problema?
        * Exemplo prático:
            - Para fatorial(3), a pilha seria:
                * fatorial(3) espera fatorial(2)
                * fatorial(2) espera fatorial(1)
                * fatorial(1) espera fatorial(0)
                * fatorial(0) retorna 1, e a pilha começa a resolver de volta.
                 
    4. Quebrar o problema em componentes simples:
        * Descrever o problema em um conjunto de etapas:
            - O que fazer com o caso atual?
            - Como delegar o restante a função?
            - Como combinar os resultados para formar a solução?
    
    5. Testar com problemas simples antes de avançar para complexos.
        * Soma de números em uma lista.
        * Verificação de palíndromos.
        * Sequência de Fibonacci.

    6. Estudar padrões de recursão:
        * Recursão com um caso base. (fatorial, soma, fibonacci)
        * Recursão com divisão de problemas. (busca binária)
        * Recursão com backtracking. (quebra cabeças e labirintos)
         
    7. Praticar escrita e depuração.
        * Escrever a função passo a passo no papel ou em um editor.
        * Usar ferramentas de depuração para observar como as chamadas recursivas se desenrolam.
*/

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    return n * (n - 1);
}

int fibonacci(int n){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

char *inverte_palavra(char *palavra, int size){
    if(size == 1){
        char *resultado = (char*) malloc(sizeof(char) * 2);  // Array para conter o caractere + '\0'
        resultado[0] = palavra[size - 1];
        resultado[1] = '\0';
        return resultado;
    }    

    char *resto_invertido = inverte_palavra(palavra, size - 1);
    
    char *resultado = malloc(sizeof(char) * (size + 1));
    
    resultado[0] = palavra[size - 1];
    
    strcpy(resultado + 1, resto_invertido);

    free(resto_invertido);
    return resultado;
}

int verifica_palindromo(char *palavra){
    return strcmp(palavra, inverte_palavra(palavra, strlen(palavra))) == 0;
}

int main(void)
{
    printf("%d\n", fatorial(3));

    int n;
    printf("Me informe qual numero da sequencia de fibonacci voce deseja: ");
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));

    char palavra[50];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if(verifica_palindromo(palavra)){
        printf("E um palindromo\n");
    } else {
        printf("Nao e um palindromo\n");
    }

    return 0;
}