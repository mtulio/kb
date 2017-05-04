// PRODUCT BY MARCO TULIO
#ifndef MAPEADORDEDADOSCLIENTE_H_
#define MAPEADORDEDADOSCLIENTE_H_

#include<string>
#include<fstream>
#include<iostream>
//classes que vao ser usadas
#include"Cliente.h"
#include"MapeadorDeDados.h"
#include"ItemPersistencia.h"


class MapeadorDeDadosCliente: public MapeadorDeDados
{
	private:
	const std::string nomeDoArquivoNoDisco;
	
	public:
	MapeadorDeDadosCliente();
	// PORQUE O CONSTRUTOR EH VIRTUAL SENDO QUE ESSA CLASSE N TEM NENHUM FILHO?????????????
	virtual ~MapeadorDeDadosCliente(){}
	//metodos 
	void gravarNoArmazenamento(ItemPersistencia *objeto);
	bool buscarNoArmazenamento(int id, ItemPersistencia *objeto);
	void removerNoArmazenamento(ItemPersistencia *objeto);	
};//fim da classe mapeador de dados

#endif /*MAPEADORDEDADOSCLIENTE_H_*/
