#ifndef INTERFACE_H_
#define INTERFACE_H_


#include"MapeadorDeDados.h"
#include"Persistencia.h"

class Interface
{
	public:
	
	static void menuPrincipal(Persistencia *locadora);
	static void menuCliente(Persistencia *locadora);
	static void menuFilme(Persistencia *locadora);
	static void menuLocacao(Persistencia *locadora);
	
	
};// FIM DA CLASSE INTERFACE

#endif /*INTERFACE_H_*/
