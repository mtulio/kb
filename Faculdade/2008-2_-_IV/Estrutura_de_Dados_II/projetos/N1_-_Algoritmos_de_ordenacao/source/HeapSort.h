#ifndef HEAPSORT_H_
#define HEAPSORT_H_



class HeapSort
{
public:
		
	static void ordena(int vet[], int tam);
	
};// fim da classe HeapSort

void HeapSort::ordena(int vet[], int n)
{
	int i=n/2, t, pai, filho;
	for(;;)
	{
		if(i>0)
		{
			i--;
			t = vet[i];
		}//fim if
		else
		{
			n--;
			if(n==0) return;
			t = vet[n];
			vet[n] = vet[0];
		}//fim else
		pai = i;
		filho = i*2+1;
		while(filho<n)
		{
			if((filho+1 < n) && (vet[filho+1]>vet[filho])) filho++;
			if(vet[filho] > t)
			{
				vet[pai] = vet[filho];
				pai = filho;
				filho = pai*2 +1;
			}//fim if
			else break;
		}//fim while
		vet[pai] = t;
	}//fim for
}//fim ordena


#endif /*HEAPSORT_H_*/
