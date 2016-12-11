#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *arquivo = fopen("teste_1.txt", "r"), *arquivo2 = fopen("teste_2.txt", "w+");
  int caractere;

  // testa se o arquivo foi aberto com sucesso
  if(arquivo != NULL){

    // vamos usar um laço para ler o conteúdo do arquivo
    // e exibí-lo
    while((caractere = fgetc(arquivo)) != EOF){
      printf("%c", caractere);
	putc(caractere,arquivo2);
	}
    fclose(arquivo); // libera o ponteiro para o arquivo
fclose(arquivo2);
  }
  else
    printf("Nao foi possivel abrir o arquivo.");

  printf("\n\n");
  system("PAUSE");
  return 0;
}

