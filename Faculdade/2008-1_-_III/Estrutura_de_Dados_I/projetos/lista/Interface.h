#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include<string>
#include"ListaDeDisciplinas.h"
#include"Disciplina.h"
#include"Aluno.h"

using namespace std;

class Interface
{
public:
	static void menuManterListaDeDisciplinas(ListaDeDisciplinas *&lista);
	static void menuManterDisciplina(Disciplina *&disciplina);	
};//fim classe Interface

void Interface::menuManterDisciplina(Disciplina *&disciplina)
{
	try{
		int opcao=1;
		while(opcao){
			system("clear");
			cout<<" \t\t MENU DISCIPLINA - LISTA DE ALUNOS"<<endl;
			cout<<" \tDisciplina: "<<disciplina->obterNomeDisciplina()<<" - "<<disciplina->obterTurmaDisciplina()<<endl;
			cout<<endl<<" 1 - Adicionar Aluno";
			cout<<endl<<" 2 - Remover Aluno";
			cout<<endl<<" 3 - Listar Alunos";
			cout<<endl<<" 4 - Consultar Aluno";
			cout<<endl<<" 0 - VOLTAR ao Menu Lista de Disciplinas";
			cout<<endl<<" Digite a opcao: ";
			cin>>opcao;
			
			switch(opcao){
			case 1: {
				try{
					string aluName;
					cout<<" Digite o nome do Aluno: ";
					cin>>aluName;
					Aluno *alu = new Aluno(aluName);
					disciplina->adicionarAluno(alu);
					cout<<" Status: Aluno adicionado com sucesso"<<endl;
					cin.get();cin.get();
					break;					
				}//fim try
				catch(string msg){
					cout<<" ERRO AddAl: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 1
			
			case 2:{
				try{
					if(disciplina->estaVazio()) {
						cout<<" Status: Nao ha alunos matriculados nessa turma! "<<endl;
						cin.get();cin.get();
						break;
					}
					string aluName;
					cout<<" Digite o nome do Aluno: ";
					cin>>aluName;
					
					Aluno *aluAux; //= new Aluno();
					aluAux = disciplina->retirarAluno(aluName);
					cout<<endl<<" O Aluno: "<<aluAux->obterNome()<<" foi removido da lista"<<endl;
					cin.get();cin.get();
					break;					
				}//fmi try
				catch(string msg){
					cout<<" ERRO RemAl: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 2
			
			case 3:{
				try{
					if(disciplina->estaVazio()) {
						cout<<endl<<" Status: Nao ha alunos matriculados nessa turma! "<<endl;
						cin.get();cin.get();
						break;
					}
					Disciplina *auxDis  = new Disciplina();
					auxDis = disciplina->listarAlunos();
					cout<<endl<<" Lista de Alunos: "<<endl;
					int i=0;
					while(!auxDis->estaVazio()){
						i++;
						Aluno *auxAlu = auxDis->retirarAluno();
						cout<<"\t"<<i<<"o - "<<auxAlu->obterNome()<<endl;
					}//fim while
					cout<<" Total de Alunos listados: "<<i<<". Enter p/ Continuar..."<<endl;
					cin.get();cin.get();
					break;					
				}//fim try
				catch(string msg){
					cout<<" ERRO LstAl: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 3
			
			case 4:{
				try{
					if(disciplina->estaVazio()) {
						cout<<" Status: Nao ha alunos matriculados nessa turma! "<<endl;
						cin.get();cin.get();
						break;
					}
					string nomeAlu;
					cout<<" Digite o nome do Aluno para consulta: ";
					cin>>nomeAlu;
					Aluno *aluno;// = new Aluno();
					if(disciplina->consultarAluno(nomeAlu, aluno)){
						cout<<endl<<" O aluno "<<aluno->obterNome()<<" esta matriculado nesta Disciplina!"<<endl;
						cin.get();cin.get();
						break;
					}
					else {
						cout<<" O nome Digitado: "<<nomeAlu<<", nao estao matriculado nesta Disciplina!"<<endl;
						cin.get();cin.get();
						break;
					}					
				}//fim try
				catch(string msg){
					cout<<" ERRO CstAl: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch				
			}//fim case 4
			
			case 0:{
				cout<<" Tecle Enter para retornar ao menu anterior!"<<endl;
				cin.get();cin.get();
				return;
				break;
			}			
			}//fim switch
		}//fim while		
	}//fim try
	catch(string msg){
		cout<<" ERRO MMDi: "<<msg<<endl;
		cin.get();cin.get();
	}//fim catch	
}//fim menu manter disciplina

void Interface::menuManterListaDeDisciplinas(ListaDeDisciplinas *&lista)
//void Interface::menuManterListaDeDisciplinas()
{
	//ListaDeDisciplinas *lista = new ListaDeDisciplinas();
	try{
		
		int opcao;
	      while(opcao){
		     system("clear");
	    	 cout<<" \t\t MENU LISTA DE DISCIPLINAS"<<endl;
	    	 
	    	 cout<<endl<<" 1 - Adicionar Disciplina;";
		     cout<<endl<<" 2 - Remover Disciplina;";
		     cout<<endl<<" 3 - Listar Disciplinas;";
		     cout<<endl<<" 4 - Consultar Disciplina;";
		     cout<<endl<<" 5 - Consultar Disciplina por Aluno;";
		     cout<<endl<<" 0 - SAIR do Programa";
		     cout<<endl<<" Digite a Opcao: ";
		     
		     cin>>opcao;
		     switch(opcao){
		     case 1:{ //ADD
		    	 Disciplina *dis, *disAux;
		    	 disAux = new Disciplina();
		    	 try{
		    		 string nameDis, turmaDis;
		    		 
		    		 cout<<"Digite o nome da Disciplinas: ";
		    		 cin>>nameDis;
		    		 
		    		 if(lista->consultarDisciplinas(nameDis, disAux)) throw string("Disciplina Existente");
		    		 delete disAux;
		    		 cout<<" Digite a Turma da Disciplina "<<nameDis<<": ";
		    		 cin>>turmaDis;
		    		 
		    		 dis = new Disciplina(nameDis, turmaDis);
		    		 
		    		 menuManterDisciplina(dis);
		    		 
		    		 lista->adicionarDisciplina(dis);
		    		 
		    		 cout<<" A Disciplina "<<dis->obterNomeDisciplina()<<" foi adicionada a lista"
		    				 " de Disciplinas"<<endl;
		    		 cin.get();cin.get();
		    		 break;
		    	 }//fim try
		    	 catch(std::string msg){
		    		 cout<<" ERRO AddD: "<<msg<<endl;
		    		 delete disAux;
		    		 cin.get();cin.get();
		    		 break;
		    	 }//fim catch
		     }//fim case 1
			
		     case 2:{//REM D.
		    	 try{
		    		 if(lista->estaVazio()){
		    			 cout<<" A lista de Disciplinas nao contem nenhuma disciplina Cadastrada, \n"
		    					 "favor, vá ao menu adicionar disciplina e inclua uma nova disciplina"<<endl;
		    			 cin.get();cin.get();
		    			 break;
		    		 }
		    		 string nomeDis;
		    		 cout<<" Digite o nome da Disciplina: ";
		    		 cin>>nomeDis;
		    		 Disciplina *auxDis; //new Disciplina();
		    		 auxDis = lista->removerDisciplina(nomeDis);
		    		 
		    		 //se executou o comando anterior sem enhuma excessao, eh porque foi excluido blz
		    		 cout<<" A disciplina: "<<auxDis->obterNomeDisciplina()<<", foi removida da lista"<<endl;
		    		 cin.get();cin.get();    		 
		    		 break;
		    	 }//fim try
		    	 catch(std::string msg){
		    	    cout<<" ERRO RemD: "<<msg<<endl;
		    	    cin.get();cin.get();
		    	    break;
		    	 }//fim catch
		     }//fim case 2
		     
		     case 3:{//LIStar DI
   		    	 try{
   		    		if(lista->estaVazio()){
   		    			 cout<<" A lista de Disciplinas nao contem nenhuma disciplina Cadastrada, \n"
   		    				 "favor, vá ao menu adicionar disciplina e inclua uma nova disciplina"<<endl;
   		    			cin.get();cin.get();
   		    			 break;
   		    		}
   		    		unsigned int qtdDisciplinas = lista->obterQtdDeDisciplinas();
   		    		string *vetor = new string[qtdDisciplinas];
   		    		vetor = lista->listarDisciplinas();
   		    		cout<<endl<<" Listagem de disciplinas: "<<endl;
   		    		int i;
   		    		for(i=0; i<qtdDisciplinas; i++)
   		    			cout<<"\t"<<i+1<<"a: "<<vetor[i]<<endl;
   		    		
   		    		cout<<endl<<"Existem "<<i<<" disciplina(s) cadastrada(s) nesta Lista"<<endl;
   		    		cin.get();cin.get();
   		    		break;
   		    	 }//fim try
		     	 catch(std::string msg){
		     		 cout<<" ERRO LstD: "<<msg<<endl;
		     	  	 cin.get();cin.get();
		     		 break;
		     	 }//fim catch
		     }//fim case 2

		     case 4:{//CONSULTAR
   		    	 try{
   		    		if(lista->estaVazio()){
   		    		   	cout<<" A lista de Disciplinas nao contem nenhuma disciplina Cadastrada, \n"
   		    		   		 "favor, vá ao menu adicionar disciplina e inclua uma nova disciplina"<<endl;
   		    		 cin.get();cin.get();
   		    		   	break;
   		    		 }
   		    		
   		    		string nomeDis;
   		    		cout<<" Digite o nome da Disciplina: ";
   		    		cin>>nomeDis;
   		    		Disciplina *disciplina = new Disciplina();
   		    		if(lista->consultarDisciplinas(nomeDis, disciplina))
   		    				menuManterDisciplina(disciplina);
   		    		else cout<<" Disciplina nao encontrada!"<<endl;	
   		    		
   		    		cin.get();cin.get();
   		    		break;
   		    	 }//fim try
		     	catch(std::string msg){
		     		cout<<" ERRO CnsD: "<<msg<<endl;
		     		cin.get();cin.get();
		     		break;
		     	}//fim catch
		     }//fim case 2
		     
		     case 5:{//CONSULTAR por aluno
		    	 try{
		    		 if(lista->estaVazio()){
		    		   	cout<<" A lista de Disciplinas nao contem nenhuma disciplina Cadastrada, \n"
		    		  		 "favor, vá ao menu adicionar disciplina e inclua uma nova disciplina"<<endl;
		    		   	cin.get();cin.get();
		    		  	break;
		    		 }
		    		 
		    		 string nomeEstudante;
		    		 cout<<" Digite o nome do Aluno: ";
		    		 cin>>nomeEstudante;
		    		 
		    		 //variavel para uso do programador:
		    		 //tamanho maximo, nao quer dizer q o vet vai ser desse tamanho
		    		 //foi usado para criar o vetor resultante do retorno do metodo
		    		 unsigned int qtdDisciplinas = lista->obterQtdDeDisciplinas(); 
		    		 string *vetor = new string[qtdDisciplinas];
		    		 
		    		 //se o aluno nao estiver cadastrado em nenhuma disciplina, caira em alguma excessao		    		 
		    		 vetor = lista->listarDisciplinasPorAluno(nomeEstudante, qtdDisciplinas);
		    		 
		    		 cout<<endl<<" Aluno: "<<nomeEstudante<<endl;
		    		 for(int i=0; i<qtdDisciplinas; i++){
		    		 	cout<<"Disciplina: "<<i+1<<" - "<<vetor[i]<<endl;
		    		 }
		    		 
		    		 cin.get();cin.get();
		    		 break;
		        }//fim try
		     	catch(std::string msg){
		     		cout<<" ERRO CnsDA: "<<msg<<endl;
		     		cin.get();cin.get();
		     		break;
		     	}//fim catch
		     }//fim case 2
		    
		    
		     case 0:{
		    	 return;
		    	 break;
		     }//fim case 0
			
		     default:{
		    	 cout<<"  Opcao Invalida"<<endl;
		    	 cin.get();cin.get();
		    	 break;
		     }
			
		     }//fim switch		
	      }//FIM WHILE
	}//fim try
	catch(std::string msg){
		cout<<" ERRO MMLD: "<<msg<<endl;
		cin.get();cin.get();
	}//fim catch
}//fim metodo manter lista de disciplinas

#endif /*INTERFACE_H_*/
