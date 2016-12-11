#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

class InsertionSort
{
 public:
        static void ordena(int vet[], int tam);      
}; //fim InsertSort
 
 //metodo do H    
//metodo do wikipedia
void InsertionSort::ordena(int vet[], int tam)
{//inicio ordena
   int j;
   for(int i=1; i<tam; i++)
   {//inicio for
      //cout<<" for 1: "<<i<<endl;
      int valor=vet[i];
      //cout<<" VALOR: "<<valor<<endl;
      j=i-1;
      //cout<<" J: "<<j<<endl;
      while( (j>=0) && (vet[j]>valor) )
      {//inicio while
         vet[j+1]=vet[j];
         //cout<<" While vet[j]: "<<vet[j]<<endl;
         //cout<<" While - vet[j+1]: "<<vet[j+1]<<endl;
         j--;
      }//fim while
      vet[j+1] = valor;
   }//fikm for
}//fim ordena

#endif /*INSERTIONSORT_H_*/
