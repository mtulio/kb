#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

/*Implementar o algoritmo 5 e executá-lo 1000 vezes pra uma entrada aleatória
 * para uma entrada aleatoria de 2 elementos. Qual é a média de comparações
 */
/* IDEIA
 * CRIAR UM VETOR COM 9 POSIÇÕES E EXECUTA-LO MIL VEZES PROCURANDO UMA DETERMINADO
 * ELEMENTO QUE EU IREI INFORMAR NO VETOR, E VER O NUMERO DE COMPARAÇÕES QUE
 * TEVE
 */

int main (int argc, char *argv[])
{

	int i = 0, cont, *vet, ch, pos = 0; //declaração

	ch = atoi(argv[1]); //caso o usuario digite uma string eu converto ela para numero
	srand(time(NULL)); //função randomica
	for(cont = 0; cont < 1000; cont ++) //variar mil vezes
	{
		int achou = FALSE;
		vet = (int *) malloc(10 * sizeof(int)); //aloca um ponteiro

		for(i = 0; i < 9; i++) //variar nove vezes o meu vetor dentro do laço para executar mil vezes
			vet[i] = rand()%1000; //funçao randomica

		for(i = 0; i < 9; i++)
		{
			if(vet[i] == ch)
				achou = TRUE;
			pos = pos + 1;
			if(achou == TRUE)
			{
				printf("\nEncontrado na posição %d.", i);
				printf("\nForam feitas %d comparações.", pos);
				printf("\nFoi encontrado na %d combinação do vetor\n", cont);
				break;
			}
		}
		free(vet);
	}
	printf("\nFoi encontrado na %d combinação do vetor\n", cont);
	printf("\nForam feitas %d comparações.\n", pos);
}
