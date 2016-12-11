#ifndef LISTADEDISCIPLINAS_H_
#define LISTADEDISCIPLINAS_H_

#include<iostream>
#include<string>

#include"Disciplina.h"
#include"Aluno.h"

class ListaDeDisciplinas {
private:
	unsigned int contadorDeDisciplinas;
	Disciplina *primeiraDisciplina;	
public:
	
	ListaDeDisciplinas():
		contadorDeDisciplinas(0),
		primeiraDisciplina(0)
		{
			//sempre o primeiro elemento eh nulo
			Disciplina *disciplina = new Disciplina();
			primeiraDisciplina = disciplina;
			primeiraDisciplina->proximaDisciplina = 0;
		}
	
	inline const bool estaVazio()
	{
		if(primeiraDisciplina->proximaDisciplina==0) return true;
		else return false;
	}
	
	void adicionarDisciplina(Disciplina *disciplina);
	Disciplina *removerDisciplina(std::string nome);
	Disciplina *removerDisciplina();
	std::string *listarDisciplinas();
	bool consultarDisciplinas(std::string &nome, Disciplina *&disciplina);
	std::string *listarDisciplinasPorAluno(std::string &nomeAluno, unsigned int &qtdDiscplinasDoAluno);
	
	unsigned int obterQtdDeDisciplinas()const {return contadorDeDisciplinas; }
	
	//dstrutor
	~ListaDeDisciplinas()
	{
		
		if(estaVazio()){
			primeiraDisciplina=0;
			return;
		}
		else {
			while(!estaVazio()){
				Disciplina *aux  = new Disciplina();
				aux = removerDisciplina();
				delete aux;
			}//fim while
			primeiraDisciplina = 0;
		}//fim else
	}//fim destrutor
	
};//fim classe

void ListaDeDisciplinas::adicionarDisciplina(Disciplina *disciplina)
{
	if(estaVazio()){
		disciplina->proximaDisciplina = 0;
		primeiraDisciplina->proximaDisciplina = disciplina;
		contadorDeDisciplinas +=1;
		return;
	}
	
	Disciplina *auxDisciplina = new Disciplina();
	
	auxDisciplina = primeiraDisciplina;
	
	while(auxDisciplina->proximaDisciplina!=0){
		
		if(auxDisciplina->proximaDisciplina->obterNomeDisciplina() ==
			disciplina->obterNomeDisciplina()) 
			throw std::string("Disciplina existente");
		
		if(auxDisciplina->proximaDisciplina->obterNomeDisciplina() >
			disciplina->obterNomeDisciplina() )
		{//inicio if
			disciplina->proximaDisciplina = auxDisciplina->proximaDisciplina;
			auxDisciplina->proximaDisciplina = disciplina;
			contadorDeDisciplinas+=1;
			return;
		}//fim if
		else {
			auxDisciplina = auxDisciplina->proximaDisciplina;
		}//fim else
	}//fim while
	
	//neste acso sera a ultima letra do afabeto da turma
	auxDisciplina = primeiraDisciplina;
	while(auxDisciplina->proximaDisciplina!=0){
		if(auxDisciplina->proximaDisciplina != 0){
			auxDisciplina = auxDisciplina->proximaDisciplina;			
		}//fim if
		if(auxDisciplina->proximaDisciplina==0){
			disciplina->proximaDisciplina=0;
			auxDisciplina->proximaDisciplina = disciplina;
			contadorDeDisciplinas+=1;
			return;
		}
	}//fim while	
}//fim add

Disciplina *ListaDeDisciplinas::removerDisciplina(std::string nome)
{
	Disciplina *aux = new Disciplina();
	aux = primeiraDisciplina;
	if(estaVazio()) throw std::string("Lista de Disciplinas vazia");
	else{
		
		while(aux->proximaDisciplina!=0){
			//verificando sempre o proximo nome da lista, ou o proximo objeto
			if(nome == aux->proximaDisciplina->obterNomeDisciplina()){
				Disciplina *encontrado = new Disciplina();
				encontrado = aux->proximaDisciplina;
				
				//CONDICAO EXIGIDA NO EXERCICIO
				//verificando se ela contem alunos matriculados
				if(!encontrado->estaVazio()) {
					std::string nameDis = encontrado->obterNomeDisciplina(), msg;
					msg = "A Disciplina "+nameDis+" contem aluno(s) matriculado(s)";
					throw msg;
				}
				
				//caso nao tenha nenhum aluno matriculado fara as alterações
				aux->proximaDisciplina = encontrado->proximaDisciplina;
				//decrementndo o contador de disciplinas
				contadorDeDisciplinas-=1;
				return encontrado;
			}//fim if 1
			else {
				aux = aux->proximaDisciplina;
			}//fim else
		}//fim while
		//entrara nessa condicao se estiver percorrido por toda a lista e nao encontrar o nome desejado
		if(aux->proximaDisciplina==0){
			throw std::string ("Disciplina nao encontrada");
		}//fim if
	}//fim else
}//fim remover

Disciplina *ListaDeDisciplinas::removerDisciplina()
{
	if(estaVazio()) throw std::string("Lista de Disciplinas vazia");
	Disciplina *aux = new Disciplina();
	aux = primeiraDisciplina->proximaDisciplina;
	
	//CONDICAO EXIGIDA NO EXERCICIO
	//verificando se ela contem alunos matriculados
	if(!aux->estaVazio()) {
		std::string nameDis = aux->obterNomeDisciplina(), msg;
		msg = "\n\tA Disciplina "+nameDis+" contem aluno(s) matriculado(s),\n"
				"\tVerifique a Disciplina e tente novamente";
		throw msg;
	}
	
	primeiraDisciplina->proximaDisciplina = aux->proximaDisciplina;
	return aux;
}//fim remover 2

std::string *ListaDeDisciplinas::listarDisciplinas()
{
	if(estaVazio()) throw std::string("Lista de Disciplinas vazia, favor revisar");
	
	
	std::string *vetor = new std::string[contadorDeDisciplinas];
	
	Disciplina *auxDis = new Disciplina();
	auxDis = primeiraDisciplina->proximaDisciplina;
	for(int i=0; i< contadorDeDisciplinas; i++){
		vetor[i] = auxDis->obterNomeDisciplina();
		auxDis = auxDis->proximaDisciplina;
	}
	
	return vetor;	
}// fim metoto listar disicplinas


//identico ao remover
bool ListaDeDisciplinas::consultarDisciplinas(std::string &nome, Disciplina *&disciplina)
{
	Disciplina *aux = new Disciplina();
	aux = primeiraDisciplina;
	while(aux->proximaDisciplina!=0){
		//verificando sempre o proximo nome da lista, ou o proximo objeto
		if(nome == aux->proximaDisciplina->obterNomeDisciplina()){
			disciplina = aux->proximaDisciplina;
			return true;
		}//fim if 1
		else {
			aux = aux->proximaDisciplina;
		}//fim else
	}//fim while
	//entrara nessa condicao se estiver percorrido por toda a lista e nao encontrar o nome desejado
	if(aux->proximaDisciplina==0){
		return false;
	}//fim if
}//fim consultar

std::string *ListaDeDisciplinas::listarDisciplinasPorAluno(std::string &nomeAluno, unsigned int &qtdDiscplinasDoAluno)
// PREMISSAS:
// 1 - VERIFICAR SE O ALUNO ESTA MATRICULADO EM CADA TURMA,
// 2 - NA MEDIDA QUE FOR ENCONTRANDO O ALUNO, ARMAZENAR O NOME DA DISCIPLINA
// 3 - SERIA MELHOR RETORNAR UM VETOR DE STRINGS 
{
	if(estaVazio()) throw std::string("Lista de Disciplinas Vazia");
		
	Disciplina *auxDis = new Disciplina();
	auxDis = primeiraDisciplina;
	
	//criando um vetor de strings
	std::string *vetorTemp = new std::string[contadorDeDisciplinas];
	//o contador eh o valor maximo que ele pode assumir
	unsigned int encontrados=0;
	
	while(auxDis->proximaDisciplina!=0){
		//lembrando de sempre verificar a proximo disciplina
		//entao...
		Aluno *aluno = new Aluno(); //objeto que vai ser usado apenas para a consulta
		if(auxDis->proximaDisciplina->consultarAluno(nomeAluno, aluno)){
			std::string nomeDisAux = auxDis->proximaDisciplina->obterNomeDisciplina();
						
			vetorTemp[encontrados] = nomeDisAux; 
			//relacaoDeDisciplinaPorAluno[encontrados] = nomeDisAux;
			encontrados+=1;
		}
		auxDis = auxDis->proximaDisciplina;		
	}//fim while	
	
	if(encontrados==0) throw std::string("Aluno nao esta matriculado em nehuma disciplina");
	else {
		//alocando um vetor de string somente do tamanho necessario, ou seja encontrado
		std::string *vetor = new std::string[encontrados];
		//fazendo a copia do vetor encontrado para o vetor a ser retornado
		for(int i=0; i<encontrados; i++){
			std::string strTemp;
			strTemp = vetorTemp[i];
			vetor[i] = strTemp;
			//std::cout<<" teste  name: "<<nomeAluno<<std::endl;
		}
		//delete[] vetorTemp;		
		qtdDiscplinasDoAluno = encontrados;
		return vetorTemp;
	}//fim else
	delete vetorTemp;
}//fim listar

#endif /*LISTADEDISCIPLINAS_H_*/
