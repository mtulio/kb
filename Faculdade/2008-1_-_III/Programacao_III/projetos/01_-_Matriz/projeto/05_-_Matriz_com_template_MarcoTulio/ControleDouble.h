#ifndef CONTROLEDOUBLE_H_
#define CONTROLEDOUBLE_H_

#include"Interface.h"

// APENAS PARA SETAR O TIPO DOS ELEMENTOS DA MATRIZ
// NESSE CASO SETARA DOUBLE

class ControleDouble{
public:
	inline static void setarTipo(){
		Interface<double>::menuPrincipal();
	}
};

#endif /*CONTROLEDOUBLE_H_*/
