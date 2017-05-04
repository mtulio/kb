#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort
{

public:
                
        static void ordena(int vet[], int inicio, int fim);
      
      
};//fim da classe QuickSOrt

void QuickSort::ordena(int vet[], int inicio, int fim)
{
	
   if(fim - inicio > 0){
      int aux;
      int pivo = vet[inicio];
      int esquerda = inicio + 1;
      
      int direita = fim;
      
      int iteste=1;
      
      while(esquerda<direita){
    	  
    	  if(vet[esquerda] <= pivo){
            esquerda++;
         }//fim if 2
         else {
              // troca o valor de vetor[esquerdo] com o vetor[direito]
              aux = vet[esquerda];
              vet[esquerda] = vet[direita];
              vet[direita] = aux;
              // fim da troca (equivale a funcao swap(vet[esquerda], vet[direita]
              direita--;              
         }//fim else                        
      }//fim while       
      //Troca de valor de vet[inicio] com vet[fim]
      if(vet[esquerda] > pivo) esquerda--;
      aux = vet[inicio];
      vet[inicio] = vet[esquerda];
      vet[esquerda] = aux;
      //fim da troca ( equivale a funcao swap(vet[inicio], vet[esquerda])
      
      //faz as chamadas recursivas para as duas  partes da lista
      ordena(vet, inicio, esquerda-1);
      ordena(vet, direita, fim);
   }//fim if 1
}//fim metodo

#endif /*QUICKSORT_H_*/
