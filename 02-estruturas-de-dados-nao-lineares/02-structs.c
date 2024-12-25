#include <stdio.h>


// Aqui, a struct Pessoa agrupa três variáveis: nome, idade e altura.
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

// Agr não precisamos usar "struct Personagem"
typedef struct Personagem {
    char nome[50];
    int atk;
    int def;
} Personagem;

int main(void)
{
    /*
        O que são structs? 
            Em C, uma struct é uma forma de agrupar variáveis diferentes (pontecialmente de tipos 
            distintos) em uma única unidade. Ela é útil para representar entidades do mundo real, 
            como um aluno, um carro ou um ponto do plano cartesiano, que possuem diversas 
            propriedades relacionadas.

            Sintaxe básica:
                struct nomeDaStruct {
                    tipo membro1;
                    tipo membro2;
                };

            Depois de declarar a struct, podemos declarar uma variável do tipo struct.

            Para acessar os membros da struct utilizamos o ponto.

            Typedef para simplificar: O typedef permite criar um alias (apelido) para o tipo struct,
                                      simplificando seu uso.
                Sintaxe:
                    typedef struct Personagem {
                        char nome[50];
                        int atk;
                        int def;
                    } Personagem;
    */
    // Criando uma instância da struct Pessoa.
    struct Pessoa pessoa1; // Declarando uma variável do tipo struct Pessoa.

    printf("Digite seu nome: ");
    scanf("%s", pessoa1.nome); // Acessando o membro nome da variável pessoa1.

    printf("Digite sua idade: ");
    scanf("%d", &pessoa1.idade); // Acessando o membro idade da variável pessoa1.

    printf("Digite sua altura: ");
    scanf("%f", &pessoa1.altura); // Acessando o membro altura da variável pessoa1.

    printf("\nInformacoes da pessoa:\n");
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    // Declarando um Personagem.
    Personagem personagem1;
    
    printf("\nDigite o nome do personagem: ");
    scanf("%s", personagem1.nome); // Acessando o membro nome da variável personagem1.

    printf("Digite o atk do personagem: ");
    scanf("%d", &personagem1.atk); // Acessando o membro atk da variável personagem1.

    printf("Digite a def do personagem: ");
    scanf("%d", &personagem1.def); // Acessando o membro def da variável personagem1.

    printf("\nInformacoes do personagem:\n");
    printf("Nome: %s\n", personagem1.nome);
    printf("Atk: %d\n", personagem1.atk);
    printf("Def: %d\n", personagem1.def);

    return 0;
}