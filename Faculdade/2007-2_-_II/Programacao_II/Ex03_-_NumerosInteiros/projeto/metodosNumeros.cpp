#include"classeNumeros.h"
#include<cmath>
#include<iostream>
#include<string>
unsigned long long numeros::fatorial()const
{//inicio do metodo fatorial

  int i,n;
  n=numero; 
  for (i=n; i>1; i--)
  {
    n = n*(i-1);
    }
    //std::cout<<std::endl<<"n.MT="<<n;

return(n);
}///fim do metodo fatorial

bool numeros::numeroPerfeito()const
{//inicio do metodo numeroperf
      /*Um numero eh perfeito qdo a soma de todos os seus divisores(excluindo ele mesmo) 
      * eh igual ao proprio numero
      */      
      unsigned int  t,sdiv;
      t=numero-1;//Condição p/ qdo o laço for executado n haver divisão por 0
      sdiv=0;//soma dos divisores do numero
      while(t>0){
          if((numero%t)==0){//encontrando os divisores e fazendo a somatoria
                  sdiv = t+ sdiv; 
            }
            t--;
      }
      if (numero==sdiv) return(true);//se 
      else return(false);
}//fim do metodonumeroperf

bool numeros::capicua()const
{//Inicio
    int i, j,temp, tmp2, den=0, pot, n;
	float den2;
    int vet[100];//valor maximo do vetor (ninguem vai dugitar um num > 100, soh se for doido...rsrs)
    //i:indice que vai calcular qtd de digitos
    i=0;
    //temp eh a variavel q vai calcular a qtd de digitos
    n=numero;
    temp=n;
    while(temp>=10){//descobrindo a qtd de digitos
                    tmp2=temp/10;
                    temp=tmp2;
                    i++;
    }
    i++;//essa condição eh pq para contar o ultimo digito de unidades
     //concatenando o valor n em um vetor
     j=i;
     pot=i-1;
     while(j>0){
                den2=(pow(10,pot));
                den=den2;
                vet[i-j]=n/den;
                n=n%den;
                pot--;
                j--;
     }
     //comparando as diagonais do vetor (capicua)
     j=i-1;
     for(i=0; i!=j ; i++,j--) {
              if(vet[i]!= vet[j]) return (false);
     }//fechando laço for
     return (true);
}//fim do metodo capicua

bool numeros::quadradoPerfeito()const
{//Inicio
        int raiz, comparacao;
        raiz = sqrt(numero);
        comparacao=raiz*raiz;
        if (comparacao==numero) return(true);//Verificando o numero informado e o resultado do calculo
        return (false);        
}//fim do metodo quad perfeito

bool numeros::numeroPrimo()const
{//Inicio
//Obs n sabemos a função da variavel i, mas precisa dela
     unsigned int t, contDiv;
     t=numero;//concatenando valores na var temporaria
     contDiv=0;//Contador do numero de divisores
     while(t>0){
          if((numero%t)==0){//encontrando o numero de divisores
                  contDiv++; 
          }
          t--;
      }
     if (numero%1==0 && numero%numero==0 && contDiv==2) return (true);
     else return (false);      
}//fim do metodo num primo

const std::string numeros::mudarBase(unsigned int base)const
{//inicio
	std::string b="0123456789ABCDEF";
	std::string nb="";
	int i;
	unsigned long n=numero;
	while(n)
		{
			i=n%base;
			nb=b[i]+nb;
			n=n/base;
		}
	return (nb);
}//fim do metodo mudança de base

unsigned long numeros::mdc(unsigned int b)const
{//inicio do metodo max divisor
int resto, mdc,n;
n=numero;
    while (n%b != 0) 
    {
     resto = n%b;
     n = b;
     b = resto;
    }
    mdc=b;//Poderia retornar b
    return (mdc);
}//fim do metodo do max divisor

unsigned long numeros::mmc(unsigned int b)const
{//inicio
         unsigned int temp,result;
         temp = numero*b;
         result = temp/mdc(b);
         return (result);
}///fim do metodo mmc

bool numeros::primosEntreSi(unsigned int b)const
{//inicio
//definição: Dois insteiros são primos entre si se somente se o mdc entre os dois for igual a 1
         if (mdc(b)==1) return(true);
         else return(false);
//são primos entre si se e somente se seu máximo divisor comum, ou MDC é igual a 1.
}//fim do metodo primos entre si

