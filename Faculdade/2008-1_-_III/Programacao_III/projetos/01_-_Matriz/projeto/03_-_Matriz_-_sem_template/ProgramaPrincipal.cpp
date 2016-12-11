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
	
	
	   //TESTES
	   //std::cout<<"  ERRO PP"<<std::endl;
	   
	   //cout<<" digite o k: ";
	   //int k;
	   //cin>>k;
	   
	   //Matriz MC(0,0);
	   if(MA != MB) cout<<"  diferentes"<<endl;
	   else cout<<" iguais "<<endl;
	   
	   //Matriz MD(0,0);
	   //MD = MB.eResultanteMultiplicacaoPorK(k);
	   
	   //cout<<" escrever Resultante MA: "<<endl;
	   //InterfaceMatriz::escreverMatriz(MC);
	   //cout<<" escrever Resultante Potencia de "<<k<<"  MB: "<<endl;
	   //InterfaceMatriz::escreverMatriz(MD);
	   	 
	   /*if(MA.eIdentidade()) cout<<" MA eh identidade"<<endl;
	   else cout<<" MA n eh identidade"<<endl;
	   
	   if(MB.eIdentidade()) cout<<" MB EH identidade "<<endl;
	   else cout<<" Mb N EH identidade"<<endl;*/
	   	   
		//cout<<" resultante: "<<endl;
	    //InterfaceMatriz::escreverMatriz(MA);
	
		/*//Matriz MD(0,0);
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
