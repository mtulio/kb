// PRODUCT BY MARCO TULIO
#ifndef MAPEADORDEDADOS_H_
#define MAPEADORDEDADOS_H_

#include<string>
#include"ItemPersistencia.h"

//A CLASSE MAPEADOR DE DADOS TEM COMO MAIOR OBJETIVO ENCAMNHAR PARA A SUA RESPECTIVO
// LOCAL NO ARQUIVO

// METODO PAI PARA MAPEAR OS DADOS DA PERSISTENCIA
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
}; // FIM DA CLASSE MAPEADOR DE DADOS

#endif /*MAPEADORDEDADOS_H_*/
