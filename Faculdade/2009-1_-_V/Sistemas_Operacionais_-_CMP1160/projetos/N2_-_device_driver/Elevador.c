/*
UCG - SISTEMAS OPERACIONAIS
GRUPO: MARCO TULIO, HELIO JUNIO, LUAN IORIS, ANDRE LUIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ACIONA 1
#define DESLIGA 0

#define VOLTAS_POR_ANDAR 75
#define SULB_DEV "/dev/chardev"

FILE *sulb_dev;

int main(void)
{
    
   system("clear");
   FILE* ELEVADOR;
   
   ELEVADOR = fopen("/dev/elevador", "w");
   
  int andarAtual;

  printf("Informe o Andar Atual: ");
  scanf("%d",&andarAtual);

 if(andarAtual!=0) inicia(andarAtual, ELEVADOR);
   andarAtual=0;
//   int estadoSubir=0;//verfica se pode subir ou n
//   int estadoDesce=0; //verifica se pode descer ou n
//   int estadoAtual=0;

   int andar;

   do{
        andar = menu();
       if(andar==3) {printf("saindo do programa\n"); exit(0);}
       if(andar==1){
               if(andarAtual==0) { sobe(VOLTAS_POR_ANDAR*andar); andarAtual=1; }
               if(andarAtual==1) printf(" O Elevador jah está no 1o andar!\n");
               if(andarAtual==2) { desce(VOLTAS_POR_ANDAR*1); andarAtual=1; }
       }//fim if 1 andar
       if(andar==2){
               if(andarAtual==0) { sobe(VOLTAS_POR_ANDAR*andar); andarAtual=2; }
               if(andarAtual==1) { sobe(VOLTAS_POR_ANDAR*(andar-andarAtual)); andarAtual=2; }
               if(andarAtual==2) printf(" O Elevador jah está no 2o andar!\n");
       }//fim if 1 andar
       if(andar==0){
               if(andarAtual==0) printf(" O Elevador jah está no 0o andar!\n");
               if(andarAtual==1) { desce(VOLTAS_POR_ANDAR*andarAtual); andarAtual=0;} 
               if(andarAtual==2) { desce(VOLTAS_POR_ANDAR*andarAtual); andarAtual=0; }
       }//fim if 1 andar
   }while(andar>=0 && andar<=3);


}//fim main

int menu()
{
    int andar;
    do{
       printf("0o - 0o andar;\n");
       printf("1o - 1o andar;\n");
       printf("2o - 2o andar;\n");
       printf("3 - para sair;\n");
       printf("Digite a opção: ");

       scanf("%d",&andar);
       if(andar<0 || andar>3) printf("\t\nOpção invalida... tenta novamente!");
    }while(andar<0 && andar>3);
    return andar;    
}//fim menu

void desce(voltas, FILE *ELEVADOR)
{
    int i = 0;
     
    while (i < voltas)
	{//ajustando o elevador
		fwrite(1, 1, 1, ELEVADOR);
		sleep(1);
		fwrite(2, 1, 1, ELEVADOR);
		sleep(1);
        fwrite(4, 1, 1, ELEVADOR);
		sleep(1);
		fwrite(8, 1, 1, ELEVADOR);
		sleep(1);
        i++;
        //uma volta
	}//roda ate em baixo
	return;
}//fim desce

void sobe(int voltas, FILE *ELEVADOR)
{
    int i = 0;
     
    while (i < voltas)
	{//ajustando o elevador
		fwrite(8, 1, 1, ELEVADOR);
		sleep(1);
		fwrite(4, 1, 1, ELEVADOR);
		sleep(1);
        fwrite(2, 1, 1, ELEVADOR);
		sleep(1);
		fwrite(1, 1, 1, ELEVADOR);
		sleep(1);
        i++;
        //uma volta
	}//roda ate em baixo
	return;
}//fim sobe

//inicia vai pra o terreo
void inicia(int andarAtual)
{
     
     printf("Ajustanto elevador...\n");
     //		printf(" \n\t ANDAR ATUAL DENTRO DO INICIAL: %d\n\n",andarAtual);
      if(andarAtual=0) return;
      if(andarAtual=1){ desce(75); return;}
      if(andarAtual=2) { desce(150); return;}
      
      return;
}//fim inicia
