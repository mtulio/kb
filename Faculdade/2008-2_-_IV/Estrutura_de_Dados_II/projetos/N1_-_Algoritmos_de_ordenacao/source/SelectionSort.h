#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include<iostream>

class SelectionSort
{      
      public:
             static void ordena(int vet[], int tam);
};//fim da class selection
      
void SelectionSort::ordena(int vet[], int tam)
{
  int j=0;
  for(int i=0; i<=tam; i++)
  {//inicio for
      if(vet[i] < vet[j] ) {
      //std::cout<<" ANTES = vET["<<i<<"]="<<Vet[i]<<std::endl;
      int aux=0;
      aux = vet[i];
      vet[i] = vet[j];
      vet[j] = aux;          
      //    std::cout<<" DEPOIS = vET["<<i<<"]="<<Vet[i]<<std::endl;
      }
      if( (i==(tam)) && (j!=(tam)) ) {
          j++; i=j;
      }//fim if
  }//fim for
}//fim ordena      
      

#endif /*SELECTIONSORT_H_*/
