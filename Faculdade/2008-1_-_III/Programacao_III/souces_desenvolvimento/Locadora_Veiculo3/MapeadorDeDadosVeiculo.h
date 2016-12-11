// PRODUCT BY MARCO TULIO
#ifndef MAPEADORDEDADOSVEICULO_H_
#define MAPEADORDEDADOSVEICULO_H_

#include<string>
#include<fstream>
//classes que vao ser usadas
#include"Veiculo.h"
#include"MapeadorDeDados.h"
#include"ItemPersistencia.h"


class MapeadorDeDadosVeiculo: public MapeadorDeDados
{
	private:
	const std::string nomeDoArquivoNoDisco;
	
	public:
	MapeadorDeDadosVeiculo();
	//metodos 
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id, ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);	
};//fim da classe mapeador de dados

#endif /*MAPEADORDEDADOSVEICULO_H_*/
