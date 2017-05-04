#ifndef CONTROLELONG_H_
#define CONTROLELONG_H_

#include"Interface.h"

// APENAS PARA SETAR O TIPO DOS ELEMENTOS DA MATRIZ
// NESSE CASO SETARA LONG

class ControleLong{
public:
	inline static void setarTipo(){
		Interface<long>::menuPrincipal();
	}
};

#endif /*CONTROLELONG_H_*/
