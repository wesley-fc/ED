#include <stdio.h>

int main(void)
{
    /*
        Laços de repetição em C permitem executar um bloco de código várias vezes, de acordo com uma 
        condição ou um conjunto de regras. Elas são amplamente utilizadas para automatizar tarefas 
        repetitivas, como processar arrays ou realizar cálculos iterativos. Em C, os principais laços
        de repetição são:
        
        1. for (para):
            O laço for é usado quando o número de iterações é conhecido. Ele possui três partes 
            principais: inicialização, condição e incremento ou decremento.
        
            sintaxe:
                for(inicialização; condição; incremento/decremento){
                    // código a ser executado.
                }
    */
    for(int i = 0; i < 5; i++){
        printf("iteracao: %d\n", i);
    }
    /*
        1. A variável i é inicializada com 0.
        2. O bloco de código é executado enquanto i < 5.
        3. A cada iteração, i é incrementado em 1 (i++).
    */

    /*
        2. while (enquanto):
            O laço while é usado quando a condição de parada não é conhecida antecipadamente e depende
            de eventos durante a execução.

            sintaxe:
                while(condicao){
                    // código a ser executado.
                }
    */
    int contador = 0;
    while(contador < 5){
        printf("Contador: %d\n", contador);
        contador++;
    }
    /*
        O bloco é executado enquanto a condição (contador < 5) for verdadeira.
    */   

    /*
        3. do-while (faça-enquanto):
            Este laço garante que o bloco de código seja executado pelo menos uma vez, mesmo que a 
            condição inicial seja falsa.

            sintaxe:
                do {
                    // código a ser executado
                } while(condição);
    */
    int contador2 = 0;
    do {
        printf("Contador2: %d\n", contador2);
        contador2++;
    } while(contador2 < 5);
    /*
        1. O bloco é executado uma vez. (temos isso por garantia)
        2. A condição é verificada após a execução.
    */

    /*
        Diferenças entre os laços:
            * for: Melhor para quando o número de iterações é conhecido.
            * while: Usado quando a repetição depende de uma condição que pode mudar durante a execução.
            * do-while: garante que o código será executado uma vez, independente da condição inicial.
    */

    /*
        Controle adicional:
            1. break: Saí do laço de repetição imediatamente.
            2. continue: Interrompe a iteração atual e vai para a próxima.
    */
    // break exemplo:
    for(int i = 0; i < 10; i++){
        if(i == 5){
            break; // Saí do laço quando i for igual a 5.
        }
        printf("%d\n", i);
    }
    // continue exemplo:
    for(int i = 0; i < 10; i++){
        if(i == 5){
            continue; // Pula a iteração quando i for igual a 5.
        }
        printf("%d\n", i);
    }

    return 0;
}