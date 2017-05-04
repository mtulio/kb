#include"ControleLocacao.h"

bool ControleLocacao::incluirLocacao(Locacao *locacao)
{
	try{
		return persistencia->gravar(locacao);
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch		
}// fim da classe Incluir

bool ControleLocacao::consultarLocacao(Locacao *locacao)
{
	try{
		return persistencia->recuperar(locacao);		
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}// fim da calsse consultar


bool ControleLocacao::alterarLocacao(Locacao *locacao)
{
	try{
		Locacao locacaoAux( locacao->obterIdentificador() );
		if(persistencia->remover(&locacaoAux)) return persistencia->gravar(locacao);
		else return false;
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}//fim alterar
