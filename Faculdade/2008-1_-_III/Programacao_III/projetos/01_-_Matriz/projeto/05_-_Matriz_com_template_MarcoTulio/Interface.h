#ifndef INTERFACEMATRIZ_H_
#define INTERFACEMATRIZ_H_

#include<iostream>
#include<iomanip>
#include<string>
#include"Matriz.h"
#include"Persistencia.h"


using namespace std;

template <class tipo>
class Interface
{
	public:
		static void lerMatriz(Matriz<tipo> &matriz);
		static void escreverMatriz(Matriz<tipo> const &matriz);
		static void menuPrincipal();
		static void menuPersistencia();
		static void menuOperacoesComUmaMatriz();
		static void menuOperacoesComDuasMatrizes();
};

template <class tipo>
void Interface<tipo>::lerMatriz(Matriz<tipo> &matriz)
{
	try{
	   for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas();linha++){
		  for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas();coluna++){
		     tipo elemento;
			 std::cout<<"Elemento["<<linha<<"]["<<coluna<<"]= ";
		     std::cin>>elemento;	
		     matriz.atribuirElementoMatriz(linha,coluna, elemento);
		  }//fim for 2
	   }//fim for 1
	}//fim try
	catch(std::string msg){
		throw msg;
	}
}//fim metodo Ler Matriz

template <class tipo>
void Interface<tipo>::escreverMatriz(Matriz<tipo> const &matriz)
{
	try{
	   unsigned int qLinhas = matriz.obterQuantidadeLinhas();
	   unsigned int qColunas = matriz.obterQuantidadeColunas();
	   for(unsigned int linha=0; linha<qLinhas;linha++){
		   std::cout<<"|";
		   for(unsigned int coluna=0; coluna<qColunas;coluna++){
		      std::cout<<std::left<<std::setw(3)<<matriz.obterElementoMatriz(linha,coluna)<<" ";
//				std::cout<<matriz.obterElementoMatriz(linha,coluna);
		   }
		   std::cout<<std::left<<std::setw(3)<<"|"<<std::endl;
	   }//fim for 2
	}//fmi try
	catch(std::string msg){
	throw msg;	
	}
	
}//fim do metdo escrever

template<class tipo>
void Interface<tipo>::menuPersistencia(){
	try{
		int opcao=1;
		while(opcao){
			system("cls");
         //system("clear");
			cout<<endl<<" \tMENU PERSISTENCIA"<<endl<<endl;
			cout<<endl<<" 1 - Adicionar Matriz no Arquivo";
			cout<<endl<<" 2 - Remover Matriz do Arquivo";
			cout<<endl<<" 3 - Listar matrizes do Arquivo";
			cout<<endl<<" 4 - Listar elementos de uma Matriz";
			cout<<endl<<" 0 - Retorna ao menu anterior";
			cout<<endl<<" Digite a opcao: ";
			cin>>opcao;
			
			switch(opcao){
			default:{
				cout<<" Opcao Invalida, tente novamente!"<<endl;
				cin.get();cin.get();
			}//fim default
			
			case 1:{ //add
				try{
					unsigned int qLinhas, qColunas;
					cout<<" Digite a quantidade de Linhas da Matriz p/ add: ";
					cin>>qLinhas;
					cout<<" Digite a quantidade de Colunas da Matriz p/ add: ";
					cin>>qColunas;
					string nome;
					cout<<" Digite o Nome da Matriz: ";
					cin>>nome;
					
					Matriz<tipo> Madd(qLinhas, qColunas);
					lerMatriz(Madd);
					Persistencia<tipo>::atribuirMatrizNoArquivo(Madd, nome);
					cout<<" Matriz armazenada no Arquivo!"<<endl;
					cin.get();cin.get();
					break;
				}//fim try
				catch(std::string msg){
					cout<<" Erro MPrAdd: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}
			}///fim case 1
			
			case 2:{//remover
				try{
					string nomeRem;
					cout<<" Digite o nome do Arquivo para remover: ";
					cin>>nomeRem;
					Persistencia<tipo>::removerMatrizDoArquivo(nomeRem);
					cout<<" Matriz: "<<nomeRem<<" removida do Arquivo"<<endl;
					cin.get();cin.get();
					break;
				}
				catch(string msg){
					cout<<" Erro MPrRem: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//CASE 2
			
			case 3:{//listar
				try{
					cout<<" Listagem de Matrizes no Arquivo: "<<endl<<endl;
					//ls eh o comando para listagem, -m, separa por virgulas e -Q coloca
					//os elementos entre aspas
					//system("ls -l *.txt");
					system("dir *.txt");
					
               cout<<endl<<" Listagem completa, tecle enter!"<<endl;
					cin.get();cin.get();
					break;
				}
				catch(string msg){
					cout<<" Erro MPrRem: "<<msg<<endl;
					cin.get();
					break;
				}//fim catch
			}//fim case 3
			
			case 4:{// listar elementos da matriz
				try{
					cout<<" Digite o nome da Matriz para a Listagem: ";
					string nome;
					cin>>nome;
					if(!Persistencia<tipo>::buscaArquivoExistente(nome)) throw std::string("matriz nao encontada!");
					Matriz<tipo> mat(Persistencia<tipo>::obterMatrizDoArquivo(nome));
					cout<<"Elementos da Matriz "<<nome<<" :"<<endl;
					escreverMatriz(mat);
					cout<<"Listagem efetuada com sucesso!"<<endl;
					cin.get();cin.get();
					break;
				}
				catch(string msg){
					cout<<" Erro MPrRem: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 4
			
			case 0:{
				return;
				break; //nem era preciso colocar esse break aki.. mas por via das duvidas
			}//FIM CASE 0
			
			}//fim switch
			
		}//fim while
	}
	catch(string msg){
		cout<<" Erro MPrst: "<<msg<<endl;
		cin.get();
	}//FIM CATCH
}//fim menuPerssitencia

template<class tipo>
void Interface<tipo>::menuOperacoesComUmaMatriz()
//premissas: ler uma matriz e fornecer os calculos com ela
{
	try{
		system("cls");
      //system("clear");
		cout<<endl<<" \tMENU OPERACOES COM UMA MATRIZ"<<endl<<endl;
		string nome;
		do{		
			cout<<"\"Instrucao: Nome com extensao *.txt. Exemplo: matriz.txt.\""<<endl;
			cout<<" Digite o nome da Matriz: ";
			cin>>nome;
			//criando um flag de saida
			if(nome=="sair") return;
			if(!Persistencia<tipo>::buscaArquivoExistente(nome)){
				cout<<endl<<" Matriz nao encontrada, digite o nome novamente ou digite 'sair'."<<endl;
			}				
		}while(!Persistencia<tipo>::buscaArquivoExistente(nome));
				
		Matriz<tipo> matriz(Persistencia<tipo>::obterMatrizDoArquivo(nome));
		
		int opcao=1;
		while(opcao){
			system("cls");
         //system("clear");
         
         cout<<endl<<" \tMENU OPERACOES COM UMA MATRIZ"<<endl<<endl;
		   cout<<endl<<" Matriz "<<nome<<": "<<endl;
         escreverMatriz(matriz);
         			
         cout<<endl<<" \tMENU OPERACOES COM UMA MATRIZ"<<endl<<endl;
			cout<<endl<<" 1 - Triangular Superior";
			cout<<endl<<" 2 - Triangular Inferior";
			cout<<endl<<" 3 - Simetrica";
			cout<<endl<<" 4 - Anti-Simetrica";
			cout<<endl<<" 5 - Identidade";
			cout<<endl<<" 6 - Ortogonal";
			cout<<endl<<" 7 - De Permutação";
			cout<<endl<<" 8 - Resultante da Transposta";
			cout<<endl<<" 9 - Resultante da Potencia";
			cout<<endl<<"10 - Multiplicacao por K";
			cout<<endl<<" 0 - Retornar ao Menu Principal";
			cout<<endl<<" Digite a opcao: ";
			cin>>opcao;
			
			switch(opcao){
			case 1:{// triangular superior
				try{
					cout<<endl<<"\t1 - TRIANGULAR SUPERIOR da MATRIZ"<<endl;
					
					if(matriz.eTriangularSuperior()) cout<<" A Matriz: "<<nome<<", é TRIANGULAR SUPERIOR"<<endl;
					else cout<<" A Matriz: "<<nome<<", NAO é TRIANGULAR SUPERIOR"<<endl;
					
					cin.get();cin.get();
					//throw std::string("MENU TS EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-TS: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 2
			case 2:{// triangular Inferior
				try{
					cout<<endl<<"\t2 - TRIANGULAR INFERIOR da MATRIZ"<<endl;
										
					if(matriz.eTriangularInferior()) cout<<" A Matriz: "<<nome<<", é TRIANGULAR INFERIOR"<<endl;
					else cout<<" A Matriz: "<<nome<<", NAO é TRIANGULAR INFERIOR"<<endl;
								
					cin.get();cin.get();
					
					//throw std::string("MENU TS EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-TI: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 2
			
			case 3:{// triangular SIMETRICA
				try{
					cout<<endl<<"\t3 - SIMETRICA da MATRIZ"<<endl;
					
					if(matriz.eSimetrica()) cout<<" A Matriz: "<<nome<<", é SIMETRICA"<<endl;
					else cout<<" A Matriz: "<<nome<<", NAO é SIMETRICA"<<endl;
													
					cin.get();cin.get();
					
					//throw std::string("MENU SM EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-SM: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 3
			
			case 4:{// triangular AS
				try{
					cout<<endl<<"\t4 - ANTI-SIMETRICA da MATRIZ"<<endl;
										
					if(matriz.eAntiSimetrica()) cout<<" A Matriz: "<<nome<<", é ANTI-SIMETRICA"<<endl;
					else cout<<" A Matriz: "<<nome<<", NAO é ANTI-SIMETRICA"<<endl;
																		
					cin.get();cin.get();
					
					//throw std::string("MENU AS EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-AS: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 4
			
			case 5:{// IDENTIDADE
				try{
					cout<<endl<<"\t5 - IDENTIDADE MATRIZ"<<endl;
					
					if(matriz.eIdentidade())  cout<<" A matriz: "<<nome<<", é Identidade!"<<endl<<endl;
					else cout<<" A matriz: "<<nome<<", NAO é Identidade!"<<endl<<endl;
					
					cin.get();cin.get();
					//throw std::string("MENU ID EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-ID: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 13
			
			case 6:{// ORTOGONAL
				try{
					cout<<endl<<"\t6 - ORTOGONAL da MATRIZ"<<endl;
					
					if(matriz.eOrtogonal())  cout<<" A matriz: "<<nome<<", é Ortogonal!"<<endl<<endl;
					else cout<<" A matriz: "<<nome<<", NAO é Ortogonal!"<<endl<<endl;
					
					cin.get();cin.get();
					//throw std::string("MENU OR EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-OR: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 6
			
			case 7:{// PERMUTACAO
				try{
					cout<<endl<<"\t7 - ORTOGONAL da MATRIZ"<<endl;
										
					if(matriz.eDePermutacao())  cout<<" A matriz: "<<nome<<", é de PERMUTACAO!"<<endl<<endl;
					else cout<<" A matriz: "<<nome<<", NAO é de PERMUTACAO!"<<endl<<endl;
							
					cin.get();cin.get();								
					//throw std::string("MENU PR EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-PR: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 13
			
			case 8:{// TRANSPOSTA
				try{
					cout<<endl<<"\t8 - TRANSPOSTA da MATRIZ"<<endl;
					
					Matriz<tipo> result;
					result = matriz.eResultanteDaTransposta();
					std::cout<<" teste"<<std::endl<<std::endl;
					escreverMatriz(result);
					
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}//FIM IF
					
					cin.get();cin.get();
              //throw std::string("MENU TN EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-TN: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 13
			
			case 9:{// POTENCIA
				try{
					cout<<endl<<"\t9 - POTENCIACAO MATRIZ"<<endl;
					
					cout<<" Digite o valor da Potencia: ";
               int pot;
					cin>>pot;
					
					Matriz<tipo> result;
					
					result = matriz.eResultanteDaPotencia(pot);
					
					escreverMatriz(result);
					
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}//FIM IF
					
					cin.get();cin.get();
					//throw std::string("MENU PT EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-PT: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 13
			
			case 10:{// MULT POR K
				try{
					cout<<endl<<"\t10 - MULTIPLICACAO da MATRIZ POR k"<<endl;
					
					cout<<" Digite o valor de k: ";
					int k;
				   cin>>k;
				   
				   Matriz<tipo> result;
					result = matriz.eResultanteMultiplicacaoPorK(k);
					
					escreverMatriz(result);
					
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}//FIM IF
					
					cin.get();cin.get();
            
            	//throw std::string("MENU MK EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO1Mt-MK: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 13
			
			case 0:{//sair
				return;
				break;
			}//fim case 0			
			}//fim switch			
		}//fim while		
	}//fim try
	catch(string msg){
		cout<<" Erro MOp1Mt: "<<msg<<endl;
		return;
	}//fim catch	
}//fim menu operacoes com uma matriz

template<class tipo>
void Interface<tipo>::menuOperacoesComDuasMatrizes()
{
	try{
		system("cls");
      //system("clear");
		cout<<endl<<" \tMENU OPERACOES COM DUAS MATRIZES"<<endl<<endl;
		string nomeA, nomeB;
		do{		
			cout<<"\"Instrucao: Nome com extensao *.txt. Exemplo: matriz.txt.\""<<endl;
			cout<<" Digite o nome da Matriz A: ";
			cin>>nomeA;
			//criando um flag de saida
			if(nomeA=="sair") return;
			if(!Persistencia<tipo>::buscaArquivoExistente(nomeA)){
				cout<<endl<<" Matriz nao encontrada, digite o nome novamente ou digite 'sair'."<<endl;
			}//fmi if				
		}while(!Persistencia<tipo>::buscaArquivoExistente(nomeA));
				
		Matriz<tipo> MA(Persistencia<tipo>::obterMatrizDoArquivo(nomeA));
		
		do{		
			cout<<"\"Instrucao: Nome com extensao *.txt. Exemplo: matriz.txt.\""<<endl;
			cout<<" Digite o nome da Matriz B: ";
			cin>>nomeB;
			//criando um flag de saida
			if(nomeB=="sair") return;
			if(!Persistencia<tipo>::buscaArquivoExistente(nomeB)){
				cout<<endl<<" Matriz nao encontrada, digite o nome novamente ou digite 'sair'."<<endl;
			}//fmi if				
		}while(!Persistencia<tipo>::buscaArquivoExistente(nomeB));
		
		Matriz<tipo> MB(Persistencia<tipo>::obterMatrizDoArquivo(nomeB));
		
		int opcao=1;
		while(opcao){
         system("cls");
      	//system("clear");
			cout<<endl<<" \tMENU OPERACOES COM DUAS MATRIZES"<<endl<<endl;
			
			cout<<endl<<" Matriz A "<<nomeA<<" : "<<endl;
			escreverMatriz(MA);
					
			cout<<endl<<" Matriz B "<<nomeB<<" : "<<endl;
			escreverMatriz(MB);
			cout<<endl<<"\t\tMENU OPERACOES COM DUAS MATRIZES"<<endl;
			cout<<endl<<" 1 - Soma";
			cout<<endl<<" 2 - Subtracao";
			cout<<endl<<" 3 - Multiplicacao";
			cout<<endl<<" 4 - Igualdade";
			cout<<endl<<" 5 - Diferenca";
			cout<<endl<<" 0 - Retornar ao Menu Principal";
			cout<<endl<<" Digite a opcao: ";
			cin>>opcao;
			
			switch(opcao){
			case 1:{
				try{
					
               cout<<endl<<"\t1 - SOMA DE MATRIZES"<<endl;					
					Matriz<tipo> result;
					result = MA + MB;					
					cout<<endl<<" Resultante da soma: "<<endl;
					Interface<tipo>::escreverMatriz(result);
					
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
							
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}					
					cin.get();cin.get();
					//throw std::string("MENU S+ EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO2Mt-S+: "<<msg<<endl;
					cin.get();cin.get();
					break;
				}//fmi catch
			}//fim case 1
			
			case 2:{
				try{
					cout<<endl<<"\t2 - SUBTRACAO DE MATRIZES"<<endl;					
					Matriz<tipo> result;
					result = MA - MB;					
					cout<<endl<<" Resultante da subtracao: "<<endl;
					Interface<tipo>::escreverMatriz(result);
										
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}					
					cin.get();cin.get();					
					//throw std::string("MENU S- EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO2Mt-S-: "<<msg<<endl;
					break;
				}//fmi catch
			}//fim case 2
			
			case 3:{//mutiplicacao
				try{
					cout<<endl<<"\t3 - MULTIPLICACAO DE MATRIZES"<<endl;					
					Matriz<tipo> result;
					result = MA - MB;					
					cout<<endl<<" Resultante da multiplicacao: "<<endl;
					Interface<tipo>::escreverMatriz(result);
											
					cout<<" Deseja Gravar a matriz resultante no arquivo?(s/n): ";
					char resp;
					cin>>resp;
					if(resp=='s' || resp=='S'){
						std::string nomeResult;
						do{
							cout<<" Digite o nome da resultante: ";
							cin>>nomeResult;
							if(Persistencia<tipo>::buscaArquivoExistente(nomeResult)) cout<<" Nome jah existe! Digite outro nome!!!"<<endl;
							else {
								Persistencia<tipo>::atribuirMatrizNoArquivo(result, nomeResult);
								cout<<endl<<" Matriz resultante armazenada com sucesso, tecle enter!"<<endl;
								break;
							}
						}while(Persistencia<tipo>::buscaArquivoExistente(nomeResult));
					}//FIM IF
					
					cin.get();cin.get();					
									
					//throw std::string("MENU M* EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO2Mt-M*: "<<msg<<endl;
					break;
				}//fmi catch
			}//fim case 3
			
			case 4:{//Igualdade
				try{
					cout<<endl<<"\t4 - IGUALDADE DE MATRIZES"<<endl;
					
               if(MA==MB) cout<<" A Matriz: "<<nomeA<<", é IGUAL a Matriz: "<<nomeB<<endl<<endl;
					else cout<<" As Matrizes: "<<nomeA<<" e "<<nomeB<<", NAO sao IGUAIS!"<<endl<<endl;
					
					cin.get();cin.get();
					//throw std::string("MENU Ig EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO2Mt-Ig: "<<msg<<endl;
					break;
				}//fmi catch
			}//fim case 4
			
			case 5:{//Diferenca
				try{
					cout<<endl<<"\t5 - DIFERENCA DE MATRIZES"<<endl;
					
					if(MA != MB) cout<<" A Matriz: "<<nomeA<<", é DIFERENTE da Matriz: "<<nomeB<<endl<<endl;
					else cout<<" As Matrizes: "<<nomeA<<" e "<<nomeB<<", NAO sao DIFERENTES!"<<endl<<endl;
					
					cin.get();cin.get();
					//throw std::string("MENU Di EM CONSTRUCAO");
					break;
				}//fim try
				catch(string msg){
					cout<<" Erro MO2Mt-Di: "<<msg<<endl;
					break;
				}//fmi catch
			}//fim case 5
			
			case 0:{
				return;
				break;
			}//fim case 0
         		
			}//fim switch
		}//fim while		
	}//fim try
	catch(string msg){
			cout<<" Erro MOp2Mt: "<<msg<<endl;
			return;
		}//fim catch	
}//fim operacao com duas matrizes

template <class tipo>
void Interface<tipo>::menuPrincipal()
{
	try{
		int opcao=1;
		while(opcao){
			do{
            system("cls");				
            //system("clear");
				cout<<endl<<" \t\tMENU PRINCIPAL"<<endl;
				cout<<endl<<" 1 - Menu Persistencia";
				cout<<endl<<" 2 - Menu Operacoes com Matrizes";
				cout<<endl<<" 0 - Sair do programa";
				cout<<endl<<"Digite a opcao: ";
				cin>>opcao;				 
			}while(opcao<0 || opcao>2);
			switch(opcao){
			case 1:{
				try{
					menuPersistencia();
					break;
				}//fim try
				catch(std::string msg){
					cout<<" Erro CMPrst: "<<msg<<endl;
					break;
				}
			}//fim case 1
			
			case 2:{
				try{
					int opcao;
					cout<<endl<<" 1 - Operacao com 1 Matriz";
					cout<<endl<<" 2 - Operacao com 2 Matrizes";
					cout<<endl<<" 0 - Abortar";
					cout<<endl<<" Escolha a opcao: ";
					cin>>opcao;
					
					if(opcao==1) menuOperacoesComUmaMatriz();
					if(opcao==2) menuOperacoesComDuasMatrizes();
					if(opcao!=1 && opcao!=2 && opcao!=0){
						cout<<" Opcao Invalida, operacao cancelada!"<<endl;
						cin.get();cin.get();
					}
					
					break;
				}//fim try
				catch(std::string msg){
					cout<<" Erro CMPrst: "<<msg<<endl;
					break;
				}//fim catch				
			}//fim case 2
			
			case 0:{
				return; //retorna ao ponto de chamada, nesse caso no programa principal
            exit(1);//exit 1 significa que o programa terminou beleza
				break;
			}//fim case 0
			
			default:{
				cout<<endl<<" Opcao Incorreta!"<<endl;
				cin.get();
			}
			}//fim switch
		}//fim while
	}//fim try
	catch(std::string msg){
		throw msg;
	}//fim catch
}//fim menu principal


#endif /*INTERFACEMATRIZ_H_*/
