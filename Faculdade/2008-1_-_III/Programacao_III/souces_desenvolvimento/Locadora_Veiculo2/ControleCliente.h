#ifndef CONTROLECLIENTE_H_
#define CONTROLECLIENTE_H_

#include"Persistencia.h"
#include"Cliente.h"
#include<iostream>

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

bool ControleCliente::incluirCliente(Cliente *cliente)
{
	try{
		// enviando o ponteiro do objeto passado como parametro para a classe
		// persistencia ("Classe unificada")
		
		return persistencia->gravar(cliente);
	}
	catch(std::string msg)
	{
		throw msg;
	}//fim catch		
}// fim da classe Incluir

bool ControleCliente::consultarCliente(Cliente *cliente)
{
	try{
		return persistencia->recuperar(cliente);		
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}// fim da calsse consultar


bool ControleCliente::alterarCliente(Cliente *cliente)
{
	try{
		// criando esse obj aux para fazer a copia do obj passado como parametro
		// ele servira pra verificar se existe no arquivo e depois o excluira do arquivo( o antigo) 
		// SE EXISTIR EH CLARO
		// DEPOIS ENVIARA PRA PERSISTENCIA GRAVAR O NOVO OBJETO(obj alterado) 
		Cliente clienteAux( cliente->obterIdentificador() );
		if(persistencia->remover(&clienteAux)) return persistencia->gravar(cliente);
		else return false;
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch	
}//fim alterar

#endif /*CONTROLECLIENTE_H_*/
