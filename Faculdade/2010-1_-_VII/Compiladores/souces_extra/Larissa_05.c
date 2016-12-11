#include <stdio.h>
#include <stdlib.h>

int digito(char dgt){
        if(dgt >= '0' && dgt<='9')
        {
                 return 1;
              }
              else{
                    return 0;
                    }
    }//fim digito

/*******************************************************************************/
int operador(char opr)
{
        if(opr=='+' || opr=='-' || opr=='*' || opr =='/'){
                       return 1;
                    }
                    else{
                          return 0;
                          }
    }//fim operador
    
/*******************************************************************************/
typedef struct token ttoken;
typedef struct ttoken *ptoken;
struct token
{
   char lexema;
   int tipo;
   ptoken prox;
};

ttoken* insere_lista(ptoken l, char c)
{
   ttoken *novo=(ttoken*) malloc(sizeof(ttoken));
   novo->lexema=c;   
    
   if(operador(c)){
      novo->tipo=2;
      }
   if(digito(c)){
      novo->tipo=1;
      }      
   novo->prox=l;
}

void gravar(ttoken *token, FILE *arq)
{
     ttoken *aux;
     aux=token;

    while(aux->prox!=NULL) 
    { 
      if(digito(aux->lexema))
      { 
        fprintf(arq,"%c\n",aux->lexema);
      }//fim do if
       
        aux=aux->prox;
    }//fim do while
    
    while(token->prox!=NULL) 
    {
    
      if(operador(token->lexema))
      {
      
      fprintf(arq,"%c\n",token->lexema);
      }//fim do if

       token=token->prox;
    }//fim do while
      
}

/*******************************************************************************/
int main()
{
	printf("teste");
   ttoken *token=NULL; //zerando lista
    char linha[255]; //tamanho do vetor
	int i=0,x=-1;
	FILE *arq1, *arq2;
	arq1=fopen("origem.txt", "r");
	arq2=fopen("destino.txt", "wt");
  
	
   fgets(linha, 255, arq1);
   int tam = strlen(linha); //pega o tamanho do vetor
   tam=tam+1;

   for(i;i<tam;i++)
   {
      token=insere_lista(token,linha[x]);
      x++;
   }
   
   gravar(token, arq2);
   
      fclose(arq1);
      fclose(arq2);
}//fim
