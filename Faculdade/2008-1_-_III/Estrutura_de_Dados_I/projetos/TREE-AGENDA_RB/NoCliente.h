#ifndef NOCLIENTE_H_
#define NOCLIENTE_H_

#include<string>

class NoCliente
{
private:
	std::string nome;
	NoCliente *filhoEsquerda;
	NoCliente *filhoDireita;
	
public:
	NoCliente(std::string &nome):
		nome(nome),
		filhoEsquerda(0),
		filhoDireita(0)
		{}		
	~NoCliente();
	
	void inserir(std::string nome)
	{
		if(nome < this->nome){
			if(filhoEsquerda==0)
				filhoEsquerda = new NoCliente(nome);
			//fim if f esquerda
			else 
				//usando a recursividade
				filhoEsquerda->inserir(nome);				
		}// fim verificacao se menor que a raiz
		else if( nome > this->nome ){
			// verificando se o filho a direita eh nulo
			if( filhoDireita==0 )
				filhoDireita = new NoCliente(nome);
			else 
				// usando a recursividade
				filhoDireita->inserir(nome);
		}// fim else verificacao maior que a raiz	
};//fim da classe

#endif /*NOCLIENTE_H_*/
