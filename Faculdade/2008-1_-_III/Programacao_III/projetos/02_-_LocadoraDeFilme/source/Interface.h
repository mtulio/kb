#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include<iomanip>

#include"Cliente.h"
#include"Filme.h"
#include"Locacao.h"
#include"Persistencia.h"
#include"Iterator.h"

class Interface
{
    /*private:
            Persistencia item;*/
	public:
		//Interface(Persistencia &item):item(item){};
        static void menuPrincipal();
		
		//  TELAS PARA CLIENTE
		static void menuManterCliente();
		static void lerDadosDoCliente(Cliente &pessoa);
		static void lerDadosDoClienteAlteracao(Cliente &pessoa);
        static void escreverDadosDoCliente(const Cliente &pessoa);
				
		//  TELAS PARA FILME
		static void menuManterFilme();
	    static void lerDadosDoFilme(Filme &filme);
        static void lerDadosDoFilmeAlteracao(Filme &filme);
        static void escreverDadosDoFilme(const Filme &filme);
		
		//  TELAS PARA LOCACAO
		static void menuManterLocacao();
//		static void lerDadosDaLocacao(unsigned int idLocacao, unsigned int idCliente, unsigned int idFilme);
//		static void escreverDadosDaLocacao(Locacao &locacao);
		
};//fim da definição da classe Interface

void Interface::menuPrincipal()
{
	int opcao=1;
	while(opcao){
		system("cls");
		std::cout<<std::endl<<"	MENU PRINCIPAL"<<std::endl;
		std::cout<<std::endl<<"	1 - CLIENTE";
		std::cout<<std::endl<<"	2 - FILME";
		std::cout<<std::endl<<"	3 - LOCACAO";
		std::cout<<std::endl<<"	0 - SAIR";	
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
				menuManterCliente();
				//std::cout<<std::endl<<"MENU CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//fim case 1	
			case 2:{//case 2
				menuManterFilme();
				//std::cout<<std::endl<<"MENU FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//fim case 2
			case 3:{//case 3
				menuManterLocacao();
				//std::cout<<std::endl<<"MENU LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cin.get();
				break;
			}//fim case 3
		}//fim do switch
	}//fim do while
}//fim do metodo menuPrincipal

//********************************************************
//  TELAS PARA CLIENTE
//********************************************************
void Interface::menuManterCliente()
{
    Persistencia item;
	int opcao=1;
	while(opcao){
		system("cls");
		std::cout<<std::endl<<"	MENU MANTER CLIENTE"<<std::endl;
		std::cout<<std::endl<<"	1 - INCLUIR";
		std::cout<<std::endl<<"	2 - EXCLUIR";
		std::cout<<std::endl<<"	3 - ALTERAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	5 - LISTAR";
		std::cout<<std::endl<<"	0 - SAIR";	
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{//case 1
				Cliente pessoa;
				lerDadosDoCliente(pessoa);
				//Persistencia item;
				//std::cout<<
				if(item.gravar(&pessoa)) std::cout<<"gravado com sucesso";
				else std::cout<<"ERRO NA GRAVACAO"<<std::endl;
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 1	
			case 2:{//case 2 - Excluir
			     std::string nome, email;
			     unsigned int id;
			     long telefone;
			     std::cout<<"Digite o id do cliente: ";
			     std::cin>>id;
			     Cliente cliente(id,"",0,"");
			     if(item.recuperar(&cliente)){
                         cliente.obter(id, nome, telefone, email);
                         std::cout<<"Nro id: "<<id<<std::endl<<"Nome: "<<nome<<std::endl;
                         std::cout<<"Telefone: "<<telefone<<std::endl<<"Email: "<<email<<std::endl;
                         std::cout<<"Confirma[s/n]: ";
                         std::cin.ignore();
                         char resp;
                         std::cin>>resp;
                         if(resp != 's' && resp !='S') resp='n';
                         if(resp=='s' || resp=='S'){
                                      if(item.remover(&cliente)) std::cout<<"Cliente EXCLUIDO!"<<std::endl;
                                      else std::cout<<"ERRO na exclusao!"<<std::endl;
                         }
                         else std::cout<<"OPERACAO CANCELADA!"<<std::endl;
                   }
                   else std::cout<<"Cliente nao encontrado"<<std::endl;
                             
                //antes de remover eu preciso consultar se existe o nome
				
                //std::cout<<std::endl<<"EXCLUIR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
                std::cin.get();
				break;
			}//fim case 2
			case 3:{//case 3  - ALTERAR
				std::string nome, email;
				unsigned int id;
				long telefone;
				std::cout<<"Digite o id do cliente: ";
				std::cin>>id;
				Cliente cliente(id,"",0,"");                
                if(item.recuperar(&cliente)){
                       cliente.obter(id, nome, telefone, email);
                       std::cout<<"Nro id: "<<id<<std::endl<<"Nome: "<<nome<<std::endl;
                       std::cout<<"Telefone: "<<telefone<<std::endl<<"Email: "<<email<<std::endl;
                       std::cout<<"Confirma[s/n]: ";
                       std::cin.ignore();
                       char resp;
                       std::cin>>resp;
                       if(resp != 's' && resp !='S') resp='n';
                       if(resp=='s' || resp=='S'){
                                    item.remover(&cliente);
                                    lerDadosDoClienteAlteracao(cliente);
                                    //eh preciso de fazer a chamada de um metodo para gravar as alteracoes
                                    if(item.gravar(&cliente)) std::cout<<std::endl<<
                                                                 "Alteracao CONCLUIDA"<<std::endl;
                                        else std::cout<<
                                                "Erro na Alteracao - item gravacao!"<<std::endl;
                       }
                       else std::cout<<"OPERACAO CANCELADA";
                }//
                else std::cout<<"Cliente nao encontrado";
                std::cout<<std::endl<<std::endl<<"<ENTER> PARA CONTINUAR";
                //std::cout<<std::endl<<"ALTERAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 3
			case 4:{//case 4 - consultar
                std::string nome, email;
				unsigned int id;
				long telefone;
				std::cout<<"Digite o id do cliente: ";
				std::cin>>id;
				Cliente cliente(id,"",0,"");
				if(item.recuperar(&cliente)){
                       escreverDadosDoCliente(cliente);
                       /*cliente.obter(id, nome, telefone, email);
                       std::cout<<"Nro id: "<<id<<std::endl<<"Nome: "<<nome<<std::endl;
                       std::cout<<"Telefone: "<<telefone<<std::endl<<"Email: "<<email<<std::endl;*/
                }//
                else std::cout<<"Cliente nao enontrado";
                std::cout<<std::endl<<std::endl<<"<ENTER> PARA CONTINUAR";

				//std::cout<<std::endl<<"CONSULTAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 4
			case 5:{//case 5
                std::string superior="  _________________________________________________________________",
					            inferior=" |_________________________________________________________________|",
					            lateral=" | ";
                Cliente cliente;
                Iterator *iterator = item.listar(&cliente);
                
                if(iterator->estaVazio()){
                                          std::cout<<"Nao ha nenhum cadastro de clientes"<<std::endl;
                                          std::cin.ignore();
                                          std::cin.get();
                                          break;
                }// fim do if esta vazio
                std::cout<<superior<<std::endl;
                std::cout<<" |__ID_________NOME___________TELEFONE______________EMAIL_________"<<lateral<<std::endl;
                iterator->inicio();
                bool condicao=true;
                while(condicao){
                       cliente = iterator->obterCliente();
                       unsigned int id;
                       long telefone;
                       std::string nome, email;
                       cliente.obter( id ,nome, telefone, email);
                       std::cout<<lateral<<std::setw(4)<<id<<lateral<<std::setw(15)<<nome<<lateral<<std::setw(10)<<telefone<<lateral<<std::setw(25)<<email<<lateral<<std::endl;
                       //std::cout<<"ID: "<<id<<" \nName: "<<nome<<" \nTelefone: "<<telefone<<" \nemial: "<<email<<std::endl;
                       
                       condicao = iterator->proximo();
                }
                std::cout<<inferior<<std::endl;
				std::cout<<std::endl<<std::endl<<"<ENTER> PARA CONTINUAR"; 
                //std::cout<<"Saiuu do while!!"<<std::endl;
                
                
                
                /*Cliente cliente;
			    Iterator *iterator = item.listar(&cliente);
			    ItemPersistencia item2;
			    iterator->inicio();
			    bool teste=true;
			    while(teste){
                             //ItemPersistencia item2 
                             item2 = iterator->obter();
                             
                             //cliente = static_cast<Cliente>(item2);
                                          
                }*/
                
                
                /*Iterator *vetItem;
			    Cliente *cliente;
			    if(item.listar(&cliente, &vetItem)){
                    vetItem->inicio();
                    bool condicao=true;
                    while(condicao){
                                    ItemPersistencia *itemAux;
                                    itemAux=vetItem->obter();
                                    cliente=static_cast<Cliente *>(itemAux);
                                    unsigned int telefone;
                                    std::string nome, email;
                                    cliente.obter(nome, telefone, email);
                                    std::cout<<"nome: "<<nome<<std::endl;
                    
                }//fim
                else std::cout<<"nao foi possivel fazer a listagem!"<<std::endl;
			*/
			   //delete *iterator;
				//std::cout<<std::endl<<"LISTAR CLIENTE EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				//std::cout<<"Saiuu do while!!"<<std::endl;
                std::cin.get();
				std::cin.get();
				break;
			}//fim case 5
		}//fim do switch
	}//fim do while
}//fim do metodo menuManterCliente

void Interface::lerDadosDoCliente(Cliente &pessoa)
{
	unsigned int id;
	std::string nome, email;
	long telefone;
	//system("clear");
	std::cout<<std::endl<<std::endl<<"DADOS DO CLIENTE - ENTRADA"<<std::endl<<std::endl;
	std::cout<<"IDENTIFICADOR: ";
	std::cin>>id;
	std::cin.ignore();
	std::cout<<"NOME: ";
	getline(std::cin,nome);
	std::cout<<"TELEFONE: ";
	std::cin>>telefone;
	std::cout<<"EMAIL: ";
	std::cin.ignore();
	getline(std::cin,email);
	pessoa.atribuir(id,nome,telefone,email);
}

void Interface::lerDadosDoClienteAlteracao(Cliente &cliente)
//criei esse metodo para melhor comodidade na hora da alteracao do cliente
{
     unsigned int id;
     std::string nome, email;
     long telefone;
     cliente.obter(id, nome, telefone, email);
     std::cout<<"ID: "<<id<<std::endl<<"NOme: "<<nome<<std::endl;
     std::cout<<"Telefone: ";
     std::cin>>telefone;
     std::cout<<"Email: ";
     std::cin.ignore();
     getline(std::cin, email);
     cliente.atribuir(id, nome, telefone, email);     
}//fim do metodo para alteracao do cadastro

void Interface::escreverDadosDoCliente(const Cliente &pessoa)
{
	unsigned int id;
	std::string nome, email;
	long telefone;
	pessoa.obter(id,nome,telefone,email);
	//system("clear");
	std::cout<<std::endl<<std::endl<<" DADOS DO CLIENTE - SAIDA"<<std::endl<<std::endl;
	std::cout<<"IDENTIFICADOR: "<<id<<std::endl;
	std::cout<<"NOME: "<<nome<<std::endl;
	std::cout<<"TELEFONE: "<<telefone<<std::endl;
	std::cout<<"EMAIL: "<<email<<std::endl;
}

//********************************************************
//  TELAS PARA FILME
//********************************************************
void Interface::menuManterFilme()
/*UM FILME DEVE CONTER OS SEGUINTES DADOS:
  * IDENTIFICADOR - NOME DO FILME
  * TITULO - NOME DO FILME
  * PREÇO DE COMPRA
  * PREÇO DE LOCAÇÃO
  * SITUAÇÃO - locado ou não locado
 > CONSTRUIR UM METODO PARA LER OS DADOS DO FILME NA INCLUSAO
 void Interface::lerDadosDoFilme(Filme &filme);
 void Interface::lerDadosDoFilmeAlteracao(Filme &filme);
 void Interface::escreverDadosDoFilme(Filme &filme);
 
 > CONSTRUIR UM METODO PARA LER OS DADOS DO FILME NA ALTERACAO
 > CONSTRUIR UM METODO PARA ESCREVER OS DADOS DO FILME
     
*/
{
	Persistencia item;
    int opcao=1;
	while(opcao){
		system("cls");
		std::cout<<std::endl<<"	MENU MANTER FILME"<<std::endl;
		std::cout<<std::endl<<"	1 - INCLUIR";
		std::cout<<std::endl<<"	2 - EXCLUIR";
		std::cout<<std::endl<<"	3 - ALTERAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	5 - LISTAR";
		std::cout<<std::endl<<"	0 - SAIR";	
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1
                Filme filme;
                lerDadosDoFilme(filme);
                if(item.gravar(&filme)) std::cout<<"Gravado com sucesso!"<<std::endl;
                else std::cout<<"ERRO NA GRAVACAO"<<std::endl;                
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 1	
			case 2:{//case 2 - excluir
                unsigned int id;
                std::cout<<"Digite o cod Id do Filme: ";
                std::cin>>id;
                Filme filme(id,"",0,0,false);
                if(item.recuperar(&filme)){//verificando se existe o nome no cadastro
                        escreverDadosDoFilme(filme);
                        std::cout<<"Confirma[s/n]: ";
                        std::cin.ignore();
                        char resp;
                        std::cin>>resp;
                        if(resp != 's' && resp !='S') resp='n';
                         if(resp=='s' || resp=='S'){
                                      if(item.remover(&filme)) std::cout<<"REMOVIDO COM SUCESSO!"<<std::endl;
                                         else std::cout<<"ERRO na exclusao!"<<std::endl;
                        }
                        else std::cout<<"OPERACAO CANCELADA!"<<std::endl;
                }
                else std::cout<<"ID nao encontrado!"<<std::endl;
				//std::cout<<std::endl<<"EXCLUIR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 2
			
			case 3:{//case 3 - alterar
                unsigned int id;
				std::cout<<"Digite o ID do filme: ";
                std::cin>>id;
                Filme filme(id,"",0,0,false);
                if(item.recuperar(&filme)){
                        escreverDadosDoFilme(filme);
                        std::cout<<"Confirma[s/n]: ";
                        std::cin.ignore();
                        char resp;
                        std::cin>>resp;
                        if(resp != 's' && resp !='S') resp='n';
                        if(resp=='s' || resp=='S'){
                               item.remover(&filme);
                               lerDadosDoFilmeAlteracao(filme);                                     
                               if(item.gravar(&filme)) std::cout<<std::endl<<"Alteracao CONCLUIDA"<<std::endl;
                                  else std::cout<<"Erro na Alteracao - item gravacao!"<<std::endl;
                        }else std::cout<<"Operacao Cancelada!"<<std::endl;
                }else std::cout<<"ID n encontrado!"<<std::endl;
                //std::cout<<std::endl<<"ALTERAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 3
			case 4:{//case 4 - consultar
                unsigned int id;
                std::cout<<"Digite o ID do filme: ";
                std::cin>>id;
                Filme filme(id,"",0,0,false);
                if(item.recuperar(&filme)){
                       escreverDadosDoFilme(filme);                                           
                }
                else std::cout<<"Filme nao encontrado!"<<std::endl;
				//std::cout<<std::endl<<"CONSULTAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 4
			case 5:{//case 5
                std::string superior="  ____________________________________________________________________",
					            inferior=" |____________________________________________________________________|",
					            lateral=" | ";
                Filme filme;
                Iterator *iterator = item.listar(&filme);
                
                if(iterator->estaVazio()){
                                          std::cout<<"Nao ha nenhum cadastro de clientes"<<std::endl;
                                          std::cin.ignore();
                                          std::cin.get();
                                          break;
                }// fim do if esta vazio
                std::cout<<superior<<std::endl;
                std::cout<<lateral<<" ID "<<lateral<<"    TITULO     ";
                std::cout<<lateral<<"PRECO_COMPRA"<<lateral<<"PRECO_LOCACAO"<<lateral<<" SITUACAO  |"<<std::endl;
                //std::cout<<" |__ID_________TITULO_______PRECO_COMPRA___|PRECO_LOCACAO___SITUACAO___"<<lateral<<std::endl;
                std::cout<<inferior<<std::endl;
                iterator->inicio();
                bool condicao=true;
                while(condicao){
                       filme = iterator->obterFilme();
                       unsigned int id;
                       int precoDeCompra, precoDeLocacao;
                       std::string titulo;
                       bool situacao;
                       filme.obter( id ,titulo, precoDeCompra, precoDeLocacao, situacao);
                       std::cout<<lateral<<std::setw(4)<<id<<lateral<<std::setw(15)<<titulo<<lateral;
                       std::cout<<"R$ "<<std::setw(6)<<precoDeCompra<<",00"<<lateral<<"R$ "<<std::setw(7)<<precoDeLocacao<<",00"<<lateral;
                       if(situacao) std::cout<<std::setw(10)<<" LOCADO"<<lateral<<std::endl;
                         else std::cout<<std::setw(10)<<"NAO-LOCADO"<<lateral<<std::endl;  
                       
                       //std::cout<<"ID: "<<id<<" \nName: "<<nome<<" \nTelefone: "<<telefone<<" \nemial: "<<email<<std::endl;
                       
                       condicao = iterator->proximo();
                }
                std::cout<<inferior<<std::endl;
				std::cout<<std::endl<<std::endl<<"<ENTER> PARA CONTINUAR"; 

                std::cin.get();
				std::cin.get();
				break;
			}//fim case 5
		}//fim do switch
	}//fim do while
}//fim do metodo manter menu filme

void Interface::lerDadosDoFilme(Filme &filme)
/*inicio do metodo de ler os dados do filme
//o filme deve conter os seguintes dados:
    NRO IDENTIFICACAO
    TITULO OU NOME
    PREÇO DE LOCACAO
    PREÇO DE VENDA
    SITUACAO*/    
{
    std::string titulo;
    unsigned int id;
    int precoCompra, precoLocacao, situacaoTemp;
    bool situacao;
    std::cout<<"ID: ";
    std::cin>>id;
    std::cout<<"Titulo: ";
    std::cin.ignore();
    getline(std::cin,titulo);
    std::cout<<"Preco de Compra: ";
    std::cin>>precoCompra;
    std::cout<<"Preco de Locacao: ";
    std::cin>>precoLocacao;
    //inicializer a var temp com 3 apenas para entrar no laço
    for(situacaoTemp=3; situacaoTemp!=1 && situacaoTemp!=0; ){
       std::cout<<"1-Locado\n0-Nao locado\nSituacao: ";
       std::cin>>situacaoTemp;
    }
    situacao=static_cast<bool>(situacaoTemp);
    filme.atribuir(id, titulo, precoCompra, precoLocacao, situacao);
}//fim metodo lerDadosDoFilme

void Interface::lerDadosDoFilmeAlteracao(Filme &filme)
{//inicio do metodo lerDadosDoFilmeAlteracao
          std::string titulo;
          unsigned int id;
          int precoCompra, precoLocacao, situacaoTemp;
          bool situacao;
          filme.obter(id, titulo, precoCompra, precoLocacao, situacao);
          std::cout<<"ID: "<<id<<std::endl;
          std::cout<<"Titulo: ";
          std::cin.ignore();
          getline(std::cin,titulo);
          std::cout<<"Preco de Compra: ";
          std::cin>>precoCompra;
          std::cout<<"Preco de Locacao: ";
          std::cin>>precoLocacao;
          //inicializer a var temp com 3 apenas para entrar no laço
          for(situacaoTemp=3; situacaoTemp!=1 && situacaoTemp!=0; ){
                std::cout<<"1-Locado\n0-Nao locado\nSituacao: ";
                std::cin>>situacaoTemp;
          }
          situacao=static_cast<bool>(situacaoTemp);
          filme.atribuir(id, titulo, precoCompra, precoLocacao, situacao);
}//fim do metodo lerDadosDoFilmeAlteracao

void Interface::escreverDadosDoFilme(const Filme &filme)
{//inicio do metodo escreverDadosDoFilme
     std::string titulo;
     int pCompra, pLocacao;
     bool situacao;
     unsigned int id;
     filme.obter(id, titulo, pCompra, pLocacao, situacao);
     std::cout<<"Id: "<<id<<std::endl;
     std::cout<<"Titulo: "<<titulo<<std::endl;
     std::cout<<"Preco Compra: "<<pCompra<<std::endl;
     std::cout<<"Preco Locacao: "<<pLocacao<<std::endl;
     std::cout<<"Situacao: "<<situacao<<std::endl;
}//fim do metodo escreverDadosDoFilme

//********************************************************
//  TELAS PARA LOCACAO
//********************************************************
void Interface::menuManterLocacao()
{
    Persistencia item;
	int opcao=1;
	while(opcao){
		system("cls");
		std::cout<<std::endl<<"	MENU MANTER LOCACAO"<<std::endl;
		std::cout<<std::endl<<"	1 - LOCAR FILME";
		std::cout<<std::endl<<"	2 - DEVOLVER FILME";
		std::cout<<std::endl<<"	3 - CANCELAR";
		std::cout<<std::endl<<"	4 - CONSULTAR";
		std::cout<<std::endl<<"	0 - SAIR";	
		std::cout<<std::endl<<std::endl<<"	OPCAO: ";
		std::cin>>opcao;
		switch(opcao){
			case 1:{// case 1 - locar filme
			//FOODA
			/* para locar um filme e preciso ter o nome do cliente e o nome do filme
			verificar a situacao do filme			
			*/
			    unsigned int idLocacao, idCliente, idFilme;
			    std::cout<<"Informe:\n ID Locacao: ";
			    std::cin.ignore();
                std::cin>>idLocacao;
			    Locacao locacao;
			    if(!item.recuperar(idLocacao, &locacao))
			    //eu quero a negacao do recuperar pois eu qro um id n existente
			    {
                    std::cout<<" ID Cliente: ";
			        std::cin>>idCliente;
			        Cliente cliente;
			        if(item.recuperar(idCliente, &cliente)){//if 1
                       std::cout<<"  NOme: "<<cliente.obterNome()<<std::endl;
                       std::cout<<" ID Filme: ";
                       std::cin>>idFilme;
                       Filme filme;
                       if(item.recuperar(idFilme, &filme)){
                          //std::cout<<"  Titulo: "<<filme.obterTitulo()<<std::endl;
                          //std::cout<<" SITUACAO= "<<!filme.obterSituacao()<<std::endl;
                          if(!filme.obterSituacao()){//if 3
                          //negacao= eu qro q o filme n esteja locado
                             //std::cout<<"IF 3 - ok!"<<std::endl;
                             int precoLocacao=filme.obterPrecoDeLocacao();
                             //std::cout<<"P Loc - ok: "<<filme.obterPrecoDeLocacao()<<std::endl;
                             Locacao locacao(idLocacao, idCliente, idFilme, precoLocacao, !filme.obterSituacao());
                             //std::cout<<"Situacao locacao: "<<locacao.obterSituacao()<<std::endl;
                             
                             if(!item.remover(&filme)) std::cout<<"Erro na exclusao do filme alterado!"<<std::endl;
                             //eh preciso remover o filme para a atribuicao da nova situacao
                             
                             filme.atribuirSituacao(locacao.obterSituacao());
                             
                             //std::cout<<"Obter situacao - ok: "<<filme.obterSituacao()<<std::endl;
                             
                             if(!item.gravar(&filme)) std::cout<<"Erro na gravacao do filme"<<std::endl;
                             //std::cout<<"Situacao filme: "<<filme.obterSituacao()<<std::endl;
                             if(item.gravar(&locacao)) std::cout<<"Locacao Concluida"<<std::endl;
                               else std::cout<<"Erro na gravacao da locacao"<<std::endl;                         
                             }//fim if 3
                          else {//else if 3
                               std::cout<<"Filme Locado"<<std::endl;
                               std::cout<<"Nao eh possivel Fazer a locacao"<<std::endl;
                          }// fim else if 3                   
                       }//fim if 2
                       else {//else if 2
                            std::cout<<"Filme nao encontrado"<<std::endl;
                            std::cout<<"Nao eh possivel fazer a locacao"<<std::endl;
                       }//fim else of2   
                    }//fim if 1
                    else {//else if 1
                         std::cout<<"NOme nao encontrado"<<std::endl;
                         std::cout<<"Nao eh possivel fazer a locacao"<<std::endl;
                    }//fim else if 1
                }//fim if 0
                else {//else if 0
                       std::cout<<"ID locacao jah existe"<<std::endl;
                       std::cout<<"Nao eh possivel fazer a locacao"<<std::endl;
                     }//fim else if 0
                
                
                /*std::string nome, email, titulo;
                unsigned int idLocacao, idCliente, idFilme;
			    int precoLocacao, precoCompra;
			    bool situacao;
			    long telefone;
                lerDadosDaLocacao(idLocacao, idCliente, idFilme);
				
                Filme filme(idFilme,"",0,0,false);
				item.recuperar(&filme);
				//eh preciso chamar essa funcao para q possa ter os dados atribuidos no objeto
				filme.obter(idFilme, titulo, precoCompra, precoLocacao, situacao);
				std::cout<<"Filme: "<<titulo<<std::endl;
                
                Cliente cliente;
                cliente.atribuir(idCliente,"",0,"");
				item.recuperar(&cliente);
                cliente.atribuir(idCliente, nome, telefone, email);
				std::cout<<"NOme is: "<<nome<<std::endl;
				
                
                if(item.recuperar(&cliente)){
                  if(item.recuperar(&filme)){
                     situacao=filme.obterSituacao();
                     precoLocacao=filme.obterPrecoDeLocacao();
                     if(!situacao){
                        situacao=!situacao;
                        Locacao locacao(idLocacao, idCliente, idFilme, precoLocacao, situacao);
                        filme.atribuirSituacao(situacao);
                        //alterando a situacao do filme
                        std::cout<<"Locacao efetuada com Sucesso!"<<std::endl;
                     }else std::cout<<"Filme Locado"<<std::endl;
                  }else std::cout<<"Filme nao encontrado!"<<std::endl; 
                }else std::cout<<"Cliente nao encontrado!"<<std::endl;*/
                               
                //std::cout<<std::endl<<"LOCAR FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 1	
			case 2:{//case 2 - devolver filme
				//para devolver um filme eh preciso:
                //pedir para informar o id de locacao
                //verificar se o id existe
                //remover a locacao
                //informar o preco a pagar
                //alterar a situacao do filme
                unsigned int idLocacao;
                std::cout<<"ID Locacao: ";
                std::cin>>idLocacao;
                Locacao locacao;
                if(item.recuperar(idLocacao, &locacao)){//if 1
                   std::string titulo, nome;
                   unsigned int idCliente, idFilme;
                   int precoLocacao;
                   bool situacao;
                   locacao.obter(idLocacao, idCliente, idFilme, precoLocacao, situacao);
                   Cliente cliente;
                   item.recuperar(idCliente, &cliente);
                   nome=cliente.obterNome();
                   Filme filme;
                   item.recuperar(idFilme, &filme);
                   titulo=filme.obterTitulo();
                   std::cout<<"Nome do Cliente: "<<nome<<std::endl;
                   std::cout<<"Titulo do Filme: "<<titulo<<std::endl;
                   std::cout<<"Preco de Locacao: "<<precoLocacao<<std::endl;
                   std::cout<<"Confirma os Dados[s/n]: ";
                   std::cin.ignore();
                   char resp;
                   std::cin>>resp;
                   if(resp != 's' && resp != 'S' ) resp = 'n' ;
                   if(resp == 's' || resp == 'S' ){// if resposta
                       situacao=locacao.obterSituacao();
                       if(item.remover(&locacao)){//if remover item
                           //item.recuperar(idFilme, &filme);
                           item.remover(&filme);
                           filme.atribuirSituacao(!situacao);
                           item.gravar(&filme);
                           std::cout<<"Filme Devolvido com Sucesso!"<<std::endl;
                           std::cout<<"Preco a pagar pela Locacao eh R$ "<<precoLocacao<<",00"<<std::endl;
                       }//fim if remover item
                       else {//else iif remover item
                            std::cout<<"Erro ao fazer a devolucao - item remover!"<<std::endl;
                            }//fim else if remover                            
                   }//fim if resposta
                   else {//else if resposta
                        std::cout<<"Operacao Cancelada Pelo Usuario"<<std::endl;
                        std::cout<<"Nao foi possivel concluir a devolucao"<<std::endl;
                        }//fim else if resposta
                }//fim if 1
                else {//else if 1
                     std::cout<<"ID inexistente"<<std::endl;
                     }//fim else if 1                
                //std::cout<<std::endl<<"DEVOLVER FILME EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 2
			case 3:{//case 3 - cancelar
			    //procedimentos para a construcao do metodo cancelar
			    //- ler o id para o cancelamento
			    //- verificar se o id existe
			    //- se existir e so mandar remover do arquivo a locacao 
			    //e logo em seguida trocar a situacao do filme q estava nessa locacao
			    // AHUIHAIUHAIUHA - e a mesma coisa do primeiro case > EU AXO  XD
			    
			    unsigned int idLocacao;
                std::cout<<"ID Locacao: ";
                std::cin>>idLocacao;
                Locacao locacao;
                if(item.recuperar(idLocacao, &locacao)){//if 1
                   std::string titulo, nome;
                   unsigned int idCliente, idFilme;
                   int precoLocacao;
                   bool situacao;
                   locacao.obter(idLocacao, idCliente, idFilme, precoLocacao, situacao);
                   Cliente cliente;
                   item.recuperar(idCliente, &cliente);
                   nome=cliente.obterNome();
                   Filme filme;
                   item.recuperar(idFilme, &filme);
                   titulo=filme.obterTitulo();
                   std::cout<<"Nome do Cliente: "<<nome<<std::endl;
                   std::cout<<"Titulo do Filme: "<<titulo<<std::endl;
                   std::cout<<"Preco de Locacao: "<<precoLocacao<<std::endl;
                   std::cout<<"Confirma os Dados[s/n]: ";
                   std::cin.ignore();
                   char resp;
                   std::cin>>resp;
                   if(resp != 's' && resp != 'S' ) resp = 'n' ;
                   if(resp == 's' || resp == 'S' ){// if resposta
                       situacao=locacao.obterSituacao();
                       if(item.remover(&locacao)){//if remover item
                           //item.recuperar(idFilme, &filme);
                           item.remover(&filme);
                           filme.atribuirSituacao(!situacao);
                           item.gravar(&filme);
                           std::cout<<"Filme Cancelado com Sucesso!"<<std::endl;
                       }//fim if remover item
                       else {//else iif remover item
                            std::cout<<"Erro ao fazer o Cancelamento - item remover!"<<std::endl;
                            }//fim else if remover                            
                   }//fim if resposta
                   else {//else if resposta
                        std::cout<<"Operacao Cancelada Pelo Usuario"<<std::endl;
                        std::cout<<"Nao foi possivel concluir o cancelamento"<<std::endl;
                        }//fim else if resposta
                }//fim if 1
                else {//else if 1
                     std::cout<<"ID inexistente"<<std::endl;
                     }//fim else if 1   
                			    
			    
				//std::cout<<std::endl<<"CANCELAR LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 3
			case 4:{//case 4 - consultar
			//esse metodo como os outros metodos de consulta sera preciso construir
			//uma classe para "transporte" dos dados - um tipo iterator
                unsigned int idLocacao;
                std::cout<<"Digite o ID de Locacao: ";
                std::cin>>idLocacao;
                Locacao locacao;
                if(item.recuperar(idLocacao, &locacao)){
                   unsigned int idCliente, idFilme;
                   int precoDeLocacao;
                   bool situacao;
                   std::string nome, titulo,
                               superior="  ___________________________________",
				               inferior=" |___________________________________|",
				               lateral=" | ";                   
                   locacao.obter(idLocacao, idCliente, idFilme, precoDeLocacao, situacao);
                   Cliente cliente;
                   item.recuperar(idCliente, &cliente);
                   nome=cliente.obterNome();
                   Filme filme;
                   item.recuperar(idFilme, &filme);
                   titulo=filme.obterTitulo();
                   std::cout<<superior<<std::endl;
                   std::cout<<lateral<<"      ID Locacao: "<<std::setw(15)<<idLocacao<<lateral<<std::endl;
                   std::cout<<lateral<<"         Cliente: "<<std::setw(15)<<nome<<lateral<<std::endl;
                   std::cout<<lateral<<"           Filme: "<<std::setw(15)<<titulo<<lateral<<std::endl;
                   std::cout<<lateral<<"Preco de Locacao: R$"<<std::setw(10)<<precoDeLocacao<<",00"<<lateral<<std::endl;
                   std::cout<<inferior<<std::endl;    
                }//fim if 1
                else {//else if 1
                     std::cout<<"ID Inexistente!"<<std::endl;                     
                     }//fim else if 1
				//std::cout<<std::endl<<"CONSULTAR LOCACAO EM CONSTRUCAO"<<std::endl<<"Tecle <enter>";
				std::cin.get();
				std::cin.get();
				break;
			}//fim case 4
		}//fim do switch	
    }//fim do while
}//fim do metodo menuManterLocacao

/*void Interface::lerDadosDaLocacao(unsigned int idLocacao, unsigned int idCliente, unsigned int idFilme)
{//inicio do metodo ler dados da locacao
     std::cout<<"ID Locacao: ";
     std::cin>>idLocacao;
     std::cout<<"ID Cliente: ";
     std::cin>>idCliente;
     std::cout<<"ID Filme: ";
     std::cin>>idFilme;
}//fim do metodo ler dados da locacao
*/

#endif /*INTERFACE_H_*/
