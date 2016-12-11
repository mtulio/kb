#ifndef AUTOMATO_H_
#define AUTOMATO_H_
#include "classe_fita.h"
#include "classe_pilha.h"
#include <string>
using namespace std;
class Automato{
	private:
		string *tabela;
		int qtd_estado;
		bool obter(unsigned int,unsigned int,string&);
		bool seta(unsigned int,unsigned int,string);
		bool busca(string,string,string[5]);
	public:
		bool validar_sentenca(Fita);
		Automato(std::string[][5]);
		~Automato();
};
#endif /*AUTOMATO_H_*/
