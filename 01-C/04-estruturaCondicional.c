#include <stdio.h>

int main(void)
{
    /*
        Em C, estruturas condicionais são usadas para tomar decisões no código com base em condições,
        Assim como em outras linguagens, as principais estruturas condicionais em C incluem if, if-else,
        else if, e o operador ternário.
    */
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    /*
        A estrutura if verifica uma condição. Se for verdadeira, executa o bloco de código associado.
    */
    if(idade >= 18){
        printf("Voce pode ir para a festa.\n");
    }

    float dinheiro;
    printf("\nDigite quanto voce tem de dinheiro: ");
    scanf("%f", &dinheiro);

    /*
        Estrutura if-else, inclui um bloco else para executar código quando a condição if for falsa.
    */
    if(dinheiro >= 1000.00){
        printf("Voce pode comprar uma televisao.\n");
    } else {
        printf("Voce nao pode comprar uma televisao.\n");
    }

    float nota; // 0.00 a 10.00
    printf("\nDigite sua nota: ");
    scanf("%f", &nota);

    /*
        Estrutura if-else if-else.
        Permite verificar múltiplas condições.
    */
    if(nota >= 9.00){
        printf("Aprovado com excelencia.\n");
    } else if(nota >= 6.00){
        printf("Aprovado.\n");
    } else {
        printf("Reprovado.\n");
    }

    int habilitacao; 
    printf("\nDigite 1 para se voce tem habilitacao e 0 para nao: ");
    scanf("%d", &habilitacao);
    
    /*
        É possível aninhar estruturas condicionais para lidar com situações complexas.
    */
    // Vou utilizar a variável idade declarada anteriormente.
    if(idade >= 18){
        if(habilitacao){ // 1 representa verdadeiro e 0 representa falso.
            printf("Pode dirigir.\n");
        } else {
            printf("Nao pode dirigir, mas e maior de idade.\n");
        }
    } else {
        printf("Nao pode dirigir, e menor de idade.\n");
    }

    /*
        O operador condicional ternário é uma forma compacta de escrever um if-else.
        Sintaxe:
            variável = (condição) ? valor_se_verdadeiro : valor_se_falso; 

        o operador ternário é preferivel em situações mais simples.
    */
    // Vou utilizar a variável idade novamente.
    char* status = (idade >= 18) ? "Maior de idade" : "Menor de idade";
    printf("\nResultado da operacao ternaria: %s\n", status);

    /*
        Condições podem ser combinadas usando os operadores lógicos && (AND), || (OR), e ! (NOT)
        
        Além desses temos os operadores de comparação:
            >  : MAIOR
            <  : MENOR
            >= : MAIOR OU IGUAL
            <= : MENOR OU IGUAL
            == | IGUAL 
            != | DIFERENTE 
    */
    // Vou utilizar as variáveis idade e habilitacao criadas anteriormente.
    if(idade >= 18 && habilitacao == 1){
        printf("\nPode dirigir.\n");
    }else {
        printf("\nNao pode dirigir.\n");
    }

    return 0;
}