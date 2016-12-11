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
      bool adicionar(NoRequisicao *&requisicao);
      bool retirar(NoRequisicao *&requisicao);
      bool estaVazio();
      
};//fim da classe Fila


Fila::~Fila(){
    if((inicioFila && fimFila)==0) return;
    //vai repetir enquanto a fila n estiver vazia
    for(; !estaVazio(); ){
          std::cout<<" entrei"<<std::endl;
          //std::cout<<" entrei2"<<std::endl;
                       NoRequisicao *aux = new NoRequisicao;
                       aux=fimFila;
                       //EH PRXIMO MESMO
                       fimFila=aux->proximo;
                       //fimFila->anterior=0;
                       delete aux;
        
   }
    inicioFila=0;
    fimFila=0;
              
}//fim destrutor

bool Fila::adicionar(NoRequisicao *&requisicao)
{
   //std::cout<<std::endl<<"\t  nome inicio "<<obj.nome_cli<<std::endl<<std::endl;
   
   if(requisicao==0) return false;
   if((inicioFila==0) && fimFila==0){
                        //std::cout<<"  IF2 ADD"<<std::endl;
	   					requisicao->proximo=inicioFila;
                        requisicao->anterior=fimFila;
                        
                        inicioFila=requisicao;
                        fimFila=requisicao;
                        return true;
     }
     else{
          //pura logica.. tem q raciocinar um pokin
          //requisicao->nome_cli = nome;
         //atualizando os campos do fim da fila e atualizando o fim da fila 
    	 //std::cout<<"  IF3 ADD"<<std::endl;
    	 requisicao->proximo=fimFila;
         fimFila->anterior=requisicao;
         fimFila=requisicao;
         fimFila->anterior=0;
         return true;
     }  
     return false;     
}

bool Fila::retirar(NoRequisicao *&requisicao)
{
     if(inicioFila==0) return false;
     
     //std::cout<<std::endl<<"\t  nome inicio "<<inicioFila->nome_cli<<std::endl<<std::endl;
         
     requisicao = inicioFila;
     
     //se apontar pra zero ele sera o unico da fila
     
     requisicao->proximo=0;
     inicioFila=requisicao->anterior;
     
     if((requisicao->proximo==0) && (requisicao->anterior==0)){
    	 //std::cout<<"  IF1 RM"<<std::endl;
    	 inicioFila=0;
    	 fimFila=0;    	 
     }
         
     return true;     
}

bool Fila::estaVazio(){
     if((inicioFila==0)||(fimFila==0)) return true;
     else return false;     
}

#endif /*FILA_H_*/
