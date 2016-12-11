#ifndef DIV3_H_
#define DIV3_H_
#include<string>
#include"Operacoes.h"

using namespace std;
class Div3
{//inicio da classe
private:
	string estadoAtual;
	string str;
	int tamStr;

	string ler_q0(int vl_lido);
	string ler_q1(int vl_lido);
	string ler_q2(int vl_lido);

public:
	Div3(string str):
		estadoAtual("q0"),
		str(str)
		{
			this->tamStr = Operacoes::obterTamanho(str);
		}//fim construtor
	~Div3(){}
	bool calcularAutomato();

};//fim da classe

bool Div3::calcularAutomato()
{

//Convertendo String para int... subtrai-se 48
	for(int i=0; i<tamStr; i++)
	{
		//lendo valores da string
		int vl_lido = str[i] - 48;
		//cout<<" "<<vl_lido;

		//Verificando o Estado atual e calculando o destino
		if(estadoAtual=="q0") estadoAtual=ler_q0(vl_lido);
			else if(estadoAtual=="q1") estadoAtual=ler_q1(vl_lido);
				else if(estadoAtual=="q2") estadoAtual=ler_q2(vl_lido);
	}//fim for


	//retornara se é ou não divisivel, true or false
	if(estadoAtual=="q0") return true;
	else return false;

}//fim metodo para verificar se o automato eh valido
//************************************
string Div3::ler_q0(int vl_lido)
{
	switch(vl_lido)
	{//switch
		case 0:{ return "q0"; break; }
		case 1:{ return "q1"; break; }
		case 2:{ return "q2"; break; }
		case 3:{ return "q0"; break; }
		case 4:{ return "q1"; break; }
		case 5:{ return "q2"; break; }
		case 6:{ return "q0"; break; }
		case 7:{ return "q1"; break; }
		case 8:{ return "q2"; break; }
		case 9:{ return "q0"; break; }
	}//fim switch
}//fim ler q0
//************************************
string Div3::ler_q1(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q1 com valor: "<<vl_lido<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q1"; break; }
		case 1:{ return "q2"; break; }
		case 2:{ return "q0"; break; }
		case 3:{ return "q1"; break; }
		case 4:{ return "q2"; break; }
		case 5:{ return "q0"; break; }
		case 6:{ return "q1"; break; }
		case 7:{ return "q2"; break; }
		case 8:{ return "q0"; break; }
		case 9:{ return "q1"; break; }
	}//fim switch
}//fim ler q1
/********************************************************************/
string Div3::ler_q2(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q2 com valor: "<<vl_lido<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q2"; break; }
		case 1:{ return "q0"; break; }
		case 2:{ return "q1"; break; }
		case 3:{ return "q2"; break; }
		case 4:{ return "q0"; break; }
		case 5:{ return "q1"; break; }
		case 6:{ return "q2"; break; }
		case 7:{ return "q0"; break; }
		case 8:{ return "q1"; break; }
		case 9:{ return "q2"; break; }
	}//fim switch
}//fim ler q2

#endif /*DIV3_H_*/
