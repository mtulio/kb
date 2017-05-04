#ifndef PESSOA_H_
#define PESSOA_H_

class Pessoa
{
private:
	String nome;
	int telefone;
	
	Aluno(): nome(nome),  telefone(0){};
	
	void atribuirNome(){ this->nome=nome}
	String obterNome(){return this->nome;}
	
	void atribuirTelefone(int telefone){ this->telefone=telefone;}
	int obterTelefone(){ return this->telefone}

};

#endif /*PESSOA_H_*/
