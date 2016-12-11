#ifndef CONTROLEVEICULO_H_
#define CONTROLEVEICULO_H_

#include"Persistencia.h"
#include"Veiculo.h"

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
};// fim da definicao de controle veiculo


bool ControleVeiculo::incluirVeiculo(Veiculo *veiculo)
{
	try{		
		return persistencia->gravar(veiculo);
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch		
}// fim da classe Incluir

bool ControleVeiculo::consultarVeiculo(Veiculo *veiculo)
{
	try{
		return persistencia->recuperar(veiculo);		
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}// fim da calsse consultar


bool ControleVeiculo::alterarVeiculo(Veiculo *veiculo)
{
	try{
		Veiculo veiculoAux( veiculo->obterIdentificador() );
		if(persistencia->remover(&veiculoAux)) return persistencia->gravar(veiculo);
		else return false;
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}//fim alterar


#endif /*CONTROLEVEICULO_H_*/
