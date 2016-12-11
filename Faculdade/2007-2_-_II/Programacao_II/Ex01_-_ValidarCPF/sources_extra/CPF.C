#include <stdio.h>
#include <string.h>

char dv(char *n)
{
    int i, soma, fat, d, l;
    soma = 0;
    l = strlen(n);
    for ( i = l - 1, fat = 2 ; i >= 0 ; --i, fat++ )
    {
       soma = soma + fat * ( n[i] - '0' );
       printf ("\n%i\nSoma = %.2i\n",fat-1,soma);
    }  
    d = 11 - (soma % 11);
    if (d > 9) d = 0;
    d += '0';
    return (d);
}     
//Retorna 1 se o CPF for valido e 0 senao for
// Parametros String E/S Digitos E
int  validacpf(char *cpf,int digitos)
   {
   unsigned int retorno;
   int tam,resp;

   retorno=dv(cpf)-48;
   tam = strlen(cpf);
   cpf[tam] = dv(cpf);
   cpf[tam + 1] = 0;
   retorno=retorno*10+(dv(cpf)-48);
   if (retorno==digitos)
   resp=1;
   else resp=0;
   return (resp);
   }     
int main ()
{
   char ccpf[50];
   int dcpf;
   
   printf("Digite um numero de cpf: ");
   scanf("%s", &ccpf);
   printf("Digite os digitos verificadores do cpf: ");
   scanf("%i", &dcpf);
   printf ("Codigo retornado pela funcao:%i\n", validacpf(ccpf,dcpf));
   getchar();
   getchar();
   
}
