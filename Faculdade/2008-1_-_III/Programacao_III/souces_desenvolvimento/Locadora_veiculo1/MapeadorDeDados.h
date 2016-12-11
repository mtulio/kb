#ifndef MAPEADORDEDADOS_H_
#define MAPEADORDEDADOS_H_

#include"ItemPersistencia.h"
#include<string>
#include<fstream>
#include<iostream>

class MapeadorDeDados
{
	public:
		// METODOS NORMAIS
		MapeadorDeDados(){}
		// METODOS VIRTUAIS NORMAIS
		virtual bool gravarDados(ItemPersistencia *objeto);
		virtual bool recuperarDados(ItemPersistencia *objeto);
		virtual bool removerDados(ItemPersistencia *objeto);		
	
	protected:
		// METODOS VIRTUAIS PUROS
		// METODO GRAVAR, tem como responsabilidade gravar o objeto do tipo pai passado 
		// como parametro
		virtual void gravarNoArmazenamento(ItemPersistencia *objeto) = 0;
		virtual bool buscarNoArmazenamento(int id, ItemPersistencia *objeto) = 0;
		virtual void removerNoArmazenamento(ItemPersistencia *objeto) = 0;
	
};//fim classe Mapeador


#endif /*MAPEADORDEDADOS_H_*/
