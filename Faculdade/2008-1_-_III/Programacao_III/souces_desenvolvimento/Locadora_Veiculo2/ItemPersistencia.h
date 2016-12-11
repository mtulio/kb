#ifndef ITEMPERSISTENCIA_H_
#define ITEMPERSISTENCIA_H_

#include<string>

class ItemPersistencia
{
protected:
	int identificador;
	const int tipoDaClasse;

public:
	ItemPersistencia(const int identificador, const int tipoDaClasse):
					identificador(identificador), tipoDaClasse(tipoDaClasse){}
	virtual ~ItemPersistencia(){};
	int obterIdentificador()const { return identificador;}
	int obterTipoDaClasse()const {return tipoDaClasse;}
	virtual void materializar(const std::string &linha) = 0;
	virtual std::string desmaterializar()const = 0;	
};


#endif /*ITEMPERSISTENCIA_H_*/
