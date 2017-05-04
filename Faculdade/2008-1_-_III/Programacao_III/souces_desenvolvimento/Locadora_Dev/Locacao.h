#ifndef LOCACAO_H_
#define LOCACAO_H_

#include<string>

#include"ItemPersistencia.h"

class Locacao: public ItemPersistencia
{
private:
	unsigned int idCliente;
	unsigned int idVeiculo;
	unsigned float kmInicial;
	unsigned float kmFinal;
	unsigned float valorPago;
	
public:
	// tipo da classe 2
	Locaocao():ItemPersistencia(0){ tipoDaClasse = 2;}
	
	Locacao(unsigned int identificador, unsigned int idCliente, unsigned int idVeiculo, unsigned float kmInicial, 
			unsigned float kmFinal, unsigned float valorPago):
            ItemPersistencia(identificador),
				idCliente(idCliente),
				idVeiculo(idVeiculo),
				kmInicial(kmInicial),
				kmFinal(kmFinal),
				valorPago(valorPago)
				{
					tipoDaClasse = 2;
				}
	
	unsigned int obterIdCliente()const {return idCliente; }
   void atribuirIdCliente(unsigned int idCliente ){ this->idCliente = idCliente }
	
	unsigned int obterIdVeiculo()const {return idVeiculo; }
   void atribuirIdVeiculo(unsigned int idVeiculo ){ this->idVeiculo = idVeiculo;}
   
   unsigned int obterIdVeiculo()const {return idVeiculo; }
   void atribuirIdVeiculo(unsigned int idVeiculo ){ this->idVeiculo = idVeiculo;}
   
   unsigned float obterKmInicial()const {return kmInicial; }
   void atribuirKmInicial(unsigned float kmInicial ){ this->kmInicial = kmInicial; }
   
   unsigned float obterKmFinal()const {return kmFinal; }
   void atribuirKmFinal(unsigned float kmFinal ){ this->kmFinal = kmFinal; }
   
   unsigned float obterValorPago()const {return valorPago; }
   void atribuirValorPago(unsigned float valorPago ){ this->valorPago = valorPago; }
   
   void materializar(std::string const &str);
	const std::string desmaterializar();
   
};//fim da classe Locacao

void Locacao::materializar(std::string const &str)
{
/*ATRIBUTOS PARA DESMATERIALIZAR
unsigned int idCliente;
unsigned int idVeiculo;
unsigned float kmInicial;
unsigned float kmFinal;
unsigned float valorPago;
*/    
        
   unsigned int aux=0, 
	             pos=0;
	
	/*materializando o identificador*/
	for(; str[pos]!=';' ; pos++) aux = aux*10 + (str[pos]-48);
	identificador = aux;
	
	/*Materializando o idCliente*/
	aux=0;
	for(pos++ ; str[pos]!=';' ; pos++) aux = aux*10 + (str[pos]-48);
	idCliente = aux;
	
	
	/*Materializando o idVeiculo*/
	aux = 0;
	for(pos++ ; str[pos]!=';' ; pos++) aux = aux*10 + (str[pos]-48);
	idVeiculo = aux;
	
	
	/*Materializando o kmInicial*/
   float auxFloat = 0;
	for(pos++ ; str[pos]!= ';' ; pos++) { auxFloat = auxFloat*10 + (str[pos]-48); }
	kmInicial = auxFloat;
	
	
	/*Materializando a carteira de kmFinal*/
   auxFloat = 0;
	for(pos++ ; str[pos]!= ';' ; pos++) { auxFloat = auxFloat*10 + (str[pos]-48);}
	kmFinal = auxFloat;
	
	
	/*Materializando o valorPago*/
	auxFloat = 0;
	for(pos++ ; str[pos]!=';' ; pos++) { auxFloat = auxFloat*10 + (str[pos]-48);}
	valorPago = auxFloat;
     
}// fim materializar

const std::string Locacao::desmaterializar()
{
/*ATRIBUTOS PARA DESMATERIALIZAR
unsigned int idCliente;
unsigned int idVeiculo;
unsigned float kmInicial;
unsigned float kmFinal;
unsigned float valorPago;
*/   

      
   std::string linha, auxString;
	
	/*Desmaterializando o identificador*/
	for(unsigned int aux = identificador ; aux ; ){//inicio
	   //Enquanto aux for maior que 0, este laco se repetira
	   char letra = (aux%10) + 48;
	   //usando o metodo de conversao de acordo com a tabela ASCII
	      
	   auxString = letra + auxString;
	   //lembrando que String = String + varString eh diferente de String = VarString + String
	   //a concatenacao da string existente com a nova string eh diferente
		 
	   aux = aux/10;
	   //Apos a conversao do ultimo digito do nro eh feita essa divisao para passar
	   //para o proximo digito
	}//fim for
	
   linha = auxString;
	linha += ";";
	
	/*Desmaterializando o idCliente*/
	auxString = "";
   for(int aux=idCliente; aux; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      auxString = letra + auxString; //concatenado strings
      aux = aux/10;
   }//fim for
   //std::cout<<str;
   linha += auxString;
	linha += ";";
	
	/*Desmaterializando o idVeiculo*/
	auxString = "";
   for(int aux=idVeiculo; aux; ){
      char letra = (aux%10)+48;
      //std::cout<<std::endl<<letra<<" "<<std::endl;
      auxString = letra + auxString; //concatenado strings
      aux = aux/10;
   }//fim for
   //std::cout<<str;
   linha += auxString;
	linha += ";";
	
	/*Desmaterializando o kmInicial*/
	auxString = "";
	for(float aux=kmInicial ; aux>=0 ; )
	{//inicio for
	   char letra = (aux%10)+48;
	   auxString = letra + auxString;
	   //std::cout<<" char: "<<letra<<" Aux Str: "<<auxStr2<<std::endl<<std::endl;
	   aux  = aux/10;
	}//fim for   
	linha += auxString;
	linha += ";";
	
	/*Desmaterializando kmFinal*/
	auxString = "";
	for(float aux=kmFinal ; aux>=0 ; )
	{//inicio for
	   char letra = (aux%10)+48;
	   auxString = letra + auxString;
	   //std::cout<<" char: "<<letra<<" Aux Str: "<<auxStr2<<std::endl<<std::endl;
	   aux  = aux/10;
	}//fim for   
	linha += auxString;
	linha += ";";
	
	/*Desmaterializando o cpf*/
	auxString = "";
	for(float aux=valorPago ; aux>=0 ; )
	{//inicio for
	   char letra = (aux%10)+48;
	   auxString = letra + auxString;
	   //std::cout<<" char: "<<letra<<" Aux Str: "<<auxStr2<<std::endl<<std::endl;
	   aux  = aux/10;
	}//fim for   
	linha += auxString;
	linha += ";";
	
	return linha;
}//fim do desmaterializar



#endif /*LOCACAO_H_*/
