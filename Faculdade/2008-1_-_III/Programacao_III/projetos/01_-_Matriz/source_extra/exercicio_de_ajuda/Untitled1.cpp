

#include<stdio.h>

 

int main () 

{

int vet1[5]={1,2,3,4,5}; /*declaração e inicialização do vetor vet1*/

int vet2[5]={6,1,2,2,5}; /*declaração e inicialização do vetor vet2*/

int vetSoma[5]; /*declaração do vetor vetSoma que vai guardar o resutado da soma dos dois vetores(vet1 e vet2).*/

int x;

 

printf("Este programa soma os dois vetores abaixo:\n");

printf("vet1={1,2,3,4,5}\n");

printf("vet2={6,1,2,2,5}\n");

printf("\n");

printf("vetor resultante da soma:\n");

 

for(x=0; x<5; x++)

{

  vetSoma[x]=vet1[x]+vet2[x]; /*soma os valores*/

  printf("vetSoma[%d]:%d\n",x,vetSoma[x]); /*exibe na tela*/

} /*fim do for*/

getchar();getchar();getchar();getchar();

 

} /*fim do programa*/
