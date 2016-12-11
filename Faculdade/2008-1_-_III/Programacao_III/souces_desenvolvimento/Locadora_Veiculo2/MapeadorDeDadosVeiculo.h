#ifndef MAPEADORDEDADOSVEICULO_H_
#define MAPEADORDEDADOSVEICULO_H_

#include"MapeadorDeDados.h" // auto jah inclui as classes incluidas em map de dados
#include"Veiculo.h" 

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
};//fim mapeador de dados veiculo

#endif /*MAPEADORDEDADOSVEICULO_H_*/
