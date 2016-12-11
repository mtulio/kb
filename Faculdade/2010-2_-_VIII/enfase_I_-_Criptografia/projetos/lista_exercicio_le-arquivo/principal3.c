#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char nome1, nome2;

	printf("Digite o nome do arquivo a ser copiado: ");
	scanf("%c",&nome1);
	printf("Digite o nome do arquivo novo: ");
	scanf("%c",&nome2);

//	FILE *arquivo = fopen("teste_1.txt", "r"), *arquivo2 = fopen("teste_3.txt", "w+");
	FILE *arquivo1 = fopen(nome1, "r"), *arquivo2 = fopen(nome2, "w+");
	int caractere;

	// testa se o arquivo foi aberto
	if(arquivo1 != NULL){
		while((caractere = fgetc(arquivo1)) != EOF){
			printf("%c", caractere);
			putc(caractere,arquivo2);
		}
		fclose(arquivo1);
		fclose(arquivo2);
  	}
  	else printf("Nao foi possivel abrir o arquivo.");
	
	printf("\n\n");
	return 0;
}//fim main

