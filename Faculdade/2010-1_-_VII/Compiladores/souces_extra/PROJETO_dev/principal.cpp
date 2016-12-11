#include<iostream>

#include"Automato.h"

using namespace std;

int main(int argc, char **argv)
{
	
	string msgRetorno, nomeDoArquivo = argv[1], nomeDoArquivoC;
	nomeDoArquivoC = nomeDoArquivo;
	nomeDoArquivoC = nomeDoArquivoC + '.';
	nomeDoArquivoC = nomeDoArquivoC + 'c';
	
	if (argc != 2)
	{
		cout << "É ncessário passar somente um parâmetro." << endl;
		return 0;
	}
	//cout<<"Digite o nome do arquivo: ";
	//cin>>nomeDoArquivo;
	
	Automato automato(argv[1]);
	msgRetorno = automato.iniciarAutomato();
//	msgRetorno = automato.iniciarAutomato(nomeDoArquivo);
	if(msgRetorno!=("-1")) cout<<msgRetorno<<endl;
	
//	cout<<endl<<"Estado Atual: "<<automato.getEstadoAtual()<<endl;	


	int estAtual = automato.getEstadoAtual();
	if(estAtual==33) {
                     cout<<"Automato alcancou o estado final. Estado: "<<estAtual<<endl;
                     cout<<"Arquivo em C gerado com sucesso: "<<nomeDoArquivoC<<endl;
                     cout<<"Compilador finalizado."<<endl;
    	}
	else {
          
          Persistencia::apagarArquivo(nomeDoArquivoC);
          cout<<"Arquivo temporario excluido: "<<nomeDoArquivoC<<endl;
          cout<<"Automato NAO alcancou o estado final. Estado atual: "<<estAtual<<endl;
          
	}//fim else if estado final
}//fim programa principal
