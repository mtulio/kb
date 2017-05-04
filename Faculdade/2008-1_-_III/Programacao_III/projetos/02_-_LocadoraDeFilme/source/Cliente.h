#ifndef CLIENTE_H_
#define CLIENTE_H_

#include<string>
#include"ItemPersistencia.h"

//***************************************************************************************
//          Classe Testada: OK - By MT                                                  *
//***************************************************************************************

//TIPO DE CLASSE 0 = CLIENTE
//O objeto desta classe contem os dados do cliente
class Cliente: public ItemPersistencia
//Herda a classe ItemPersistencia
//ItemPersistencia é super-classe e Cliente é sub-classe
{
   //Atributos
   private:
      std::string nome;
      long telefone;
      std::string email;
   //Metodos ou procedimentos
   public:
      /*Construtor e Destrutor*/
      //Comtrutor inline implicito sem parametros, tem a função apenas de inicializar 
      //o atributo tipoDaClasse.
      Cliente():ItemPersistencia(0){tipoDaClasse=0;};
	  Cliente( unsigned int identificador, const std::string &nome, 
               long telefone, const std::string &email);
      //Destrutor Default
      ~Cliente(){};
	  /*Definição dos metodos da classe Cliente*/
      void obter( unsigned int &identificador,std::string &nome, 
                  long &telefone,std::string &email)const;
      void atribuir( unsigned int identificador, const std::string &nome,
                      long telefone, const std::string &email);
      const std::string obterNome(){return nome;};
      
      void materializar(const std::string linha);
	  //recebe uma string como parametro e armazena nos atributos os respectivos valores
      const std::string desmaterializar();
      //transforma atributos em uma string, esta obtendo os dados dos atributos para string	  
};//Fim da definição da classe Cliente

//***************************************************************************************
//Descricao do Contrutor
Cliente::Cliente(	unsigned int identificador, const std::string &nome, 
									long telefone, const std::string &email):
   ItemPersistencia(identificador),
   //recebe um numero(unsigned int) digitado "no programa principal"
   nome(nome),
   telefone(telefone),
   email(email)
{//inicio do bloco de comandos do Contrutor
   tipoDaClasse=0;
/* Atributo herdado da classe ItemPersistencia.
O tipo 0, significa que é a classe Cliente, cada classe tem o seu tipo.
*/
}//fim do Contrutor Cliente

//***************************************************************************************

void Cliente::obter( unsigned int &identificador,std::string &nome,
											long &telefone,std::string &email)const
/* Este metodo tem como funcao retornar os valores dos atributos aos seus 
argumentos ou parametros. */
{//inicio
   identificador = this->identificador;
   nome = this->nome;
   telefone = this->telefone; 
   email = this->email; 
}//fim do metodo obter

//***************************************************************************************

void Cliente::atribuir(	unsigned int identificador,const std::string &nome,
												long telefone,const std::string &email)
/* Este metodo tem como funcao atribuir os valores revebidos pelos seus argumentos
ou parametros aos atributos desta classe e de sua super-classe.
*/
{//inicio
   this->identificador=identificador;
   this->nome=nome;
   this->telefone=telefone; 
   this->email=email; 
}//fim do metodo atribuir

//***************************************************************************************

const std::string Cliente::desmaterializar()
/* Este metodo tem como funcao converter(transformar) os atributos em 
uma string e retorna-la pelo nome do metodo
*/
{//inicio
   std::string linha, 
               idString;

   /*Convertendo o identificador*/
   for(unsigned int aux = identificador ; aux ; ){//inicio
   //Enquanto aux for maior que 0, este laco se repetira
      char letra = (aux%10) + 48;
      //usando o metodo de conversao de acordo com a tabela ASCII
      
      idString = letra + idString;
      //lembrando que String = String + varString eh diferente de String = VarString + String
      //a concatenacao da string existente com a nova string eh diferente
	  
      aux = aux/10;
	  //Apos a conversao do ultimo digito do nro eh feita essa divisao para passar
	  //para o proximo digito
   }//fim for
   linha = idString;

   //adicionando o ; pois e a regra estabelecida para a divisao dos atributos dentro da string
   //linha += ";"; eh o mesmo que linha = linha + ";";
   linha += ";";

   /*Armazenando o nome na string - n eh preciso converter o nome pois ele jah eh string*/
   linha += nome;
   linha += ";";

   /*Comvertendo o telefone*/
   std::string foneString;
   for(unsigned int aux=telefone;aux;)
   {//inicio for
      char letra = (aux%10)+48;
      foneString = letra + foneString;
      aux  = aux/10;
   }//fim for   
   linha += foneString;

   linha += ";";
   /*Armazenando o email na linha - n eh preciso conversao pois o email jah eh string*/
   linha += email;
   
   linha += ";";
   
   //retornando uma string para o metodo
   return linha;
}//fim do metodo desmaterializar

//***************************************************************************************

void Cliente::materializar(const std::string linha)
/* Metodo tem como funcao converter ou separar os valores que estao em uma string
e armazena-los nos seus respectivos atributos.*/
{//inicio
   unsigned int aux=0, 
                pos=0;
   
   /*Encontrado o identificador*/
   for(; linha[pos]!=';' ; pos++) aux = aux*10 + (linha[pos]-48);
   //este metodo se repetira enquanto nao encontrar o ";" na string linha
   //usando o metodo de conversao da tabela ASCII convertendo string para inteiro
   identificador = aux;
   
   /*Encontrando o nome*/
   std::string strAux = "";
   for(pos++ ; linha[pos]!=';' ; pos++) strAux += linha[pos];
   nome = strAux;
   
   /*Encontrando o telefone*/
   long aux2=0;
   for(pos++ ; linha[pos]!=';' ; pos++) aux2 = aux2*10 + (linha[pos]-48);
   telefone = aux2;
   
   /*Encontrando o email*/
   strAux=""; //dando o valor para string de "vazio", pois ela foi usada anteriormente
   for(pos++ ; linha[pos]!=';' ; pos++) strAux += linha[pos];
   email = strAux;
   //armazenando a string encontrada no atributo
   
   //retornando ao ponto de chamada do metodo sem retornar nenhum valor, pois esse metodo eh void
}//fim do metodo materializar

//***************************************************************************************

#endif /*CLIENTE_H_*/
