/*
 * Exemplo.c
 *
 *  Created on: 11/04/2009
 *      Author: marcotulio
 */

#include "util.h"

int main()
{
   int numero;
   clearscn();
   setxy(5,5);
   setcolor(BRANCO,PRETO);
   printf("Ola mundo!");
   setxy(1,1);
   setcolor(PRETO,BRANCO);
   settype(NEGRITO);
   printf("Ola mundo!!");
   setcolor(MARROM,ROSA);
   setxy(15,3);
   settype(PISCAR);
   printf("OLA MUNDO!");
   settype(RESET);
   setxy(3,3);
   printf("ola mundo..");
   setxy(1,12);
   printf("digite um numero (sem echo): ");
   setecho(OFF);
   scanf("%d",&numero);
   setxy(6,13);
   printf("voce digitou %d ! :D",numero);
   setxy(1,14);
   setcolor(ROSA,PADRAO);
   printf("digite um numero (com echo): ");
   setcolor(ROSA,PRETO);
   setecho(ON);
   scanf("%d",&numero);
   setxy(6,15);
   settype(RESET);
   printf("voce digitou: %d ! ",numero);
   setcolor(AZUL,PADRAO);
   printf(":");
   setcolor(VERMELHO,PADRAO);
   printf("D");
   setxy(1,17);
   numero = chartoint('8');
   printf(" -> %d",numero);
   setxy(1,19);
   settype(RESET);
   return 0;
}
