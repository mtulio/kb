#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<fstream>
#include<iostream>
#include<string>

class Persistencia
{
private:
	std::string nomeDoArquivo;
	unsigned int ultimaLinhaLida;
	unsigned int qtdTotalDeLinhas;
	
public:
	
	unsigned int getUltimaLinhaLida(){ return this->ultimaLinhaLida; }
	unsigned int getQtdTotalDeLinhas() { return this->qtdTotalDeLinhas; }

	Persistencia(std::string nomeDoArquivo):ultimaLinhaLida(0),qtdTotalDeLinhas(0)
	{
		this->nomeDoArquivo=nomeDoArquivo;
		std::fstream arquivo;
		arquivo.open(nomeDoArquivo.c_str(),std::ios::in);
		if(!arquivo.is_open()) arquivo.open(nomeDoArquivo.c_str(),std::ios::out|std::ios::trunc);//..criara um novo
		
		while(!arquivo.eof())
		{ 
			//std::cout<<"QTD total de linhas: "<<qtdTotalDeLinhas<<std::endl;
			this->qtdTotalDeLinhas++; 
			std::string linha;
			getline(arquivo,linha);

		}
		qtdTotalDeLinhas-=1; //so para corrigir o bug de contar uma linha a mais	
	
		arquivo.close();
		std::string strTemp = nomeDoArquivo+".c";
		std::remove(strTemp.c_str());
	}//fim construtor
	
	bool fimDoArquivo()
	{ 
		//std::cout<<"QTD total de linhas: "<<qtdTotalDeLinhas<<std::endl;
		if(qtdTotalDeLinhas==0) return true;
		if(this->ultimaLinhaLida == this->qtdTotalDeLinhas) return true;
		else return false;
	}//fim fim do arquivo
	
	std::string lerProxLinhaDoArquivo()
	{
		int i=0, j=0;
		std::string linhaAux, strTemp;
		//2 casos:
		// - se for a primeira linha
		// - se for as demais
		
		//caso 1
		if(ultimaLinhaLida==0){
			std::ifstream arquivo2;
			arquivo2.open(nomeDoArquivo.c_str(),std::ios::in);
			getline(arquivo2,linhaAux);
			arquivo2.close();
			
			ultimaLinhaLida++;
			return linhaAux;
		}//fim if
		//caso 2
		else { 
			for(i=0; i<this->qtdTotalDeLinhas; i++){
				
				//std::cout<<"Pers-lerProx-ifelse-For1"<<std::endl;
				
				//tenso de entender isso...mas basicamente eh que o indice comeca 
				//com 0 e a ultima linha comeca a contar com 1, entao o indice sempre estara
				//um campo a frete que o valor de ultimaLinhaLida
				if(i==(ultimaLinhaLida)){
					//std::cout<<"Pers-lerProx-ifelse-For1-if1"<<std::endl;
					std::ifstream arquivo2;
					arquivo2.open(nomeDoArquivo.c_str(),std::ios::in);
					//ler cada linha do arquivo ate encontrar a desejada
					for(j=0;!arquivo2.eof();j++){
						//std::cout<<"Pers-lerProx-ifelse-For1-if1-for1"<<std::endl;
						if(j==i){
							//std::cout<<"Pers-lerProx-ifelse-For1-if1-for1-if1"<<std::endl;
							getline(arquivo2,linhaAux);
						}
						else {
							//std::cout<<"Pers-lerProx-ifelse-For1-if1-for1-ifelse1"<<std::endl;
							getline(arquivo2,strTemp);
						}//fim else
					}//fim for
					arquivo2.close();
					ultimaLinhaLida++;
					return linhaAux;
				}//fim if
			}//fim for
		}//fim else 
	}//fim ler proxima linha do arquivo

	static std::string gravarLinha(std::string arquivoStr, std::string linha)
	{
		//std::cout<<"\n\t Dentro da persistencia - antes gravar 1 linha"<<std::endl;
		//std::cout<<"\n\t Dentro da persistencia - arquivoStr="<<arquivoStr<<"\nlinha="<<linha<<std::endl;
		std::ofstream arquivo;
		
		arquivo.open(arquivoStr.c_str(),std::ios::app);
		if(!arquivo.is_open()) arquivo.open(arquivoStr.c_str(),std::ios::out|std::ios::trunc);
		
		arquivo<<linha;
		
		arquivo.close();
		//std::cout<<"\n\t Dentro da persistencia - FIM GRAVAR"<<std::endl;	
		
		return("-1");
	}//fim gravar
	
};//fim classe persistencia

#endif /*PERSISTENCIA_H_*/
