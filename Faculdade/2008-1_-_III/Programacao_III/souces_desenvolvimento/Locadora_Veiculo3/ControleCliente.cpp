#include"ControleCliente.h"

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
