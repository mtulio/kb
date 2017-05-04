#ifndef ALUNO_H_
#define ALUNO_H_

//#include<iomanip>
#include<string>

class Aluno{
public:
	std::string nomeAluno;
	Aluno *proximo;
	
	Aluno(){}
	Aluno(std::string nome): 
		nomeAluno(nome),
		proximo(0){}
		
	std::string obterNome(){ return nomeAluno; }
	void atribuirNome(std::string nome) { this->nomeAluno = nome; }
};//fim classe

#endif /*ALUNO_H_*/
