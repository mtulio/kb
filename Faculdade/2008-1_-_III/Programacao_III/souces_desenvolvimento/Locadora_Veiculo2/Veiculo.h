#ifndef VEICULO_H_
#define VEICULO_H_

#include"ItemPersistencia.h"

class Veiculo: public ItemPersistencia
{
private:
	std::string modelo;
	std::string marca;
	std::string placa;
	// foi usado int para o valor de compra e de venda para facilitar na hora 
	// de materializar e desmaterializar
	int valorDeCompra;
	int valorDeVenda;
	bool situacao;
public:
		
	Veiculo(): 
		ItemPersistencia(0,1),
		modelo(""),
		marca(""),
		placa(""),
		valorDeCompra(0),
		valorDeVenda(0),
		situacao(false)
		{}
			
	Veiculo(int identificador):
		ItemPersistencia(identificador,1),
		modelo(""),
		marca(""),
		placa(""),
		valorDeCompra(0),
		valorDeVenda(0),
		situacao(false)
		{}
		
		void materializar(const std::string &linha);
		std::string desmaterializar()const; 
	
		// OBTER E ATRIBUIR PARA CADA ATRIBUTO
		std::string obterModelo()const { return modelo; }
		void atribuirModelo(std::string &modelo) { this->modelo = modelo; }
		
		std::string obterMarca()const { return marca; }
		void atribuirMarca(std::string &marca) { this->marca = marca; }
		
		std::string obterPlaca()const { return placa; }
		void atribuirPlaca(std::string &placa) { this->placa = placa; }
		
		int obterValorDeCompra()const { return valorDeCompra; }
		void atribuirValorDeCompra(int valorDeCompra) { this->valorDeCompra = valorDeCompra; }
		
		int obterValorDeVenda()const { return valorDeVenda; }
		void atribuirValorDeVenda(int valorDeVenda) { this->valorDeVenda = valorDeVenda; }
		
		bool obterSituacao()const { return situacao;}
		void atribuirSituacao(bool situacao) { this->situacao = situacao; }		
	
};//fim da classe Veiculo

#endif /*VEICULO_H_*/
