#include<iostream>
#include"Persistencia.h"

using namespace std;

int main(void)
{
	
	string msgRetorno, nomeArquivoFonte="fonte.por";
	
	Persistencia persistencia(nomeArquivoFonte);
		
	//cout<<"Ultima Linha Lida: "<<persistencia.getUltimaLinhaLida()<<endl;
    //cout<<"qtdToal de linhas: "<<persistencia.getQtdTotalDeLinhas()<<endl;
		
	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;
	
	//cout<<"Ultima Linha Lida: "<<persistencia.getUltimaLinhaLida()<<endl;
    //cout<<"qtdToal de linhas: "<<persistencia.getQtdTotalDeLinhas()<<endl;

	
	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;


	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;
	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;
	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;

	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;
	cout<<" Prox linha: "<<persistencia.lerProxLinhaDoArquivo()<<endl;

	
	
}//fim programa principal
