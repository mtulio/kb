#ifndef MAPEADORDEDADOSLOCACAO_H_
#define MAPEADORDEDADOSLOCACAO_H_

#include<string>
#include<fstream>
#include"MapeadorDeDados.h"
#include"ItemPersistencia.h"
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
}; // FIM DA CLASSE MAPEADOR DE DADOS DA LOCACAO

#endif /*MAPEADORDEDADOSLOCACAO_H_*/
