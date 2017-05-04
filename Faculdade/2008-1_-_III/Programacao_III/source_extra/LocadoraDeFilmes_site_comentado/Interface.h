#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"Persistencia.h"
#include<iostream>
#include"Cliente.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Interface
{
	public:
		static void menu01(Persistencia *locadora);
		static void menuCliente(Persistencia *locadora);
	
};

#endif /*INTERFACE_H_*/
