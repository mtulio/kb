#ifndef ALUNO_H_
#define ALUNO_H_

class Aluno : public Pessoa
{
private:
	int matricula;
	double media;
	
	Aluno():  int matricula(0),double media{};
	
	void atribuirNome(){ this->nome=nome}
	String obterNome(){return this->nome;}
	
	void atribuirTelefone(int telefone){ this->telefone=telefone;}
	int obterTelefone(){ return this->telefone}
	
	void atribuirMatricula(int matricula){ this->matricula = matricula;}
		int obterMatricula(){ return this->matricula}

		void atribuirMedia(double media){ this->media=media;}
			int obterMedia(){ return this->media}
	
};





#endif /*ALUNO_H_*/
