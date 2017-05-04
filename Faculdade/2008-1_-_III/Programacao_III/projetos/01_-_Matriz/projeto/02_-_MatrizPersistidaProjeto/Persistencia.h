#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<string>
#include "Matriz.h"
#include <fstream>
//#include<iostream>

class Persistencia
{
	public:
		static void atribuirMatrizNoArquivo(Matriz const &matriz, std::string const &nomeDoArquivo);
		static const Matriz * const obterMatrizDoArquivo(std::string const &nomeDoArquivo);
};

#endif /*PERSISTENCIA_H_*/
