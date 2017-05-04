#ifndef ARVORE_H_
#define ARVORE_H_

#include"NoCliente.h"
#include<string>

class Arvore
{
	private:
		NoCliente *raiz;	
	public:
		Arvore(): raiz(0){}
		
		void inserirNo(std::string &nome)
		{
			// se a raiz for null, eh pq n foi criada
			if( raiz==0 ){
				raiz = new NoCliente(nome);
			else 
				raiz->inserir(nome);
		}//fim inserirNo
		
		
	
};

#endif /*ARVORE_H_*/
