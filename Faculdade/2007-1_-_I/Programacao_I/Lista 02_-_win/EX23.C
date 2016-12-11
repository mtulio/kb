                        /*Marco Tulio*/

#include<stdio.h>
main () {
     printf ("\n\t\t\tExercicio 23 - Lista 02\n\n");
     int opcao;
     float valor, valorf;
     printf ("Digite o valor do produto: ");
     scanf ("%f", &valor);
     printf ("Condições de pagamento:\n\n\t(1)-À Vista,dinheiro ou cheque;\n\t(2)-À vista,Cartão de Crédito;\n\t(3)-Em 2 Vezes sem juros;\n\t(4)-Em 4 vezes, com juros de 10%;\nDigite a opção desejada: ");
     scanf ("%i", &opcao);
     switch (opcao) {
            case 1: 
                 valorf = valor*0.90;
                 break;
            case 2:
                 valorf = valor*0.95;
                 break;
            case 3:
                 valorf = valor/2.0;
                 break;
            case 4:
                 valorf = (valor*1.10)/3.0;
                 break;
            default:
                    printf ("\n\n\t\tOpção Invalida, Tente Novamente!!!\n\n");
     }
     printf ("\n\nO total a pagar é de R$ %.2f.\n",valorf);
     getchar();
     getchar();
}
