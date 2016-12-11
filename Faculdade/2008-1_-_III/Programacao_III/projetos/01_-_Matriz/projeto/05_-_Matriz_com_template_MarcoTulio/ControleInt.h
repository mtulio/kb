#ifndef CONTROLEINT_H_
#define CONTROLEINT_H_

#include"Interface.h"

// APENAS PARA SETAR O TIPO DOS ELEMENTOS DA MATRIZ
// NESSE CASO SETARA INT

class ControleInt{
public:
	inline static void setarTipo(){
		Interface<int>::menuPrincipal();
	}
};


#endif /*CONTROLEINT_H_*/
