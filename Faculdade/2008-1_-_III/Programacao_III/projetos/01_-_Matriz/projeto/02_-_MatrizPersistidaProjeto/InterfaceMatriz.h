#ifndef INTERFACEMATRIZ_H_
#define INTERFACEMATRIZ_H_
#include"Matriz.h"

class InterfaceMatriz
{
	public:
		static void lerMatriz(Matriz &matriz);
		static void escreverMatriz(Matriz const &matriz);
		static void menuPrincipal();
};
#endif /*INTERFACEMATRIZ_H_*/
