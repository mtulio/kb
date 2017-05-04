/*
 * Interface.h
 *
 *  Created on: 11/10/2009
 *      Author: marco
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<string>

using namespace std;

class Interface
{
private:
	unsigned int qtdEstados;
	string* estados[];
	string* transicoesEstados[];
	unsigned int qtdAlfabeto;
	string alfabeto;


public:
Interface();
~Interface();

	void atribuirQtdEstados(unsigned int qtdEstados) { this->qtdEstados=qtdEstados; }
	void obterQtdEstados(unsigned int qtdEstados) { qtdEstados = this->qtdEstados; }

	void atribuirEstados(string estados);
	void obterEstados(string estados);

	void atribuirTransicoesEstados(string transicoesEstados) { this->transicoesEstados=transicoesEstados; }
	void obterTransicoesEstados(string transicoesEstados) { transicoesEstados= this->transicoesEstados; }

	void atribuirQtdAlfabeto(unsigned int qtdAlfabeto) { this->qtdAlfabeto=qtdAlfabeto; }
	void obterQtdAlfabeto(unsigned int qtdAlfabeto) { qtdAlfabeto = this->qtdAlfabeto; }

	void atribuirAlfabeto(string alfabeto) { this->alfabeto=alfabeto; }
	void obterAlfabeto(string alfabeto) { alfabeto = this->alfabeto; }

};


Interface::Interface():
		{
		this->qtdEstados=0;
		this->estados=NULL;
		this->transicoesEstados=NULL;
		this->qtdAlfabeto=0
		this->alfabeto=0;
		this->string="";
		}


void atribuirEstados(string estados);
void obterEstados(string estados);


#endif /* INTERFACE_H_ */
