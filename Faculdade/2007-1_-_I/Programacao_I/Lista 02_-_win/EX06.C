                /*Marco Tulio*/

#include<stdio.h>
#include<math.h>
main(){
    printf ("\n\t\t\tExercicio 06 - Lista 02\n\n");
    float a,b,c,x1,x2,delta, raizimaginaria;

/*Leitura das variavies*/
    printf("Digite o valor de a: ");
    scanf("%f",&a);
    printf("Digite o valor de b: ");
    scanf("%f",&b);
    printf("Digite o valor de c: ");
    scanf("%f",&c);

/*Calculo das variaveis e exibicao dos resultados*/
    delta = (b*b)-(4*a*c);

//printf("Equacao: %.0fx^2+%.0fx+%.0f = 0",a,b,c);
    printf("\nDelta = %.0f",delta);

	if(delta<0){  //caso 1
  	printf("\n\n\tRaizes imaginarias!");
  	x1 = (-1.0*b)/2.0*a;
  	raizimaginaria = sqrt(-1.0*delta)/(2.0*a);
  	printf ("\nX1: %.2f+%.2fi",x1, raizimaginaria);
  	printf ("\nX2: %.2f-%.2fi",x1, raizimaginaria);
  	}
	else if(delta == 0){  //caso 2
       		printf("\nRaiz unica!");
        	x1=-1.0*b/2.0*a;
        	printf("\nX1 = X2 = %.2f",x1);
        	}else if (delta>1.0) {
             		printf("\n\n\tDuas raizes distintas!"); //caso 3


             		x1 = (-1.0*b/2.0*a) + sqrt(delta)/2.0*a;
             		x2 = (-1.0*b/2.0*a) - sqrt(delta)/2.0*a;
             		printf("\nX1: %.2f",x1);
             		printf("\nX2: %.2f",x2);



               	}
    fflush(stdin); //limpa buffet do teclado - Windows
    //__fpurge(stdin); //limpa buffet do teclado - Linux
    getchar();
}
