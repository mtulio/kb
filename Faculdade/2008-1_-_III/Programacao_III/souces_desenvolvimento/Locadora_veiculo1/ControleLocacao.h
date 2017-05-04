#ifndef CONTROLELOCACAO_H_
#define CONTROLELOCACAO_H_

#include"Persistencia.h"
#include"Locacao.h"

class ControleLocacao
{
private:
	Persistencia *persistencia;
public:
	ControleLocacao(Persistencia *persistencia):
		persistencia(persistencia){}
	
	bool incluirLocacao(Locacao *locacao);
	bool consultarLocacao(Locacao *locacao);
	bool alterarLocacao(Locacao *locacao);	
};//fim controle locacao


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

#endif /*CONTROLELOCACAO_H_*/
