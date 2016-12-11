#include "stdio.h"
main () {
     int tempo=0, tempoh, tempom, tempos;
     float massa, mf;
    
     printf ("Digite a massa, em gramas, do material radioativo: ");
     scanf ("%f", &massa);
     mf = massa;
    
     while (mf>=0.5) {
           mf = mf/2.0;
           tempo = tempo + 50;
     }
          
     tempoh = tempo/3600;
     tempom = (tempo%3600)/60;
     tempos = (tempo%3600)%60;
             
     printf ("\nMassa Inicial: %.2f gramas.\nMassa Final: %.2f.",massa, mf);
     printf ("\nO tempo para que a massa inicial fique menor que 0.5 gramas e´ de:\n%i(h) : %i(m) : %i(s)\n",tempoh, tempom, tempos);
     getchar();
     getchar();
}
     
