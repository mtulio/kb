#ifndef LIVRO_H_
#define LIVRO_H_

class Livro
using namespace std;
{
private: // atrivbutos
	string titulo;
	string autor;
	int ano;
	string editora;

public:
	void atribuirTitulo(String titulo) {this->titulo=titulo;}
	string obterTitulo() {return titulo;}
	void atribuirAutor(String autor) {this->autor=autor;}
	string obterAutor() {return autor;}
	void atribuirAno(int ano) {this->ano=ano;}
	int obterAno() {return ano;}
	void atribuirEditora(String editora) {this->editora=editora;}
	string obterEditora() {return editora;}
};


#endif /*LIVRO_H_*/
