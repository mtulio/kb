#include<stdio.h>
#include<string.h>
main ()
{
     int n,temp, tmp2, i;

     printf("Digite numero= \n");     
     scanf("%i", &n);
     temp=n;
     i=0;
        
     while(temp>=10)
     {
                    tmp2=temp/10;                  
                    temp=tmp2;
                    i++;    
     }
     i=i+1;
     
     printf ("\nA qtd de digitos eh %i",i);  
  
  
     
     getchar();
     getchar();
     }
