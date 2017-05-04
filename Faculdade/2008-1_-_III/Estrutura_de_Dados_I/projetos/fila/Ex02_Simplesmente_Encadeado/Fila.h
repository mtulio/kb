#ifndef FILA_H_
#define FILA_H_
#include<iostream>
#include<string>
#include"NoRequisicao.h"

class Fila{
   private:
      
      NoRequisicao *inicioFila;
      NoRequisicao *fimFila;
   public:
      
      Fila():inicioFila(0),fimFila(0){};
      ~Fila();
      bool adicionar(NoRequisicao *requisicao);
      NoRequisicao *retirar();
      bool estaVazio();
      
};//fim da classe Fila


Fila::~Fila(){
    if((inicioFila && fimFila)==0) return;
    //vai repetir enquanto a fila n estiver vazia
    for(; !estaVazio(); ){
          //std::cout<<" entrei"<<std::endl;
          //std::cout<<" entrei2"<<std::endl;
          NoRequisicao *aux = new NoRequisicao;
          aux=inicioFila;
          inicioFila=aux->proximo;
          delete aux;        
   }//fim for
    inicioFila=0;
    fimFila=0;              
}//fim destrutor

bool Fila::adicionar(NoRequisicao *requisicao)
{
   //std::cout<<std::endl<<"\t  nome inicio "<<obj.nome_cli<<std::endl<<std::endl;
   
   //se a requisicao nao estiver apontando pra "ninguem" na memoria,
   //significa que o mesmo nao existe
   if(requisicao==0) return false;
   
   //esta condicao so ocorrera no primeiro elemento da fila
   //o bloco de comandos faz com que o inicio e o fim aponte para este elemento
   if((inicioFila==0) && fimFila==0){
      //std::cout<<"  IF2 ADD"<<std::endl;
	   requisicao->proximo=fimFila;
      
      //como eh o primeiro elemento, os campos fimFila e inicioFila
      //vao apontar pro mesmo elemento
      inicioFila=requisicao;
      fimFila=requisicao;
      return true;
    }//fim if
     
     else{
         //fazer com que o campo proximo do elemento que esta no fim da fila 
         //aponte para o elemento que sera add
         fimFila->proximo=requisicao;
         
         //atualizando o fim da fila
         fimFila=requisicao;
         return true;
     }//fim else  
     
     return false;     
}//fim add

NoRequisicao *Fila::retirar()
{
   NoRequisicao *requisicao = new NoRequisicao;
   
   requisicao = inicioFila;

   //como requisicao aponta para o mesmo elemento do inicio da fila
   //pode-se fazer essa operacao que esta atualizando o inicioFila
   inicioFila=requisicao->proximo;
   
   return requisicao;
}//fim retirar

bool Fila::estaVazio(){
     if((inicioFila==0)||(fimFila==0)) return true;
     else return false;     
}

#endif /*FILA_H_*/
