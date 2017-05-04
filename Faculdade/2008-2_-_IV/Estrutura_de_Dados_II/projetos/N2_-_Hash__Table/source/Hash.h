#ifndef HASH_H_
#define HASH_H_

#include<iostream>
//#include<cstdlib>
#include<iomanip>

#include"No.h"
//#include"Interface.h"

class Hash
{
public:
	No *hash;
	const unsigned int n;
	unsigned int contador;
	
	//construtor da tabela
	Hash():
		contador(0),
		n(52)
	{
		hash = new No();
		hash = new No[n];
		//inicializando todos os campos
		for(int i=0;i<n;i++){
			hash[i].vazio = true;//flag para verificar se o
			//campo esta vazio
		}//fim for
	}//fim construtor
	
	int funcaoHash(int chave);
	int funcaoPrimo(int nTmp);
	
	//metodos de encadeamento externo
	void inserirEncadExterno(No *&obj);
	int buscaEncadExterno(No *&obj);
	bool encadExternoVazio();
	
	//metodos Linear
	int inserirLinear(No *obj);
	bool buscaLinear(No *obj);
	void imprimiLinear();
	
	//metodo hash duplo
	int inserirHashDuplo(No *obj);
	int funcaoHashDuplo(int chave);
	bool buscaHashDuplo(No *obj);
	//void imprimiLinear();

};

int Hash::funcaoHash(int chave)
{
	
	int funcaoPrimo(n);           
	int pos;
	pos = chave%funcaoPrimo;//mod
	return pos;
}

int Hash::funcaoPrimo(int nTmp)
{
	if( nTmp % 2 == 0 ) nTmp++;
	for ( ; ! funcaoPrimo ( nTmp ) ; nTmp += 2 )
	 return nTmp;
}//fim do primxo

void Hash::inserirEncadExterno(No *&obj)
{
	int i;
	int chave = obj->getMatricula();
	
	No *aux;
	aux = new No();
	
	//std::cout<<" teste fs"<<std::endl;
	i = funcaoHash(chave);
	
	aux = &hash[i];
	
	//std::cout<<" Chave: "<<chave<<"  primo calc: "<<i<<std::endl;
	
	//caso q nao exista registro na posicao
	if(hash[i].vazio==true)
	{
		//std::cout<<"  TESTE DE ENTRADA NO  1 IF"<<std::endl;
		//No *auxNo;
		//auxNo = new No();
		//auxNo->chave = chave;
		
		//hash[i].proximo = auxNo;
		hash[i].proximo = obj;
		hash[i].proximo->proximo = 0;
		//atualizando o campo do no
		hash[i].proximo->vazio=false; 
		//atualziando o campo do vetor
		hash[i].vazio = false;//ocupado
		contador++;
	}//fim if
	else{
		//std::cout<<" teste de entrada else"<<std::endl;
		while(aux->proximo!=0)
		{
			//std::cout<<"  TESTE DE ENTRADA NO WHILE: "<<i<<std::endl;
			
			aux = aux->proximo;
						
			//std::cout<<"  Teste do prx "<<aux->chave<<std::endl;
			//if(aux->proximo==0) aux->proximo->vazio=true;
			
			/*aux = aux->proximo;
			No *auxNo;
			auxNo = new No();
			//atualizando os campos do no
			auxNo->chave = chave;
			auxNo->vazio = false;
			//inseriondo o no na lista
			aux = auxNo;
			//atalizando o ultio cammpo da lista
			aux->vazio=true;
			auxNo->proximo = 0;
			auxNo->chave = 0;*/
		}//fim while
		
		//std::cout<<"  Teste do prx2 "<<aux->proximo->chave<<std::endl;
		//aux chega com o ultimo elemento da lista
		
		//if(aux->proximo==0) std::cout<<" PROXIMO ESTA VAZIO"<<std::endl;
		if(aux->proximo==0){
			obj->vazio=false;
			obj->proximo=0;
			aux->proximo=obj;
			aux->vazio=false;
			contador++;
			/*No *auxAux;
			auxAux = new No();
			auxAux->chave=chave;
			auxAux->vazio=false;
			auxAux->proximo=0;
			aux->proximo=auxAux;*/
		}//fim if		
	}//fim else	
	
	//std::cout<<" cnt: "<<contador<<std::endl;
	//std::cout<<" hash["<<i<<"]="<<hash[i].proximo->chave<<std::endl;
	
}//fim inserir

bool Hash::encadExternoVazio()
{
	int i=0;
	while(i<n){
		if(hash[i].vazio==false) return false;
		i++;
	}
	return true;
}

int Hash::buscaEncadExterno(No *&obj)
{
	if(encadExternoVazio()) std::cout<<" LISTA VAZIA"<<std::endl;
	
	int chave = obj->getMatricula();
	int i ;//= funcaoHash(chave);
	
	No *aux;
	aux = &hash[i];
	
	//busca nao encontradaint i;
	i=funcaoHash(chave);
	
	//std::cout<<" Chave: "<<chave<<"  primo calc: "<<i<<std::endl;
	
	
	
	while(hash[i].vazio==false){
		i++;
	}
	std::cout<<" valor de i1: "<<i<<std::endl;
	int j=i;
	int cont=0;
	for(; cont<n; cont++){
		if(hash[j].vazio==true){
			if(hash[j].chave!=chave){
				hash[j].chave = chave;
			}//if 1
			else return -3;//jah existe
		}
		if(j>=n){
			j=j-n;
		}
		else j++;
	}//fim for
	
	//std::cout<<" valor de i2: "<<i<<std::endl;
	if(hash[i].vazio==true) {
		//std::cout<<" entro no if busca"<<std::endl;
		return -1;//campo vazio
	}
	
	//quase uma copia do inserir
	while(!aux->vazio)
	{
		//std::cout<<"  TESTE DE ENTRADA NO WHILE "<<std::endl;
		//std::cout<<"  hash["<<i<<"]="<<aux->chave<<" "<<std::endl;
		if(aux->chave==chave) {
			//std::cout<<"  retornando essa chave: "<<aux->chave<<std::endl;
			return aux->chave;
		}
		if(aux->proximo!=0){
			aux = aux->proximo;
			aux->vazio=false;
		}
		else aux->vazio=true;
				
	}//fim while
	
	return -2;//caso n encontrado	
}//fim busca

//********************ition
int Hash::inserirLinear(No *obj)
{
	int chave = obj->getMatricula();
	int i, cont=n;
	i = funcaoHash(chave);
	
	//merda de while..perdi 5 hrs q idiotisse
	while(hash[i].vazio==false && cont>0)
	{
		//std::cout<<" entro no while da insercao"<<std::endl;
		if(contador>=n) return -1;//tabela cheia
		i = (i+1)%n;
		cont--;
	}
	//No *no;
	//no = new No();
	
	//no->chave=chave;
	//hash[i].proximo = no;
	
	hash[i].proximo = obj;
	hash[i].vazio=false;
	
	contador++;
	
	//std::cout<<" cnt: "<<contador<<std::endl;
	//std::cout<<" hash["<<i<<"]="<<hash[i].proximo->chave<<std::endl;
	
}//fim inserir

void Hash::imprimiLinear()
{
	int cont=0;
	std::cout<<std::endl<<" _____________________________________________________";
	std::cout<<std::endl<<std::setw(15)<<"|    Matricula  |"
	<<std::setw(15)<<"     Nome     |"<<std::setw(10)<<"    RG     |"
	<<std::setw(10)<<"   CPF    |"<<std::endl;
	for(int i=0; i<n; i++){
		if(hash[i].proximo!=0){
			std::cout<<"|"<<std::setw(15)<<hash[i].proximo->getMatricula()
			<<"|"<<std::setw(15)<<hash[i].proximo->getNome()
			<<"|"<<std::setw(10)<<hash[i].proximo->getRg()
			<<"|"<<std::setw(10)<<hash[i].proximo->getCpf()
			<<"|"<<std::endl;
			
			//std::cout<<std::endl<<" Matricula: "<<hash[i].proximo->getMatricula();
			//std::cout<<std::endl<<" Nome: "<<hash[i].proximo->getNome();
			//std::cout<<std::endl<<" RG: "<<hash[i].proximo->getRg();
			//std::cout<<std::endl<<" CPF: "<<hash[i].proximo->getCpf();
			//std::cout<<std::endl<<" ___________________________"<<std::endl;
			//std::cout<<" chave: "<<i<<std::endl;
			//std::cout<<" hash["<<i<<"]="<<hash[i].proximo->chave<<std::endl;
			cont++;
		}//fim if
	}//fim for
	if(cont==0);
	std::cout<<"|_____________________________________________________|";
	
}//fim metoto imprimir
bool Hash::buscaLinear(No *obj)
{
	int chave = obj->getMatricula();
	
	int i, valor, cont=0;
	i = funcaoHash(chave);
	
	valor=-1;//inicial p entrar no laco
	
	while(valor!=chave && cont<n)
	{
		if(hash[i].proximo!=0) valor=hash[i].proximo->chave;
		if(valor==chave){
			return true;
		}
		
		i=(i+1)%n;
		cont++;
		
	}//fim while
	
	return false;//nao encontrado
	
}//fim busca linear

//****************************
//retornando uma valor dora do intevalo
int Hash::funcaoHashDuplo(int chave)
{
	int funcaoPrimo(n);
	int pos, k, h2;
	k=1;
	pos = chave%funcaoPrimo;
	//std::cout<<"pos: "<<funcaoPrimo<<std::endl;
	int reHash, hash1, hash2;
	
	hash1 = funcaoHash(chave);
	//std::cout<<"hash1: "<<hash1<<std::endl;
	hash2 = 1+ hash1;
	//std::cout<<"hash2: "<<hash2<<std::endl;
	reHash = (hash1+(k*hash2))%funcaoPrimo;
	//std::cout<<"reHash: "<<reHash<<std::endl;
	//std::cout<<" funciont hash: "<<reHash<<std::endl;
	
	int cont=0;
	
	if(hash[reHash].vazio==false){
		while(hash[reHash].vazio && cont<n){
			k++;
			//buscando uma posicao vazia
			reHash = (hash1+(k*hash2))%funcaoPrimo;	
			cont++;
		}//
		if(cont==n) return -1;//cheia
	}//fim if
	
	return reHash;	
	
}//fim da funcao hash duplo

int Hash::inserirHashDuplo(No *obj)
{
	int chave = obj->getMatricula();
	int i;
	//std::cout<<" i  e chave antes da cond: "<<i<<" - "<<chave<<std::endl;
	i = funcaoHash(chave);
	
	int cont=0;
	
	while(hash[i].vazio==false && cont<n)
	{
		if(contador>n) return -1;//tabela cheia
		i = funcaoHashDuplo(chave);
		if(i==-1) return i;//cheia	
		cont++;
	}///fim while
	
	if(buscaHashDuplo(obj)) return -2;//jah existe
	
	//No *no;
	//no = new No();
	
	//no->chave = chave;
	//no->vazio=false;
	obj->vazio=false;
	hash[i].proximo=obj;
	hash[i].vazio=false;
	
	contador++;
	
	//std::cout<<" cnt: "<<contador<<std::endl;
	//std::cout<<" hash["<<i<<"]="<<hash[i].proximo->chave<<std::endl;
	
}//fim inserir hash duplo

bool Hash::buscaHashDuplo(No *obj)
{
	int chave = obj->getMatricula();
	int i, valor, cont;
	i = funcaoHash(chave);
	
	cont=0;
	
	valor=-1;//inicial p entrar no laco
	
	while(valor!=chave && cont<n)
	{
		//std::cout<<"\t  ake "<<i<<std::endl;
		if(hash[i].vazio==false) {
			valor = hash[i].proximo->chave;
		}
		if(valor==chave) {
			//std::cout<<" i: "<<i<<"  valor "<<valor<<std::endl;
			return true;
		}else {
		   
		   i=funcaoHashDuplo(chave);
		   //std::cout<<"\t  ake "<<i<<std::endl;
		}
		
		cont++;		
	}//fim while
	
	return false;//nao encontrado
	
}//fim busca hash duplos

#endif /*HASH_H_*/
