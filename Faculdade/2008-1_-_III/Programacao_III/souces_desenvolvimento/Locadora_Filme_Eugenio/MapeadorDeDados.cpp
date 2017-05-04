#include "MapeadorDeDados.h"

bool MapeadorDeDados::gravarDados(ItemPersistencia *objeto)
{
	if(!buscarNoArmazenamento(objeto->obterIdentificador(),objeto)) {
		gravarNoArmazenamento(objeto);
		return true;
	}return false;
}

bool MapeadorDeDados::recuperarDados(ItemPersistencia *objeto)
{
	if(buscarNoArmazenamento(objeto->obterIdentificador(),objeto)) return true;
		else return false;
}

bool MapeadorDeDados::removerDados(ItemPersistencia *objeto)
{
	if(buscarNoArmazenamento(objeto->obterIdentificador(),objeto)){
		removerNoArmazenamento(objeto);
		return true;
	}
		else return false;
}
