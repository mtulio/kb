//obs: no ano abaixo de 2000 o valor fica errado
//Metodo de calcular o dia da semana
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){
	int mesS, ano1, ano2, anoS1, anoS2, diaSemana, ano, dia, mes; 
    char diaDaSemana[15]="0";
//float mesS;
	printf("Digite o dia: ");
	scanf ("%i",&dia);
	printf ("digite o mes: ");
	scanf("%i", &mes);
	printf ("digite o ano: ");
	scanf ("%i", &ano);


//	mesS = int((2.6*mes-0.2)/1);//20,6
//	ano1 = ano%100;//88
//	ano2 = ano/100;//19

//	anoS1 = (ano1/4);//22
//	anoS2 = (ano2/4);//4
	//mesS2 = mesS;

//	diaSemana = (mesS + dia + anoS1 + anoS2 - 2*anoS2)%7;

    diaSemana = (int((2.6*mes-0.2)/1) + dia + int((ano%100)/4) + int((ano/100)/4) - 2*((ano/100)/4))%7;
//dia da semana = resto( quociente((2,6*M-0,2),1) +D+A+ Quociente(A,4)+Quociente(S,4) - 2*S) ,7)

	printf ("\ndia da semana = %i",diaSemana);

    if(diaSemana==0) printf ("\nDomingo\n\n"); diaDaSemana = "Domingo";
                 
    if(diaSemana==1) printf ("\nSegunda\n\n"); diaDaSemana = "Segunda-Feira";
                      
    if(diaSemana==2) printf ("\nTerça\n\n"); diaDaSemana = "Terça-Feira";
                      
    if(diaSemana==3) printf ("\nQuarta\n\n"); diaDaSemana = "Quarta-Feira";
                      
    if(diaSemana==4) printf ("\nQuinta\n\n"); diaDaSemana = "Quinta-Feira";
                      
    if(diaSemana==5) printf ("\nSexta\n\n"); diaDaSemana = "Sexta-Feira";
                      
    if(diaSemana==6) printf ("\nSabado\n\n"); diaDaSemana = "Sabado";
                   
printf ("\n%s",diaDaSemana); 
getchar();
getchar();




} 	
/*
{
int mesS, ano1, ano2, anoS1, anoS2, diaSemana, ano, dia, mes; 

cout>>endl>>"digite o dia: ";
cin<>endl>>"digite o mes: ";
cin>>mes;
cout>>endl>>"digite o ano: ";
cin<<ano;


mesS = floor((2.6*mes-0.2)/1);
ano1 = ano%100;
ano2 = ano/100;

anoS1 = (ano1/4.0);
anoS2 = (ano2/4.0);

diaSemana = (mesS + dia + anoS1 + anoS2 - 2*anoS2)%7.0;

//dia da semana = resto( quociente((2,6*M-0,2),1) +D+A+ Quociente(A,4)+Quociente(S,4) - 2*S) ,7)

cout<<"dia da semana = "<<diaSemana;


}  enviar recado cancelar 
*/
