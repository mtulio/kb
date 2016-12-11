#include<stdio.h>


main ()
{
int a, i; 
printf("Digite um numero= \n");
scanf("%i", &a);
//fatn=fat;
for (i=a; i>1; i--)
{
    a = a*(i-1);
}
printf ("VAlor de fat=%i",a);


getchar();
getchar();
}
