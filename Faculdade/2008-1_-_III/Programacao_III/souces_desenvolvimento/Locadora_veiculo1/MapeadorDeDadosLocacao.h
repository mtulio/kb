#ifndef MAPEADORDEDADOSLOCACAO_H_
#define MAPEADORDEDADOSLOCACAO_H_

#include"MapeadorDeDados.h"
#include"Locacao.h"

class MapeadorDeDadosLocacao: public MapeadorDeDados
{
private:
	const std::string nomeDoArquivoNoDisco;
	
public:
	MapeadorDeDadosLocacao();
	//metodos 
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id, ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);	
};//dim da calsse mapeador de dados locacao

#endif /*MAPEADORDEDADOSLOCACAO_H_*/
