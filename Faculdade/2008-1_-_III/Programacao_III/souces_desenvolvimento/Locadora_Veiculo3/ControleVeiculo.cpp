#include"ControleVeiculo.h"

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
