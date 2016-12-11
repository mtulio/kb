#ifndef CLASSECPF_H_//diretiva de pré-compilação
#define CLASSECPF_H_

class CPF
{//inicio da classe CPF
	
	//atributos
	private:
		unsigned long numero;
		unsigned int digitoVerificador;
	
	//metodos
	public:
		bool validar(unsigned long numeroCPF, unsigned int dV);
		bool atribuir(unsigned long numeroCPF, unsigned int dV); 
		void obter(unsigned long &numeroCPF, unsigned int &dV);
		CPF(); //Construtor
		~CPF();	//Destrutor
};//Fim da classe
#endif /*CLASSECPF_H_*/
