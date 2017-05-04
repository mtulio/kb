#ifndef ITEMPERSISTENCIA_H_
#define ITEMPERSISTENCIA_H_

#include<string>
//CLASSE "PAI"

class ItemPersistencia{

//atributos protected sao como private, para as classes membros(filhos)
protected:
	unsigned int identificador;
	unsigned int tipoDaClasse;
	// O atributo idClasse serve para identificar o tipo da classe, que são:
	// 	0 - Cliente
	//	1 - Carro
	//	2 - Locacao
	
//metodos
public:
	// construtor com o paramentro inicializdor do atributo identificador
	// lembrando que o atributo tipoDaClasse nao foi inicializado, entao sera inicializado na
	// classe membro
	ItemPersistencia(unsigned int identificador): identificador(identificador){}
	
	//destrutor virtual, (CRIAR DEFINICAO)
	virtual ~ItemPersistencia(){}
	
	// metodos virtuais puros. 
	// Metodos virtuais puros NUNCA podem ser declarados na sua classe, mas sim apenas nas classes membros
	// Para escolha dos metodos virtuais puros sao analizados os metodos em comum das classes membros
	virtual const std::string desmaterializar() = 0;
	virtual void materializar(std::string const &str) = 0;
	
	//metodos normais inline
	unsigned int obterIdentificador()const { return identificador; };
	unsigned int obterTipoDaClasse()const { return tipoDaClasse; };
			
};//fim da classe

#endif /*ITEMPERSISTENCIA_H_*/
