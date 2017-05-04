#ifndef CONTROLESHORT_H_
#define CONTROLESHORT_H_

#include"Interface.h"

// APENAS PARA SETAR O TIPO DOS ELEMENTOS DA MATRIZ
// NESSE CASO SETARA SHORT

class ControleShort{
public:
	inline static void setarTipo(){
		Interface<short>::menuPrincipal();
	}
};

#endif /*CONTROLESHORT_H_*/
