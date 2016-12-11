#ifndef PROFESSOR_H_
#define PROFESSOR_H_


class Professor : public Pessoa
{
private:
	int registro;
	double salario;
	
	// construtor
	
	Professor(): registro(0),  salario(0) {};
	
	// metodos
	void atribuirNome( String nome){this->nome=nome}
	String obterNome(){ return this->Nome;}
	
	void atribuirTelefone(int telefone){ this->telefone=telefone;}
		int obterTelefone(){ return this->telefone}
		
		void atribuirRegistro(int registro){ this->registro=registro;}
			int obterRegistro(){ return this->registro}
			
			void atribuirSalario(double salario){ this->salario=salario;}
				int obterSalario(){ return this->salario}
	
	
};

#endif /*PROFESSOR_H_*/
