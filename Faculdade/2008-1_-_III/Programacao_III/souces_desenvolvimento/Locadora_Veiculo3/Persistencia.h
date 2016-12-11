#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include"ItemPersistencia.h"
#include"MapeadorDeDados.h"
#include"MapeadorDeDadosCliente.h"
#include"MapeadorDeDadosVeiculo.h"
//#inlcude"MapeadorDeDadosLocacao.h"

// CLASSE IMPORTANTE!!! : INICIO DO FRAMEWORK

class Persistencia
{
	private:
	// CRIANDO UM OBJETO da classe mapeador de dados que e responsavel para manipular os dados
	// dentro do arquivo, mas aqui eh o inicio da criação do FRAMEWORK, AKI EH A UNIFICAÇÃO DAS CLASSES
	// e a identificação de qual sera usada sera atraves do vetor de objetos da classe mapeador de dados
	// criado logo abaixo.  UMA DAS PARTES MAIS IMPORTANTES PARA O DISCERNIMENTO DO FRAMEWORK EH ESSA CLASSE
		MapeadorDeDados *baseDeDados[3];
	
	public:
		Persistencia();
		virtual ~Persistencia(); //PORQUE DE VIRTUAL?
		bool gravar(ItemPersistencia *objeto);
		bool recuperar(ItemPersistencia *objeto);
		bool remover(ItemPersistencia *objeto);	
};//fim da classe Persistencia

#endif /*PERSISTENCIA_H_*/
