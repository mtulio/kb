#include <stdio.h>
int main (void) {
    int C,C1,C2,C3,Cinverso,Soma,Mult1,Mult2,Mult3,SomaMult,CodVer;
    printf ("\n ** Calculo do digito verificador de uma Conta Corrente **\n\n");
    printf ("Informe o numero da conta corrente, c/3 digitos sendo o 1 numero diferente de 0: ");
    scanf ("%i", &C);
    C1 = C/100;
    C2 = (C%100)/10;
    C3 = ((C%100)%10)/1;
    Cinverso = C3*100+C2*10+C1;
    Soma = C+Cinverso;
    Mult1 = (Soma/100)*1;
    Mult2 = ((Soma%100)/10)*2;
    Mult3 = (((Soma%100)%10)/1)*3;
    SomaMult = Mult1+Mult2+Mult3;
    CodVer = (SomaMult%10);
    printf ("\nO digito verificador é: %i.\n\n",CodVer);
    printf ("<<Marco Tulio>>");
    getchar(),getchar();
}
