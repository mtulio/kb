# include <stdio.h>
main () {
     int Vl,Q1,Q2,Q3,Q4,R1,R2,R3,R4;
     printf ("\n\n** Calculo de notas possiveis em X Reais **\n");
     printf ("\nInforme um valor em Reais:");
     scanf ("%i",&Vl);
     Q1 = Vl / 100;
     R1 = Vl % 100;
     Q2 = R1 / 50;
     R2 = R1 % 50;
     Q3 = R2 / 10;
     R3 = R2 % 10;
     Q4 = R3 / 5;
     R4 = R3 % 5;
     printf ("\nEm %i,00 sao possiveis:\n\n%i nota(s) de cem;\n%i nota(s) de cinquenta;\n%i nota(s) de dez;\n%i nota(s) de cinco;\n%i nota(s) de um real.\n",Vl,Q1,Q2,Q3,Q4,R4);
     printf ("\n\n<< Marco Tulio >>\n");
     getchar(),getchar();
}     
