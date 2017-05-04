#include <stdio.h>
main () {
     int id,r1,anos,meses,dias;
     printf ("\nInforme a idade em dias: ");
     scanf ("%i",&id);
     anos = id / 365;
     r1 = id % 365;
     meses = r1 / 30;
     dias = r1 % 30;
     printf ("\nA idade e:\n%i anos, %i meses, %i dias.\n",anos,meses,dias);
     printf ("\n\n<< Marco Tulio >>\n");
     getchar(),getchar();
}
