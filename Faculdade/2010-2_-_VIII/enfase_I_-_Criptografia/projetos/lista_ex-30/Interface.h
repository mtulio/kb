#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include"Matriz.h"
#include"Operacoes.h"

using namespace std;
class Interface
{

public:
	static void menuCifraHill();
	static void menuCrifraAfim();
	static void menuPrincipal();

};//fim class Interface

#endif /*INTERFACE_H_*/

void Interface::menuPrincipal()
{
	int opcao=0;

	do {
		cout<<endl<<"(1) - Cifra de Hill";
		cout<<endl<<"(2) - Cifra Afim";
		cout<<endl<<"(0) - Sair";
		cout<<endl<<"Digite a opcao: ";
		cin>>opcao;
		
		switch(opcao){
			case 1:{
				menuCifraHill();
				break;
			}//fim case 1
			case 2:{
				menuCrifraAfim();
				break;
			}//fim case 2
			case 0:{
				return;	
				break;
			}
			default: { cout<<endl<<"Opcao incorreta"<<endl; break; }
		}//fim switch
	}while(opcao!=0);
}//fim menu principal

void Interface::menuCifraHill()
{
/*
 * Ler a mensagem
 * Ler a matrix 3x3
 * 

*/
	int tamLinhas=3, tamColunas=3, elemento;
	Matriz matrizOriginal(tamLinhas,tamColunas);
	int linhaTmp=0,colunaTmp=0;	
	for (int tamVetor = tamLinhas * tamColunas, i=0; i< tamVetor; i++) 
	{

		//if(!(linhaTmp < tamLinhas)) linhaTmp++;
//		else colunaTmp++;
		cout<<"Digite o elemento na pos["<<i<<"]: ";
		cin>>elemento;
//		cout<<endl<<"i = "<<i;
//		cout<<endl<<"elemento = "<<elemento;
		if(!matrizOriginal.escreverMatriz(i,elemento)) cout<<endl<<"Erro ao add elemento na matriz!"<<endl;
	}//fim for


	cout<<endl<<endl<<"Lendo o vetor: "<<endl;
	for (int tamVetor = tamLinhas * tamColunas, i=0; i< tamVetor; i++) 
	{
		//if(!(linhaTmp < tamLinhas)) colunaTmp++;
//		cout<<endl<<"i = "<<i;		
		cout<<endl<<"Elemento na pos["<<i<<"]: "<<matrizOriginal.lerMatriz(i);
	}//fim for

	//calculando determinante
	int det = matrizOriginal.calcularDeterminanteMat33();
	cout<<endl<<endl<<"Determinante da matriz eh: "<<det<<endl;	

	//calculando mdc
	int mdc = Operacoes::mdc(det,26);
	cout<<endl<<"MDC é: "<<mdc;

	//calculando a inversa
	int modulo = 26, valorA=det;
	int inv = Operacoes::inverso(modulo,valorA);
	cout<<endl<<"O inverso de "<<valorA<<" mod "<<modulo<<" é "<<inv;

	//Encontrando  a matriz Transposta:
	
	//4,5 - Calcular as determinantes ( tirando linha e coluna ) para montar a matriz dos cofatores
	//- em modulo 26
	Matriz matrizCofatores(3,3);
	matrizCofatores.calcularCofatores(&matrizOriginal);

	cout<<endl<<endl<<"Lendo A matriz de cofatores: "<<endl;
	for (int tamVetor = tamLinhas * tamColunas, i=0; i< tamVetor; i++) 
		{ cout<<endl<<"Elemento na pos["<<i<<"]: "<<matrizCofatores.lerMatriz(i); }

	//6 - Montar a matriz Adjacente - em modulo 26
	Matriz matrizAdjacente(3,3);
	matrizAdjacente.calcularAdjacente(&matrizCofatores);
	cout<<endl<<endl<<"Lendo A matriz adjacente: "<<endl;
	for (int tamVetor = tamLinhas * tamColunas, i=0; i < tamVetor; i++) 
		{ cout<<endl<<"Elemento na pos["<<i<<"]: "<<matrizAdjacente.lerMatriz(i); }

	//Calculando o inverso da matriz pela matriz adjacente e o resultado é a transposta
	//- em modulo 26
	Matriz matrizTransposta(3,3);
	matrizTransposta.calcularTransposta(inv,&matrizAdjacente);
	cout<<endl<<endl<<"Lendo A matriz transposta: "<<endl;
	for (int tamVetor = tamLinhas * tamColunas, i=0; i < tamVetor; i++) 
		{ cout<<endl<<"Elemento na pos["<<i<<"]: "<<matrizTransposta.lerMatriz(i); }
	
	//Pronto...já tem a transposta em mãos, agora eh criptorgrafar

	//CRIPTOGRAFANDO
	//Para criptografar eh preciso seguir as seguintes regras:
	// - a mensagem não pode ter espaco
	// - a mensagem será predefinida e dividida em 3 blocos cada
	// - a mensagem inicial será: FERMAT
	// - O valor de cada letra do alfabeto é descoberto pela formula: valorLet = 'A' - 65, no caso dará 0

	//definindo a mensagem
	string msg = "FERMAT", mensagem, msgCript, msgCriptografada;
	cout<<endl<<endl<<"Mensagem original(msg): "<<msg;

	int i=0,j;

	//i - controla a posicao da mensagem original e j controla a posicao da msg de copia
	for(j=0;i < 3; i++,j++) { mensagem[j] = msg[i]; }
	msgCript = matrizOriginal.obterCript(mensagem);
	cout<<endl<<"A mensagem: \""<<mensagem[0]<<mensagem[1]<<mensagem[2]<<"\" ,criptografada eh: \""<<msgCript<<"\".";
	msgCriptografada += msgCript;

	for(j=0;i < 6; i++,j++) { mensagem[j] = msg[i]; }
	msgCript = matrizOriginal.obterCript(mensagem);
	cout<<endl<<"A mensagem: \""<<mensagem[0]<<mensagem[1]<<mensagem[2]<<"\" ,criptografada eh: \""<<msgCript<<"\".";
	msgCriptografada += msgCript;	
	cout<<endl<<"A mensagem final criptografada eh: "<<msgCriptografada;

	//Descriptografando
	i=0;
	string msgDecriptografada="";

	//decriptografando primeiro bloco
	for(j=0;i < 3; i++,j++) { mensagem[j] = msgCriptografada[i]; }
	msgCript = matrizTransposta.obterCript(mensagem);
	cout<<endl<<"A mensagem: \""<<mensagem[0]<<mensagem[1]<<mensagem[2]<<"\" , decriptografada eh: \""<<msgCript<<"\".";
	msgDecriptografada += msgCript;

	for(j=0;i < 6; i++,j++) { mensagem[j] = msgCriptografada[i]; }
	msgCript = matrizTransposta.obterCript(mensagem);
	cout<<endl<<"A mensagem: \""<<mensagem[0]<<mensagem[1]<<mensagem[2]<<"\" , decriptografada eh: \""<<msgCript<<"\".";
	msgDecriptografada += msgCript;

	cout<<endl<<"A mensagem final decriptografada eh: "<<msgDecriptografada<<endl;
}//fim cifra de hill

void Interface::menuCrifraAfim()
{

	string mensagem;
	int a, b, n;
	int inverso, mdc;
	n = 26;
	do{

		cout<<endl<<"Digite o valor de \"a\". Ou 0 pra sair: ";
		cin>>a;
		if(a==0) return;		
		cout<<"Digite o valor de \"b\": ";
		cin>>b;

	
		cout<<endl<<"A formula de cript eh: E(x)= "<<a<<"x + "<<b<<" mod "<<n<<endl; 

		mdc = Operacoes::mdc(a,n);

		if(mdc!=1) cout<<"O valor de A: "<<a<<" e N: "<<n<<", não tem MDC =1.\n Digite novamente.\nValor MDC: "<<mdc<<endl;

		inverso = Operacoes::inverso(n,a);
		inverso = inverso%26;
		if(inverso < 0 )inverso = 26 + inverso;

		cout<<"O valor do inverso de a eh: "<<inverso<<endl; 

	} while(mdc!=1 && a ==0);

	string mensagemCript="", mensagemDecript="";
	mensagem= "AGORA";
	int tam=0,i,tmp;
	for(i=0; mensagem[i] != '\0'; ++i)
	tam=i;	
//Criptografando	
	for(i=0; i <= tam; i++){
//		cout<<endl<<"mensagem["<<i<<"]:"<<mensagem[i];
//		cout<<endl<<"mensagemCript["<<i<<"]:"<<mensagemCript[0];
		tmp = mensagem[i];
		tmp -= 65;
		int ex = ((a * tmp) + b)%26;
		if(ex < 0) ex = 26+ex;
		char letra = ex+65;
		mensagemCript +=letra;
//		cout<<endl<<"mensagemCript="<<tmp;

	}//fim for

//Decriptografando
	for(i=0; i <= tam; i++)
	{
		tmp = mensagemCript[i];
		tmp -= 65;
		int dy = ((tmp - b) * inverso)%26;
		if(dy < 0) dy = 26+dy;
		char letra = dy+65;
		mensagemDecript += letra;
	}//fim for

	cout<<endl<<"Mensagem Original: "<<mensagem;
	cout<<endl<<"Mensagem Criptografada: "<<mensagemCript;
	cout<<endl<<"Mensagem Criptografada: "<<mensagemDecript<<endl;
	

}//fim menu crirfra afim
