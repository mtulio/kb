#include <stdio.h>
main () {
     float ia,im,id,idias;
     printf ("\nInforme a idade em anos: ");
     scanf ("%f",&ia);
     printf ("\nInforme a idade em meses: ");
     scanf ("%f",&im);
     printf ("\nInforme a idade em dias: ");
     scanf ("%f",&id);
     idias = ia * 365.25 + im * 12.0 + id;
     printf ("\nA idade informada e: %f dias.\n",idias);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
