#include"MapeadorDeDadosLocacao.h"

using namespace std;

MapeadorDeDadosLocacao::MapeadorDeDadosLocacao():
	nomeDoArquivoNoDisco("ArquivoDeLocacao.txt")
	{
		std::fstream arquivo;
		try{			
			arquivo.open(nomeDoArquivoNoDisco.c_str(), std::ios::in);
			if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc); 
			if(!arquivo.is_open()) throw string("> MpDdLoc-Cst: ERRO AO ABRIR/CRIAR ARQUIVO DE LOCACAO");
			arquivo.close();
		}//fim try
		catch(string msg){
			arquivo.close();
			throw msg;
		}//fim throw	
		
	}//fim construtor

bool MapeadorDeDadosLocacao::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	fstream arquivo;
	try
	{// inicio try
		string linha;
		Locacao locacaoAux;
		Locacao *locacao;
		
		locacao = static_cast<Locacao *>(objeto);
		
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		if(!arquivo.is_open()) throw string("> MpDdLoc-Bsc: ERRO AO ABRIR O ARQUIVO DE LOCACAO");
		
		getline(arquivo, linha);
		
		while(!arquivo.eof())
		{//inicio while
			locacaoAux.materializar(linha);
			if(id == locacaoAux.obterIdentificador()){
				arquivo.close();
				if(arquivo.is_open()) throw string("> MpDdLoc-Bsc: ERRO AO FECHAR O ARQUIVO DE LOCACAO");
				locacao->materializar(linha);
				return true;
			}//fim if
			getline(arquivo, linha);			
		}//fim while
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdLoc-Bsc: ERRO AO FECHAR O ARQUIVO DE LOCACAO");
		return false;		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	}//fim catch	
}//fim do buscar

void MapeadorDeDadosLocacao::gravarNoArmazenamento(ItemPersistencia *objeto)
{
	 ofstream arquivo;
	 try{
	 	Locacao *locacao;
	 	locacao = static_cast<Locacao *>(objeto);
	 	// verificando se oponteiro aponta para um espaco na memoria
	 	if(locacao == 0) throw string("> MpDdLoc-Grv: PONTEIRO NAO ALOCADO / CONVERSAO NAO EFETUADA");
	 	
	 	
	 	arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::app);			
	 	string linha = locacao->desmaterializar(); 
	 	arquivo<<linha<<endl;	 	 		 	
	 	arquivo.close();
	 	if(arquivo.is_open()) throw string("> MpDdLoc-Grv: ERRO AO FECHAR O ARQUIVO DE LOCACAO");
	 	
	 	// FINALIZANDO O METODO 	
	 }//fim try
	 catch(string msg)
	 {
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	 }//fim catch	
}//fim do gravar

void MapeadorDeDadosLocacao::removerNoArmazenamento(ItemPersistencia *objeto)
{
	fstream arquivo, arquivoBackup;
	try{
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		if(!arquivo.is_open()) throw string("> MpDdLoc-Rem: ERRO AO ABRIR O ARQUIVO DE LOCACAO");

		string strArquivoBackup = "ArquivoBackupLocacao.txt";
		arquivoBackup.open(strArquivoBackup.c_str(), ios::out|ios::trunc);
		if(!arquivo.is_open()) throw string("> MpDdLoc-Rem: ERRO AO CRIAR O ARQUIVO DE BACKUP DO LOCACAO");
		// ***********************************************************************************************
		
		string linha;
		Locacao locacaoAux;
		
		// o id jah esta no pai
		int id = objeto->obterIdentificador();

		// ***********************************************************************************************

		getline(arquivo, linha);
		while(!arquivo.eof())
		{
			locacaoAux.materializar(linha);
			if(id != locacaoAux.obterIdentificador())
			{//inicio if
				arquivoBackup<<linha<<endl;
			}//fim if
			getline(arquivo, linha);
		}//fim do while

		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdLoc-Rem: ERRO AO FECHAR O ARQUIVO DE LOCACAO");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdVei-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO LOCACAO");
		// ***********************************************************************************************
		
		remove("ArquivoDeLocacao.txt");
		rename("ArquivoBackupLocacao.txt" , "ArquivoDeLocacao.txt");		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdLoc-Rem: ERRO AO FECHAR O ARQUIVO DE LOCACAO");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdLoc-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO LOCACAO");
		throw msg;		
	}//fim catch	
}//FIM REMOVER
