#include <stdio.h>
#include <math.h>
int main (void) {
    printf ("\n ** Calculo das medias: Aritmetica,Harmonica,Geometrica e Quadratica ** \n\n");
    float a,b,c,d,A,H,G,Q;
    printf ("Informe a nota da prova 1: ");
    scanf ("%f", &a);
    printf ("Informe a nota da prova 2: ");
    scanf ("%f", &b);
    printf ("Informe a nota da prova 3: ");
    scanf ("%f", &c);
    printf ("Informe a nota da prova 4: ");
    scanf ("%f", &d);
    A = (a+b+c+d)/4.0;
    H = 4.0/(1.0/a+1.0/b+1.0/c+1.0/d);
    G = pow (a*b*c*d,1.0/4.0);
    Q = sqrt ((pow(a,2.0)+pow(b,2.0)+pow(c,2.0)+pow(d,3.0))/4.0);
    printf ("\nA media Aritmetica é: %.2f;\nA media Harmonica  é: %.2f;\nA media Geometrica é: %.2f;\nA media Quadratica é: %.2f.\n\n",A,H,G,Q);
    printf ("<<Marco Tulio>>");
    getchar(),getchar();
}
