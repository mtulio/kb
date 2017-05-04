#ifndef DIV7_H_
#define DIV7_H_
#include<string>
#include"Operacoes.h"

using namespace std;
class Div7
{//inicio da classe
private:
	string estadoAtual;
	string str;
	int tamStr;

	string ler_q0(int vl_lido);
	string ler_q1(int vl_lido);
	string ler_q2(int vl_lido);
	string ler_q3(int vl_lido);
	string ler_q4(int vl_lido);
	string ler_q5(int vl_lido);	
	string ler_q6(int vl_lido);

public:
	Div7(string str):
		estadoAtual("q0"),
		str(str)
		{
			this->tamStr = Operacoes::obterTamanho(str);
		}//fim construtor
	~Div7(){}
	bool calcularAutomato();

};//fim da classe

bool Div7::calcularAutomato()
{

//Convertendo String para int... subtrai-se 48
	for(int i=0; i<tamStr; i++)
	{
		//lendo valores da string
		int vl_lido = str[i] - 48;
		//cout<<" "<<vl_lido;

		if(estadoAtual=="q0") estadoAtual=ler_q0(vl_lido);
			else if(estadoAtual=="q1") estadoAtual=ler_q1(vl_lido);
				else if(estadoAtual=="q2") estadoAtual=ler_q2(vl_lido);
					else if(estadoAtual=="q3") estadoAtual=ler_q3(vl_lido);
						else if(estadoAtual=="q4") estadoAtual=ler_q4(vl_lido);
							else if(estadoAtual=="q5") estadoAtual=ler_q5(vl_lido);
								else if(estadoAtual=="q6") estadoAtual=ler_q6(vl_lido);
	}//fim for


	//retornara se é ou não divisivel, true or false
	if(estadoAtual=="q0") return true;
	else return false;

}//fim metodo para verificar se o automato eh valido
//************************************

string Div7::ler_q0(int vl_lido)
{
	switch(vl_lido)
	{//switch
		case 0:{ return "q0"; break; }
		case 1:{ return "q1"; break; }
		case 2:{ return "q2"; break; }
		case 3:{ return "q3"; break; }
		case 4:{ return "q4"; break; }
		case 5:{ return "q5"; break; }
		case 6:{ return "q6"; break; }
		case 7:{ return "q0"; break; }
		case 8:{ return "q1"; break; }
		case 9:{ return "q2"; break; }
	}//fim switch
}//fim ler q0
//************************************
string Div7::ler_q1(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q1 com valor: "<<vl_lido<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q3"; break; }
		case 1:{ return "q4"; break; }
		case 2:{ return "q5"; break; }
		case 3:{ return "q6"; break; }
		case 4:{ return "q0"; break; }
		case 5:{ return "q1"; break; }
		case 6:{ return "q2"; break; }
		case 7:{ return "q3"; break; }
		case 8:{ return "q4"; break; }
		case 9:{ return "q5"; break; }
	}//fim switch
}//fim ler q1
/********************************************************************/
string Div7::ler_q2(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q2 com valor: "<<vl_lido<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q6"; break; }
		case 1:{ return "q0"; break; }
		case 2:{ return "q1"; break; }
		case 3:{ return "q2"; break; }
		case 4:{ return "q3"; break; }
		case 5:{ return "q4"; break; }
		case 6:{ return "q5"; break; }
		case 7:{ return "q6"; break; }
		case 8:{ return "q0"; break; }
		case 9:{ return "q1"; break; }
	}//fim switch
}//fim ler q2
/********************************************************************/
string Div7::ler_q3(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q3 com valor: "<<vl_lido<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q2"; break; }
		case 1:{ return "q3"; break; }
		case 2:{ return "q4"; break; }
		case 3:{ return "q5"; break; }
		case 4:{ return "q6"; break; }
		case 5:{ return "q0"; break; }
		case 6:{ return "q1"; break; }
		case 7:{ return "q2"; break; }
		case 8:{ return "q3"; break; }
		case 9:{ return "q4"; break; }
	}//fim switch
}//fim ler q3
/********************************************************************/
string Div7::ler_q4(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q4 com valor: "<<vl_lido<<endl<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q5"; break; }
		case 1:{ return "q6"; break; }
		case 2:{ return "q0"; break; }
		case 3:{ return "q1"; break; }
		case 4:{ return "q2"; break; }
		case 5:{ return "q3"; break; }
		case 6:{ return "q4"; break; }
		case 7:{ return "q5"; break; }
		case 8:{ return "q6"; break; }
		case 9:{ return "q0"; break; }
	}//fim switch
}//fim ler q4
/********************************************************************/
string Div7::ler_q5(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q5 com valor: "<<vl_lido<<endl<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q1"; break; }
		case 1:{ return "q2"; break; }
		case 2:{ return "q3"; break; }
		case 3:{ return "q4"; break; }
		case 4:{ return "q5"; break; }
		case 5:{ return "q6"; break; }
		case 6:{ return "q0"; break; }
		case 7:{ return "q1"; break; }
		case 8:{ return "q2"; break; }
		case 9:{ return "q3"; break; }
	}//fim switch
}//fim ler q5
/********************************************************************/
string Div7::ler_q6(int vl_lido)
{
//cout<<"\n\tENTREI NO MTD ler_q6 com valor: "<<vl_lido<<endl<<endl;
	switch(vl_lido)
	{//switch
		case 0:{ return "q4"; break; }
		case 1:{ return "q5"; break; }
		case 2:{ return "q6"; break; }
		case 3:{ return "q0"; break; }
		case 4:{ return "q1"; break; }
		case 5:{ return "q2"; break; }
		case 6:{ return "q3"; break; }
		case 7:{ return "q4"; break; }
		case 8:{ return "q5"; break; }
		case 9:{ return "q6"; break; }
	}//fim switch
}//fim ler q6
/********************************************************************/

#endif /*DIV7_H_*/
