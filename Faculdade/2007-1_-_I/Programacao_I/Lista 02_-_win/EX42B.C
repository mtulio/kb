#include <stdio.h>
#include<stdlib.h> /*Biblioteca para o uso do exit(0);*/

int main (void) {
    int data,dia,mes,ano,ano1,ano2,ano3,ano4,resto;
   printf ("\n\t\t\tExercicio 42-B - Lista 02\n\n");    
   printf ("Digite a Data no formato, ddmmaaaa: ");
   scanf ("%d", &data);

   //Ex.: 07021985 - 10000000
   dia = (data/10000000)*10 + (data%10000000)/1000000;
   mes = (((data%10000000)%1000000)/100000)*10 + (((data%10000000)%1000000)%100000)/10000;
   ano1 = ((((data%10000000)%1000000)%100000)%10000)/1000;
   resto = ((((data%10000000)%1000000)%100000)%10000)%1000;
   ano2 = resto/100;
   resto = resto%100;
   ano3 = resto/10;
   ano4 = resto%10;
   ano = ano1*1000+ano2*100+ano3*10+ano4;
   
   if(dia<=0|dia >=31){
      printf("\nDia invalido - finalizando o programa!");
      getchar();
      getchar();
      exit(0);
      }
   if(mes<=0|mes>12){
       printf("\nMes invalido - finalizando o programa!");
       getchar();
       getchar();
       exit(0);
       }
   if(ano<=0){
      printf("\nAno invalido - finalizando o programa!");
      getchar();
      getchar();
      exit(0);
      }
      
  
   
  switch(mes){
    case 1: printf("\n%i de Janeiro de %i",dia,ano);
            break;
    case 2: printf("\n%i de Fevereiro de %i",dia,ano);
            break;
    case 3: printf("\n%i de Março de %i",dia,ano);
            break;
    case 4: printf("\n%i de Abril de %i",dia,ano);
            break;
    case 5: printf("\n%i de Maio de %i",dia,ano);
            break;
    case 6: printf("\n%i de Junho de %i",dia,ano);
            break;
    case 7: printf("\n%i de Julho de %i",dia,ano);
            break;
    case 8: printf("\n%i de Agosto de %i",dia,ano);
            break;
    case 9: printf("\n%i de Setembro de %i",dia,ano);
            break;
    case 10: printf("\n%i de Outubro de %i",dia,ano);
            break;
    case 11: printf("\n%i de Novembro de %i",dia,ano);
            break;
    case 12: printf("\n%i de Dezembro de %i",dia,ano);
            break;
   

}       
getchar();
getchar();
}   
