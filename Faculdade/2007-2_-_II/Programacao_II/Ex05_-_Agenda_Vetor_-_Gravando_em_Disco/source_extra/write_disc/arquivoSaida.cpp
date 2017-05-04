//somente quer escrever nele
#include<iostream>
#include<string>//usada pra fazer entrada dos dados
#include<fstream>//habilitando a biblioteca

int main(void)
{// inicio do programa
	
	std::string nomeDoArquivoNoDisco;//
	std::cout<<std::endl<<"Nome do Arquivo: ";//
	std::cin>>nomeDoArquivoNoDisco;//leitura do nome do arquivo
	
	// criando um arquivo de saida
	std::ofstream arquivo;//nome q sera usado no interior do programa
	
	// abrindo um arquivo de saida
	arquivo.open(nomeDoArquivoNoDisco.c_str());//abrindo um arquivo , segundo o nome q o ususario digitar
	//,c_str() > esse kra transforma a string de um objeto da lasse string para um objeto da string primitiva em C
	
	// verificando erro de abertura do arquivo de saida
	if(!arquivo.is_open()){//se n for criado vaxa do programa  arquivo.falue()>> a mesma coisa
		std::cout<<std::endl<<"ERRO - Arquivo nao criado";
		exit(1);
	}
	
	std::string linhas;//perguntando qtas linhas o user vai digitar
	std::cout<<"Quantidade de linhas: ";
	int qLinhas;
	std::cin>>qLinhas;
	std::cin.ignore();
	system("clear");
	std::cout<<"ARQUIVO DE SAIDA:  "<<nomeDoArquivoNoDisco;
	std::cout<<std::endl<<"QUANTIDADE DE LINHAS: "<<qLinhas<<std::endl; 
	for(int cont=1;cont<=qLinhas;cont++){
		std::cout<<cont<<" ";// lendo oa arquivo digitado 
		getline(std::cin,linhas);
		
		// escrevendo no arquivo de saida
		arquivo<<linhas<<std::endl;
	}//guarda a linha e pula pra linha de baixo com o endl
	
	// fechado o arquivo de saida
	arquivo.close();
	getchar();getchar();
	
}//fim do programa;
