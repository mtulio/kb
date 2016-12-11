#ifndef CONTROLEFILA_H_
#define CONTROLEFILA_H_

#include<iostream>
#include<string>
#include"Fila.h"
#include"NoRequisicao.h"


//esta classe tem como objetivo auxiliar para a procura 
//listagem e outras opera��es na fila

class ControleFila{
  public:
     static bool busca(std::string &nome, Fila *&fila,  NoRequisicao *&cliente);
     static void copiarFila(Fila *&fila, Fila *&copiaFila);
};

bool ControleFila::busca(std::string &nome, Fila *&fila, NoRequisicao *&cliente)
{
     
     Fila *filaAux = new Fila();
     NoRequisicao *clieAux = new NoRequisicao();
     bool respVerificacao=false;
     //variavel serve pra contar a qtd de elementos da fila
     //para a condicao do for
     unsigned int qtdElementos=0;
     
     //verificando cada elemento da fila original e copiando pra aux
     for(; !fila->estaVazio(); ){
           fila->retirar(clieAux);
           std::string nomeAux=clieAux->obterNome();
           
           if(nome==nomeAux){
                
                respVerificacao=true;
                cliente=clieAux;//pegando os dados do nome encontrado
                
                //std::cout<<"  resp: "<<respVerificacao<<"  nome: "<<cliente->nome_cli<<std::endl;
                filaAux->adicionar(clieAux);       
           }
           else filaAux->adicionar(clieAux);
           
           qtdElementos++;
     }//fim da verificacao da fila original
     
     //retornando os dados para a fila original
     copiarFila(filaAux, fila);
     
    
     //delete clieAux;
   
     if(respVerificacao) return respVerificacao;
     else return respVerificacao;
     
}//fim busca

//metodo copiar FIla
void ControleFila::copiarFila(Fila *&fila, Fila *&copiaFila)
{
	Fila *auxCopia = new Fila();
	
	//variavel q serve pra saber a qtd de elementos da lista para ser usado no for 2
	//nao foi possivel usar o metodo esta vazio
	unsigned int qtdElementos=0;
	
	//std::cout<<"  entrei - copiar fila"<<std::endl;
	
	//copiando a fila original pra aux
	for( ; !fila->estaVazio() ; ){//for 1
		//std::cout<<"  entrei for 1 - copiar fila"<<std::endl;
		
		NoRequisicao *auxReq = new NoRequisicao();
		fila->retirar(auxReq);
		
		//std::string nome;
		//auxReq->obter(nome);
		//std::cout<<"   NOME copiando: "<<auxReq->obterNome()<<std::endl;
		
		auxCopia->adicionar(auxReq);
		qtdElementos++;
	}//fim for
	
	for(unsigned int i=0 ; i<qtdElementos ; i++){//for 2
		NoRequisicao *auxReq = new NoRequisicao();
		NoRequisicao *auxReq2 = new NoRequisicao();
		
		auxCopia->retirar(auxReq);
		
		//fazendo a copia dos objetos, pois nao pode apontar duas filas para um mesmo objeto
		std::string nome, end, model_pc, num_serie_pc;
		unsigned long cpf, tel, cel;
		
		auxReq->obter(nome,cpf, end, tel, cel, model_pc, num_serie_pc);
		auxReq2->atribuir(nome,cpf, end, tel, cel, model_pc, num_serie_pc);
		//nome=auxReq2->obterNome();
		//std::cout<<"   NOME COPIAR: "<<nome<<std::endl;
		
		
		//voltando os objetos para a fila
		fila->adicionar(auxReq);
		copiaFila->adicionar(auxReq2);		
	}

}//fim metodo copiar

#endif /*CONTROLEFILA_H_*/
