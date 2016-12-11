#ifndef RETANGULO_H_
#define RETANGULO_H_

class Retangulo
{
	
	private:
		unsigned int largura;
		unsigned int comprimento;
		
	public:
		Retangulo():largura(0),comprimento(0){};
		//~Retangulo();
		void atribuirLargura(unsigned int largura){this->largura=largura;}
		// so objetos da classe pode acessar oa tributo
		//passando por paramentro a variavel largura
		// atributo recebe a variavel largura que guarda ela
		unsigned int obterLargura(){return this->largura;}
		// metodo obter largura, retorna largura"atributo" q esta armezada
		
		void atribuirComprimento(unsigned int y){this->comprimento=y;}
		unsigned int obterComprimento(){return this->comprimento;}
		
		unsigned int perimetro(unsigned int comprimento, unsigned int largura);
		unsigned int area(unsigned int comprimento, unsigned int largura);
};

unsigned int Retangulo::perimetro(unsigned int comprimento, unsigned int largura)
{
	unsigned int total;
	total=(2*comprimento)+(2*largura);
	return total;
}

unsigned int Retangulo::area(unsigned int comprimento, unsigned int largura)
{
	unsigned int total;
	total=comprimento*largura;
	return total;
}

#endif /*RETANGULO_H_*/
