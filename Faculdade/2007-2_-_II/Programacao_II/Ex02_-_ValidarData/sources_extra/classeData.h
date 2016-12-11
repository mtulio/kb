#ifndef CLASSEDATA_H_
#define CLASSEDATA_H_
#include <string>
using namespace std;
class Data 
{//inicio da classe Data
	//Atributos
	private:
		unsigned int dia;
		unsigned int mes;
		unsigned int ano;
		
	//Metodos
	public: 
		bool validar( unsigned int dd, unsigned int mm, unsigned int aa)const;
		bool atribuir( unsigned int dd, unsigned int mm, unsigned int aa);
		void obter( unsigned int &dd, unsigned int &mm, unsigned int &aa)const;
		void obter( unsigned int &dd, string &mm, unsigned int &aa)const;
		const string diaDaSemana();
	Data():dia(1),mes(1),ano(1){}//inicializando as variaveis
	//Construtor e destrutor Default
};//fim da classe Data

#endif /*CLASSEDATA_H_*/
