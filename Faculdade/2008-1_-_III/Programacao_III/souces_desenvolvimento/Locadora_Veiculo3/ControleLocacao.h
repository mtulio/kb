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
};//fim da class ControleLocacao

#endif /*CONTROLELOCACAO_H_*/
