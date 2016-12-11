#ifndef MAPEADORDEDADOSCLIENTE_H_
#define MAPEADORDEDADOSCLIENTE_H_

#include"MapeadorDeDados.h"
#include"Cliente.h"

class MapeadorDeDadosCliente: public MapeadorDeDados
{
	private:
		const std::string nomeDoArquivoNoDisco;
	
	public:
		MapeadorDeDadosCliente();
		
		virtual ~MapeadorDeDadosCliente(){}
		//metodos 
		void gravarNoArmazenamento(ItemPersistencia *objeto);
		bool buscarNoArmazenamento(int id, ItemPersistencia *objeto);
		void removerNoArmazenamento(ItemPersistencia *objeto);	
};//



#endif /*MAPEADORDEDADOSCLIENTE_H_*/
