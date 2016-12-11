#ifndef CLIENTE_H_
#define CLIENTE_H_

#include<iostream>
#include<string>

#include"ItemPersistencia.h"

class Cliente: public ItemPersistencia
{
private:
	std::string nome;
	std::string endereco;
	unsigned long telefone;
	unsigned long cnh;
	unsigned long cpf;
	
	
public:
	// Usando a sobrecarga de construtor 
	
	Cliente():ItemPersistencia(0){ tipoDaClasse = 0;};
	
	//FICAR ATENTO PARA OS TIPOS DOS ATRIBUTOS
	// MUITAS DUVIDAS NOS CONSTS
	Cliente(unsigned int identificador, std::string const &nome, std::string const &endereco, 
			unsigned long telefone, unsigned long cnh, unsigned long cpf): 
				//eh preciso criar um objeto da classe ItemPersistencia para conter o ID do cliente, ou coisa assim
				ItemPersistencia(identificador),
				nome(nome),
				endereco(endereco),
				telefone(telefone),
				cnh(cnh),
				cpf(cpf)
		{
			//todo atributo do "pai" deve ser inicializando dentro do bloco de comandos do construtor 
			//membro que o esta utilizando
			tipoDaClasse = 0; 
		}//fim do construtor inline
	
	~Cliente(){}
	
	

	std::string obterNome()const { return nome;};
	void atribuirNome(std::string &nome){ this->nome = nome;}
	
	std::string obterEndereco()const { return nome;}
	void atribuirEndereco(std::string endereco){ this->endereco = endereco; }
	
	unsigned long obterTelefone()const { return telefone;};
  	void atribuir(unsigned long telefone){ this->telefone = telefone; }
	
	unsigned long obterCnh()const{ return cnh;};
 	void atribuirCnh(unsigned long cnh){ this->cnh = cnh;}	

	unsigned long obterCpf()const{ return cpf;};
	void atribuirCpf(unsigned long cpf){ this->cpf = cpf; }

	
	
	//passagem de parametro por referencia porque esta retornando pelo metodo os valores dos atributos
	// ou quze isso, ainda tenho que melhorar ahiuahuahuiha
	void obter(unsigned int &identificador, std::string &nome, std::string &endereco,
			unsigned long &telefone, unsigned long &cnh, unsigned long &cpf)const
	{
		identificador = this->identificador;
		nome = this->nome;
		endereco = this->endereco;
		telefone = this->telefone;
		cnh = this->cnh;
		cpf = this->cpf;
		
	}//fim obter
	
	void atribuir(unsigned int identificador, std::string &nome, std::string &endereco,
			unsigned long telefone, unsigned long cnh, unsigned long cpf)
	{
		this->identificador = identificador;
		this->nome = nome;
		this->endereco = endereco;
		this->telefone = telefone;
		this->cnh = cnh;
		this->cpf = cpf;
	}
	
	
	
	//metodos virtuais do pai
	void materializar(std::string const &str);
	const std::string desmaterializar();
	
};//fim da definição da classe Cliente

// recebe como paramentro os dados e coloca nos seus atributos
void Cliente::materializar(std::string const &str)
{
	
	unsigned int aux=0, 
	             pos=0;
	
	/*materializando o identificador*/
	for(; str[pos]!=';' ; pos++) aux = aux*10 + (str[pos]-48);
	identificador = aux;
	
	/*Materializando o nome*/
	std::string strAux = "";
	for(pos++ ; str[pos]!=';' ; pos++) strAux += str[pos];
	nome = strAux;
	
	
	/*Materializando o endereco*/
	strAux = "";
	for(pos++ ; str[pos]!=';' ; pos++) strAux += str[pos];
	endereco = strAux;
	
	
	/*Materializando o telefone*/
	unsigned long aux2=0; //nao useu aux pois o tipo do telefone eh diferente
	for(pos++ ; str[pos]!= ';' ; pos++) {
		//std::cout<<"1 - pos: "<<pos<<" | str[pos]: "<<str[pos]<<" | aux2: "<<aux2<<std::endl;
		aux2 = aux2*10 + (str[pos]-48);
		//std::cout<<"2 - pos: "<<pos<<" | str[pos]-48: "<<(str[pos]-48)<<" | aux2: "<<aux2<<std::endl;
		
	}
	telefone = aux2;
	
	
	/*Materializando a carteira de motorista*/
	aux2=0;
	for(pos++ ; str[pos]!= ';' ; pos++) {
		aux2 = aux2*10 + (str[pos]-48);
	}
	cnh = aux2;
	
	
	/*Materializando o cpf*/
	aux2=0;
	for(pos++ ; str[pos]!=';' ; pos++) {
		//std::cout<<"1 - pos: "<<pos<<" | str[pos]: "<<str[pos]<<" | aux2: "<<aux2<<std::endl;
		aux2 = aux2*10 + (str[pos]-48);
		//std::cout<<"2 - pos: "<<pos<<" | str[pos]-48: "<<(str[pos]-48)<<" | aux2: "<<aux2<<std::endl;
	}
	cpf = aux2;
	
}// fim do materializar

const std::string Cliente::desmaterializar()
{
	
	std::string linha, auxString;
	
	/*Desmaterializando o identificador*/
	for(unsigned int aux = identificador ; aux ; ){//inicio
	   //Enquanto aux for maior que 0, este laco se repetira
	   char letra = (aux%10) + 48;
	   //usando o metodo de conversao de acordo com a tabela ASCII
	      
	   auxString = letra + auxString;
	   //lembrando que String = String + varString eh diferente de String = VarString + String
	   //a concatenacao da string existente com a nova string eh diferente
		 
	   aux = aux/10;
	   //Apos a conversao do ultimo digito do nro eh feita essa divisao para passar
	   //para o proximo digito
	}//fim for
	linha = auxString;
	
	linha += ";";
	
	/*Desmaterializando o nome*/
	linha += nome;
	linha += ";";
	
	/*Desmaterializando o endereco*/
	linha += endereco;
	linha += ";";
	
	/*Desmaterializando o Telefone*/
	auxString = "";
	//std::string auxStr2;
	for(unsigned int aux=telefone;aux;)
	{//inicio for
	   char letra = (aux%10)+48;
	   auxString = letra + auxString;
	   //std::cout<<" char: "<<letra<<" Aux Str: "<<auxStr2<<std::endl<<std::endl;
	   aux  = aux/10;
	}//fim for   
	linha += auxString;
	linha += ";";
	
	/*Desmaterializando a carteira de Motorista*/
	auxString="";
	for(unsigned int aux=cnh; aux; ){
		char letra = (aux%10)+48;
		auxString = letra + auxString;
		aux = aux/10;
	}
	linha += auxString;	
	linha += ";";
	
	/*Desmaterializando o cpf*/
	auxString ="";
	for(long aux=cpf; aux ; )
	{
		char letra = (aux%10)+48;
		auxString = letra + auxString;
		aux = aux/10;
	}//fim for
	linha += auxString;	
	linha += ";";
	
	return linha;
	
}//fim do desmaterializar


#endif /*CLIENTE_H_*/
