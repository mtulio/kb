#ifndef VETOR_H_
#define VETOR_H_
#include <iostream>
#include <cstdlib>

using namespace std;

//using std::rand;

class Vetor
{
	private:
		int qtd;
		int *vet;
	
	public:
		Vetor(int qtd):qtd(qtd){vet = new int(qtd);}
		//~Vetor(){ delete[]vet; }
		
		//obter elemento e atribuir qtd
		int *obterElemento(){return this->vet;}
		void atribuirQtd(const int qtd){this->qtd=qtd;}
		
		//vetores
		void VetAleatorio(int qtd);
		void VetOrdenado(int qtd);
		void VetInverso(int qtd);
		void imprimir();
		
		//ordenaçao
		void insertSort();
		void bubbleSort();
		void quickSort(int pi,int pf);
		int partition(int pi , int pf);
		void mergeSort(int pi, int pf);
		void merge(int pi ,int m,int n ,int pf);
		
		
	
};

void Vetor::VetAleatorio(int qtd)
{
	//vet = new Vetor(qtd);

	for(int cont=0; cont<qtd; cont++)
	{
		vet[cont] = rand()%qtd+1;
		//cout<<vet[cont]<<endl;
	}
	
}

void Vetor::VetOrdenado(int qtd)
{
	//vet = new Vetor(qtd);
	for(int cont=0; cont<qtd; cont++)
	{
		int x=cont;
		vet[cont]=x++;
		//cout<<vet[cont]<<endl;
	}
	
}

void Vetor::VetInverso(int qtd)
{
	//vet = new Vetor(qtd);
	int j=0;
	for(int i=qtd ; i>0 ; i--)
	{
		vet[j]=i;
		j++;
	}
}

void Vetor::imprimir()
{

	for(int i=0 ; i < qtd ; i++)
	{	 
		
		cout<<"[ "<< vet[i]<<" ]"<<endl;

		
	}
}

void Vetor::insertSort()
{
	int aux,j,i;
   for(i=0; i<qtd; i++)
   {
   		aux=vet[i];
   		j=i;
   		while(j > 0 && vet[j - 1] > aux)
   		{
   			vet[j] = vet[j - 1];  
   			 j--;
   		}
   		vet[j] = aux;
   }
}

void Vetor::bubbleSort()
{
	int i,j,aux;
	for( i = 0 ; i < qtd-1 ; i ++)
	{
		 for( j = qtd-1 ; j > i ; j --)
		 {
		 	if(  vet[j] < vet[j-1] )
		 	{
		 		aux = vet [ j ];
		 		vet[ j ] = vet[ j -1 ];
		 		vet[ j-1 ] = aux;
		 	}
		 	
		 }  
		
	}  

}

void Vetor::quickSort(int pi , int pf)
{
	int q;
	if(pi<pf)
	{
		q= partition (pi , pf );
		quickSort(pi , q );
		quickSort((q+1) , pf );
	}
}

int Vetor::partition(int pi , int pf)
{
	int x,i,j,t;
	x=vet[pi];
	i=pi-1;
	j=pf+1;
	
	for(;;)
	{
		do { j--; } while(vet[j]>x);
		do { i++; } while(vet[i]<x);
		if (i<j) 
		{
			t = vet[i];
		    vet[i] = vet[j];
		    vet[j] = t;
		 } 
		 else
		    return j;
	}

}

void Vetor::mergeSort(int pi , int pf)
{
	int m;
	m=(pi + pf)/2;
	if(pf>pi)
	{
		mergeSort(pi,m);
		mergeSort((m+1),pf);
		merge(pi,m,(m+1),pf);
	}
}

void Vetor::merge(int pi ,int m,int n ,int pf)
{
	  int i = pi;
	  int j = m+1;
	  int k = 0;
	  int t[pf-pi+1];
	  
	  while(i<m+1 || j<pf+1) 
	  {
	    if (i==m+1) 
	    { 
	      t[k] = vet[j];
	      j++; k++;
	      
	    } 
	    else if (j==pf+1) 
	    { 
	      t[k] = vet[i];
	      i++; k++;
	      
	    } 
	    else if (vet[i] < vet[j]) 
	    { 
	      t[k] = vet[i];
	      i++; k++;
	    } 
	    else 
	    { 
	      t[k] = vet[j];
	      j++; k++;
	    }
	  }
	  for(i=pi;i<=pf;i++)
	    vet[i] = t[i-pi];
}

#endif /*VETOR_H_*/
