                        /*Marco Tulio*/

#include <stdio.h>
#include <stdlib.h>
int main (void) {
    printf ("\n\t\t\tExercicio 28 - Lista 02\n\n");
    char repeat[3];
    int bairro, tel, prefixo;
    
    do{
    printf ("\n\t(1)-Oeste\n\t(2)-Centro\n\t(3)-Sul\n\t(4)-Bueno\n\t(5)-Campinas\n\t(0)-Sair\nEscolha o Bairro: ");
    scanf ("%i", &bairro);
    
    if (bairro==0) exit (0);
    if (bairro<1 || bairro>5) printf ("\nBairro Invalido, Tente Novamente!\n");
    }while(bairro<1 || bairro>5);
    
    printf ("Digite o numero completo do telefone: ");
    scanf ("%i", &tel);
    prefixo = ( ((tel/10000000)*1000) + (((tel%10000000)/1000000)*100) + ((((tel%10000000)%1000000)/100000)*10) + (((((tel%10000000)%1000000)%100000)/10000)*1) );
    switch (bairro) {
           case 1: /*oeste*/
                if ((prefixo==3223) || (prefixo==3225) || (prefixo==3212) ){
                   printf ("\n\t\t\tTelefone Correto!!!\n\n");}
                else{ printf ("\tTelefone, ou Bairro, informado incorreto!!!\n\n");}
                break;

           case 2: /*centro*/
                if ((prefixo==3223) || (prefixo==3224) || (prefixo==3212) ){
                   printf ("\n\t\t\tTelefone Correto!!!\n\n");}
                else printf ("\tTelefone, ou Bairro, informado incorreto!!!\n\n");
                break;

           case 3: /*sul*/
                if ((prefixo==3241) || (prefixo==3242) || (prefixo==3243) || (prefixo==3281) ){
                   printf ("\n\t\t\tTelefone Correto!!!\n\n");}
                else printf ("\tTelefone, ou Bairro, informado incorreto!!!\n\n");
                break;

           case 4: /*bueno*/
                if ((prefixo==3251) || (prefixo==3285) ){
                   printf ("\n\t\t\tTelefone Correto!!!\n\n");}
                else printf ("\tTelefone, ou Bairro, informado incorreto!!!\n\n");

           case 5: /*campinas*/
                if ((prefixo==3233) || (prefixo==3291)){
                   printf ("\n\t\t\tTelefone Correto!!!\n\n");}
                else printf ("\tTelefone, ou Bairro, informado incorreto!!!\n\n");
    }
        
    getchar();
    getchar();
}
                  
