#ifndef CLASSECONTROLE_H_
#define CLASSECONTROLE_H_
#include<string>
#include"classePersistencia.h"
//*****************************************************************
// tem acesso direto a classe persistencia, 
// assim chamando os metodos da mesma...
//*****************************************************************

class Controle
{
	//Atributos
		private:
			Persistencia agendaDePessoas;//istanciando um objeto da classe Persistencia
	//Metodos 
		public: 
			Controle(Persistencia &agendaDePessoas ):
                                  //iniciando o atributo objeto da classe persistencia com o parametro do construtor
                                  agendaDePessoas(agendaDePessoas)
                                  {};
			int incluir(const std::string &nome, unsigned long telefone, const std::string &email);
			bool consultar(const std::string &nome, unsigned long &telefone, std::string &email)const;
			bool excluir(const std::string &nome);
			bool alterar(const std::string &nome, unsigned long telefone, const std::string &email);
			Iterator* listagemGeral(){return agendaDePessoas.obterTodasAsPessoas();}
			Iterator* listagemNome(char letra){return agendaDePessoas.obterTodasAsPessoasNome(letra);}
};

//******************************************************************************************

// tem como funçao receber os nomes como parametro digitados na classe interface
// coloca-los dentro de um objeto
// e chamar o atribuir da classe Peristencia
// retornando um inteiro
int Controle::incluir(const std::string &nome, unsigned long telefone, const std::string &email)
{//a classe controle envia um comando para a classe persistencia para atribuir o nome, telefone e email digitado na classe interface
	Pessoa pessoa(nome,telefone,email);//cria um objeto da classe pessoa para enviar para a persistencia
	int resp;
    resp = agendaDePessoas.atribuir(pessoa);
	return resp;
}

//*********************************************************************************************

bool Controle::consultar(const std::string &nome, unsigned long &telefone, std::string &email)const
{//cria um objeto da classe pessoa e verifica se tem como obter, caso seja afirmativo atribuira os valores as respecttivas variaveis
// O consultar vai obter o nome pesquisado dentro da agenda
//Como eu sei o nome pois eu digitei ele
// so me interessa obter o telefone e o email do nome digitado
		Pessoa pessoa;
		//unsigned long telefoneAux;
//		std::string emailAux;
		if(agendaDePessoas.obter(nome,pessoa)){                       
			telefone=pessoa.obterTelefone();			
			email=pessoa.obterEmail();;
			return true;
		}else return false;
		
}
//***********************************************************************************************

bool Controle::excluir(const std::string &nome)
{//apenas envia um comando para o metodo apagar da classe persistencia
	return agendaDePessoas.apagar(nome);
}


//************************************************************************************************

bool Controle::alterar(const std::string &nome, unsigned long telefone, const std::string &email)
{
	excluir(nome); 
	//primeiro exclui o nome e obtem ele dinovo dentro da agenda com os novos dados alterados
	Pessoa pessoa(nome,telefone,email);
	agendaDePessoas.atribuir(pessoa);
	return true;
}
			
#endif /*CLASSECONTROLE_H_*/
