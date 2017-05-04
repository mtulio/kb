#ifndef NO_H_
#define NO_H_

class No
{
private:
	std::string nome;
	unsigned int rg;
	unsigned int cpf;
	
public:
	int chave;
	No *proximo;
	bool vazio;
	
	No():
		chave(0),
		proximo(0),
		vazio(true),
		rg(0),
		cpf(0)
		{}
	
	void setNome(std::string nome){this->nome = nome; }
	void setRg(unsigned int rd){this->rg = rg;}
	void setCpf(unsigned int cpf){this->cpf=cpf;}
	
	std::string getNome(){return nome;}
	unsigned int getRg(){return rg;}
	unsigned int getCpf(){return cpf;}
	
	//como o identificador(chave) é a matricula
	void setMatricula(int matricula){
		this->chave=matricula;
		//this->vazio=false;//auto qdo pede pra set mat
		//eh pq vai guardar um obj
	}
	unsigned int getMatricula(){return chave;}
	
};//fim class No

#endif /*NO_H_*/
