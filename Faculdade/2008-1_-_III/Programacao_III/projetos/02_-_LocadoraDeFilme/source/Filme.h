#ifndef FILME_H_
#define FILME_H_

#include<string>
#include"ItemPersistencia.h"

//********************************************************************
//        Classe Testada: OK - By MT                                 *
//********************************************************************

//TIPO DA CLASSE 1 = FILME
//O objeto desta classe contem os dados de um filme
class Filme: public ItemPersistencia
//Define a classe Filme que eh Heranca da classe ItemPersistencia
//a classe Filme eh sub-classe da super-classe ItemPersistencia
{//inicio

   //Atributos
   private:
      std::string titulo;
      int precoDeCompra;
      int precoDeLocacao;
      bool situacao;
      
   //Metodos
   public:
      /*Contrutor e Destrutor*/
      Filme():ItemPersistencia(0){tipoDaClasse=1;};
      Filme( unsigned int identificador, const std::string &titulo, int precoDeCompra, 
             int precoDeLocacao, bool situacao);
      ~Filme(){};
      /*Definicao dos metodos da calsse Filme*/
      void obter( unsigned int &identificador, std::string &titulo, int &precoDeCompra,
                  int &precoDeLocacao, bool &situacao)const;
      void atribuir( unsigned int identificador, const std::string &titulo, int precoDeCompra,
                     int precoDeLocacao, bool situacao);
      
      void materializar(const std::string linha);
      const std::string desmaterializar();
            
      //Metodo inline implicito
      int obterPrecoDeCompra()const { return precoDeCompra; };
      int obterPrecoDeLocacao()const { return precoDeLocacao; };
      bool obterSituacao()const { return situacao; };
      const std::string obterTitulo() { return titulo; };
      void atribuirSituacao(bool situacao) { this->situacao = situacao; };	

};//fim da definicao da classe Filme

//***************************************************************************************

Filme::Filme( unsigned int identificador, const std::string &titulo, int precoDeCompra, 
							int precoDeLocacao, bool situacao):
   ItemPersistencia(identificador),
   titulo(titulo),
   precoDeCompra(precoDeCompra),
   precoDeLocacao(precoDeLocacao),
   situacao(situacao)
{//inicio do bloco de instrucoes do construtor
	tipoDaClasse=1;
/*Atributo herdado da classe ItemPersistencia
Tem como funcao identificar o tipo da classe, o tipo da classe Filme eh 1.
*/
}//fim do metodo construtor

//***************************************************************************************

void Filme::obter( unsigned int &identificador, std::string &titulo, int &precoDeCompra, 
										int &precoDeLocacao, bool &situacao)const
{//inicio 
   identificador= this->identificador;
   titulo=this->titulo;
   precoDeCompra=this->precoDeCompra;
   precoDeLocacao=this->precoDeLocacao;
   situacao=this->situacao;
}//fim do metodo obter

//***************************************************************************************

void Filme::atribuir( unsigned int identificador, const std::string &titulo, int precoDeCompra, 
											int precoDeLocacao, bool situacao)
{//inicio do atribuir
   this->identificador=identificador;
   this->titulo=titulo;
   this->precoDeCompra=precoDeCompra;
   this->precoDeLocacao=precoDeLocacao;
   this->situacao=situacao;
}//fim do metodo atribuir

//***************************************************************************************

void Filme::materializar(const std::string linha)
/*Tem como obter os dados de uma string e armazenar nos seus respectivos atributos*/
/*Materializar = Separar o valor de uma string e armazena-lo em seu devido lugar*/
{//inicio do metodo materializar
   unsigned int pos=0, 
                aux=0;
   int auxInt=0;
   bool auxSitu;
   std::string strAux;
   
   /*Materializando identificador*/
   for( ; linha[pos]!=';' ; pos++) aux = aux*10 + static_cast<unsigned int>(linha[pos])-48;
   //Usando o metodo static_cast para a conversao de tipos, no caso sting para unsigned int
   identificador = aux;
   
   /*Materializando titulo*/
   for(pos++ ; linha[pos]!=';' ; pos++) strAux += linha[pos];
   titulo=strAux;
   
   /*Materializando precoDeCompra*/
   for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + static_cast<int>(linha[pos])-48;
   precoDeCompra=auxInt;
   
   /*Materializando precoDeLocacao*/
   auxInt=0;
   for(pos++ ; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + static_cast<int>(linha[pos])-48;
   precoDeLocacao=auxInt;
   
   /*Materializando situacao*/
   auxInt=0;
   for(pos++ ; linha[pos]!=';' ; pos++) auxInt = static_cast<int>(linha[pos])-48;
   auxSitu = static_cast<bool>(auxInt);
   situacao = auxSitu;
   
   //teste
   //std::cout<<"ID: "<<identificador<<" Titulo: "<<titulo<<" P.Cp: "<<precoDeCompra<<" P.Lc: "<<precoDeLocacao<<" Sit: " <<situacao<<std::endl;   

   //retornando ao ponto de chamada do metodo void   
}//fim do metodo materizalizar

//***************************************************************************************

const std::string Filme::desmaterializar()
/*Este metodo tem como funcao "pegar" os valores dos atributos e armazena-los em uma string*/
/*Desmaterializar = Obter os atributos e armazena-los em uma string. "Desmaterializando os atributos"*/
{
   std::string linha, 
               idString;
   
   /*Desmaterializando identificador*/
   for(unsigned int aux=identificador ; aux ; ){
   //repetira enquanto aux for inteiro positivo
      char letra = (aux%10) + 48;
      idString = letra + idString;
      //lembrando q a ordem altera os fatores
      // idString = idStrig + letra ou idString += letra, eh diferente de
      // idString = letra + idString
      //pois o 1 exemplo tem como result de letra=a e idString=b, entao 
      //idString tera o valor de "ba"
      //e no segundo exemplo idString tera o valor de "ab"
      //std::cout<<"idString="<<idString<<std::endl;
      aux = aux/10;
   }//fim do for   
   linha+=idString;

   linha+=";";

   /*Desmaterializando titulo*/
   linha+=titulo;
   linha+=";";
    
   /*Desmaterializando precoDeCompra*/
   std::string pCompraString;
   for(int aux=precoDeCompra; aux; ){
      char letra = (aux%10)+48;
      pCompraString = letra + pCompraString;
      aux = aux/10;
   }
   linha += pCompraString;
   linha += ";";
   
   /*Desmaterializando precoDeLocacao*/
   std::string pVendaString;
   for(int aux=precoDeLocacao; aux; ){
      char letra = (aux%10) + 48;
      pVendaString = letra + pVendaString;
      aux = aux/10;
   }
   linha += pVendaString;
   linha += ";";
   
   /*Desmaterializando situacao*/
   char situacaoString=static_cast<char>(situacao)+48;
   linha += situacaoString;
   linha += ";";
   
   //retornando a linha para o metodo
   return linha;
//aff q tenso esse metodo...       
}//fim do metodo desmaterizalizar

//***************************************************************************************

#endif /*FILME_H_*/
