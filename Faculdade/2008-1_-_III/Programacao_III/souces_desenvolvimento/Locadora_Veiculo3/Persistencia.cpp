#include"Persistencia.h"

//***************************************************************************************************
Persistencia::Persistencia()
{//inicio do construtor
	try{
		//LEMBRANDO QUE A INICIACAO DOS ATRIBUTOS DO OBJETO DEVE SER ATRAVES DO CONSTRUTOR
		// ENTAO:
		// ESTA CRIANDO UM VETOR DE 3 POSICOES QUE A CADA POSICAO IDENTIFICARA O TIPO DA CLASSE,
		// EXEMPLO: NA POSICAO 0, TEMOS A CLASSE CLIENTE - QUEM IDENTIFICA ISSO E O ATRIBUTO tipoDaClasse 
		// DA CLASSE ItemPersistencia. 
		// NA POSICAO 1 E 2 TEMOS AS CLASSES Veiculo e Locacao RESPECTIVAMENTE.
	
		// ESSA LINHA QUER DIZER QUE NA POSICAO 0 DO VETOR DE OBJETOS DO TIPO MapeadorDeDados TEMOS UM
		// OBJETO DO TIPO MapeadorDeDadosCliente QUE EH FILHO DA CLASSE MapeadorDeDados...
		baseDeDados[0] = new MapeadorDeDadosCliente();
	
		baseDeDados[1] = new MapeadorDeDadosVeiculo();
	
		//baseDeDados[2] = new MapeadorDeDadosLocacao();	
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch
}// fim do construtor

//***************************************************************************************************

// DESTRUTOR
Persistencia::~Persistencia()
{
	//TODA VEZ QUE EH CRIADO UM VETOR SERA PRECISO DELETA-LO
	// deletando ovetor no inicio, EU ACHO, consequentemente deleta-ra todo o restante do vetor
	delete baseDeDados[0]; 	
	
}// fim do destrutor

//***************************************************************************************************

bool Persistencia::gravar(ItemPersistencia *objeto)
{//inicio do metodo gravar
	try{
		// IMPORTANTE: SE ENTENDER ESSE PROCESSO, ENTENDERA TODO O FRAMEWORK, caso ocontrario... PEDE PRA SAIR =D
	
		// 1 - objeto->obterTipoDaClasse(): CHAMADA DO METODO obterTipoDaClasse , para a identificacao 
		//     do tipo da classe (Cliente, Veiculo ou locacao)

		// 2 - baseDeDados[objeto->obterTipoDaClasse()] : APOS Q OBTEVE O TIPO SERA FEITA A IDENTIFICACAO INDO 
		//     NO VETOR DO ATRIBUTO DA CLASSE BaseDeDados

		// 3 - baseDeDados[objeto->obterTipoDaClasse()]->gravarDados(objeto) : QUANDO IDENTIFICADOR NA POSICAO DO VETOR, 
		//     SERA FEITA UMA CHAMADA DO METODO gravarDados DA CLASSE MapeadorDeDados E ENVIANDO COMO PARAMETRO UM 
		//     OBJETO QUE ENTROU COMO PARAMETRO DESSE METODO GRAVAR
	
		// 4 - return baseDeDados[objeto->obterTipoDaClasse()]->gravarDados(objeto): O VALOR DE RETORNO SERA TRUE OU FALSE 
		//     QUE SERA RETORNADO PELO METODO gravarDados.
	
		return baseDeDados[objeto->obterTipoDaClasse()]->gravarDados(objeto);	
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch
}//fim do metodo gravar

//***************************************************************************************************

bool Persistencia::recuperar(ItemPersistencia *objeto)
{
	try{
		// ESSE METODO APENAS IDENTIFICA E ENVIA OS DADOS ( PARAMETRO ) PARA A CLASSE RESPONSAVEL(RECUPERAR DADOS)
		// DA CLASSE MAPEADOR DE DADOS
	
		return baseDeDados[ objeto->obterTipoDaClasse() ]->recuperarDados(objeto);
	}//fim catch
	catch(std::string msg)
	{
		throw msg;
	}//fim catch
}// fim da classe recuperar

//***************************************************************************************************

bool Persistencia::remover(ItemPersistencia *objeto)
{
	try{
	
		// MESMA RESPONSABILIDADE DA CLASSE RECUPERAR
		return baseDeDados[ objeto->obterTipoDaClasse() ]->removerDados(objeto);		
	
	}//fim try
	catch(std::string msg)
	{
		throw msg;
	}//fim catch
}// fim da classe remover

