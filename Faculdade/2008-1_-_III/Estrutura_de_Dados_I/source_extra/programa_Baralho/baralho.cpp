#include "baralho.h"
#include "carta.h"

Baralho::Baralho(string nome) {
	nome_baralho=nome;
	qde_cartas=0;
	topo=0;	
}

/****************************************************************************/

Baralho::~Baralho() {
	Carta *aux;
	while(!this->isempity()) {
		aux=this->remove_carta();
		delete [] aux;
	}
}

/****************************************************************************/

bool Baralho::isempity() {
	return this->topo==0;
}



/****************************************************************************/

void Baralho::adiciona_carta(Carta *nova) {
	nova->proximo=this->topo;
	this->topo=nova;
	this->qde_cartas++;
}


/****************************************************************************/

void Baralho::lista_carta() {
	Carta *aux;
	if(this->isempity()) cout << endl << "O Baralho ainda não possui cartas." << endl;
	else{
		cout << endl;
		Baralho *bar_aux=new Baralho("auxiliar");
		while(!this->isempity()) {
			aux=this->remove_carta();
			cout << aux->ncarta << "	";
			cout << aux->naipe << endl;
			bar_aux->adiciona_carta(aux);
		}
		while(!bar_aux->isempity()) {
			aux=bar_aux->remove_carta();
			this->adiciona_carta(aux);
		}
		bar_aux->~Baralho();
	}
}

/****************************************************************************/

void Baralho::inverte_baralho() {
	Carta *aux;
	if(this->isempity()) cout << endl << "O Baralho ainda não possui cartas." << endl;
	else{
		Baralho *bar_aux=new Baralho("auxiliar");
		while(!this->isempity()) {
			aux=this->remove_carta();
			bar_aux->adiciona_carta(aux);
		}
		this->topo=bar_aux->topo;
		this->qde_cartas=bar_aux->qde_cartas;
		bar_aux->topo=0;
		bar_aux->qde_cartas=0;
		bar_aux->~Baralho();
	}
}


void Baralho::criar_baralho(std::string nome) {
	int i, k;
	char naip;
	Carta * aux;
	this->nome_baralho=nome;
	// cria os 4 naipes
	for(i=1; i<=4; i++) {
		if(i==1) naip='c';
		if(i==2) naip='o';
		if(i==3) naip='e';
		if(i==4) naip='p';
		for(k=1; k<=13; k++) {
			aux = cria_carta(k, naip);
			adiciona_carta(aux);
		}
	}
	// cria os 2 curingas com naipe 'a' e número 14 e 15.
	aux = cria_carta(14, 'a');
	adiciona_carta(aux);
	aux = cria_carta(15, 'a');
	adiciona_carta(aux);
	//return bara;
}

/****************************************************************************/

Carta * Baralho::cria_carta(int nc, char naipe) {
	Carta * ptr;
	ptr = new Carta(nc, naipe);
	return ptr;	
}

/****************************************************************************/

Carta * Baralho::remove_carta(){
	Carta * ptr;
	ptr=this->topo;
	this->topo=ptr->proximo;
	ptr->proximo=0;	
	this->qde_cartas--;
	return ptr;	
}
