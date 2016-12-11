#include"Matriz.h"
#include"InterfaceMatriz.h"

//#include"Excessoes.h"
#include"Persistencia.h"
#include<iostream>
using namespace std;


int main(void)
{
	unsigned int linha,coluna;
	try{	
	   system("clear");
	   cout<<" S I S T E M A  D E  M A T R I Z E S  MATRIZ A";
	   cout<<endl<<endl;
	   
	   //cout<<" Digite o nome da matriz: ";
	   //string nomeMat;
	   //cin>>nomeMat;
	      	   
	   cout<<"Quantidade de Linhas da matriz: ";
	   cin>>linha;
	   cout<<"Quantidade de Colunas da matriz: ";
	   cin>>coluna;	
	   Matriz MA(linha,coluna);
	   InterfaceMatriz::lerMatriz(MA);
	   
	   //nomeMat+=".txt";
	   //Persistencia::atribuirMatrizNoArquivo(MA, nomeMat );
	   
	   cout<<endl<<endl<<"Escrita da matriz MATRIZ A"<<endl<<endl;
	   InterfaceMatriz::escreverMatriz(MA);
	      

	   cout<<" S I S T E M A  D E  M A T R I Z E S  MATRIZ B";
	   cout<<endl<<endl;
	   
	   //cout<<" Digite o nome da matriz: ";
	   //cin>>nomeMat;
	      
	   cout<<"Quantidade de Linhas da matriz: ";
	   cin>>linha;
	   cout<<"Quantidade de Colunas da matriz: ";
	   cin>>coluna;
	
	   Matriz MB(linha,coluna);
	   InterfaceMatriz::lerMatriz(MB);
	      
	   //nomeMat+=".txt";
	   //Persistencia::atribuirMatrizNoArquivo(MA, nomeMat );
	   
	   cout<<endl<<endl<<"Escrita da matriz MATRIZ B"<<endl<<endl;
	   InterfaceMatriz::escreverMatriz(MB);
	   cout<<endl<<endl;
	
	

	   
	   {//inicio dos metodos do julliano
		   {
			   Matriz MC(0,0);
			   MC = MA + MB;
			   cout<<"  Escreve add: ";
			   InterfaceMatriz::escreverMatriz(MC);
		   }//fim add
		   {
			   Matriz MC(0,0);
			   MC = MA - MB;
			   cout<<"  Escreve sub: ";
			   InterfaceMatriz::escreverMatriz(MC);
		   }//fim sub
		   {
			   if(MA.eIdentidade()) cout<<" MA eh identidade"<<endl;
			   else cout<<" MA nao eh iodentidade"<<endl;
			   if(MB.eIdentidade()) cout<<"  MB eh identidade"<<endl;
			   else cout<<" MB nao eh identidade"<<endl;
		   }//fim identidade
	   }//fim julliano
	   
	   {//metodos marco tulio
		   
		   {
			   Matriz MC(0,0);
			   MC = MA * MB;
			   cout<<"Resultante de multiplicacao "<<endl;
			   InterfaceMatriz::escreverMatriz(MC);
		   }//fim multiplicacao
		   
		   Matriz MC(0,0), MD(0,0);
		   
		   MC = MA.eResultanteDaTransposta();
		   cout<<" Resultante da trasnposta MA:";
		   InterfaceMatriz::escreverMatriz(MC);
		   
		   MD = MB.eResultanteDaTransposta();
		   cout<<" Resultante da trasnposta MB:";
		   InterfaceMatriz::escreverMatriz(MD);
		   
		   if(MA.eOrtogonal()) cout<<" MA eh ortogonal"<<endl;
		   else cout<<" MA nao eh ortogonal "<<endl;
		   if(MB.eOrtogonal()) cout<<" MB eh ortogonal"<<endl;
		   else cout<<" MB nao eh ortogonal "<<endl;
		   
		   if(MA.eDePermutacao()) cout<<" MA eh de permutacao"<<endl;
		   else cout<<" MA nao eh de permutacao"<<endl;
		   if(MB.eDePermutacao()) cout<<" MB eh de permutacao"<<endl;
		   else cout<<" MB nao eh de permutacao"<<endl;
		   
	   }//fim marco tulio
	   
	   
	   /*
	   //TESTES
	   //std::cout<<"  ERRO PP"<<std::endl;
	   //cout<<" digite o k: ";
	   //int k;
	   //cin>>k;
	   
	   //Multiplicacao
	   Matriz MC(0,0);
	   MC = MA * MB;
	   cout<<" Matriz Resultante: ";
	   InterfaceMatriz::escreverMatriz(MC);
	   
	   //Transposta
	   Matriz MD(0,0);
	   MD = MA.eResultanteDaTransposta();
	   InterfaceMatriz::escreverMatriz(MD);
	   
	   Matriz ME(0,0);
	   ME = MB.eResultanteDaTransposta();
	   InterfaceMatriz::escreverMatriz(ME);
	   
	   //Ortogonal
	   if(MA.eOrtogonal()) cout<<" MA eh Ortogonal "<<endl;
	   else cout<<" MA nao eh ortogonal"<<endl;
	   
	   if(MB.eOrtogonal()) cout<<" MB eh Ortogonal "<<endl;
	   else cout<<" MB nao eh ortogonal"<<endl;
	   	   
	   //Permutacao
	   if(MA.eDePermutacao()) cout<<" MA eh de Permutacao "<<endl;
	   	   else cout<<" MA nao eh de Permutacao"<<endl;
	   if(MB.eDePermutacao()) cout<<" MB eh de Permutacao "<<endl;
	   	   else cout<<" MB nao eh de Permutacao"<<endl;
	   
	   
	   
	   if(MA != MB) cout<<"  diferentes"<<endl;
	   else cout<<" iguais "<<endl;
	   
	   //Matriz MD(0,0);
	   //MD = MB.eResultanteMultiplicacaoPorK(k);
	   
	   //cout<<" escrever Resultante MA: "<<endl;
	   //InterfaceMatriz::escreverMatriz(MC);
	   //cout<<" escrever Resultante Potencia de "<<k<<"  MB: "<<endl;
	   //InterfaceMatriz::escreverMatriz(MD);
	   	 
	   if(MA.eIdentidade()) cout<<" MA eh identidade"<<endl;
	   else cout<<" MA n eh identidade"<<endl;
	   
	   if(MB.eIdentidade()) cout<<" MB EH identidade "<<endl;
	   else cout<<" Mb N EH identidade"<<endl;
	   
	   if(MA.eAntiSimetrica()) cout<<"MA E ANTI"<<endl;
	   else cout<<"NAO E"<<endl;
	   	   
		//cout<<" resultante: "<<endl;
	    //InterfaceMatriz::escreverMatriz(MA);
	
		//Matriz MD(0,0);
		if(MB.eDePermutacao()) cout<<" MB eh de permutcaocao"<<endl;
		else cout<<"  MB nao eh de permutacao"<<endl;
		InterfaceMatriz::escreverMatriz(MB);
	   
		*/
	   //cout<<endl<<endl<<endl<<"Escrita da matriz  MATRIZ C"<<endl<<endl;
	   
	   //PERSISTENCIA
	   /*Persistencia::atribuirMatrizNoArquivo(MC,"Resultante.txt");
	   InterfaceMatriz::escreverMatriz(MC);
	   	   
	   cout<<"Nome da matriz para recuperar: ";
	   cin>>nomeMat;
	   
	   Matriz MD((Persistencia::obterMatrizDoArquivo(nomeMat+".txt")));
	   InterfaceMatriz::escreverMatriz(MD);*/

}//fim try
catch(string msg){
	cout<<endl<<"  ERRO: "<<msg<<endl;
}//fim catch 1

catch(int idException){
	if(idException==0) cout<<endl<<" ERRO: "<<" Memoria Principal Cheia "<<endl;
	
	if(idException==1) cout<<endl<<" ERRO: "<<" Linha e/ou Coluna fora do intevalo "<<endl;
	
	if(idException==2) cout<<endl<<" ERRO: "<<" Quantidade de Linhas e/ou Quantidade de Colunas diferentes! "<<endl;
	
	//idException=1;
	//string msg;
	//Persistencia::obterNomeExcessao(idException, msg);
	//Excessoes::obterExcessao(msg);
	//cout<<endl<<" Per. ERRO: "<<idException<<"  "<<msg<<"."<<endl;
}
	cin.get();
	return 1;
}
