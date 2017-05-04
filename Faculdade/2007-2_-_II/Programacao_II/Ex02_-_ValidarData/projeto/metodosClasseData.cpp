#include "classeData.h"
#include <string>

using namespace std;
bool Data::validar( unsigned int dd, unsigned int mm, unsigned int aa )const
{
	unsigned int diaMes[13];
	diaMes[0]=1;
	diaMes[1]=31;
	diaMes[2]=28;
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
	
	if (dd<1 || mm<1 || dd>31 || mm>12 || aa<1) return(false);
	if (aa%4==0 &&(aa%100!=0 || aa%400==0)) diaMes[2]+=1;
	if (dd>diaMes[mm]) return(false);
	return(true);
}

bool Data::atribuir( unsigned int dd, unsigned int mm, unsigned int aa)
{
	if ( validar(dd, mm, aa)) {
		dia = dd;
		mes = mm;
		ano = aa;
		return (true);
	}
	else return (false);
}

void Data::obter( unsigned int &dd, string &mm, unsigned int &aa )const
{
	string mesv[13];
	mesv[0]="vazio";
	mesv[1]="Janeiro";
	mesv[2]="Fevereiro";
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
}

const string Data::diaDaSemana()
{
	string diaDaSemana[7];
    diaDaSemana[0]="Domingo";
	diaDaSemana[1]="Segunda-feira";
	diaDaSemana[2]="Terça-feira";
	diaDaSemana[3]="Quarta-feira";
	diaDaSemana[4]="Quinta-feira";
	diaDaSemana[5]="Sexta-feira";
	diaDaSemana[6]="Sabado";

unsigned int ano1, ano2,diaS;
if (mes<=2) mes+=10; 
else mes-=2;
  ano1=(ano/100);
  ano2=(ano%100);
  diaS=((int(2.6*mes-0.2)/1 +dia+ ano2 + int(ano2/4) + int(ano1/4) - 2*ano1)%7);
  return (diaDaSemana[diaS]);
}
