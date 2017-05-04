#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include<iostream>
#include<string>

#include"Aluno.h"

class Disciplina{
private:
	std::string nomeDisciplina;
	std::string turma;
	Aluno *primeiroAluno;	
public:
	Disciplina *proximaDisciplina;
	
	Disciplina():
		primeiroAluno(0),
		proximaDisciplina(0)
		{	
		   //criando um elemento nulo
			Aluno *primeiro = new Aluno();
			//informando que esse eh o primeiro aluno, um aluno nulo
			primeiroAluno = primeiro;
			primeiroAluno->proximo = 0;
		}
	Disciplina(std::string nome):
		nomeDisciplina(nome),
		primeiroAluno(0),
		proximaDisciplina(0)
		{
			//criando um elemento nulo
			Aluno *primeiro = new Aluno();	
			//primeiro->ativarPrimeiroElemento();
			primeiroAluno = primeiro;
			primeiroAluno->proximo = 0;
		}
	Disciplina(std::string nome, std::string turma):
		nomeDisciplina(nome),
		turma(turma),
		primeiroAluno(0),
		proximaDisciplina(0)
		{
			//criando um elemento nulo
			Aluno *primeiro = new Aluno();	
			primeiroAluno = primeiro;
			primeiroAluno->proximo = 0;
		}
	std::string obterNomeDisciplina(){ return nomeDisciplina; }
	std::string obterTurmaDisciplina(){ return turma; }
	
	void adicionarAluno(Aluno *aluno);
	Aluno *retirarAluno(std::string nome);
	Aluno *retirarAluno();
	Disciplina *listarAlunos();
	bool consultarAluno(std::string const nome, Aluno *&aluno);
		
	inline const bool estaVazio(){
		if(primeiroAluno->proximo==0) return true;
		else return false;
	}
	
	//destrutor, destroi apenas a lista de alunos
	//o reposanvel para remover a proxima disciplina e a lista de disciplinas
	~Disciplina(){
		if(estaVazio()) {
			primeiroAluno=0;
			return;
		}
		while(!estaVazio()){
			Aluno *aux = retirarAluno();
			delete aux;
		}
	}//fim destrutor	
};//fim classe


void Disciplina::adicionarAluno(Aluno *aluno)
{	
	//condicao para o primeiro aluno
	if(estaVazio()){
		aluno->proximo=0;
		primeiroAluno->proximo = aluno;
		 //unico elemento
		
		//std::cout<<" ADD 1o elemento: ";
		//std::cout<<primeiroAluno->proximo->obterNome()<<" !!"<<std::endl;
		return;
	}
	Aluno *aluAux1 = new Aluno();
	aluAux1 = primeiroAluno;
	while(aluAux1->proximo!=0){
		if(aluAux1->proximo->obterNome() == aluno->obterNome()) throw std::string("Nomes Iguais!");
		if(aluAux1->proximo->obterNome() > aluno->obterNome()){
			aluno->proximo = aluAux1->proximo;
			aluAux1->proximo = aluno;
			return;
		}
		else {
			aluAux1 = aluAux1->proximo;
		}
	}//fim while
	
	//se for a ultima letra em ordem alfabetica da turma
	aluAux1 = primeiroAluno;
	while(aluAux1->proximo!=0){
		if(aluAux1->proximo!=0){
			aluAux1 = aluAux1->proximo;
		}
		if(aluAux1->proximo==0){
			aluno->proximo=0;
			aluAux1->proximo = aluno;
			return;
		}//fim if
	}//fim while	
}//fim add

Aluno *Disciplina::retirarAluno(std::string nome)
{
	if(primeiroAluno->proximo==0) throw std::string("Retirar1 - Lista vazia");
	else {
		Aluno *aluAux = new Aluno();
		aluAux = primeiroAluno;
		while(aluAux->proximo!=0){
			if(nome == aluAux->proximo->obterNome()){
				//criado esse objeto para retira-lo da fila sem perder o restante da fila de vista
				Aluno *aluEncontrado = new Aluno();
				aluEncontrado = aluAux->proximo;
				aluAux->proximo = aluEncontrado->proximo;
				return aluEncontrado;				
			}//fim if
			else {
				aluAux = aluAux->proximo;
			}
		}//fim while
		if(aluAux->proximo==0){
			throw std::string("Nome nao encontrado!");
			//return;
		}
	}//fim else
}//fim retirar

//metodo usado a sobrecarga, este pode ser usado na listagem geral de alunos
Aluno *Disciplina::retirarAluno()
{
	if(estaVazio()) throw std::string("Retirar2 - Lista vazia");
	Aluno *aux = new Aluno();
	aux = primeiroAluno->proximo;
	primeiroAluno->proximo = aux->proximo;
	return aux;
}

Disciplina *Disciplina::listarAlunos()
{
	if(primeiroAluno->proximo==0) throw std::string("Listar Al - Lista Vazia!!");

	Disciplina *disAux = new Disciplina();
	
	///fazendo a copia da lista de alunos
	Aluno *auxAlu = new Aluno();
	auxAlu = primeiroAluno->proximo;
	while(auxAlu!=0){
		//std::cout<<"While listagem "<<std::endl;
		std::string nome;
		nome = auxAlu->obterNome();
		//std::cout<<"  nome obtido: "<<nome<<std::endl;
		Aluno *alunoCopia = new Aluno();
		//alunoCopia->atribuirDados();
		alunoCopia->atribuirNome(nome);
		disAux->adicionarAluno(alunoCopia);
		auxAlu = auxAlu->proximo;
	}	
	return disAux;				
}//fim retirar

bool Disciplina::consultarAluno(std::string const nome, Aluno *&aluno)
{	
	if(estaVazio()) return false; 
	Aluno *auxAluno = new Aluno();
	auxAluno = primeiroAluno;	
	while(auxAluno->proximo!=0){
		if(auxAluno->proximo->obterNome() == nome){
			aluno = auxAluno->proximo;
			return true;
		}
		else{
			auxAluno = auxAluno->proximo;
		}
	}
	//se xegou ate essa parte do programa eh pq foi verificado todas
	//os elementos
	//entao
	return false;
}//fim consulta

#endif /*DISCIPLINA_H_*/
