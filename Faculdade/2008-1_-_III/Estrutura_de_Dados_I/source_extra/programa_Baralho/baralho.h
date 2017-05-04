#ifndef BARALHO_H_
#define BARALHO_H_

#include <string>
#include <iostream>
#include "carta.h"

using namespace std;

class Baralho {

	private:
		string nome_baralho;
		int qde_cartas;
		Carta * topo;
	public:
		Baralho(string nome);
		~Baralho();
		bool isempity();
		Carta * cria_carta(int nc, char naipe);
		void adiciona_carta(Carta *nova);
		Carta * remove_carta();
		void lista_carta();
		void inverte_baralho();
		void criar_baralho(std::string nome);
};

#endif /*BARALHO_H_*/
