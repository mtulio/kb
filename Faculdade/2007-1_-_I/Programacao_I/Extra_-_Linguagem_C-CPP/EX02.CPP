#include <stdio.h>
#include <math.h>
int main (void){
    float n, qp;
    printf ("\n\nDigite um numero:");
    scanf ("%f",  &n);
    qp = sqrt(n);
    if (qp = trunc(qp)){
           printf ("O numero %f nao e um Quadrado Perfeito.\n\n",n);
    }
    else {
       printf ("\nO quadrado perfeito de %.2f e %.2f.\n\n",n,qp);
    }
}
