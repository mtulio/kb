#ifndef CLASSENUMEROS_H_
#define CLASSENUMEROS_H_
#include<string>
class numeros
{//inicio da classe
	//atributos
	private:
		unsigned long numero;
	//metodos
	public:
        //Usando metodo inline implicito: o corpo do metodo está na declaração do mesmo
        inline void atribuir(unsigned long numerop){numero=numerop;}//Tem como objetivo atribuir um valor ao atributo
        inline unsigned long obter()const{return numero;}//Const: n pode alterar os valores dos atributos
        
        unsigned long long fatorial()const;
        bool numeroPerfeito()const;
        bool capicua()const;
        bool quadradoPerfeito()const;
        bool numeroPrimo()const;        
        const std::string mudarBase(unsigned int base)const;        
        unsigned long mdc(unsigned int b)const;
        unsigned long mmc(unsigned int b)const;
        bool primosEntreSi(unsigned int b)const;

		//Metodo construtor inline
        //inline numeros();
       //~numeros(){};
}; //Fim da clase

#endif /*CLASSENUMEROS_H_*/
