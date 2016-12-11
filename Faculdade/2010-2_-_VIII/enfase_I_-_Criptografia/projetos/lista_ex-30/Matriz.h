#ifndef MATRIZ_H_
#define MATRIZ_H_

#include<iostream>
#include<string>
#include<math.h>

class Matriz {

private: 
	unsigned int tamLinha;
	unsigned int tamColuna;
	int *vetMatriz;
	unsigned int tamVet;

public:

	Matriz(unsigned int tamLinha, unsigned int tamColuna): tamLinha(tamLinha), tamColuna(tamColuna)
	{
		tamVet = tamLinha*tamColuna;
		vetMatriz = new int[tamVet];
		//preenchendo todos campos da matriz com -100
		//for(int i=0; i<tamVet; i++){ vetMatriz[i] = -100; }

	}
	~Matriz(){
		if(vetMatriz) delete vetMatriz;
	}	

	bool escreverMatriz(unsigned int pos, int elemento);
	int lerMatriz(unsigned int pos);
	int calcularDeterminanteMat33();
	void calcularCofatores(Matriz *matrizOriginal);
	void calcularAdjacente(Matriz *matrizOriginal);
	void calcularTransposta(int inv,Matriz *matrizAdjacente);
	std::string obterCript(std::string mensagem);

	unsigned int obterTamVet(){ return tamVet; }

 
};//fim class Matriz

#endif /*MATRIZ_H_*/


bool Matriz::escreverMatriz(unsigned int pos, int elemento)
{
	if((pos > 0) || (pos < this->tamVet)) { 
		vetMatriz[pos] = elemento;
		//std::cout<<std::endl<<"Elemento "<<vetMatriz[pos]<<" gravado com sucesso";
		return true; 
	}
	else return false;
}//fim escreverMatriz

int Matriz::lerMatriz(unsigned int pos)
{
	if((pos > 0) || (pos < tamVet)) { return vetMatriz[pos]; }
	else return (-100);	vetMatriz[0] = vetMatriz[0]%26;
	if(vetMatriz[0] < 0) vetMatriz[0] = 26 + vetMatriz[0];
}//fim lerMatriz

int Matriz::calcularDeterminanteMat33()
{
	//calculando pelo metodo da "borboleta"
	int part1, part2, part3, part4, part5, part6, total;
	
	part1 = (vetMatriz[0]*vetMatriz[4]*vetMatriz[8]);
	part2 = (vetMatriz[1]*vetMatriz[5]*vetMatriz[6]);
	part3 = (vetMatriz[2]*vetMatriz[7]*vetMatriz[3]);
	part4 = ((vetMatriz[2]*vetMatriz[4]*vetMatriz[6])*(-1));
	part5 = ((vetMatriz[1]*vetMatriz[3]*vetMatriz[8])*(-1));
	part6 = ((vetMatriz[0]*vetMatriz[7]*vetMatriz[5])*(-1));

//	std::cout<<std::endl<<" part1: "<<part1;
//	std::cout<<std::endl<<" part2: "<<part2;
//	std::cout<<std::endl<<" part3: "<<part3;
//	std::cout<<std::endl<<" part4: "<<part4;
//	std::cout<<std::endl<<" part5: "<<part5;
//	std::cout<<std::endl<<" part6: "<<part6;

	total = part1 + part2 + part3 + part4 + part5 + part6;

	total = total%26;
	if(total < 0) total = 26+total;	
	
//	std::cout<<std::endl<<" total: "<<total;

	return total;

//	return ( (vetMatriz[0]*vetMatriz[4]*vetMatriz[8]) + (vetMatriz[1]*vetMatriz[5]*vetMatriz[6]) + 
//		(vetMatriz[2]*vetMatriz[7]*vetMatriz[3]) + ((vetMatriz[2]*vetMatriz[4]*vetMatriz[6])*(-1)) + 
//		((vetMatriz[1]*vetMatriz[3]*vetMatriz[8])*(-1)) + ((vetMatriz[0]*vetMatriz[7]*vetMatriz[5])*(-1)) );

}//fim calcular determinante


void Matriz::calcularCofatores(Matriz *matrizOriginal)
{
	vetMatriz[0] = ( (matrizOriginal->lerMatriz(4) * matrizOriginal->lerMatriz(8)) - (matrizOriginal->lerMatriz(5) * matrizOriginal->lerMatriz(7)) ) * (pow((-1),(1+1))) ;
//	vetMatriz[0] = vetMatriz[0]%26;
//	if(vetMatriz[0] < 0) vetMatriz[0] = 26 + vetMatriz[0];

	vetMatriz[1] = ( (matrizOriginal->lerMatriz(3) * matrizOriginal->lerMatriz(8)) - (matrizOriginal->lerMatriz(5) * matrizOriginal->lerMatriz(6)) ) * (pow((-1),(1+2)));
	//std::cout<<std::endl<<"matrizOriginal->lerMatriz(3): "<<matrizOriginal->lerMatriz(3);
	//std::cout<<std::endl<<"matrizOriginal->lerMatriz(8): "<<matrizOriginal->lerMatriz(8);
//	std::cout<<std::endl<<"matrizOriginal->lerMatriz(5): "<<matrizOriginal->lerMatriz(5);
//	std::cout<<std::endl<<"matrizOriginal->lerMatriz(6): "<<matrizOriginal->lerMatriz(6);
//	std::cout<<std::endl<<"vetMatriz[1]: "<<vetMatriz[1];
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];
//	std::cout<<std::endl<<"vetMatriz[1]%26 - dep if: "<<vetMatriz[1];

	vetMatriz[2] = ( (matrizOriginal->lerMatriz(3) * matrizOriginal->lerMatriz(7)) - (matrizOriginal->lerMatriz(4) * matrizOriginal->lerMatriz(6)) ) * (pow((-1),(1+3)) );
//	vetMatriz[2] = vetMatriz[2]%26;
//	if(vetMatriz[2] < 0) vetMatriz[2] = 26 + vetMatriz[2];

	vetMatriz[3] = ( (matrizOriginal->lerMatriz(1) * matrizOriginal->lerMatriz(8)) - (matrizOriginal->lerMatriz(2) * matrizOriginal->lerMatriz(7)) ) * (pow((-1),(2+1)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	vetMatriz[4] = ( (matrizOriginal->lerMatriz(0) * matrizOriginal->lerMatriz(8)) - (matrizOriginal->lerMatriz(2) * matrizOriginal->lerMatriz(6)) ) * (pow((-1),(2+2)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	vetMatriz[5] = ( (matrizOriginal->lerMatriz(0) * matrizOriginal->lerMatriz(7)) - (matrizOriginal->lerMatriz(1) * matrizOriginal->lerMatriz(6)) ) * (pow((-1),(2+3)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	vetMatriz[6] = ( (matrizOriginal->lerMatriz(1) * matrizOriginal->lerMatriz(5)) - (matrizOriginal->lerMatriz(2) * matrizOriginal->lerMatriz(4)) ) * (pow((-1),(3+1)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	vetMatriz[7] = ( (matrizOriginal->lerMatriz(0) * matrizOriginal->lerMatriz(5)) - (matrizOriginal->lerMatriz(2) * matrizOriginal->lerMatriz(3)) ) * (pow((-1),(3+2)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	vetMatriz[8] = ( (matrizOriginal->lerMatriz(0) * matrizOriginal->lerMatriz(4)) - (matrizOriginal->lerMatriz(1) * matrizOriginal->lerMatriz(3)) ) * (pow((-1),(3+3)) );
//	vetMatriz[1] = vetMatriz[1]%26;
//	if(vetMatriz[1] < 0) vetMatriz[1] = 26 + vetMatriz[1];

	//convertendo em modulo 26
	for(int i=0; i < tamVet; i++)
	{
		vetMatriz[i] = vetMatriz[i]%26;
		if(vetMatriz[i] < 0) vetMatriz[i] = 26 + vetMatriz[i];
	}//fim ofr

}//fim cofaores

void Matriz::calcularAdjacente(Matriz *matrizOriginal)
{//invertendo a mtriz
	vetMatriz[0] = matrizOriginal->lerMatriz(0);
	vetMatriz[1] = matrizOriginal->lerMatriz(3);
	vetMatriz[2] = matrizOriginal->lerMatriz(6);
	vetMatriz[3] = matrizOriginal->lerMatriz(1);
	vetMatriz[4] = matrizOriginal->lerMatriz(4);
	vetMatriz[5] = matrizOriginal->lerMatriz(7);
	vetMatriz[6] = matrizOriginal->lerMatriz(2);
	vetMatriz[7] = matrizOriginal->lerMatriz(5);
	vetMatriz[8] = matrizOriginal->lerMatriz(8);
}//fim matrizAdjacente

void Matriz::calcularTransposta(int inv,Matriz *matrizAdjacente)
{
	for(int i=0; i < tamVet; i++)
	{
		vetMatriz[i] = (matrizAdjacente->lerMatriz(i) * inv)%26;
//		std::cout<<std::endl<<"vetMatriz["<<i<<"]:"<<vetMatriz[i];
	}//fimfor
}//fim calcularTransposta




std::string Matriz::obterCript(std::string mensagem)
{

//	std::cout<<std::endl<<"mensagem[0]: "<<mensagem[0];
//	std::cout<<std::endl<<"mensagem[1]: "<<mensagem[1];
//	std::cout<<std::endl<<"mensagem[2]: "<<mensagem[2];

	int valor0 = mensagem[0], valor1 = mensagem[1], valor2 = mensagem[2];

	valor0-=65;
	valor1-=65;
	valor2-=65;

//	std::cout<<std::endl<<"valor0: "<<valor0;
//	std::cout<<std::endl<<"valor1: "<<valor1;	
//	std::cout<<std::endl<<"valor2: "<<valor2;		

	int letra0 = valor0 * lerMatriz(0) + valor1 * lerMatriz(3) + valor2 * lerMatriz(6);
	int letra1 = valor0 * lerMatriz(1) + valor1 * lerMatriz(4) + valor2 * lerMatriz(7);
	int letra2 = valor0 * lerMatriz(2) + valor1 * lerMatriz(5) + valor2 * lerMatriz(8);

//	std::cout<<std::endl<<"letra0: "<<letra0;
//	std::cout<<std::endl<<"letra1: "<<letra1;	
//	std::cout<<std::endl<<"letra2: "<<letra2;

	letra0 = letra0%26;
	letra1 = letra1%26;
	letra2 = letra2%26;
	
//	std::cout<<std::endl<<"letra0: "<<letra0;
//	std::cout<<std::endl<<"letra1: "<<letra1;	
//	std::cout<<std::endl<<"letra2: "<<letra2;

	char l0 = letra0+65;
	char l1 = letra1+65;
	char l2 = letra2+65;

//	std::cout<<std::endl<<"l0: "<<l0;
//	std::cout<<std::endl<<"l1: "<<l1;	
//	std::cout<<std::endl<<"l2: "<<l2;

	std::string resultante=""; 
	resultante = resultante + l0;
	resultante = resultante + l1;
	resultante = resultante + l2;
//	std::cout<<std::endl<<"mensagem = "<<mensagem;
//	std::cout<<std::endl<<"l1 = "<<l0;
//	std::cout<<std::endl<<"l2 = "<<l1;
//	std::cout<<std::endl<<"l3 = "<<l2;
//	std::cout<<std::endl<<"REsult = "<<resultante;
	return resultante;
}//fim obterCript
