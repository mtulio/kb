// PRODUCT BY ANDRE
#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "ItemPersistencia.h"
//#include "Persistencia.h"
#include <string>

class Cliente : public ItemPersistencia {

	//atributos
	private:
	
	std::string nome;
	std::string endereco;
	unsigned long telefone;
	unsigned long cpf;
	unsigned long cnh;
	

	//metodos
	public:
	Cliente():
		ItemPersistencia(0,0),
		nome(""),
		endereco(""),
		telefone(0),
		cpf(0),
		cnh(0) 
		{}
		
	Cliente(int identificador):
		ItemPersistencia(identificador,0), 
		nome(""),
		endereco(""),
		telefone(0),
		cpf(0),
		cnh(0) 
		{}
	
	~Cliente(){} //Destrutor Default
	
	
	
	std::string obterNome()const {return nome;}
	void atribuirNome(const std::string nome) {this->nome=nome;}
	
	unsigned long obterTelefone()const {return telefone;}
	void atribuirTelefone(unsigned long telefone) {this->telefone=telefone;}
	
	unsigned long obterCnh()const {return cnh;}
	void atribuirCnh(unsigned long cnh) {this->cnh=cnh;}
	
	unsigned long obterCpf()const {return cpf;}
	void atribuirCpf(unsigned long cpf) {this->cpf=cpf;}
	
	std::string desmaterializar()const;
	void materializar(const std::string linha);
	

};
	
#endif /*CLIENTE_H_*/

