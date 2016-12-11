#include "Persistencia.h"
#include "MapeadorDeDadosCliente.h"

Persistencia::Persistencia()
{
	baseDeDados[0] = new MapeadorDeDadosCliente();
	//baseDeDados[1] = new MapeadorFilme();
	//baseDeDados[2] = new MapeadorLocacao(); 
}

Persistencia::~Persistencia()
{
	delete baseDeDados[0];
}

bool Persistencia::gravar(ItemPersistencia *objeto)
{
	return baseDeDados[objeto->obterTipoDaClasse()]->gravarDados(objeto);
}

bool Persistencia::recuperar(ItemPersistencia *objeto)
{
	return baseDeDados[objeto->obterTipoDaClasse()]->recuperarDados(objeto);
}

bool Persistencia::remover(ItemPersistencia *objeto)
{
	return baseDeDados[objeto->obterTipoDaClasse()]->removerDados(objeto);
}
