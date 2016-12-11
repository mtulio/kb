#include <stdio.h>
main () {
     int i=1, sexo, nhomens=0, nmulher=0;
     float altura, menoralt=100.0, maioralt=-100.0, smulheralt=0, mediaAmulher;
     while (i<=50) {
           printf ("\t(1)-Masculino;\n\t(2)-Feminino;\nInforme o sexo do %io individuo: ",i);
           scanf ("%i", &sexo);
           printf ("Digite a altura: ");
           scanf ("%f", &altura);
           //Caso 1
           if (altura < menoralt) menoralt = altura;
           if (altura > maioralt) maioralt = altura;
           //Caso 2
           if (sexo==2) { 
              smulheralt = altura + smulheralt;
              nmulher +=1;
           }
           //Caso 3
           if (sexo==1) nhomens +=1;
           i++;
     }
     printf ("\nA maior altura do grupo eh %.2f metros",maioralt);
     printf ("\nA menor altura do grupo eh %.2f metros",menoralt);
     mediaAmulher = smulheralt / nmulher;
     printf ("\nA media da altura de %i mulher(es) eh %.2f",nmulher, mediaAmulher);
     printf ("\nO numero de homens eh de %i\n",nhomens);
     getchar();
     getchar();
}
     
