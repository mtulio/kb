#include<stdio.h>
main ()
    {
    int diasm2, pn, tp;
    
    
    printf ("\n\t(1)-Domingo;\n\t(2)-Segunda;\n\t(3)-Terça;\n\t(4)-Quarta;\n\t(5)-Quinta;\n\t(6)-Sexta;\n\t(7)-Sabado.\nDigite o dia da locação: ");
    scanf ("%i", &diasm2);
    
    diasm2 = 1;
    diasm2 = 2;
    diasm2 = 3;
    diasm2 = 4;
    diasm2 = 5;
    diasm2 = 6;
    diasm2 = 7;
        
    while (diasm2) {
          diasm2 = process1();
          if (diasm2)
          tp = pn;                       
    return diasm2;
    }
}
