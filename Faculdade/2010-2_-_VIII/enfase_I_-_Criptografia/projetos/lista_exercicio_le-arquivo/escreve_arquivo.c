/* escrevendo caracteres num arquivo */

#include <stdio.h>

int main(int argc, char *argv[])
  {
    FILE *arquivo;
    char caracter;

    if(argc < 2)
      {
        printf("\nErro: Digite o nome do arquivo !!!\n\n");
        exit(1);
      }

    if((arquivo = fopen(argv[1],"w")) == NULL)
      {
        printf("Erro ao abrir arquivo!!!\n\n");
        exit(1);
      }

    do
      {
        caracter = getchar();
        putc(caracter,arquivo);
      }
    while(caracter != '$');

    fclose(arquivo);

    printf("\nGravado com sucesso em %s\n\n",argv[1]);

    return(0); 
  }

