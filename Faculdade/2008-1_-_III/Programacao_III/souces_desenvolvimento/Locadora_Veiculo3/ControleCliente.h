#ifndef CONTROLECLIENTE_H_
#define CONTROLECLIENTE_H_

//a classe string jah faz parte da cliente
#include"Cliente.h"
#include"Persistencia.h"

class ControleCliente
{
	private:
		Persistencia *persistencia;
	public:
		// o construtor recebe como parametro a persistencia que na verdade eh a LOCADORA (SACOU XD)
		// e eh faz-se o atributo apontar para a LOCADORA... 
		// DAI ESSA CLASSE DIRECIONARA E CONVERTERA, O QUE AGORA EH UM CLIENTE PASSADO COMO PARAMETRO
		// DOS METODOS, EM PAI(OU SEJA ITEMPERSISTNCIA) E O MANDARA PARA A PERSISTENCIA
		// AKI EH ONDE COMECOU O PROCESSO DE UNIFICACAO DO FRAMEWORK PARA A PERSSITENCIA
		ControleCliente(Persistencia *persistencia):
			persistencia(persistencia){}
		
		bool incluirCliente(Cliente *cliente);
		bool consultarCliente(Cliente *cliente);
		bool alterarCliente(Cliente *cliente);	
	
};// fim da classe ControleCliente

#endif /*CONTROLECLIENTE_H_*/
