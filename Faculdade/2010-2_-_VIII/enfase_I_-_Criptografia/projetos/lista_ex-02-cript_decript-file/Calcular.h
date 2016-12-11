//Arquivo: Calcular.h

#ifndef CALCULAR_H_
#define CALCULAR_H_

#include<string>

#include"Persistencia.h"

using namespace std;
class Calcular {

private:
	unsigned int a;
	unsigned int b;
	static const unsigned int n = 256; //n eh preciso criar um objeto para usa-lo
	string nomeArqTexto, nomeArqCript, nomeArqDecript;
public:
	Calcular(unsigned int a, unsigned int b):
		a(a),
		b(b)
		{
			this->nomeArqTexto="texto.txt";
			this->nomeArqCript = "texto.txt.cript";
			this->nomeArqDecript = "texto.txt.decript";			
		}
	string obterNomeArqTexto() {return this->nomeArqTexto; }
	string obterNomeArqCript() {return this->nomeArqCript; }
	string obterNomeArqDecript() {return this->nomeArqDecript; }

	bool criptografar();
	bool decriptografar();

	static int inverso(int valorA); //retorna -1 se não tem inversa
};//fim calcular

#endif /*CALCULAR_H_*/

//calcula a criptografia do arquivo
//função: E(x) = ax + b mod n
bool Calcular::criptografar()
{
	//tem que abrir o arquivo
	Persistencia arqTexto(this->nomeArqTexto, 'r');
	Persistencia arqCript(this->nomeArqCript, 'w');

     while(!arqTexto.fimDoArquivo()){
	char xChar;
	int x, bModN, Ex;
	xChar = arqTexto.obterCaracter();
	x = (int)xChar;
	bModN = (int)b%n;
	Ex=(a*x) + bModN;
	arqCript.gravarCaracter(Ex);
     }//fim do while

	//O arquivo sera fechado quando o destrutor da Persistencia for chamado
	return true;
}//fim criptografar

//Calcula a decriptografia
//função: D(y) = (y-b) . a^-1 mod n
bool Calcular::decriptografar()
{
	Persistencia arqDecript(nomeArqDecript,'w');
	Persistencia arqCript(nomeArqCript,'r');
	while(!arqCript.fimDoArquivo()){
		char yChar;
		int y, invA, invAmodN, Dy;

		yChar = arqCript.obterCaracter();
		y = (int)yChar;
		invA = inverso(a);
		if(invA == -1) return false; //erro de calcular o inverso
		invAmodN = (int)invA%n;
		Dy = (y-b) * invAmodN;
		arqDecript.gravarCaracter(Dy);
	}//fim do while

	//O arquivo sera fechado quando o destrutor da Persistencia for chamado
}//fim decriptografar


//implementar o algoritmo do livro na pagina 54
int Calcular::inverso(int valorA)
{

	int n0=n;
	int b0=valorA;
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
	if (b0 != 1) return -1; // -1 representa o sinal de erro
	else return (t%n); //retorna o inverso de valorA
}//fim inverso
