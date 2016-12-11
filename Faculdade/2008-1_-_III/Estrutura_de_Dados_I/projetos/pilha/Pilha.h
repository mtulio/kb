#ifndef PILHA_H_
#define PILHA_H_
//biblioteca usada pra teste
#include<iostream>

#include"no.h"
class Pilha
{
   //private
   public:   
      no *topoPilha;
   public:      
      Pilha():topoPilha(0){}
      bool atribuirPilha(char letra);
      bool retirarPilha(char &letra);
      bool estaVazio();
};//fim da classe pilha

bool Pilha::atribuirPilha(char letra)
{
   no *pt = new no;
   
   if(pt==0) return false;
   //no(letra, 0);
   pt->elemento = letra;
   pt->proximo = topoPilha;
  
   topoPilha = pt;
   return true;     
}//fim do metodo atribuir

bool Pilha::retirarPilha(char &letra)
{//inicio do metodo
   if(topoPilha==0) return false;
   
   letra = topoPilha->elemento;
   no *ptAux = topoPilha;
   
   //atualizando o topo da pilha
   topoPilha = ptAux->proximo;
   
   //deletando o objeto do topo da pilha
   delete ptAux;
   return true;
}//fim do metodo 

bool Pilha::estaVazio()
{
     if(topoPilha==0) return true;
     else return false;
}
#endif /*PILHA_H_*/
