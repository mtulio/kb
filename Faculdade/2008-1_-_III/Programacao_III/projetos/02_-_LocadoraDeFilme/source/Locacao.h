#ifndef LOCACAO_H_
#define LOCACAO_H_

#include"ItemPersistencia.h"

//********************************************************************
//        Classe Testada: OK - By MT                                 *
//********************************************************************

// TIPO DE CLASSE 2 = LOCACAO
//O objeto desta classe contem os dados de uma Locacao
class Locacao: public ItemPersistencia
/* Esta classe herda a classe ItemPersistencia*/
//Ao herdar uma classe vc tem "acesso direto" todos os seus atributos e metodos dela
{//Inicio da definicao da classe Locacao
   
   //Atributos
   private:
      unsigned int idCliente;//e o numero de identificacao do cliente, um codigo para identificalo
      unsigned int idFilme;//e o codigo do filme
      int precoDeLocacao;
      bool situacao;//situação da fita, locado ou nao
   
   //Metodos
   public:
      /*Contrutor e Destrutor*/
      Locacao():ItemPersistencia(0){ tipoDaClasse=2; };
      Locacao( unsigned int identificador, unsigned int idCliente, unsigned int idFilme,
               int precoDeLocacao, bool situacao);
      
      /*Definicao dos metodos da calsse Filme*/
      void obter( unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme,
                  int &precoDeLocacao, bool &situacao)const;
      void atribuir( unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme,
                     int &precoDeLocacao, bool situacao);
      bool obterSituacao()const { return situacao; };
      void atribuirSituacao(bool situacao) { this->situacao=situacao; };      
      void materializar(const std::string str);
      const std::string desmaterializar();
      
};//fim da definicao da classe Locacao

//***************************************************************************************

Locacao::Locacao( unsigned int identificador, unsigned int idCliente, unsigned int idFilme, 
                    int precoDeLocacao, bool situacao):
   ItemPersistencia(identificador),
   idCliente(idCliente),
   idFilme(idFilme),
   precoDeLocacao(precoDeLocacao),
   situacao(situacao)

{//inicio do bloco de comandos do construtor
   tipoDaClasse=2;
   //Atributo herdado da classe ItemPersistencia, para identificar o tipo da classe
}//fim metodo construtor

//***************************************************************************************

void Locacao::obter( unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme, 
                     int &precoDeLocacao, bool &situacao)const
{//inicio
   identificador = this->identificador;
   idCliente = this->idCliente;
   idFilme = this->idFilme;
   precoDeLocacao = this->precoDeLocacao;
   situacao = this->situacao;
}//fim obter

//***************************************************************************************

void Locacao::atribuir(unsigned int &identificador, unsigned int &idCliente, unsigned int &idFilme, 
                        int &precoDeLocacao, bool situacao)
{//inicio
   this->identificador=identificador;
   this->idCliente=idCliente;
   this->idFilme=idFilme;
   this->precoDeLocacao=precoDeLocacao;
   this->situacao=situacao;                                
}//fim atribuir

//***************************************************************************************

void Locacao::materializar(const std::string linha)
/*Tem como obter os dados de uma string e armazenar nos seus respectivos atributos*/
/*Materializar = Separar o valor de uma string e armazena-lo em seu devido lugar*/
{//inicio do metodo materializar
   //std::cout<<" Inicio do materializar"<<std::endl;
   //ENCONTREI O ERRO DENTRO DO MATERIALIZAR
   unsigned int aux=0,
                pos=0;
   int auxInt=0;
   bool auxBool;

   /*Materializando identificador*/
   for(pos=0; linha[pos]!=';' ; pos++) aux = aux*10 + static_cast<unsigned int>(linha[pos])-48;
   identificador=aux;
   //std::cout<<" Materializado Id Locacao: "<<identificador<<std::endl;
   
   /*Materializando idCliente*/
   aux=0;
   for(pos++; linha[pos]!=';' ; pos++) aux = aux*10 + static_cast<unsigned int>(linha[pos])-48;
   idCliente = aux;
   //std::cout<<" Materializado Id Cliente: "<<idCliente<<std::endl;
   
   /*Materializando idFilme*/
   aux=0;
   for(pos++; linha[pos]!=';' ; pos++) aux = aux*10 + static_cast<unsigned int>(linha[pos])-48;
   idFilme=aux;
   //std::cout<<" Materializado id Filme: "<<idFilme<<std::endl;
   
   /*Materializando precoDeLocacao*/
   for(pos++; linha[pos]!=';' ; pos++) auxInt = auxInt*10 + static_cast<int>(linha[pos])-48;
   precoDeLocacao=auxInt;
   //std::cout<<" Materializado Preco de locacao: "<<precoDeLocacao<<std::endl;
   
   /*Materializando situacao*/
   auxInt=0;
   //std::cout<<"= "<<str[pos--]<<" - "<<str[pos++]<<std::endl;
   for(pos++; linha[pos]!=';' ; pos++) {
               auxInt = static_cast<int>(linha[pos])-48;
               //std::cout<<" ? "<<str[pos];
   }//fim for
   //std::cout<<"Aux int = "<<auxInt<<std::endl;
   auxBool=static_cast<bool>(auxInt);
   situacao=auxBool;
   //std::cout<<" Materializado Situacao: "<<situacao<<std::endl;
   //std::cout<<" FIM do materializar"<<std::endl;
   
   //Metodo void, retornando ao ponto de chamada
}//fim do metodo materializar

//***************************************************************************************

const std::string Locacao::desmaterializar()
/*Este metodo tem como funcao "pegar" os valores dos atributos e 
armazena-los em uma string*/
/*Desmaterializar = Obter os atributos e armazena-los em uma string. 
"Desmaterializando os atributos"*/
{//inicio do metodo desmaterializar
//erro tambem
   std::string linha, 
               idString;
   
   /*Desmaterializando identificador*/
   for(int aux=identificador; aux; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      idString = letra + idString;
      aux = aux/10;
   }//fim for
   //std::cout<<"Linha "<<str;
   linha += idString;   
   linha+=";";
   
   /*Desmaterializando idCliente*/
   std::string idClieString;
   for(int aux=idCliente; aux; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      idClieString = letra + idClieString; //concatenado strings
      aux = aux/10;
   }//fim for
   //std::cout<<str;
   linha += idClieString;
   linha += ";";
   
   /*Desmaterializando idFilme*/    
   std::string idFilmeString;
   for(int aux=idFilme; aux ; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      idFilmeString = letra + idFilmeString;
      aux=aux/10;
   }//fim for
   //std::cout<<linha;
   linha += idFilmeString;
   linha += ";";
   
   /*Desmaterializando precoDeLocacao*/    
   std::string pLocString;
   for(int aux=precoDeLocacao; aux; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      pLocString = letra + pLocString;
      aux = aux/10;
   }//fim for
   //std::cout<<" "<<str;
   linha += pLocString;
   linha += ";";
    
   /*Desmaterializando situacao*/        
   std::string situacaoString;
   situacaoString = static_cast<char>(situacao)+48;
   //char letra=static_cast<char>(situacao)+48;
   //std::cout<<std::endl<<letra<<" "<<std::endl;
   linha += situacaoString;
   linha += ";";
   //std::cout<<str;
   //linha=str;
   
   //retorna a sting linha para o metodo
   return linha;                 
}//fim do metodo desmaterializar

//***************************************************************************************

#endif /*LOCACAO_H_*/
