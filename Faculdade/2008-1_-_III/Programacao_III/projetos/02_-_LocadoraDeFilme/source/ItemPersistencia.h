#ifndef ITEMPERSISTENCIA_H_
#define ITEMPERSISTENCIA_H_

#include<string>

//********************************************************************
//        Classe Testada: OK - By MT                                 *
//********************************************************************

//Esta classe tem a função de armazenar o identificador e o tipoDeClasse
//de cada objeto pois as classes Cliente, Filme e Locacao tem esse atributo 
//em comum
class ItemPersistencia
//"Super-classe"
{//inicio da definicao da classe
   //Attributos
   protected:
      unsigned int identificador;
      unsigned int tipoDaClasse;
	  //esse atributo serve para identificar o tipo de classe
	  // 0 - CLIENTE
	  // 1 - FILME
	  // 2 - LOCACAO
   //Metodos
   public:
      /*Contrutor e Destrutor*/
      ItemPersistencia(unsigned int identificador):identificador(identificador){};
      //tem como parametro um numero digitado pelo usuario, aonde sera o identificador 
	  //no construtor da classe Cliete tem a inicializacao do atributo tipoClasse
      virtual ~ItemPersistencia(){};
      
      /*Definicao dos metodos*/
      unsigned int obterIdentificador()const{return identificador;};
      unsigned int obterTipoDaClasse()const{return tipoDaClasse;};
      
      /*Ate o momento nao foi preciso usar esses dois metodos*/
      //virtual const std::string desmaterializar() = 0;             
      //virtual void materializar(const std::string s) = 0 ;
      
};//fim da definicao da classe ItemPersistencia

#endif /*ITEMPERSISTENCIA_H_*/
