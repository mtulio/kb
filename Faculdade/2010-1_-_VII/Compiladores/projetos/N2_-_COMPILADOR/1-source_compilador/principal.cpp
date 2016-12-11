/*
* Pontificia Universidade Catolica de Goias, PUC-GO
* Curso: Engenharia da Computação
* Disciplina: Compiladores
* Semestre: 2010/1
* Programa: Implementação de um Compilador  simplificado: Fase I
* Integrantes:
* - Marco Túlio Rodrigues Braga 
* - Gustavo de Andrade Rosa
* - Adão Junior
* - Juliane Barbosa Maximo
* - Marcus Vinissius Costa Rodrigues
* - Marco Aurelio de Faria
*
* Detalhes: Programa principal recebe um nome do arquivo do sistema de arquivos 
* como parametro e instancia um objeto da classe Automato informando esse arquivo
* gerando também um arquivo temporario em C com nome do arquivo original concatenado
* no suffixo a seguinte string: .c. Logo após é informado e impresso as informações
* geradas pelo automato.
*/
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

	Automato automato(argv[1]);
	msgRetorno = automato.iniciarAutomato();
//	msgRetorno = automato.iniciarAutomato(nomeDoArquivo);
	if(msgRetorno!=("-1")) cout<<msgRetorno<<endl;
	
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
