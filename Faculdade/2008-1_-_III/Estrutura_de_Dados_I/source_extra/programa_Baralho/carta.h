#ifndef CARTA_H_
#define CARTA_H_

class Carta {
	public:
		int ncarta;
		char naipe;
		Carta * proximo;
		//usando inline implicito para a redução do programa
  		Carta(int ncart, char naip):
                  ncarta(ncart),
                  naipe(naip)
                  { proximo=0; }    
};
#endif /*CARTA_H_*/
