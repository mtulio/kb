                     /*Marco Tulio*/

#include <stdio.h>
#include <string.h>
main () {
     char nome[20];
     int tipopulv;
     float areamt, areaacre, totalpg, valoracre;
     printf ("\n\t\t\tExercicio 37 - Lista 02\n\n");
     printf ("\t\t\tCompanhia de Pulverização Faz Tudo\n\n");     
     printf ("Digite o Nome do Fazendeiro: ");
     gets (nome);
     printf ("Tipos de Pulverização:\n\t(1)-Contra Ervas Daninhas, R$5,00 por acre\n\t(2)-Contra Gafanhotos, R$10,00 por acre\n\t(3)-Contra Broca, R$15,00 por acre\n\t(4)-Contra Ervas Daninhas,Gafanhotos e Broca, R$25,00 por acre\nInforme o Tipo de Pulverização: ");
     scanf ("%i", &tipopulv);
     printf ("Digite a area à ser pulverizada, em m^2: ");
     scanf ("%f", &areamt);
//1 acre = 4046.80 m²
     areaacre = areamt/4046.80;
     switch (tipopulv) {
            case 1: /*Ervas daninhas = 5,00. Enunciado: >300, desc = 5%. Valor sem desc >1750, desc = 10%.  >300 acre e Valor sem desc > 1750, dec = 5% + 10%[em cima dos 5% descontados]*/
                 valoracre = areaacre*5.0;
                 if ((areaacre <300.0) && (valoracre <1750.0)) { totalpg = valoracre; }
                 if ((areaacre <300.0) && (valoracre >1750.0)) { totalpg = valoracre*0.90; }
                 if ((areaacre >300.0) && (valoracre <1750.0)) { totalpg = valoracre*0.95; }
                 if ((areaacre >300.0) && (valoracre >1750.0)) { totalpg = (valoracre*0.95)*0.90;}
                 break;
             case 2:
                  valoracre = areaacre*10.0;
                  if ((areaacre <300.0) && (valoracre <1750.0)) { totalpg = valoracre; }
                  if ((areaacre <300.0) && (valoracre >1750.0)) { totalpg = valoracre*0.90; }
                  if ((areaacre >300.0) && (valoracre <1750.0)) { totalpg = valoracre*0.95; }
                  if ((areaacre >300.0) && (valoracre >1750.0)) { totalpg = (valoracre*0.95)*0.90;}
                  break;
             case 3:
                  valoracre = areaacre*15.0;
                  if ((areaacre <300.0) && (valoracre <1750.0)) { totalpg = valoracre; }
                  if ((areaacre <300.0) && (valoracre >1750.0)) { totalpg = valoracre*0.90; }
                  if ((areaacre >300.0) && (valoracre <1750.0)) { totalpg = valoracre*0.95; }
                  if ((areaacre >300.0) && (valoracre >1750.0)) { totalpg = (valoracre*0.95)*0.90;}
                  break;
             case 4:
                  valoracre = areaacre*15.0;
                  if ((areaacre <300.0) && (valoracre <1750.0)) { totalpg = valoracre; }
                  if ((areaacre <300.0) && (valoracre >1750.0)) { totalpg = valoracre*0.90; }
                  if ((areaacre >300.0) && (valoracre <1750.0)) { totalpg = valoracre*0.95; }
                  if ((areaacre >300.0) && (valoracre >1750.0)) { totalpg = (valoracre*0.95)*0.90;}
                  break;
            // default:
              //       printf ("\n\t\tOpção Invalida!!!\nTentar novamente?y ou n: ");
                     //scanf ("%s", &voltar);
                       //     if (strcmp(voltar,'y') goto inicio;
                         //   else 
                            
     }
     
     printf ("\nNome Fazendeiro: %s\nTipo de Pulverização: %i\nTotal a Pagar: R$%.2f\n",nome,  tipopulv, totalpg);
          
      fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
     
}             
