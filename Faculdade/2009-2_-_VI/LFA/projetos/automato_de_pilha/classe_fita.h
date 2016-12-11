#ifndef FITA_H_
#define FITA_H_
#include <string>
using namespace std;
class Fita{
	private:
		//vetor com elementos da fita
		 string vetor;

		 int inicio;
		
	public:
		char leitura_da_fita();
		int tamanho();
		bool final();
		Fita(string);
		~Fita();
};
#endif /*FITA_H_*/
