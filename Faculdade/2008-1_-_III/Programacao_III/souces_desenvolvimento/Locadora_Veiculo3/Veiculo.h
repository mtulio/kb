// PRODUCT BY MARCO TULIO
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
		// foi usado int para o valor de compra e de venda para facilitar na hora 
		// de materializar e desmaterializar
		int valorDeCompra;
		int valorDeVenda;
	public:
		
		Veiculo(): 
			ItemPersistencia(0,1),
			modelo(""),
			marca(""),
			placa(""),
			valorDeCompra(0),
			valorDeVenda(0)
			{}
			
		Veiculo(int identificador):
			ItemPersistencia(identificador,1),
			modelo(""),
			marca(""),
			placa(""),
			valorDeCompra(0),
			valorDeVenda(0)
			{}
			
		// OBTER E ATRIBUIR PARA CADA ATRIBUTO
		std::string obterModelo()const { return modelo; }
		std::string obterMarca()const { return marca; }
		std::string obterPlaca()const { return placa; }
		int obterValorDeCompra()const { return valorDeCompra; }
		int obterValorDeVenda()const { return valorDeVenda; }
		
		void atribuirModelo(std::string modelo) { this->modelo = modelo; }
		void atribuirMarca(std::string marca) { this->marca = marca; }
		void atribuirPlaca(std::string placa) { this->placa = placa; }
		void atribuirValorDeCompra(int valorDeCompra) { this->valorDeCompra = valorDeCompra; }
		void atribuirValorDeVenda(int valorDeVenda) { this->valorDeVenda = valorDeVenda; }
		
		void materializar(std::string linha);
		std::string desmaterializar()const; 
};

#endif /*VEICULO_H_*/
