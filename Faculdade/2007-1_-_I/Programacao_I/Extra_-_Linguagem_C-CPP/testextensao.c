#include<stdio.h>
#include<math.h>

int main (void){
 int opcao, i=0;
 float  raio, altura, vol, area, raiz;

 do{
    printf ("Escolha a figura Geometrica p/o calculo do Volume e a Àrea:\n\t(1)-Cone Reto;\n\t(2)-Cilindro;\n\t(3)-Esfera;\n\n\t(4)-Sair\nDigite a opção: ");
    scanf ("%i", &opcao);
    
     i++;
     }while ( (opcao != 1)&&(opcao != 2)&&(opcao != 3)&&(opcao != 4) );
    
    switch (opcao) {
           case 1:
             printf ("\n\t\tCONE RETO\n");
             
             printf ("Digite o Raio: ");
             scanf ("%f", &raio);
             printf ("Digite a Altura: ");
             scanf ("%f", &altura);
             
             vol = (3.1415*(pow(raio,2.0))*altura)/3.0;
             raiz = sqrt(pow(raio,2.0))+(pow(altura,2.0));
             area = 3.1415*raio*raiz;
             
             printf ("\n\n\tO Volume é %.2f.\n\tA Àrea é %.2f.\n\n",vol, area);
             break;
           case 2:
             printf ("\n\t\tCILINDRO\n");

             printf ("Digite o Raio: ");
             scanf ("%f", &raio);
             printf ("Digite a Altura: ");
             scanf ("%f", &altura);

              vol = 3.1415*(pow(raio,2.0))*altura;
              area = 2.0*3.1415*raio*altura;
              
              printf ("\n\n\tO Volume é %.2f.\n\tA Àrea é %.2f.\n\n",vol, area);
              break;
           case 3:
              printf ("\n\t\tESFERA\n");
              
              printf ("Digite o Raio: ");
              scanf ("%f", &raio);
              printf ("Digite a Altura: ");
              scanf ("%f", &altura);
              
              vol = (4.0/3.0)*3.1415*(pow(raio,3));
              area = 4.0*3.1415*(pow(raio,2));
              
              printf ("\n\n\tO Volume é %.2f.\n\tA Àrea é %.2f.\n\n",vol, area);
              break;
              case 4:
                   return;
              
              
    }
       
     
    
   
   getchar();
   getchar();
   system("ex21.exe");
}
