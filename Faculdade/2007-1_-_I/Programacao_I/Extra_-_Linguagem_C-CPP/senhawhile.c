/*Marco Tulio*/
#include <string.h>
#include <stdio.h>

main ()
{
    
    char str[20];
    
    int x, diasm, tl;
    for(x=0; x<5 && strcmp(str, "tulio"); ++x) {
             printf ("\nDigite a Senha: ");
             gets (str);
                          
    }
    if (x==5) { printf ("\n\t\tSenha Incorreta!!!\n"); return; }
    else {
    
    
    float pn, tp;
    printf ("\nDigite o preço normal da fita: ");
    scanf ("%f", &pn);
    
    do{
    printf ("\n\t(1)-Domingo;\n\t(2)-Segunda;\n\t(3)-Terça;\n\t(4)-Quarta;\n\t(5)-Quinta;\n\t(6)-Sexta;\n\t(7)-Sabado.\nDigite o dia da locação: ");
    scanf ("%i", &diasm);
    }while((diasm != 1) && (diasm != 2)&&(diasm != 3)&&(diasm != 4)&&(diasm != 5)&&(diasm != 6)&&(diasm != 7) );
    
    do{
    printf ("\nTipos de Locação:\n\t(1)-Normal;\n\t(2)-Lançamento.\nDigite o tipo de locação: ");
    scanf ("%d", &tl);
    }while ( (tl !=1) && (tl !=2) );
    
    switch (diasm) {
           case 2:
           case 3:
           case 5:
                switch (tl){
                       case 1:
                            tp = 0.60*pn;
                            break;
                       case 2:
                            tp = (1.15*pn)*0.60;
                            break;
                }
           break;
           case 1:
           case 4:
           case 6:
           case 7:
                switch (tl){
                       case 1:
                            tp = pn;
                            break;
                       case 2:
                            tp = 1.15*pn;
                            break;
                }
           break;
           default :
                   printf ("\n\t\tOpção Invalida, TENTE NOVAMENTE!!!\n\n");
    }
    printf ("\n\n\t\tO total a pagar é de R$ %.2f .\n\t",tp);
    getchar();
    getchar();
    }
}
