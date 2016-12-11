#ifndef VEICULO_H_
#define VEICULO_H_

#include<string>

#include"ItemPersistencia.h"

class Veiculo: public ItemPersistencia
{
private:
	std::string modelo;
	std::string marca;
	std::string placa;
	float valorDeCompra;
	float valorDeVenda;
		
public:
	Veiculo(): ItemPersistencia(0){tipoDaClasse = 2; };
	
	Veiculo(unsigned int identificador, std::string const &modelo, std::string const &marca, 
			std::string const &placa, float valorDeCompra, float valorDeVenda):
				ItemPersistencia(identificador),
				modelo(modelo),
				marca(marca),
				placa(placa),
				valorDeCompra(valorDeCompra),
				valorDeVenda(valorDeVenda)
				{
					tipoDaClasse = 2;
				}
	
	~Veiculo(){};
	
	std::string obterModelo()const { return modelo;};
	void atribuirModelo(std::string &nome){ this->modelo = modelo;}
	
	std::string obterMarca()const { return marca;}
	void atribuirMarca(std::string marca){ this->marca = marca; }
	
	std::string obterPlaca()const { return placa;}
	void atribuirPlaca(std::string placa){ this->placa = placa; }
	
	float obterValorDeCompra()const { return valorDeCompra;};
  	void atribuirValorDeCompra(float valorDeCompra){ this->valorDeCompra = valorDeCompra; }
	
	float obterValorDeVenda()const { return valorDeVenda;};
  	void atribuirValorDeVenda(float valorDeVenda){ this->valorDeVenda = valorDeVenda; }
	
	//repare nos & sao porque sao parametros de saida
	void obter(unsigned int &identificador, std::string const &modelo, std::string const &marca, 
			std::string const &placa, float &valorDeCompra, float &valorDeVenda)const;
	
	void atribuir(unsigned int identificador, std::string const &modelo, std::string const &marca, 
			std::string const &placa, float valorDeCompra, float valorDeVenda);
	
	void materializar(std::string const &str);
	std::string desmaterializar()const;
	
	std::string obterModelo()const { return modelo; };
	
};//fim da classe Veiculo

void Veiculo::obter(unsigned int &identificador, std::string const &modelo, std::string const &marca, 
		std::string const &placa, float &valorDeCompra, float &valorDeVenda)const
{
	identificador = this->identificador;
	modelo = this->modelo;
	marca = this->marca;
	placa = this->placa;
	valorDeCompra = this->valorDeCompra;
	valorDeVenda = this->valorDeVenda;
}

void Veiculo::atribuir(unsigned int identificador, std::string const &modelo, std::string const &marca, 
			std::string const &placa, float valorDeCompra, float valorDeVenda)
{
	this->identificador = identificador;
	this->modelo = modelo;
	this->marca = marca;
	this->placa = placa;
	this->valorDeCompra = valorDeCompra;
	this->valorDeVenda = valorDeVenda;
}

void Veiculo::materializar(std::string &str)
{
	/* Atributos para conversao
	 * unsigned int identificador	 
	 * string modelo;
	 * string marca; 
	 * string placa;
	 * float valorDeCompra;
	 * float valorDeVenda;	
	*/
	
	unsigned int aux=0, pos=0;
		
	/*materializando o identificador*/
	for(; str[pos]!=';' ; pos++) aux = aux*10 + (str[pos]-48);
	identificador = aux;
		
	/*Materializando o modelo*/
	std::string strAux = "";
	for(pos++ ; str[pos]!=';' ; pos++) strAux += str[pos];
	modelo = strAux;
		
		
	/*Materializando o marca*/
	strAux = "";
	for(pos++ ; str[pos]!=';' ; pos++) strAux += str[pos];
	marca = strAux;
	
	/*Materializando o placa*/
	strAux = "";
	for(pos++ ; str[pos]!=';' ; pos++) strAux += str[pos];
	placa = strAux;
	
	
		
	/*Materializando o VAlor De Compra*/
	float auxFloat;
	for(pos++ ; str[pos]!= ';' ; pos++) {
			//std::cout<<"1 - pos: "<<pos<<" | str[pos]: "<<str[pos]<<" | aux2: "<<aux2<<std::endl;
			aux2 = aux2*10 + (str[pos]-48);
			//std::cout<<"2 - pos: "<<pos<<" | str[pos]-48: "<<(str[pos]-48)<<" | aux2: "<<aux2<<std::endl;
			
	}
	valorDeCompra = aux2;
		
		
	/*Materializando a carteira de Valor de Venda*/
	auxFloat=0;
	for(pos++ ; str[pos]!= ';' ; pos++) {
		auxFloat = auxFloat*10 + (str[pos]-48);
	}
	valorDeVenda = auxFloat;
}


std::string Veiculo::desmaterializar()const
{
	/* Atributos para conversao
		 * unsigned int identificador	 
		 * string modelo;
		 * string marca; 
		 * string placa;
		 * float valorDeCompra;
		 * float valorDeVenda;	
		*/
	
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
		
	/*Desmaterializando o modelo*/
	linha += modelo;
	linha += ";";
		
	/*Desmaterializando o marca*/
	linha += marca;
	linha += ";";
		
	/*Desmaterializando o placa*/
	linha += placa;	
	linha += ";";
		
	/*Desmaterializando a valorDeCompra*/
	float auxFloat;
	for(unsigned int auxFloat=valorDeCompra; auxFloat; ){
		char letra = (aux%10)+48;
		auxString = letra + auxString;
		auxFloat = auxFloat/10;
	}
	linha += auxString;	
	linha += ";";
		
	/*Desmaterializando o valorDeVenda*/
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
}

#endif /*VEICULO_H_*/
