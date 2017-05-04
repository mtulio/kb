#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<string>
#include<iostream>
#include<fstream>
#include"Cliente.h"

//***********************************************************************************
//			CLASSE MAPEADOR DE DADOS DA PERSISTENCIA
//***********************************************************************************

class MapeadorDeDados
{
	//Metodos
		public:
		   MapeadorDeDados() {};
		   virtual ~MapeadorDeDados(){};
			virtual bool gravarDados(ItemPersistencia *item);
			virtual bool recuperarDados(ItemPersistencia *item);
			virtual bool removerDados(ItemPersistencia *item);
			//  criar
		protected:
			virtual void gravarNoArmazenamento(ItemPersistencia *item)=0;
			virtual bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item) =0;
			virtual void removerNoArmazenamento(ItemPersistencia *item)=0;
};

bool MapeadorDeDados::gravarDados(ItemPersistencia *item)
{
	if(!buscarNoArmazenamento(item->obterIdentificador(),item)) {
		gravarNoArmazenamento(item);
		return true;
	}return false;
}

bool MapeadorDeDados::recuperarDados(ItemPersistencia *item)
{
	if(buscarNoArmazenamento(item->obterIdentificador(),item)) return true;
		else return false;
}

bool MapeadorDeDados::removerDados(ItemPersistencia *item)
{
	if(buscarNoArmazenamento(item->obterIdentificador(),item)){
		removerNoArmazenamento(item);
		return true;
	}
		else return false;
}

//***********************************************************************************
//			CLASSE MAPEADOR DE DADOS DO CLIETNE NA PERSISTENCIA
//***********************************************************************************
class MapeadorDeCliente:  public MapeadorDeDados
{
		private:
			const std::string nomeDoArquivoNoDisco;
	  	public:
	  		MapeadorDeCliente();
	  		void gravarNoArmazenamento(ItemPersistencia *item);
	  		bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item);
	  		void removerNoArmazenamento(ItemPersistencia *item);
};

MapeadorDeCliente::MapeadorDeCliente():
					nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
{
	std::fstream arquivo;
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
	arquivo.close();
}

bool MapeadorDeCliente::buscarNoArmazenamento(unsigned int id, ItemPersistencia *item)
{
	std::fstream arquivo;
	std::string linha;
	Cliente pessoaAux;
	Cliente *pessoa;
	pessoa=static_cast<Cliente *>(item);
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
	getline(arquivo,linha);
	while(!arquivo.eof()){
		pessoaAux.materializar(linha);
		if(id==pessoaAux.obterIdentificador()){
			arquivo.close();
			std::string nome,email;
			unsigned int id;
			long telefone;
			pessoaAux.obter(id,nome,telefone,email);
			pessoa->atribuir(id,nome,telefone,email);
			return true;
		}
		getline(arquivo,linha);
	}
	arquivo.close();
	return false;
}

void MapeadorDeCliente::gravarNoArmazenamento(ItemPersistencia *item)
{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  		Cliente *cliente;
	  		cliente=static_cast<Cliente *>(item);
	  		
	  	//  Gravar no arquivo	
	  		std::ofstream arquivo;
			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);
			
			std::string linha = cliente->desmaterializar();
			arquivo<<linha<<std::endl;
			arquivo.close();		
}


//   ESTOU AQUI

void MapeadorDeCliente::removerNoArmazenamento(ItemPersistencia *item)
{
		// Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
	  	//	Cliente *cliente;
	  	//	cliente=static_cast<Cliente *>(item);
	  	
	  	// Criando Arquivo Auxiliar
	  	std::fstream arquivoAux;	
	  	arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);	
	  		
	  	//  abrindo arquivo Original no inicio	
	  	std::fstream arquivo;
		arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
			
		std::string linha;
		Cliente pessoaAux;	
		unsigned int id= item->obterIdentificador();
		
		getline(arquivo,linha);
		while(!arquivo.eof()){
			pessoaAux.materializar(linha);
			if(id!=pessoaAux.obterIdentificador())arquivoAux<<linha<<std::endl;
			getline(arquivo,linha);
		}
		arquivo.close();	
		arquivoAux.close();
		
		// Apagando arquivo Original
//		std::string comando = "rm "+nomeDoArquivoNoDisco;	
//		system(comando.c_str());
		
		// Renomeia arquivo Auxiliar
//		comando =
			
}


//***********************************************************************************
//			CLASSE PERSISTENCIA
//***********************************************************************************

class Persistencia
{
	//Atributos
		private:
			MapeadorDeDados  *baseDeDados[3];
	//Metodos
		public:
			Persistencia();
			~Persistencia();
			bool gravar(ItemPersistencia *item);
			bool recuperar(ItemPersistencia *item);
			bool remover(ItemPersistencia *item);
			
};

Persistencia::Persistencia()
{
	baseDeDados[0] = new MapeadorDeCliente();
		    	//baseDeDados[1] = new MapeadorFilme();
		    	//baseDeDados[2] = new MapeadorLocacao(); 
}

Persistencia::~Persistencia()
{
				delete baseDeDados[0];
}
			
bool Persistencia::gravar(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->gravarDados(item);
}

bool Persistencia::recuperar(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->recuperarDados(item);
}

bool Persistencia::remover(ItemPersistencia *item)
{
				 return baseDeDados[item->obterTipoDaClasse()]->removerDados(item);
}

#endif /*PERSISTENCIA_H_*/
