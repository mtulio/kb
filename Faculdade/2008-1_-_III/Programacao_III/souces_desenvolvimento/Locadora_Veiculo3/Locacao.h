// PRODUCT BY ANDRE
#ifndef LOCACAO_H_
#define LOCACAO_H_

#include<string>
#include"ItemPersistencia.h"

class Locacao: public ItemPersistencia 
{ //inicio da classe
	
	//atributos
	private:
	int idCliente;
	int idVeiculo;
	int kmInicial;
	int kmFinal;
	int valorPago;
	bool situacao;
	
	//metodos
	
	public:
	
	Locacao():
		ItemPersistencia(0,2),
		idCliente(0),
		idVeiculo(0),
		kmInicial(0),
		kmFinal(0),
		valorPago(0),
		situacao(false)
		{}
		
	Locacao(int identificador): 
		ItemPersistencia(identificador,2),
		idCliente(0),
		idVeiculo(0),
		kmInicial(0),
		kmFinal(0),
		valorPago(0),
		situacao(false)
		{}
	
	virtual ~Locacao(){};
	
	int obterIdCliente() {return idCliente;}
	void atribuirIdCliente (int idCliente) {this->idCliente=idCliente;}
	
	int obterIdVeiculo() {return idVeiculo;}
	void atribuirIdVeiculo(int idVeiculo) {this->idVeiculo=idVeiculo;}
	
	int  obterKmInicial() {return kmInicial;}
	void atribuirKmInicial(int kmInicial) {this->kmInicial=kmInicial;}
	
	int obterKmFinal() {return kmFinal;}
	void atribuirKmFinal(int kmFinal) {this->kmFinal=kmFinal;}
	
	bool obterSituacao() {return situacao;}
	void atribuirSituacao(bool situacao) {this->situacao=situacao;}
	
	std::string desmaterializar()const;
	void materializar(const std::string linha);
};


#endif /*LOCACAO_H_*/
