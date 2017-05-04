#ifndef CLIENTE_H_
#define CLIENTE_H_

//#include<string>
#include"ItemPersistencia.h"


// TIPO DA CLASSE EH 0

//using namespace std;

class Cliente: public ItemPersistencia
{
private:
	std::string nome;
	std::string endereco;
	long telefone;
	long cnh;
	long cpf;

public:
	Cliente():
		ItemPersistencia(0,0),
		nome(""),
		endereco(""),
		telefone(0),
		cnh(0),
		cpf(0)
		{}
	
		
	Cliente(int identificador):
		ItemPersistencia(identificador, 0),
		nome(""),
		endereco(""),
		telefone(0),
		cnh(0),
		cpf(0)
		{}
	
	~Cliente(){}
	
	void materializar(const std::string &linha);
	std::string desmaterializar()const;
	
	std::string obterNome()const {return nome;}
	void atribuirNome(const std::string nome) {this->nome=nome;}
		
	std::string obterEndereco()const {return endereco;}
	void atribuirEndereco(const std::string endereco) { this->endereco = endereco;}
	
	unsigned long obterTelefone()const {return telefone;}
	void atribuirTelefone(unsigned long telefone) {this->telefone=telefone;}
		
	unsigned long obterCnh()const {return cnh;}
	void atribuirCnh(unsigned long cnh) {this->cnh=cnh;}
	
	unsigned long obterCpf()const {return cpf;}
	void atribuirCpf(unsigned long cpf) {this->cpf=cpf;}
	
};// fim class cliente



#endif /*CLIENTE_H_*/
