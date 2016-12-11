#include "MapeadorDeDadosCliente.h"

MapeadorDeDadosCliente::MapeadorDeDadosCliente():
					nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeDadosCliente::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	std::fstream arquivo;
	std::string linha;
	Cliente pessoaAux;
	Cliente *pessoa;
	pessoa=static_cast<Cliente *>(objeto);
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	
	getline(arquivo,linha);
	while(!arquivo.eof()){
		pessoaAux.materializar(linha);
		if(id==pessoaAux.obterIdentificador()){
			arquivo.close();
			pessoa->materializar(linha);
			return true;
		}
		getline(arquivo,linha);
	}
	arquivo.close();
	return false;
}

void MapeadorDeDadosCliente::gravarNoArmazenamento(ItemPersistencia *objeto)
{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  		Cliente *cliente;
	  		cliente=static_cast<Cliente *>(objeto);
	  		
	  	//  Gravar no arquivo	
	  		std::ofstream arquivo;
			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);
			
			std::string linha = cliente->desmaterializar();
			arquivo<<linha<<std::endl;
			arquivo.close();		
}

void MapeadorDeDadosCliente::removerNoArmazenamento(ItemPersistencia *objeto)
{
	  	// Criando Arquivo Auxiliar
	  	std::fstream arquivoAux;	
	  	arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);	
	  		
	  	//  abrindo arquivo Original no inicio	
	  	std::fstream arquivo;
		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
		std::string linha;
		Cliente pessoaAux;	
		int id= objeto->obterIdentificador();
		
		getline(arquivo,linha);
		while(!arquivo.eof()){
			pessoaAux.materializar(linha);
			if(id!=pessoaAux.obterIdentificador())  arquivoAux<<linha<<std::endl;
			getline(arquivo,linha);
		}
		arquivo.close();	
		arquivoAux.close();
		
		// Apagando arquivo Original
		std::string comando = "rm "+nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar
		
		// Renomeia arquivo Auxiliar
		comando = "cp  "; // mudar
		comando += "ArquivoTemporario.txt  "; // mudar
		comando += nomeDoArquivoNoDisco;	// mudar
		system(comando.c_str()); // mudar
		
		comando = "rm ";
		comando +="ArquivoTemporario.txt ";	 // mudar
		system(comando.c_str());  // mudar
			
}




