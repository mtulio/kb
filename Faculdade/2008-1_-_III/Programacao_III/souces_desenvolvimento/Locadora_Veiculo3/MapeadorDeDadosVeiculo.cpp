// PRODUCT BY MARCO TULIO
#include"MapeadorDeDadosVeiculo.h"
//#include<iostream>

using namespace std;

//CONSTRUTOR
MapeadorDeDadosVeiculo::MapeadorDeDadosVeiculo():
	nomeDoArquivoNoDisco("ArquivoDeVeiculo.txt")
	{
		std::fstream arquivo;
		try{			
			arquivo.open(nomeDoArquivoNoDisco.c_str(), std::ios::in);
			if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc); 
			if(!arquivo.is_open()) throw string("> MpDdVei-Cst: ERRO AO ABRIR/CRIAR ARQUIVO DE VEICULO");
			arquivo.close();
		}//fim try
		catch(string msg){
			arquivo.close();
			throw msg;
		}//fim throw	
		
	}//fim construtor

bool MapeadorDeDadosVeiculo::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	fstream arquivo;
	try
	{// inicio try
		string linha;
		Veiculo veiculoAux;
		Veiculo *veiculo;
		
		veiculo = static_cast<Veiculo *>(objeto);
		
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		if(!arquivo.is_open()) throw string("> MpDdVei-Bsc: ERRO AO ABRIR O ARQUIVO DE VEICULO");
		
		getline(arquivo, linha);
		
		while(!arquivo.eof())
		{//inicio while
			veiculoAux.materializar(linha);
			if(id == veiculoAux.obterIdentificador()){
				arquivo.close();
				if(arquivo.is_open()) throw string("> MpDdVei-Bsc: ERRO AO FECHAR O ARQUIVO DE VEICULO");
				veiculo->materializar(linha);
				return true;
			}//fim if
			getline(arquivo, linha);			
		}//fim while
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdVei-Bsc: ERRO AO FECHAR O ARQUIVO DE VEICULO");
		return false;		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	}//fim catch	
}//fim do buscar

void MapeadorDeDadosVeiculo::gravarNoArmazenamento(ItemPersistencia *objeto)
{
	 ofstream arquivo;
	 try{
	 	Veiculo *veiculo;
	 	veiculo = static_cast<Veiculo *>(objeto);
	 	// verificando se oponteiro aponta para um espaco na memoria
	 	if(veiculo == 0) throw string("> MpDdVei-Grv: PONTEIRO NAO ALOCADO / CONVERSAO NAO EFETUADA");
	 	
	 	
	 	arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::app);			
	 	string linha = veiculo->desmaterializar(); 
	 	arquivo<<linha<<endl;	 	 		 	
	 	arquivo.close();
	 	if(arquivo.is_open()) throw string("> MpDdVei-Grv: ERRO AO FECHAR O ARQUIVO DE VEICULO");
	 	
	 	// FINALIZANDO O METODO 	
	 }//fim try
	 catch(string msg)
	 {
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	 }//fim catch	
}//fim do gravar

void MapeadorDeDadosVeiculo::removerNoArmazenamento(ItemPersistencia *objeto)
{
	fstream arquivo, arquivoBackup;
	try{
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		if(!arquivo.is_open()) throw string("> MpDdVei-Rem: ERRO AO ABRIR O ARQUIVO DE VEICULO");

		string strArquivoBackup = "ArquivoBackupVeiculo.txt";
		arquivoBackup.open(strArquivoBackup.c_str(), ios::out|ios::trunc);
		if(!arquivo.is_open()) throw string("> MpDdVei-Rem: ERRO AO CRIAR O ARQUIVO DE BACKUP DO VEICULO");
		// ***********************************************************************************************
		
		string linha;
		Veiculo veiculoAux;
		
		// o id jah esta no pai
		int id = objeto->obterIdentificador();

		// ***********************************************************************************************

		getline(arquivo, linha);
		while(!arquivo.eof())
		{
			veiculoAux.materializar(linha);
			if(id != veiculoAux.obterIdentificador())
			{//inicio if
				arquivoBackup<<linha<<endl;
			}//fim if
			getline(arquivo, linha);
		}//fim do while

		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdVei-Rem: ERRO AO FECHAR O ARQUIVO DE VEICULO");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdVei-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO VEICULO");
		// ***********************************************************************************************
		
		remove("ArquivoDeVeiculo.txt");
		rename("ArquivoBackupVeiculo.txt" , "ArquivoDeVeiculo.txt");		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdVei-Rem: ERRO AO FECHAR O ARQUIVO DE VEICULO");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdVei-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO VEICULO");
		throw msg;		
	}//fim catch	
}//FIM REMOVER
