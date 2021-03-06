#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<string>
#include<iostream>
#include<iomanip>

#include"NoRequisicao.h"
#include"Fila.h"

class Interface
{
   public:
      static void lerDadosRequisicao(NoRequisicao *&requisicao);
      static void escreverRequisicao(NoRequisicao *&requisicao);
      static void listarTodos(Fila *&copiaFila);
};//fim classe interface

void Interface::lerDadosRequisicao(NoRequisicao *&requisicao)
{
    //system("clear"); 
	std::cout<<"  ENTRADA DE DADOS DA REQUISICAO"<<std::endl;
     std::string nome, end, model_pc, num_serie_pc;
     unsigned long tel, cel;
     unsigned int cpf;
     
     std::cout<<" Nome: ";
     std::cin.ignore();
     getline(std::cin,nome);
     //std::cin>>nome;
     
     std::cout<<" CPF: ";
     std::cin>>cpf;
     
     std::cout<<" Endereco: ";
     std::cin.ignore();
     getline(std::cin, end);
     //std::cin>>end;
     
     std::cout<<" Telefone: ";
     std::cin>>tel;
     
     std::cout<<" Celular: ";
     std::cin>>cel;
     
     std::cout<<" Modelo PC: ";
     std::cin.ignore();
     getline(std::cin, model_pc);
     //std::cin>>model_pc;
     
     std::cout<<" Nro Serie PC: ";
     std::cin.ignore();
     getline(std::cin, num_serie_pc);
     //std::cin>>num_serie_pc;    
     
     requisicao->atribuir(nome,cpf, end, tel, cel, model_pc, num_serie_pc);
}//fim ler

void Interface::escreverRequisicao(NoRequisicao *&requisicao)
{
	std::cout<<"  SAIDA DE DADOS DA REQUISICAO"<<std::endl;
	std::string lateral="|", superior="_____________________________";
	std::string nome, end, model_pc, num_serie_pc;
	unsigned long tel=0, cel=0;	
	unsigned int cpf;
	//std::string nome=requisicao->obterNome();
	requisicao->obter(nome,cpf, end, tel, cel, model_pc, num_serie_pc);
	
	std::cout<<superior<<std::endl;
	std::cout<<lateral<<"   REQUISICAO DE: "<<std::setw(10)<<nome<<lateral<<std::endl;
	std::cout<<superior<<lateral<<std::endl;
	std::cout<<lateral<<"             CPF: "<<std::setw(10)<<cpf<<lateral<<std::endl;
	std::cout<<lateral<<"        ENDERECO: "<<std::setw(10)<<end<<lateral<<std::endl;
	std::cout<<lateral<<"        TELEFONE: "<<std::setw(10)<<tel<<lateral<<std::endl;
	std::cout<<lateral<<"         CELULAR: "<<std::setw(10)<<cel<<lateral<<std::endl;
	std::cout<<lateral<<"       MODELO PC: "<<std::setw(10)<<model_pc<<lateral<<std::endl;
	std::cout<<lateral<<" NUMERO SERIE PC: "<<std::setw(10)<<num_serie_pc<<lateral<<std::endl;
	std::cout<<superior<<lateral<<std::endl;
}


void Interface::listarTodos(Fila *&copiaFila)
{
   for(; !copiaFila->estaVazio(); ){
         NoRequisicao *requisicao = new NoRequisicao();
         copiaFila->retirar(requisicao);
         escreverRequisicao(requisicao);
   }     
     
     
}//fim metodo listar

#endif /*INTERFACE_H_*/
