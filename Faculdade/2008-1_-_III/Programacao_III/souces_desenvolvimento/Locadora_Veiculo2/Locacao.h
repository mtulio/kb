#ifndef LOCACAO_H_
#define LOCACAO_H_

#include"ItemPersistencia.h"

class Locacao: public ItemPersistencia
{
	//atributos
private:
	int idCliente;
	int idVeiculo;
	int kmInicial;
	int kmFinal;
	int valorPorKm;
	int valorPago;
	bool devolvido; // serve para nao devolver um filme duas vezes
		
	//metodos
	public:
	Locacao():
		ItemPersistencia(0,2),
		idCliente(0),
		idVeiculo(0),
		kmInicial(0),
		kmFinal(0),
		valorPorKm(0),
		valorPago(0),
		devolvido(true)
		{}
		
	Locacao(int identificador): 
		ItemPersistencia(identificador,2),
		idCliente(0),
		idVeiculo(0),
		kmInicial(0),
		kmFinal(0),
		valorPorKm(0),
		valorPago(0),
		devolvido(true)
		{}
		
	~Locacao(){};
	
	void materializar(const std::string &linha);
	std::string desmaterializar()const;
		
	int obterIdCliente() {return idCliente;}
	void atribuirIdCliente (int idCliente) {this->idCliente=idCliente;}
	
	int obterIdVeiculo() {return idVeiculo;}
	void atribuirIdVeiculo(int idVeiculo) {this->idVeiculo=idVeiculo;}
	
	int  obterKmInicial() {return kmInicial;}
	void atribuirKmInicial(int kmInicial) {this->kmInicial=kmInicial;}
	
	int obterKmFinal() {return kmFinal;}
	void atribuirKmFinal(int kmFinal) {this->kmFinal=kmFinal;}
	
	int obterValoPorKm()const {return valorPorKm; }
	void atribuirValorPorKm(int valorPorKm){ this->valorPorKm = valorPorKm;}
	
	int obterValorPago() { return valorPago; }
	void atribuirValorPago(int valorPago) { this->valorPago = valorPago; }
	
	bool obterDevolvido()const {return devolvido; }
	void atribuirDevolvido(bool devolvido) {this->devolvido = devolvido; }
	
};//fim da calsse locacao

#endif /*LOCACAO_H_*/
