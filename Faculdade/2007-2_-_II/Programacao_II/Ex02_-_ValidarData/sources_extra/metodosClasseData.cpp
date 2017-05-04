#include "classeData.h"
#include <string>
#include <vector> //Biblioteca stl vector
using namespace std;
bool Data::validar( unsigned int dd, unsigned int mm, unsigned int aa )const
{//inicio do metodo validar
	vector<unsigned int>diaMes(13);//criando um variavel(vetor) com 12 posições
	diaMes[0]=1;//Vetor que n vai ser utilizado
	diaMes[1]=31;//iniciando o vetor na posição 1(Janeiro) c/ 31(ultimo dia do mes)
	diaMes[2]=28;//e assim sucessivamente
	diaMes[3]=31;
	diaMes[4]=30;
	diaMes[5]=31;
	diaMes[6]=30;
	diaMes[7]=31;
	diaMes[8]=31;
	diaMes[9]=30;
	diaMes[10]=31;
	diaMes[11]=30;
	diaMes[12]=31;
	//condição de existencia da data
	if (dd<1 || mm<1 || dd>31 || mm>12 || aa<1) return(false);
	//VErificando se o ano eh bissexto e incrementando o mes de fevereiro
	if (aa%4==0 &&(aa%100!=0 || aa%400==0)) diaMes[2]+=1;
	//Verificando se a data que o usuario digitou eh valida
	if (dd>diaMes[mm]) return(false);
	return(true);
}//fim do metodo validar

bool Data::atribuir( unsigned int dd, unsigned int mm, unsigned int aa)
{//inicio do metodo atribuir
	if ( validar(dd, mm, aa)) {//chama o metodo validar e se for true eh executado o if
		dia = dd;
		mes = mm;
		ano = aa;
		return (true);
	}
	else return (false);
}//fim do metodo atribuir

//Esse metodo pode ser colocando dentro do arquivo .h, para maior desempenho do programa
void Data::obter( unsigned int &dd, unsigned int &mm, unsigned int &aa )const
{//inicio do metodo obter
	dd = dia;
	mm = mes;
	aa = ano;
}//fim do metodo obter

void Data::obter( unsigned int &dd, string &mm, unsigned int &aa )const
{//inicio do metodo obter com string
	vector<string>mesv(13);//criando um vetor string com 12 posições
	mesv[0]="vazio";//Para facilitar os calculos e entendimento do programa a primeira posição do vetor fica vazio
	mesv[1]="Janeiro";//Concatenando o nome "Janeiro" dentro da posição 1 do vetor
	mesv[2]="Fevereiro";//e assim sucessivamente
	mesv[3]="Março";
	mesv[4]="Abril";
	mesv[5]="Maio";
	mesv[6]="Junho";
	mesv[7]="Julho";
	mesv[8]="Agosto";
	mesv[9]="Setembro";
	mesv[10]="Outubro";
	mesv[11]="Novembro";
	mesv[12]="Dezembro";
	dd = dia;
	mm = mesv[mes];
	aa = ano;	
}//fim do metodo obter com string

const string Data::diaDaSemana()
{//inicio do metodo string dia da Semana
	vector<string>diaDaSemana(7);//criando um vetor string diaSemana
	diaDaSemana[0]="Domingo";//Atribuindo valores para os dias da semana
	diaDaSemana[1]="Segunda-feira";
	diaDaSemana[2]="Terça-feira";
	diaDaSemana[3]="Quarta-feira";
	diaDaSemana[4]="Quinta-feira";
	diaDaSemana[5]="Sexta-feira";
	diaDaSemana[6]="Sabado";
	int aa=ano;//criando e inicializando a variavel aa
	int f = aa+dia+3*(mes-1)-1;
	if(mes<3) aa--;
		else f -=(int(ano/4) - int((aa/100+1)*0.75));
		f %=7;
		return (diaDaSemana[f]);	
}//fim do metodo string dia da semana