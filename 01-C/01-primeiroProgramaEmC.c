/*
	#include <stdio.h>
	Diretiva de pré-processador que inclui o arquivo de cabeçalho stdio.h (Biblioteca padrão de entrada
	e saída)
*/
#include <stdio.h>

/*
	Função principal do programa.
	Todo programa C começa sua execução a partir da função main. 
	É o ponto de entrada de todo programa C.
*/
int main(void)
{
	// A função printf em C é usada para exibir informações no terminal. (saída padrão)
	printf("Ola mundo!\n"); // o \n é um caractere de escape que serve para quebrar linha.

	/*
		O 0 como retorno informa ao sistema operacional que o programa foi executado com sucesso.
	*/
	return 0;
}