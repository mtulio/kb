#include <iostream>
#include<string>
#include"Matriz.h"
#include"InterfaceMatriz.h"
#include"Persistencia.h"

using namespace std;

//Nao esta sendo usado
/*void lerDadosMatriz(Matriz &matriz, std::string &nomeMatriz)
{
   unsigned int linhas, colunas;
   
   cout<<" Digite o nome do arquivo: ";
   cin>>nomeMatriz;
   nomeMatriz +=".txt";
   nomeMatriz = "./Matrizes/"+nomeMatriz;
   
   cout<<"Quantidade de Linhas da matriz: ";
   cin>>linhas;
   cout<<"Quantidade de Colunas da matriz: ";
   cin>>colunas;   
   matriz.atribuirQuantidadeLinhas(linhas);
   matriz.atribuirQuantidadeColunas(colunas);
   
   InterfaceMatriz::lerMatriz(matriz);  

}//fim metodo lerDadosMatriz*/


int main()
{//inicio do programa principal
   system("clear");
   cout<<" PROGRAMACAO III - PROGRAMA DE MATRIZES"<<endl<<endl;
   
   cout<<"__MATRIZ A__"<<endl<<endl;
   //lerDadosMatriz(MA, nomeMatriz);
   
   std::string nomeMatriz;
   cout<<" Digite o nome do arquivo: ";
   cin>>nomeMatriz;
   nomeMatriz +=".txt";
   nomeMatriz = "./Matrizes/"+nomeMatriz;
   
   unsigned int linhas, colunas;
   cout<<"Quantidade de Linhas da matriz: ";
   cin>>linhas;
   cout<<"Quantidade de Colunas da matriz: ";
   cin>>colunas;
   
   Matriz MA(linhas,colunas);
   InterfaceMatriz::lerMatriz(MA); 
   
   //Atribuindo a matriz no arquivo
   Persistencia::atribuirMatrizArquivo(MA, nomeMatriz);
   cin.get();
   
   cout<<"\t__Recuperando a Matriz do Arquivo__"<<endl;
   system("ls ./Matrizes");
   //system("ls");
   cout<<"Digite o nome da Matriz em que vc deseja recuperar:";
   getline(cin, nomeMatriz);
   nomeMatriz+=".txt";
   nomeMatriz="./Matrizes/"+nomeMatriz;
   Matriz MC(Persistencia::obterMatrizDoArquivo(nomeMatriz));
   InterfaceMatriz::escreverMatriz(MC);
   cin.get();
   
   cout<<"\t__Apagando a Matriz do Arquivo__"<<endl;
   cout<<"Digite o nome da Matriz em que vc deseja apagar:";
   getline(cin, nomeMatriz);
   nomeMatriz+=".txt";
   //nomeMatriz="./Matrizes/"+nomeMatriz;
   if(Persistencia::apagarArquivo(nomeMatriz)) cout<<" apagado com sucesso"<<endl;
   else cout<<"nao apagado!!!"<<endl;
   
   cin.get();
   cout<<" Terminando o programa.. Tecle Enter"<<endl;
   cin.get();
   system("clear");
   
}//fim do programa principal

