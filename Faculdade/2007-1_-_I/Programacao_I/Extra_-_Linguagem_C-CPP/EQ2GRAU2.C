#include<stdio.h>
#include<math.h>
main(){
float a,b,c,x1,x2,termo1,termo2,delta;

/*Leitura das variavies*/
printf("Digite o valor de a: ");
scanf("%f",&a);
printf("Digite o valor de b: ");
scanf("%f",&b);
printf("Digite o valor de c: ");
scanf("%f",&c);

/*Calculo das variaveis e exibicao dos resultados*/
delta = (b*b)-(4*a*c);
printf("Equacao: %.0fx^2+%.0fx+%.0f = 0",a,b,c);
printf("\nDelta = %.0f",delta);
	if(delta<0){  //caso 1
  	printf("\nRaizes imaginarias!");
  	x1 = (-1*b)/2*a;
  	printf("\nX1: %.2f+%.2fi",x1,sqrt(-1*delta)/(2*a));
  	printf("\nX2: %.2f-%.2fi",x1,sqrt(-1*delta)/(2*a));
  	}
	else if(delta ==0){  //caso 2
       		printf("\nRaiz unica!");
        	x1=-1*b/2*a;
        	printf("\nX1 = X2 = %.2f",x1);
        	}else {
             		printf("\nDuas raizes distintas!"); //caso 3
             		termo1 = (-1*b/2*a);
             		termo2 = sqrt(delta)/2*a;
             		x1 = termo1 + termo2;
             		x2 = termo1 - termo2;
             		printf("\nX1: %.2f",x1);
             		printf("\nX2: %.2f",x2);
             		printf("\ntermo1 %.2f",termo1);
             		printf("\ntermo2 %.2f",termo2);
//printf("\nsqrt %.2f",sqrt(delta)/2);
               	}
getchar();
getchar();
}
