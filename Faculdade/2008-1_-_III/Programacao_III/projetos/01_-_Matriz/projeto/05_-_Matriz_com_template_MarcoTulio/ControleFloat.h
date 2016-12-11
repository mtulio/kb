#ifndef CONTROLEFLOAT_H_
#define CONTROLEFLOAT_H_

#include"Interface.h"

// APENAS PARA SETAR O TIPO DOS ELEMENTOS DA MATRIZ
// NESSE CASO SETARA FLOAT

class ControleFloat{
public:
	inline static void setarTipo(){
		Interface<float>::menuPrincipal();
	}
};

#endif /*CONTROLEFLOAT_H_*/
