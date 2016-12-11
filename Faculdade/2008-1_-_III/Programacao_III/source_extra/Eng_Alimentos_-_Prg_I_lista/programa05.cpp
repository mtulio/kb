#includde<iostream>
#include<string>

int main (void)
{
   //DECLARANDO AS VARIAVEIS
   float CC, DR, RT;
   int grau;
	
   // LENDO AS INFORMACOES PARA O CALCULO
   std::cout<<" Digite o conteudo do carbono: ";
   std::cin>>CC;
   std::cout<<" Digite a dureza Rockwell: ";
   std::cin>>DR;
   std::cout<<" Digite a resistencia a tracao: ";
   std::cin>>RT;
	
   // REALIZANDO OS CALCULOS
   if( (CC<7) && (DR>50) && (RT>8000)) grau = 10;	
   else if( (CC<7) && (DR>50)) grau = 9;
   
   if( (CC<7) && (DR<=50) && (RT<=8000)) grau = 8;
   
   if( (CC>7) && (DR<=50) && (RT<=8000)) grau = 7;	
   
   std::cout<<" O grau de classificação do aco eh: "<<grau<<"\n";	
}
