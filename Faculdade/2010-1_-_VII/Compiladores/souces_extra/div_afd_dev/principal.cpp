/* PUC-GO
 * Disciplina: Compiladores
 * Aluno: Marco Tulio Rodrigues Braga
 * Descricao: Programa que le e verifica se um numero eh divisivel por 7
 * utilizando um AFD.
 * Dt. Criacao: 27/02/2010
 * Dt. Modificacao: 27/02/2010 */
//#include<iomanip>
#include<iostream>
#include<string>
#include"div7.h"
using namespace std;
//***************** INICIO DOS METODOS ******************************/
/********************************************************************/
/*
string ler_qi(int vl_lido)
{//inicio do ler qi
//cout<<"\n\tENTREI NO MTD ler_qi com valor: "<<vl_lido<<endl;
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
}//fim ler qi
/********************************************************************/
/*
string ler_q0(int vl_lido)
{//inicio do ler q0
//cout<<"\n\tENTREI NO MTD ler_q0 com valor: "<<vl_lido<<endl;
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
/********************************************************************/
/*
string ler_q1(int vl_lido)
{//inicio do ler q1
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
/*
string ler_q2(int vl_lido)
{//inicio do ler q2
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
/*
string ler_q3(int vl_lido)
{//inicio do ler q3
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
/*
string ler_q4(int vl_lido)
{//inicio do ler q4
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
/*
string ler_q5(int vl_lido)
{//inicio do ler q5
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
/*
string ler_q6(int vl_lido)
{//inicio do ler q6
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
/********************************************************************/
/*
void calcular_automato(string str,int tam_str)
{//inicio do calcular automato

//inicia-se no estado qi
string est_atual="qi";

//Convertendo String para int... subtrai-se 48
for(int i=0; i<tam_str; i++)
{
	//lendo valores da string
	int vl_lido = str[i] - 48;
	//cout<<" "<<vl_lido;

	//Verificando o Estado atual e calculando o destino
	if(est_atual=="qi") est_atual=ler_qi(vl_lido);
	else if(est_atual=="q0") est_atual=ler_q0(vl_lido);
		else if(est_atual=="q1") est_atual=ler_q1(vl_lido);
			else if(est_atual=="q2") est_atual=ler_q2(vl_lido);
				else if(est_atual=="q3") est_atual=ler_q3(vl_lido);
					else if(est_atual=="q4") est_atual=ler_q4(vl_lido);
						else if(est_atual=="q5") est_atual=ler_q5(vl_lido);
							else if(est_atual=="q6") est_atual=ler_q6(vl_lido);
}//fim for

cout<<endl<<endl<<"ESTADO FINAL: "<<est_atual<<endl; 
if(est_atual=="q0") cout<<endl<<"\tO numero "<<str<<" e divisivel por 7"<<endl<<endl;
else cout<<endl<<"\tO numero "<<str<<" nao e divisivel por 7"<<endl<<endl;
}//fim do calcular automato
*/
/********************************************************************/
/********************************************************************/
/********************************************************************/
int main(void)
{//inicio main
//system("clear");
cout<<" _____________________________________________________"<<endl;
cout<<"|_Programa com a finalidade de calcular se um dado   "<<endl;
cout<<"|_numero informado eh ou n divisivel por 7 utilizando"<<endl;
cout<<"|_AFD."<<endl;

string str;
//int id_erro=0;
//int tam_str;

cout<<endl<<"Alfabero: [0-9]";
cout<<endl<<"Digite a string correspondente ao alfabero: ";
cin>>str;
	

	if(!Operacoes::validarString(str)) cout<<endl<<"Valor digitado nao pertence ao alfabero[0-9]!"<<endl<<endl;
	else 
	{
		int tam_str=Operacoes::obterTamanho(str);
		if(tam_str < 0) cout<<endl<<"Valor digitado excede os limites permitidos. \nQtd char. Digitados: "<<tam_str*(-1)<<endl<<endl;
		else {
			int var_div;
			cout<<"Divisibilidade:"<<endl;
			cout<<"\t(7) - Divisivel por 7:"<<endl;
			cout<<"Informe o valor entre parenteses: ";
			cin>>var_div;
			switch(var_div)
			{
				case 7:
				{
					Div7 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 7"<<endl;
					else cout<<"O numero informado não é divisivel por 7"<<endl;
				break;
				}//fim case 7
				default:
				{
					cout<<endl<<"Opcao Invalida"<<endl;
					break;
				}//fim default
			}//fim switch
		}//fim else para calcular o automato
	}//fim else


	//Verificando os erros
	//Erro 1: Valor digitado diferente do alfabeto [0-9]
/*	for (tam_str=0; str[tam_str] != '\0' ; tam_str++)
	{//inicio for
		if(((str[tam_str] < '0') || (str[tam_str] > '9'))){
		 	//cout<<endl<<"entreiii"<<endl;
			id_erro=1;
		}
	}//fim for
	//Erro 2: Valor digitado maior do que 254
	if(tam_str>=255) id_erro=2;

	//Tratamento de erros
	if(id_erro==0) {//inicia o calculo do automato
		//chamada ao metodo de calcular automato
		calcular_automato(str,tam_str);
	}//fim do if que inicia o calculo do automato
	else if(id_erro==1) cout<<endl<<"Valor digitado nao pertence ao alfabero[0-9]!"<<endl<<endl;
		else if(id_erro==2) cout<<endl<<"Valor digitado excede os limites permitidos. \nQtd char. Digitados: "<<tam_str<<endl<<endl;
*/
}//fim main
