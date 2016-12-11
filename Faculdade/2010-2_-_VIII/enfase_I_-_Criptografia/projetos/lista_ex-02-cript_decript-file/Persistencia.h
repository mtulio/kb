//Arquivo: Persistencia.h

#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<string>
#include<cstdio>

using namespace std;

class Persistencia
{
private:
	string nomeArq;
	FILE *arquivo;

public:
	//o construtor abre o arquivo de acordo com os parametros informados
	//e o arquivo fica aberto em memoria
	Persistencia(string nomeArquivo, char tipo): nomeArq(nomeArquivo)
	{
		if(tipo == 'w') { arquivo = fopen(nomeArq.c_str(), "+w"); }
		else if(tipo == 'r') { arquivo = fopen(nomeArq.c_str(), "+r"); }

	}
	//O destrutor se encarrega de fechar o arquivo automaticamente
	~Persistencia()
	{
		fclose(arquivo);
	}
	char obterCaracter(); //obtem cada caractere do arquivo - um por vez
	bool gravarCaracter(char carac); //grava um caracter no arquivo
	bool fimDoArquivo(){ //informa o fim do arquivo
		if (arquivo!= NULL) 
			return false; 
		else return true; 
	}
};//fim classe

#endif /*PERSISTENCIA_H_*/

//Retorna um Caracter lido do arquivo
char Persistencia::obterCaracter()
{
	char temp, caract;
	temp = fscanf(this->arquivo,"%c",&temp);
	caract = temp;
	return caract;
}//fim obter

//Grava um caracter no arquivo
bool Persistencia::gravarCaracter(char carac)
{
	fprintf(arquivo,"%c",carac);
	return true;
}//fim gravar
