                        /*Marco Tulio*/

#include <stdio.h>
#include <math.h>
int main (void) {
    printf ("\n\t\t\tExercicio 26 - Lista 02\n\n");
    int opcao;
    float a, b, c, media, media1;
    printf ("\n\t(1)-Aritmetica;\n\t(2)-Ponderada(3,3,4);\n\t(3)-Harmonica;\n\t(4)-Geometrica\n\t(5)-Quadratica;\nEscolha a media: ");
    scanf ("%i", &opcao);
    printf ("Informe a nota 1: ");
    scanf ("%f", &a);
    printf ("Informe a nota 2: ");
    scanf ("%f", &b);
    printf ("Informe a nota 3: ");
    scanf ("%f", &c);
    switch (opcao) {
           
           //Aritmetica
           case 1: 
                media = (a+b+c)/3.0;
                printf ("\nA Media Aritmetica das Notas %.2f, %.2f, %.2f é %.2f.\n\n",a, b, c, media );
                break;
           
           //Ponderada
           case 2:
                media = (a*3.0 + b*3.0 + c*4.0)/(3.0 + 3.0 + 4.0);
                printf ("\nA Media Ponderada das Notas %.2f, %.2f, %.2f é %.2f.\n\n",a, b, c, media );
                break;
           
           //Harmonica
           case 3:
                media = 3.0/((1.0/a)+(1.0/b)+(1.0/c));
                printf ("\nA Media Harmonica das Notas %.2f, %.2f, %.2f é %.2f.\n\n",a, b, c, media );
                break;
           
           //Geometrica: pow(a1*a2*a3...an, 1.0/n)
           case 4:
                media = pow (a*b*c,1.0/3.0);
                printf ("\nA Media Geometrica das Notas %.2f, %.2f, %.2f é %.2f.\n\n",a, b, c, media );
                break;
           //Quadratica
           case 5:
                media = sqrt ((pow(a,2.0)+pow(b,2.0)+pow(c,2.0))/3.0);
                printf ("\nA Media Quadratica das Notas %.2f, %.2f, %.2f é %.2f.\n\n",a, b, c, media );
                break;
    }
    
    getchar();
    getchar();
}
