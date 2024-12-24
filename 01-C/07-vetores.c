#include <stdio.h>

// protótipo da função 
void imprimeVetor(int v[], int tamanho); 

int main(void)
{
    /*
        Vetores (também chamados de arrays) na linguagem C são estruturas de dados que permitem armazenar
        uma coleção de valores do mesmo tipo, organizados de forma sequencial na memória.
        Eles são úteis para armazenar conjuntos de dados que precisam ser manipulados ou acessados de 
        forma indexada.

            1. Declaração e Inicialização:
                Um vetor é declarado especificando o tipo de dado, seguido do nome do vetor e do número
                de elementos entre colchetes.

                Inicialização na declaração: Podemos inicializar os valores ao declarar o vetor.

                Se fornecemos menos valores que o tamanho especificado do vetor, os elementos restantes
                serão inicializados com zero.

                Se o tamanho não for especificado, ele será deduzido a partir dos valores fornecidos.

            2. Acesso aos Elementos:
                Os elementos de um vetor são acessados pelo índice, começando em 0.
            
            3. Percorrendo vetores:
                É comum usar laços como for para percorrer um vetor.

            4. Limitações e Cuidados:
                * Acesso fora do limite: C não verifica se o índice está dentro dos limites do vetor.
                Acessar um índice inválido pode causar comportamento indefinido.

                * Tamanho fixo: o tamanho do vetor deve ser conhecido em tempo de compilação. Para 
                tamanhos dinâmicos, use a alocação dinâmica (com malloc ou calloc).

            5. Vetores Multidimensionais:
                C também suporta vetores com mais de uma dimensão, como matrizes.
            
            6. Passando vetores para funções:
                Ao passar um vetor para uma função, apenas o endereço do primeiro elemento é passado, 
                não uma cópia dos dados.
    */
    int numeros1[5]; // declara um vetor de 5 inteiros.
    int numeros2[5] = {10, 20, 30, 40, 50}; // inicializa com 5 valores.
    int numeros3[5] = {1, 2}; // Os elementos restantes serão: {1, 2, 0, 0, 0}.
    int numeros4[] = {1, 2, 3, 4}; // Tamanho deduzido: 4. 

    // O primeiro índice de um vetor é 0.
    printf("valor de numeros4[0] = %d\n", numeros4[0]);
    numeros4[0] = 15; // Atribui o valor 15 para o índice 0 do vetor, anteriormente o valor era 1.
    printf("valor de numeros4[0] = %d\n", numeros4[0]);

    // Percorrendo um vetor usando um laço for.
    for(int i = 0; i < 5; i++){
        printf("numeros2[%d] = %d\n", i, numeros2[i]); // imprimindo índice e valor  do vetor numeros2.
    }
    /*
        A linguagem C não impediu isso, mas escrevemos em um local da memória que não pertence 
        oficialmente ao vetor numeros2. Dependendo da organização da memória nesse momento 
        (que varia entre sistemas, compiladores, e execução), isso pode não causar um 
        problema imediato, mas ainda é perigoso.
    */
    // numeros2[10] = 100; // Evitar fazer esse tipo de coisa.

    // Declaração e inicialização de uma matriz.
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // As linhas e colunas funcionam igualmente um vetor, seus índices começam em 0.
    printf("matriz[1][2] = %d\n", matriz[1][2]); // Acessa o elemento da linha 1, coluna 2 (valor: 6).   

    imprimeVetor(numeros2, 5); // passei o vetor numeros2 e o seu tamanho que é 5. 

    return 0;
}

// v[] recebe o endereço do primeiro índice do vetor, tamanho recebe o tamanho do vetor.
void imprimeVetor(int v[], int tamanho){
    printf("{");
    for(int i = 0; i < tamanho; i++){
        // os elementos do vetor serão impressos um ao lado do outro.
        printf(" %d", v[i]);
    }
    printf(" }\n");
}