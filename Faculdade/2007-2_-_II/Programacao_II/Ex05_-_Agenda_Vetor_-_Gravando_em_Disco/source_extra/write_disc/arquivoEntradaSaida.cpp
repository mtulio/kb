// e vc que vai dizer o que vai fazer...
#include<iostream>
#include<fstream>
#include<string>
int main(void)
{

	std::string nomeDoArquivoNoDisco;
	std::cout<<std::endl<<"Nome do Arquivo: ";
	std::cin>>nomeDoArquivoNoDisco;
	
	// criando um arquivo de entrada/saida
	std::fstream arquivo;
	
	system("clear");
	std::cout<<std::endl<<" Menu de Opcao para Arquivo Texto";
	std::cout<<std::endl<<"1 - Anexar no arquivo";
	std::cout<<std::endl<<"2 - Mostrar o arquivo";
	std::cout<<std::endl<<"3 - Criar novo arquivo";
	std::cout<<std::endl<<"Opcao: ";
	int opcao;
	std::cin>>opcao;
	switch(opcao){// inicio switch
		case 1:{// inicio case 1
			//anexar no fim do arquivo
			
						// abrindo o arquivo no final
						arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::app);//to dizendo q quero um arquivo de saida no final dele
												
						// verificando erro de abertura do arquivo de saida
						if(!arquivo.is_open()){//conseguiu abrir?!
							std::cout<<std::endl<<"ERRO - Arquivo nao criado";
							exit(1);
						}
						std::string linhas;
						std::cout<<"Quantidade de linhas: ";
						int qLinhas;
						std::cin>>qLinhas;
						std::cin.ignore();
						system("cls");
						std::cout<<"ARQUIVO DE SAIDA - ANEXAR:  "<<nomeDoArquivoNoDisco;
						std::cout<<std::endl<<"QUANTIDADE DE LINHAS: "<<qLinhas<<std::endl; 
						char setaDireita=10;//10 eh o decima para o enter
                        for(int cont=1;cont<=qLinhas;cont++){//ler do teclado e escreve no arquivo
								std::cout<<cont<<" ";
								getline(std::cin,linhas);
		
								// escrevendo no arquivo de saida
								//arquivo<<linhas<<std::endl;
								arquivo<<linhas<<setaDireita;//
						}
	
						// fechado o arquivo de saida
						arquivo.close();
						break;
		}// fim case 1
						
		case 2:{// inicio case 2
			//apenas ler o conteudo no arquivo e escrever na tela
						// abrindo o arquivo no final
						arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
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
						getline(arquivo,linha);
						int cont=1;
						// teste de fim de arquivo
						while(!arquivo.eof()){
							std::cout<<cont<<" "<<linha<<std::endl;
							cont++;
							getline(arquivo,linha);
						}
						std::cout<<std::endl<<std::endl;
	
						// fechado o arquivo de saida
						arquivo.close();
						break;
		}// fim case 2
		case 3:{// inicio case 3
			//novo arquivo, saida
						// abrindo o arquivo no final
						arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
												
						// verificando erro de abertura do arquivo de saida
						if(!arquivo.is_open()){
							std::cout<<std::endl<<"ERRO - Arquivo nao criado";
							exit(1);
						}
						std::string linhas;
						std::cout<<"Quantidade de linhas: ";
						int qLinhas;
						std::cin>>qLinhas;
						std::cin.ignore();
						system("clear");
						std::cout<<"ARQUIVO DE SAIDA - ANEXAR:  "<<nomeDoArquivoNoDisco;
						std::cout<<std::endl<<"QUANTIDADE DE LINHAS: "<<qLinhas<<std::endl; 
						for(int cont=1;cont<=qLinhas;cont++){
								std::cout<<cont<<" ";
								getline(std::cin,linhas);
		
								// escrevendo no arquivo de saida
								arquivo<<linhas<<std::endl;
						}
	
						// fechado o arquivo de saida
						arquivo.close();
						break;
			
		}// fim case 3
						
						
	}// fim switch
	getchar();getchar();
	
}


//trunc elimina o conteudo do arquivo
//foi mudada a forma de abertura

// para o trabalho de agenda
/* vai mexer apenas na classe persistencia
 * e na classe pessoa pra transformar em string 
 * 
 * 
*/
/*manipulação de caracteres:
 * A virar a >> A+32 = a    >> a-32=A ( EH O TREM MAIS IDIOTA DO MUNDO ) TA? =) Bom! isso sao as letras, eh tranquilo.
 * e fika mais interessante o processo.
 * 0=48
 * 9=55
 * 23/10 = resto=3  qquo=2   pega o rsto e soma 48  
 * 2/10  = resto 2 quocinte = 0  ....  p/ transformar pra tabela ascII basta apenas somar 48
 * "23"
 * VET[0]->'2'
 * VET[1]-> '3'
 * 
*/
