#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<sys/time.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

#include"InsertionSort.h"
#include"SelectionSort.h"
#include"QuickSort.h"
#include"ShellSort.h"
#include"HeapSort.h"

#include"Persistencia.h"


using namespace std;

class Interface
{
private:
    static void menuInsertionSort(int tam);
    static void menuSelectionSort(int tam);
    static void menuQuickSort(int tam);
    static void menuShellSort(int tam);
    static void menuHeapSort(int tam);
                
    static void gerarVetor(int vet[], int tam); //gera o vetor com elementos aleatorios
    static int lerNumeroDeRepeticoes();
    static void escreverVetor(int vet[], int tam);
 
public:	 
    static void menuPrincipal();        
      
};//fim interface

void Interface::menuPrincipal()
{
int opcao=1;
do{
   system("clear");
   int tamOpt=0;
   cout<<endl<<"\t **** MENU PRINCIPAL *** "<<endl;
   cout<<endl<<" Informe o Tamanho do Vetor:";
   cout<<endl<<" 1 - 100 <> 10^2";
   cout<<endl<<" 2 - 1.000 <> 10^3";
   cout<<endl<<" 3 - 10.000 <> 10^4";
   cout<<endl<<" 4 - 100.000 <> 10^5";
   cout<<endl<<" 5 - 1.000.000 <> 10^6";
   //cout<<endl<<" 7 - Todas as op��es - O COMPUTADOR FICAR� OCIOSO";
   cout<<endl<<" 0 - SAIR";
   cout<<endl<<" Digite a opcao: ";
   cin>>tamOpt;
   
   switch(tamOpt){
      case 0:{
         cout<<" Finalizando Programa...Tecle Enter!"<<endl; 
         getchar();getchar();
         exit(0);
         break;             
      }//fim case 0
   }//fim switch
   
   int tam;
   if (tamOpt>=1 && tamOpt<=7) tam = pow(10,(tamOpt+1)); 
      else tam=0;
   
   int opcao;
   cout<<endl<<"\t *** Menu Escolha de Metodo ***"<<endl;
   cout<<endl<<"Tamanho do Vetor: "<<tam<<endl;
   cout<<endl<<" Informe o Metodo a ser calculado: ";
   cout<<endl<<" 1 - InsertionSort";
   cout<<endl<<" 2 - SelectionSort";
   cout<<endl<<" 3 - QuickSort";
   cout<<endl<<" 4 - ShellSort";
   cout<<endl<<" 5 - HeapSort";
   cout<<endl<<" 0 - SAIR";
   cout<<endl<<" Digite a opcao: ";
   cin>>opcao;
   
   switch(opcao){
        case 0:{
            cout<<" Finalizando Programa...Tecle Enter!"<<endl; 
            getchar();getchar();
            exit(0);
             break;             
        }//fim case 0
        case 1:{
             menuInsertionSort(tam);
             break;
        }//fim case 1   
        case 2:{
             menuSelectionSort(tam);
             break;            
        }// FIM CASE 2
        case 3:{
             menuQuickSort(tam);
             break;
        }//fim case 3  
        case 4:{
             menuShellSort(tam);
             break;            
        }// fim case 4
        case 5:{
             menuHeapSort(tam);
             break;            
        }// fim case 5      
     }//fim switch
      
}while(opcao!=0);

}//segundo menu principal 2

void Interface::gerarVetor(int vet[], int tam)
// gera vetor com valores aleatorios
{
      vet[tam];
      
      srand(tam); //gerando nros aleatorios
      int num;
      for(int i=0; i<(tam); i++)
      {//inicio for
          num = rand() % tam; //gera um numero
          vet[i] = num;
      }//fim for
      //return vet;
}//fim gerar vetor

void Interface::escreverVetor(int vet[], int tam){
     
     for(int i=0; i<tam; i++)
     {
         cout<<" Vet["<<i<<"]="<<vet[i]<<endl;   
     }//fim for impressao
}//fim escreve vetor


int Interface::lerNumeroDeRepeticoes()
{//inicio ler numero de repeti��es
   int qtd=0;
   do{
          cout<<" Digite o numero de Repeticoes do Codigo (de 1 a 5 ): ";
          cin>>qtd;
          if((qtd<0) || (qtd>5)) qtd=0; //condicao para for�ar o user digitar um valor
   }while(qtd==0);
   
   return qtd;
}//fim ler numero de repeticoes

// ************************ MENU INSERTION SORT
void Interface::menuInsertionSort(int tam)
{//inicio
	string metodo="InsertionSort";
   int qtd = lerNumeroDeRepeticoes();
   
   for(int i=0; i<qtd; i++)
   {// for para o numero de repeticoes
      
	   // *************************************
      // INICIO DO CODIGO DE MARCAR TEMPO
      double ti,tf,deltaT; //ti == tempo inicial, tf == tempo final
      // struct timeval � declarada em time.h 
      struct timeval tempo_inicio, tempo_fim;
      // *************************************
      //tam=10;
      int vet[tam]; 
      
      gerarVetor(vet, tam);
              
      //escreverVetor(vet,tam);
               
      cout<<endl<<endl;
      cout<<" \t STATUS: \"Processando "<<metodo<<"\""
              <<" \n\t Nro Repeticoes: "<<qtd
              <<"\n\t Repeticao Atual: "<<i+1
              <<"\n\t Complexidade: "<<tam<<endl;
      cout<<"\t POR FAVOR AGUARDE..."<<endl;
      
      //****************** INICIO DO MARCACAO DO TEMPO
      gettimeofday(&tempo_inicio,NULL);
      // *********************************************
      
      InsertionSort::ordena(vet, tam);
      
      //****************** FIM DA MARCACAO DO TEMPO
      gettimeofday(&tempo_fim,NULL);
      // *********************************************
      
      tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
      ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
      deltaT = (tf-ti);
               
      //cout<<" DELTA T: "<<deltaT<<endl<<endl;
      //escreverVetor(vet,tam);
               
      cout<<"\t Metodo "<<metodo<<" processado e gravado no Arquivo: \n\t\t"<<
           Persistencia::gravarNoArquivo(metodo, tam, deltaT, (i+1))
           <<endl;
   }//fim for
   cout<<endl;
   cout<<" CONCLUSAO: Processamento do Metodo "<<metodo<<" concluido com sucesso!"<<endl
   		<<"           Consulte o Arquivo para mais detalhes!!!"<<endl<<endl;
   
   getchar();getchar();
}//fim menu insertion sort

// ************************ MENU SELECTION SORT

void Interface::menuSelectionSort(int tam)
{//inicio menu SELECTION SORT
   string metodo="SelectionSort";
   int qtd = lerNumeroDeRepeticoes();
   
   for(int i=0; i<qtd; i++)
   {// for para o numero de repeticoes
      
	   // ********************************
      // INICIO DO CODIGO DE MARCAR TEMPO
      double ti,tf,deltaT; //ti == tempo inicial, tf == tempo final
      // struct timeval � declarada em time.h 
      struct timeval tempo_inicio, tempo_fim;
      // ********************************
      
      int vet[tam]; 
      
      gerarVetor(vet, tam);
              
      //escreverVetor(vet,tam);
               
      cout<<endl<<endl;
      cout<<" \t STATUS: \"Processando "<<metodo<<"\""
                    <<" \n\t Nro Repeticoes: "<<qtd
                    <<"\n\t Repeticao Atual: "<<i+1
                    <<"\n\t Complexidade: "<<tam<<endl;
      cout<<"\t POR FAVOR AGUARDE..."<<endl;
      
      //****************** INICIO DO MARCACAO DO TEMPO
      gettimeofday(&tempo_inicio,NULL);
      // *********************************************
      
      SelectionSort::ordena(vet, tam);
      
      //****************** FIM DA MARCACAO DO TEMPO
      gettimeofday(&tempo_fim,NULL);
      // *********************************************
      
      tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
      ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
      deltaT = (tf-ti);
               
      //cout<<" DELTA T: "<<deltaT<<endl<<endl;
      //escreverVetor(vet,tam);
               
      cout<<"\t Metodo "<<metodo<<" processado e gravado no Arquivo: \n\t\t"<<
           Persistencia::gravarNoArquivo(metodo, tam, deltaT, (i+1))
           <<endl;
   }//fim for
   cout<<endl;
   cout<<" CONCLUSAO: Processamento do Metodo "<<metodo<<" concluido com sucesso!"<<endl
      		<<"           Consulte o Arquivo para mais detalhes!!!"<<endl<<endl;
   
   getchar();getchar();   
}//fim menu SELECTION SORT  

// ************** MENU SHELL SORT

void Interface::menuShellSort(int tam)
{
	string metodo="ShellSort";
	int qtd = lerNumeroDeRepeticoes();
	
	for(int i=0; i<qtd; i++)
	{// for para o numero de repeticoes
	    
		// ************************************
	    // INICIO DO CODIGO DE MARCAR TEMPO
	    double ti,tf,deltaT; 
	    //ti == tempo inicial, tf == tempo final
	    // struct timeval � declarada em time.h 
	    struct timeval tempo_inicio, tempo_fim;
	    // ************************************
	      
	    int vet[tam]; 
	      
	    gerarVetor(vet, tam);
	              
	    //escreverVetor(vet,tam);
	               
	    cout<<endl<<endl;
	    cout<<" \t STATUS: \"Processando "<<metodo<<"\""
	        <<" \n\t Nro Repeticoes: "<<qtd
	        <<"\n\t Repeticao Atual: "<<i+1
	        <<"\n\t Complexidade: "<<tam<<endl;
	    cout<<"\t POR FAVOR AGUARDE..."<<endl;
	      
	    //****************** INICIO DO MARCACAO DO TEMPO
	    gettimeofday(&tempo_inicio,NULL);
	    // *********************************************
	      
	    ShellSort::ordena(vet, tam);
	      
	    //****************** FIM DA MARCACAO DO TEMPO
	    gettimeofday(&tempo_fim,NULL);
	    // *********************************************
	    
	    tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
	    ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
	    deltaT = (tf-ti);
	               
	    //cout<<" DELTA T: "<<deltaT<<endl<<endl;
	    //escreverVetor(vet,tam);
	               
	    cout<<"\t Metodo "<<metodo<<" processado e gravado no Arquivo: \n\t\t"<<
	          Persistencia::gravarNoArquivo(metodo, tam, deltaT, (i+1))
	          <<endl;
	   }//fim for
	   cout<<endl;
	   cout<<" CONCLUSAO: Processamento do Metodo "<<metodo<<" concluido com sucesso!"<<endl
	      	<<"           Consulte o Arquivo para mais detalhes!!!"<<endl<<endl;
	   
	   getchar();getchar();
}//fim menu Shell Sort


//************ MENU QUICK SORT

void Interface::menuQuickSort(int tam)
{//inicio quicj Sort
	string metodo="QuickSort";
	int qtd = lerNumeroDeRepeticoes();
	   
	for(int i=0; i<qtd; i++)
	{// for para o numero de repeticoes
	   
		// **********************************
	   // INICIO DO CODIGO DE MARCAR TEMPO
	   double ti,tf,deltaT; //ti == tempo inicial, tf == tempo final
	   // struct timeval � declarada em time.h 
	   struct timeval tempo_inicio, tempo_fim;
	    // ***********************************
	    
	   //instanciando um objeto quick q gera um vetor 
	   // de inteiros no seu construtor passado como
	   // parametro o tamanho do vetor
	   //QuickSort quickSort(tam);
	   
	   //quick trabalha com pivos para efetuar os seus 
	   // calculos
	   //int pivoInicial, pivoFinal;
	   //pivoInicial = 0;
	   //pivoFinal = tam-1;
	   
	   int vet[tam];
	   int inicio=0, fim=tam-1;
	   
	   gerarVetor(vet,tam);
	   
	   //escreverVetor(vet,tam);
	   
	   cout<<endl<<endl;
	   cout<<" \t STATUS: \"Processando "<<metodo<<"\""
	       <<" \n\t Nro Repeticoes: "<<qtd
	       <<"\n\t Repeticao Atual: "<<i+1
	       <<"\n\t Complexidade: "<<tam<<endl;
	   cout<<"\t POR FAVOR AGUARDE..."<<endl;
	   
	   //****************** INICIO DO MARCACAO DO TEMPO
	   gettimeofday(&tempo_inicio,NULL);
	   // *********************************************
	   
	   QuickSort::ordena(vet, inicio, fim);
	   
	   //****************** FIM DA MARCACAO DO TEMPO
	   gettimeofday(&tempo_fim,NULL);
	   // *********************************************
	   
	   tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
	   ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
	   deltaT = (tf-ti);	               
	    
	   //cout<<endl<<"\t\t DELTA T = "<<deltaT<<endl<<endl;
	   
	   //escreverVetor(vet,tam);
	   
	   cout<<"\t Metodo "<<metodo<<" processado e gravado no Arquivo: \n\t\t"<<
	         Persistencia::gravarNoArquivo(metodo, tam, deltaT, (i+1))
	         <<endl;
	   }//fim for
	   cout<<endl;
	   cout<<" CONCLUSAO: Processamento do Metodo "<<metodo<<" concluido com sucesso!"<<endl
	      	<<"           Consulte o Arquivo para mais detalhes!!!"<<endl<<endl;
	   
	   getchar();getchar();
}//fim quick Sort



// ************* menu HEAP SORT

void Interface::menuHeapSort(int tam)
{
	string metodo="HeapSort";
	int qtd = lerNumeroDeRepeticoes();
		   
	for(int i=0; i<qtd; i++)
	{// for para o numero de repeticoes
	    
		// ********************************
		// INICIO DO CODIGO DE MARCAR TEMPO
		double ti,tf,deltaT; 
		//ti == tempo inicial, tf == tempo final
		// struct timeval � declarada em time.h 
		struct timeval tempo_inicio, tempo_fim;
		// ********************************
		 
		//int *vet;
		int vet[tam];
		
		//HeapSort heapSort(tam);
		
        gerarVetor(vet, tam);
          
        //escreverVetor(vet, tam);
           
		cout<<endl<<endl;
		cout<<" \t STATUS: \"Processando "<<metodo<<"\""
		    <<" \n\t Nro Repeticoes: "<<qtd
		    <<"\n\t Repeticao Atual: "<<i+1
		    <<"\n\t Complexidade: "<<tam<<endl;
		cout<<"\t POR FAVOR AGUARDE..."<<endl;
		   
		//****************** INICIO DO MARCACAO DO TEMPO
		gettimeofday(&tempo_inicio,NULL);
		// *********************************************
		   
		HeapSort::ordena(vet, tam);
		   
		//****************** FIM DA MARCACAO DO TEMPO
		gettimeofday(&tempo_fim,NULL);
		// *********************************************
		   
		tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
		ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
		deltaT = (tf-ti);
		               
		//escreverVetor(vet, tam); 
                       
		cout<<"\t Metodo "<<metodo<<" processado e gravado no Arquivo: \n\t\t"<<
		    Persistencia::gravarNoArquivo(metodo, tam, deltaT, (i+1))
		    <<endl;
	}//fim for
	cout<<endl;
	cout<<"  Processamento do Metodo "<<metodo<<" concluido com sucesso!"<<endl
		<<"           Consulte o Arquivo para mais detalhes!!!"<<endl<<endl;
	
	getchar();getchar();
}//fim menu Heap Sort

#endif /*INTERFACE_H_*/
