#include <iostream>
#include<string>
#include"Matriz.h"
#include"InterfaceMatriz.h"
#include"Persistencia.h"

using namespace std;

int main()
{
	unsigned int linha,coluna;
	system("clear");
	cout<<" S I S T E M A  D E  M A T R I Z E S";
	cout<<endl<<endl;

/*   cout<<" \t\tProgramado por JAMMT S/A"<<endl<<endl;
   cout<<"Para executar o programa, configure-o segundo as especificacoes!!!"<<
          endl<<"\"Retire os comentarios no FONTE Principal e execute novamente\"";
   cout<<endl<<endl<<"\t\"RODANU QUI NEM BALINHA NA BOKA DE BANGUELA =D \""<<endl;
   cin.get(); 
*/

//LENDO AS MATRIZES
 cout<<"Quantidade de Linhas da matriz A: ";
	cin>>linha;
	cout<<"Quantidade de Colunas da matriz A: ";
	cin>>coluna;
	
	Matriz MA(linha,coluna);
	InterfaceMatriz::lerMatriz(MA);
	cout<<endl<<endl<<"Escrita da matriz A  SEm arquivo"<<endl<<endl;
	InterfaceMatriz::escreverMatriz(MA);
	

   cout<<"Quantidade de Linhas da matriz B: ";
	cin>>linha;
	cout<<"Quantidade de Colunas da matriz B: ";
	cin>>coluna;
	
	Matriz MB(linha,coluna);
	InterfaceMatriz::lerMatriz(MB);
	cout<<endl<<endl<<"Escrita da matriz B"<<endl<<endl;
	InterfaceMatriz::escreverMatriz(MB);
	

//IMPRIMINDO AS MATRIZES ORIGINAIS PARA CONFERENCIA
/*system("clear");
cout<<endl<<"    Matriz A"<<endl;
InterfaceMatriz::escreverMatriz(MA);


cout<<endl<<"    Matriz B"<<endl;
InterfaceMatriz::escreverMatriz(MB);*/

//TESTES PERSISTENCIA
/*	string str="matrizMA.txt";
   Persistencia per;
	per.atribuirMatrizArquivo(MA, str);
	cout<<"  Gravouuuu  "<<endl<<endl;
	//cout<<"Nao gravou"<<endl;	
	cin.get();cin.get();
	
   Matriz MC(Persistencia::obterMatrizDoArquivo(str));
	InterfaceMatriz::escreverMatriz(MC);
	cout<<"  AKI"<<endl;
	cin.get();
*/
/*
cin.get();cin.get();
{
Matriz MC(0,0);
if(per.obterMatrizArquivo(MC, "MA.txt")){
                              cout<<"  Entrei pra imprimir..teste"<<endl<<endl;
                              InterfaceMatriz::escreverMatriz(MC);
                              }
else cout<<" nao foi possivel recuperar"<<endl<<endl;
cin.get();cin.get();
}
*/


//   METODOS A SEREM APRESENTADOS NO DIA 04/03/2008
//testando os metodos
/*
    cout<<endl<<"__SOMA DAS MATRIZES 1__"<<endl<<endl;
   //TESTADO E APROVADO
   {
   Matriz MC(0,0);
   if(!MC.adicao(MA, MB)) cout<<"Imposs�vel ADD"<<endl;
   InterfaceMatriz::escreverMatriz(MC);
   }
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
*/ 
   
   /*cout<<endl<<"__SUBTRACAO DAS MATRIZES 2__"<<endl<<endl;
   //TESTADO E APROVADO
   {
   Matriz MC(0,0);
   if(!MC.subtracao(MA,MB)) cout<<"Impossivel subtrair"<<endl;
   InterfaceMatriz::escreverMatriz(MC);   
   }
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
   */
   
   cout<<endl<<"__MULTIPLICACAO DAS MATRIZES 3__"<<endl<<endl;
   //TESTADO E APROVADO
   {
   Matriz MC(0,0);
   if(!MC.multiplicacao(MA,MB)) cout<<"IMPOSSIVEL EFETUAR MULTIPLICACAI"<<endl<<endl;
   InterfaceMatriz::escreverMatriz(MC);
   getchar();getchar();
   }
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();getchar();

   
/*   
   cout<<"__TRIANGULAR SUPERIOR 4__"<<endl<<endl;
   
   if(MA.triangularSuperior()) cout<<" A eh triangular superior"<<endl;
   else cout<<" A nao eh triangular superior"<<endl;
   if(MB.triangularSuperior()) cout<<" B eh triangular superior"<<endl;
   else cout<<" B nao eh triangular superior"<<endl;
      
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();


/*
   cout<<"__TRIANGULAR INFERIOR 5__"<<endl<<endl;
   
   if(MA.triangularInferior()) cout<<" A eh triangular inferior"<<endl;
   else cout<<" A nao eh triangular inferior"<<endl;
   if(MB.triangularInferior()) cout<<" B eh triangular inferior"<<endl;
   else cout<<" B nao eh triangular inferior"<<endl;
      
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
*/

/*
cout<<"__SIMETRICA 06__"<<endl<<endl;
if(MA.simetrica()) cout<<"\t A Matriz A eh simetrica"<<endl<<endl;
else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;
if(MB.simetrica()) cout<<" \tA Matriz B eh simetrica"<<endl<<endl;
else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;

cout<<endl<<" TECLE ENTER PRA CONTINUAR"<<endl;
cin.get();cin.get();  
*/


/*
cout<<"__ANTI SIMETICA 07__"<<endl<<endl;
if(MA.antiSimetrica()) cout<<" \tA Matriz A eh anti-Simetrica"<<endl<<endl;
else cout<<"\tA matriz A nao eh anti-simetrica"<<endl<<endl;
if(MB.antiSimetrica()) cout<<"\tA matriz B eh anti-simetrica"<<endl<<endl;
else cout<<"\tA Matriz B nao eh anti simetrica"<<endl<<endl;

cout<<endl<<" TECLE ENTER PRA CONTINUAR"<<endl;
cin.get();cin.get();
*/

/*cout<<"__IDentidade 8__"<<endl<<endl;
if(MA.identidade()) cout<<"A matriz A eh identidade"<<endl<<endl;
else cout<<"A Matriz A nao eh identidade"<<endl<<endl;    
cin.get();cin.get();
*/

/*cout<<" __TRANSPOSTA 9__"<<endl<<endl;
{
Matriz MC(0,0);
MC.resultanteDaTransposta(MA);
InterfaceMatriz::escreverMatriz(MC);
cin.get();cin.get();
}*/



/*   cout<<" __POTENCIACAO 10__"<<endl<<endl;
   {
   //cout<<"Digite a potencia de A: ";
   //int pot;
   //cin>>pot;
   for(int pot=0; pot<5; pot++){
     Matriz MC(0,0);
     MC.resultanteDaPotencia(MA, pot);
     InterfaceMatriz::escreverMatriz(MC);   
     cout<<endl<<endl;
   }
   }
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
*/

/*
cout<<"MULTIPLICACAO POR K__11__"<<endl<<endl;
{
cout<<"Digite o valor de k p MA: ";
int k;
cin>>k;
Matriz MC(0,0);
MC.multiplicacaoPorK(MA, k);
InterfaceMatriz::escreverMatriz(MC);
cin.get();cin.get();
}
{
cout<<"Digite o valor de k p MB: ";
int k;
cin>>k;
Matriz MC(0,0);
MC.multiplicacaoPorK(MB, k);
InterfaceMatriz::escreverMatriz(MC);
cin.get();cin.get();
}
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
*/
/*
cout<<" __IGUALDADE 12__"<<endl<<endl;
   if(MA.igual(MB)) cout<<"As matrizes sao iguais"<<endl<<endl;
   else cout<<"as matrizes nao sao iguais"<<endl<<endl;
   
   cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
   getchar();
   getchar();
*/

/*
cout<<"___DIFERENTE 13__"<<endl<<endl;
if(MA.diferente(MB)) cout<<"A matriz A eh diferente de B"<<endl<<endl;
else cout<<"A matriz A nao eh diferente de B"<<endl<<endl;
cin.get();cin.get();
*/


/*cout<<"__MAtriz Ortogonal 14__"<<endl<<endl;
if(MA.ortogonal()) cout<<" Eh ortogonal"<<endl;
else cout<<" nao eh ortogonal "<<endl;

cout<<endl<<" TECLE ENTER PRA CONTINUAR"<<endl;
cin.get();cin.get();
*/


/*
cout<<"__PERMUTACAO 15__"<<endl<<endl;
//int situacao;
//situacao=MA.permutacao();
//cout<<" situacao = "<<situacao<<endl;

if(MA.permutacao())  cout<<" A Matriz A eh de permutacao"<<endl<<endl;
else cout<<" A matriz A nao eh de permutacao"<<endl<<endl;

cout<<endl<<" TECLE ENTER PRA CONTINUAR"<<endl;
cin.get();cin.get();
*/


/*


   int opcao;
	do{
      system("cls");
      cout<<" S I S T E M A  D E  M A T R I Z E S"<<endl;
      cout<<endl<<" 1 - Adicao";
      cout<<endl<<" 2 - Subtracao";
      cout<<endl<<" 3 - Multiplicacao";
      cout<<endl<<" 4 - Triangular Superior";
      cout<<endl<<" 5 - Triangular Inferior";
      cout<<endl<<" 6 - Simetrica";
      cout<<endl<<" 7 - Anti-Simetrica";
      cout<<endl<<" 8 - Identidade";
      cout<<endl<<" 9 - Transposta";
      cout<<endl<<"10 - Potencia";
      cout<<endl<<"11 - Mult por K";
      cout<<endl<<"12 - Igualdade";
      cout<<endl<<"13 - Diferenca";
      cout<<endl<<"14 - Ortogonal";
      cout<<endl<<"15 - Permutacao";
      cout<<endl<<" 0 - SAIR";
      cout<<endl<<"Digite a opcao: ";
      cin>>opcao;
      
      switch(opcao){
                    case 1:{//inicio case 1 - Soma                           
                         cout<<endl<<"__SOMA DAS MATRIZES 1__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(!MC.adicao(MA, MB)) cout<<"Imposs�vel ADD"<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 1
                    case 2:{//subtracao
                         cout<<endl<<"__SUBTRACAO DAS MATRIZES 2__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(!MC.subtracao(MA,MB)) cout<<"Impossivel subtrair"<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 2
                    case 3:{//inicio case 3
                         cout<<endl<<"__MULTIPLICACAO DAS MATRIZES 3__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(MC.multiplicacao(MA,MB)==0) cout<<"IMPOSSIVEL EFETUAR MULTIPLICACAI"<<endl<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 3
                    case 4:{//
                         cout<<"__TRIANGULAR SUPERIOR 4__"<<endl<<endl;
                         if(MA.triangularSuperior()) cout<<" A eh triangular superior"<<endl;
                            else cout<<" A nao eh triangular superior"<<endl;
                         if(MB.triangularSuperior()) cout<<" B eh triangular superior"<<endl;
                            else cout<<" B nao eh triangular superior"<<endl;
                         
                         cin.get();cin.get();
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 6
                    
                    case 5:{
                         cout<<"__TRIANGULAR INFERIOR 5__"<<endl<<endl;
                         if(MA.triangularInferior()) cout<<" A eh triangular inferior"<<endl;
                            else cout<<" A nao eh triangular inferior"<<endl;
                         if(MB.triangularInferior()) cout<<" B eh triangular inferior"<<endl;
                            else cout<<" B nao eh triangular inferior"<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 7
                    
                    case 6:{// 
                         cout<<"__SIMETRICA 06__"<<endl<<endl;
                         if(MA.simetrica()) cout<<"\t A Matriz A eh simetrica"<<endl<<endl;
                            else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;
                         if(MB.simetrica()) cout<<" \tA Matriz B eh simetrica"<<endl<<endl;
                            else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 8
                    
                    case 7:{//
                         cout<<"__ANTI SIMETICA 07__"<<endl<<endl;
                         
                         if(MA.antiSimetrica()) cout<<" \tA Matriz A eh anti-Simetrica"<<endl<<endl;
                            else cout<<"\tA matriz A nao eh anti-simetrica"<<endl<<endl;
                         if(MB.antiSimetrica()) cout<<"\tA matriz B eh anti-simetrica"<<endl<<endl;
                            else cout<<"\tA Matriz B nao eh anti simetrica"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 9
                    case 8:{
                         cout<<"__IDentidade 8__"<<endl<<endl;
                         if(MA.identidade()) cout<<"A matriz A eh identidade"<<endl<<endl;
                            else cout<<"A Matriz A nao eh identidade"<<endl<<endl; 
                         if(MB.identidade()) cout<<"A matriz B eh identidade"<<endl<<endl;
                            else cout<<"A Matriz B nao eh identidade"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                         
                    }//fim case 10             
                    case 9:{
                       cout<<" __TRANSPOSTA 9__"<<endl<<endl;
                       {
                          cout<<"\t Transposta de A:"<<endl;
                          Matriz MC(0,0);
                          MC.resultanteDaTransposta(MA);
                          InterfaceMatriz::escreverMatriz(MC);
                       }
                       {
                          cout<<"\t Transposta de B:"<<endl;
                          Matriz MC(0,0);
                          MC.resultanteDaTransposta(MB);
                          InterfaceMatriz::escreverMatriz(MC);
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;     
                    }//fim case 11
                    case 10:{
                       cout<<" __POTENCIACAO 10__"<<endl<<endl;
                       {
                          cout<<"Digite a potencia de A: ";
                          int pot;
                          cin>>pot;
                          Matriz MC(0,0);
                          MC.resultanteDaPotencia(MA, pot);
                          InterfaceMatriz::escreverMatriz(MC);   
                          cout<<endl<<endl;
                       }
                       {
                          cout<<"Digite a potencia de B: ";
                          int pot;
                          cin>>pot;
                          Matriz MC(0,0);
                          MC.resultanteDaPotencia(MB, pot);
                          InterfaceMatriz::escreverMatriz(MC);   
                          cout<<endl<<endl;
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 10 
                    case 11:{
                       cout<<"MULTIPLICACAO POR K__11__"<<endl<<endl;  
                       {
                          cout<<"Digite o valor de k p MA: ";
                          int k;
                          cin>>k;
                          Matriz MC(0,0);
                          MC.multiplicacaoPorK(MA, k);
                          InterfaceMatriz::escreverMatriz(MC);
                          cin.get();
                       }
                       {
                          cout<<"Digite o valor de k p MB: ";
                          int k;
                          cin>>k;
                          Matriz MC(0,0);
                          MC.multiplicacaoPorK(MB, k);
                          InterfaceMatriz::escreverMatriz(MC);
                          cin.get();
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 11 
                    case 12:{
                       cout<<" __IGUALDADE 12__"<<endl<<endl;
                       if(MA.igual(MB)) cout<<"As matrizes sao iguais"<<endl<<endl;
                          else cout<<"as matrizes nao sao iguais"<<endl<<endl;
                         
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 12
                    case 13:{
                       cout<<"___DIFERENTE 13__"<<endl<<endl;  
                       if(MA.diferente(MB)) cout<<"A matriz A eh diferente de B"<<endl<<endl;
                          else cout<<"A matriz A nao eh diferente de B"<<endl<<endl;
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim   case 13
                     case 14:{
                       cout<<"__MAtriz Ortogonal 14__"<<endl<<endl;
                       if(MA.ortogonal()) cout<<" A Matriz A eh ortogonal"<<endl;
                          else cout<<" A Matriz A nao eh ortogonal "<<endl;
                       cin.get();
                       
                       if(MB.ortogonal()) cout<<" A Matriz B eh ortogonal"<<endl;
                          else cout<<" A Matriz B nao eh ortogonal "<<endl;
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim case 10         
	                 case 15:{
                       cout<<"__PERMUTACAO 15__"<<endl<<endl;
                       if(MA.permutacao())  cout<<" A Matriz A eh de permutacao"<<endl<<endl;
                          else cout<<" A matriz A nao eh de permutacao"<<endl<<endl;
                       cin.get();
                       if(MB.permutacao())  cout<<" A Matriz B eh de permutacao"<<endl<<endl;
                          else cout<<" A matriz B nao eh de permutacao"<<endl<<endl;
                       
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim case 10
                    case 0:{
                         cout<<"Finalizando Programa... Tecle Enter."<<endl<<endl;
                         exit(0);
                         cin.get();
                         break;
                    }
                         
                    default:{
                            cout<<"Opcao invalida"<<endl<<endl;
                            cin.get();
                            break;
                    }
      }//fim switch
	
  }while(opcao!=0);
*/
	//Persistencia::persistirMatrizNoArquivo(MA,"matriz.txt");
	
	//return 1;
	exit(1);
}
