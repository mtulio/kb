#ifndef OPERACOES_H_
#define OPERACOES_H_

#include<string>

using namespace std;

class Operacoes
{
public:

	static int obterTamanho(string str);
	static bool validarString(string str);//validando de acordo com o alfabeto


}; //fim operacoes

//*********
int Operacoes::obterTamanho(string str)
{
	int tam_str;
	for (tam_str=0; str[tam_str] != '\0' ; tam_str++);

	//TRATAMENTO DE ERROS: -2 = tamanho invalido
	if(tam_str>=255) return ((tam_str)*(-1));
	else return tam_str;

}//fim metodo obter
//************

bool Operacoes::validarString(string str)
{
	int id_erro;
	int tam_str;
	for (tam_str=0; str[tam_str] != '\0' ; tam_str++)
	{//inicio for
		if(((str[tam_str] < '0') || (str[tam_str] > '9'))){
		 	//cout<<endl<<"entreiii"<<endl;
			id_erro=-1;
		}
	}//fim for

	//TRATAMENTO DE ERROS: -1 = Alfabero/string invalida
	if(id_erro==-1) return false;
	else return true;

}//fim metodo validar

#endif /*OPERACOES_H_*/
