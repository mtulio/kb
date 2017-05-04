// PRODUCT BY MARCO TULIO
#include"MapeadorDeDados.h"
#include"ItemPersistencia.h"
using namespace std;
bool MapeadorDeDados::MapeadorDeDados::gravarDados(ItemPersistencia *objeto)
{
	try{// pode ocorrer erros nas classes filhos
		if(!buscarNoArmazenamento(objeto->obterTipoDaClasse(), objeto)){
			gravarNoArmazenamento(objeto);
			return true;			
		}//fim if
		else return false;	
	}//fim try
	catch(string msg)
	{
		throw msg;
	}//	fim catch	
}//fim gravar dados

bool MapeadorDeDados::recuperarDados(ItemPersistencia *objeto)
{
	try{		
		//se encontrou o objeto o busca retornara como parametro os dados e o
		// metodo retornara verdadeiro
		if(buscarNoArmazenamento(objeto->obterTipoDaClasse(), objeto))
		{
			return true;	
		}//fim if
		else return false;	
	}//fim try
	catch(string msg){
		throw msg;		
	}//fim throw
}//fim recuperarDados

bool MapeadorDeDados::removerDados(ItemPersistencia *objeto)
{
	//o recuperar pede pra buscar o objeto no arquivo, se encontrado
	// chama o metodo remover
	try{
		if(buscarNoArmazenamento(objeto->obterTipoDaClasse(), objeto))
		{
			removerNoArmazenamento(objeto);	
		}//fim if
		else return false;		
	}//fim try
	catch(string msg){
		throw msg;	
	}// fim catch	
}//fim recuperarDados
