#ifndef OPERACOES_H_
#define OPERACOES_H_

#include<string>

class Operacoes
{

public:
	static int mdc(int num1, int num2);
	static int inverso(int n, int valorA);
	
	static std::string obterCript(std::string mensagem,Matriz *matrizOriginal);

};//fim opecacoes

#endif /*OPERACOES_H_*/

int Operacoes::mdc(int num1, int num2)
{
	int resto, mdc;
	while (num1%num2 != 0) 
    	{
     		resto = num1%num2;
     		num1 = num2;
     		num2 = resto;
    	}
    	mdc=num2;//Poderia retornar b
    	return (mdc);
}//fim mdc

int Operacoes::inverso(int n, int valorA)
{
	
	int n0=n; //valor do modulo
	int b0=valorA; //valorA é o valor do nnumero q calcula a inversa
	int t0=0;
	int t=1;
	int q=n0/b0; // q = |n0/q0|
	int r = n0 - q * b0;
	while (r > 0){
		int temp = t0 - q * t;
		if (temp >= 0 ) temp = temp%n;
		else if(temp < 0) temp = n- ((-1*temp)%n);
		t0 = t;
		t = temp;
		n0 = b0;
		b0 = r;
		q = n0/b0;
		r = n0 - q * b0;
	}//fim while
	if (b0 != 1) return -100; // -1 representa o sinal de erro q n existe inversa
	else return (t%n); //retorna o inverso de valorA
}//fim inverso


