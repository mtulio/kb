
/* lendo e exibindo o conteúdo de um arquivo texto */

#include <stdio.h>
#include <fstream>
#include<string>

int main(int argc, char *argv[])
  {
    char caracter;
    FILE *arquivo, *arquivo2;

    if(argc < 2)
      {
        printf("\nErro: Digite o nome do arquivo !!!\n\n");
        exit(1);
      }

    printf("\n%s\n\n",argv[1]);

    if((arquivo = fopen(argv[1],"r")) == NULL)
      {
        printf("Erro ao abrir arquivo!!!\n\n");
        exit(1);
      };
     
	std::string nomeDoArquivoNoDisco = argv[1];

     std::ifstream arquivoPrincipal;

     arquivoAgenda.open(nomeDoArquivoNoDisco.c_str());

	char caracter;
     
     std::ofstream arqTemp;

     std::string arquivoTemporario="temp.txt";

     arqTemp.open(arquivoTemporario.c_str(),std::ios::trunc);

     while(!arquivoPrincipal.eof()){

	caracter = getc(arquivo);
	putc(caracter,arqTemp);
	
            
     }//fim do while

     arquivoPrincipal.close();
     arqTemp.close();



    printf("\nArquivo %s copiado para arquivo: %s\n\n",argv[1],arq2);

    return(0);
  }

