#ifndef PILHA_H_
#define PILHA_H_
#include <string>
using namespace std;
class Pilha{
	private:
		
		//vetor com os elementos da pilha
		string *vetor;
	    //topo da pilha inicio
		int topo;
		const  int tamanho;
		
	public:
		bool push(string);
		bool pop(string &,bool);
		int obterTamanho();
		bool pilhaVazia();
		Pilha(unsigned int);
		~Pilha();
};
#endif /*PILHA_H_*/
