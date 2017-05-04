/*
 * util.h
 *
 *  Created on: 11/04/2009
 *      Author: marcotulio


#ifndef UTIL_H_
#define UTIL_H_


#endif /* UTIL_H_ */


#include <stdio.h>

// setecho(..);
#define OFF 0
#define ON 1

// settype(..);
#define RESET 0

#define BOLD 1
#define NEGRITO 1

#define BLINK 5
#define PISCAR 5

// setcolor(.. , ..);
#define BLACK 0
#define PRETO 0

#define RED 1
#define VERMELHO 1

#define GREEN 2
#define VERDE 2

#define BROWN 3
#define MARROM 3

#define BLUE 4
#define AZUL 4

#define MAGENTA 5
#define ROSA 5

#define CYAN 6
#define CIANO 6

#define WHITE 7
#define BRANCO 7

#define DEFAULT 9
#define PADRAO 9

int setcolor(int cor,int bk);
int settype(int tipo);
int setxy(int x, int y);
int setecho(int echo);
int chartoint(char inteiro);
int clearscn();

int setecho(int echo)
{
   if (echo == 1) system("stty echo");
   else if (echo == 0) system("stty -echo");
   else return 0;
   return 1;
}

int chartoint(char inteiro)
{
   int temp;
   temp = inteiro - '0';
   return temp;
}

int setcolor(int cor, int bk)
{
   cor = cor + 30;
   bk = bk + 40;
   printf("{FONTE}33[%d;%dm",cor,bk);
   return 1;
}

int settype(int tipo)
{
   printf("{FONTE}33[%dm",tipo);
   return 1;
}

int setxy(int x, int y)
{
   printf("{FONTE}33[%d;%dH",y,x);
   return 1;
}

int clearscn()
{
   printf("{FONTE}33[2J");
   return 1;
}
