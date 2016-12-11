#ifndef CONTROLEVEICULO_H_
#define CONTROLEVEICULO_H_

#include"Veiculo.h"
#include"Persistencia.h"

class ControleVeiculo
{
	private:
		Persistencia *persistencia;
	public:
		ControleVeiculo(Persistencia *persistencia):
			persistencia(persistencia){}
		
		bool incluirVeiculo(Veiculo *veiculo);
		bool consultarVeiculo(Veiculo *veiculo);
		bool alterarVeiculo(Veiculo *veiculo);		
};// fim da classe Veiculo

#endif /*CONTROLEVEICULO_H_*/
