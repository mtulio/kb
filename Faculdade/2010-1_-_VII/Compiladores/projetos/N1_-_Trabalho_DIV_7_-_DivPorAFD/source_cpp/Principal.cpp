/* PUC-GO
 * Disciplina: Compiladores
 * Alunos: Marco Tulio Rodrigues Braga, Adão Junior
 * Descricao: Programa que le e verifica se um numero eh divisivel por 7
 * utilizando um AFD.
 * Dt. Criacao: 27/02/2010
 * Dt. Modificacao: 30/03/2010 
*/

#include<iostream>
#include<string>

#include"div2.h"
#include"div3.h"
#include"div4.h"
#include"div5.h"
#include"div6.h"
#include"div7.h"
#include"div8.h"
#include"div9.h"

using namespace std;

int main(void)
{//inicio main
cout<<" _____________________________________________________"<<endl;
cout<<"|_Programa com a finalidade de calcular se um dado   "<<endl;
cout<<"|_numero é ou não divisivel por um divisor de 1 a 9"<<endl;
cout<<"|_utilizando AFD."<<endl;

string str;

cout<<endl<<"Alfabeto: [0-9]";
cout<<endl<<"Tamanho: menor ou igual a 255 caracteres.";
cout<<endl<<"Digite a string correspondente ao alfabeto: ";
cin>>str;
	

	if(!Operacoes::validarString(str)) cout<<endl<<"Valor digitado nao pertence ao alfabeto[0-9]!"<<endl<<endl;
	else 
	{
		int tam_str=Operacoes::obterTamanho(str);
		//cout<<"\n\n\t\tTAMANHO: "<<tam_str<<"\n\n\t\t";
		if(tam_str < 0) cout<<endl<<"Valor digitado excede os limites permitidos. \nQtd caracteres digitados: "<<tam_str*(-1)<<endl<<endl;
		else {
			int var_div;
			cout<<"Divisibilidade:"<<endl;
			cout<<"\t(1) - Divisivel por 1:"<<endl;
			cout<<"\t(2) - Divisivel por 2:"<<endl;
			cout<<"\t(3) - Divisivel por 3:"<<endl;
			cout<<"\t(4) - Divisivel por 4:"<<endl;
			cout<<"\t(5) - Divisivel por 5:"<<endl;
			cout<<"\t(6) - Divisivel por 6:"<<endl;
			cout<<"\t(7) - Divisivel por 7:"<<endl;
			cout<<"\t(8) - Divisivel por 8:"<<endl;
			cout<<"\t(9) - Divisivel por 9:"<<endl;
			cout<<"Informe o valor do divisor: ";
			cin>>var_div;
			switch(var_div)
			{
				//partindo de que todo numero é divisivel por 1
				case 1:
				{
					cout<<"O numero informado é divisivel por 1"<<endl<<endl;
				break;
				}
				case 2:
				{
					Div2 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 2"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 2"<<endl<<endl;
				break;
				}//fim case 2
				case 3:
				{
					Div3 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 3"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 3"<<endl<<endl;
				break;
				}//fim case 3
				case 4:
				{
					Div4 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 4"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 4"<<endl<<endl;
				break;
				}//fim case 4
				case 5:
				{
					Div5 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 5"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 5"<<endl<<endl;
				break;
				}//fim case 5
				case 6:
				{
					Div6 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 6"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 6"<<endl<<endl;
				break;
				}//fim case 6
				case 7:
				{
					Div7 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 7"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 7"<<endl<<endl;
				break;
				}//fim case 7
				case 8:
				{
					Div8 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 8"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 8"<<endl<<endl;
				break;
				}//fim case 8
				case 9:
				{
					Div9 obj(str);
					if(obj.calcularAutomato()) cout<<"O numero informado é divisivel por 9"<<endl<<endl;
					else cout<<"O numero informado não é divisivel por 9"<<endl<<endl;
				break;
				}//fim case 9
				default:
				{
					cout<<endl<<"Opcao Invalida"<<endl<<endl;
					break;
				}//fim default
			}//fim switch
		}//fim else para calcular o automato
	}//fim else
}//fim main
