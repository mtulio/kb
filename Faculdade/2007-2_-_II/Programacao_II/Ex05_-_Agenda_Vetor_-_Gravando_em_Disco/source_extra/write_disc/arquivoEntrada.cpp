#include<iostream>
#include<string>
#include<fstream>

int main(void)
{// inicio do programa
	
	std::string nomeDoArquivoNoDisco;
	std::cout<<std::endl<<"Nome do Arquivo: ";
	std::cin>>nomeDoArquivoNoDisco;
	
	// criando um arquivo de entrada
	std::ifstream arquivo;///vai ser usado na busca, pois vc so quer ler o arquivo
	
	// abrindo um arquivo de entrada
	arquivo.open(nomeDoArquivoNoDisco.c_str());//
	
	
	//eof, verifica se vc xegou no fim do aqruivo
	
	// verificando erro de abertura do arquivo de entrada
	if(!arquivo.is_open()){
		std::cout<<std::endl<<"ERRO - Arquivo nao existe";
		exit(1);
	}
	
	system("clear");
	std::cout<<"ARQUIVO DE ENTRADA:  "<<nomeDoArquivoNoDisco;
	std::cout<<std::endl<<std::endl;
	std::string linha;
	
	// lendo do arquivo
	getline(arquivo,linha);//pegando a 1 linha ate achar o endl
	int cont=1;
	// Teste de fim do arquivo
	while(!arquivo.eof()){//perguntando se xegou no fim do arquivo, ate axar...
		//coontrola o fim do arquivo
		std::cout<<cont<<" "<<linha<<std::endl;
		cont++;
		//lendo do arquivo
		getline(arquivo,linha);
	}
	std::cout<<std::endl<<std::endl;
	
	// fechado o arquivo de entrada
	arquivo.close();
	
	
	getchar();getchar();
}//fim do programa;
