#ifndef INTERFACE_H_
#define INTERFACE_H_
#include"Vetor.h"
#include <sys/time.h>

class Interface{
	
	public:
		static void menuPrincipal();
		static void menuSec(int qtd);
		
};

void Interface::menuPrincipal()
{
	system("clear");
	
	int dec;
	system("clear");
	cout<<"Qual método de ordenação:"<<endl;
	cout<< "1 - 10 Elementos"<<endl;
	cout<< "2 - 1000 Elementos"<<endl;
	cout<< "3 - 10000 Elementos"<<endl;
	cout<< "0 - Encerrar o programa"<<endl<<endl;
	cin>>dec;
		
	switch(dec)
	{
		case 0: exit(0);
		case 1:{
			int y=10;
			Interface::menuSec(y);
		}
		break;
		case 2:{
			int y=1000;
			Interface::menuSec(y);
		}
		break;
		case 3:{
			int y=10000;
			Interface::menuSec(y);
		}
		break;
	} 

}

void Interface::menuSec(int qtd)
{
	int aux;
	system("clear");
	cout<<"Qual método de ordenação:"<<endl;
	cout<< "1 - Ordenado"<<endl;
	cout<< "2 - Invertido"<<endl;
	cout<< "3 - Aleatório"<<endl;
	cout<< "0 - Voltar ao menu Anterior:"<< endl;
	cin>>aux;	
	switch(aux)
	{
		//double ti,tf,insert,bub,mer,qu;
		
		case 1:{
			////////////////////////////////////////////////////
			///////////////////// 1-quick sort //////////////////
			//////////////////////////////////////////////////

			cout<<"Número de elementos: "<<qtd<<endl;
			cout<<"Vetor Ordenado"<<endl;
			cin.get();cin.get();
			
			system("clear");
			cout<< "QUICK SORT:"<<endl<<endl;
			double ti, tf, qui;
			Vetor vet1(qtd);
			vet1.VetOrdenado(qtd);
			
			
			vet1.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			int pi=0;
			int pf=qtd-1;
			
			//medindo o tempo de execução
			struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			
			//metodo de ordnação
			vet1.quickSort(pi,pf);
			
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			qui = (tf-ti);
			
			
			vet1.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< qui<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 2-merge Sort ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "MERGE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			
			double merg;
			Vetor vet2(qtd);
			vet2.VetOrdenado(qtd);
			
			
			vet2.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			pi=0;
			pf=qtd-1;
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet2.mergeSort(pi,pf);
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			merg = (tf-ti);
			
			
			vet2.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< merg<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			
			///////////////////////////////////////////////////////////////
			/////////////////// 3-BUBBLE SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "BUBBLE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double bub;
			Vetor vet3(qtd);
			vet3.VetOrdenado(qtd);
			
			vet3.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet3.bubbleSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			bub = (tf-ti);
			
			
			vet3.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 4-INSERT SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "INSERT SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double ins;
			Vetor vet4(qtd);
			vet4.VetOrdenado(qtd);
			
			vet4.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet4.insertSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			ins = (tf-ti);
			
			
			vet4.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
		}
		break;
		case 2:{
			
			////////////////////////////////////////////////////
			///////////////////// 1-quick sort //////////////////
			//////////////////////////////////////////////////

			cout<<"Número de elementos: "<<qtd<<endl;
			cout<<"Vetor Invertido"<<endl;
			cin.get();cin.get();
			
			system("clear");
			cout<< "QUICK SORT:"<<endl<<endl;
			double ti=0, tf=0, qui=0;
			Vetor vet1(qtd);
			vet1.VetInverso(qtd);
			
			
			vet1.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			int pi=0;
			int pf=qtd-1;
			
			//medindo o tempo de execução
			struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet1.quickSort(pi,pf);
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			qui = (tf-ti);
			
			
			vet1.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< qui<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 2-merge Sort ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "MERGE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			
			double merg;
			Vetor vet2(qtd);
			vet2.VetInverso(qtd);
			
			
			vet2.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			pi=0;
			pf=qtd-1;
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet2.mergeSort(pi,pf);
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			merg = (tf-ti);
			
			
			vet2.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< merg<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			
			///////////////////////////////////////////////////////////////
			/////////////////// 3-BUBBLE SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "BUBBLE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double bub;
			Vetor vet3(qtd);
			vet3.VetInverso(qtd);
			
			vet3.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet3.bubbleSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			bub = (tf-ti);
			
			
			vet3.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 4-INSERT SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "INSERT SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double ins;
			Vetor vet4(qtd);
			vet4.VetInverso(qtd);
			
			vet4.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet4.insertSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			ins = (tf-ti);
			
			
			vet4.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
		}
		break;
		case 3:{
			
			
			////////////////////////////////////////////////////
			///////////////////// 1-quick sort //////////////////
			//////////////////////////////////////////////////

			cout<<"Número de elementos: "<<qtd<<endl;
			cout<<"Vetor Ordenado"<<endl;
			cin.get();cin.get();
			
			system("clear");
			cout<< "QUICK SORT:"<<endl<<endl;
			double ti, tf, qui;
			Vetor vet1(qtd);
			vet1.VetAleatorio(qtd);
			
			
			vet1.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			int pi=0;
			int pf=qtd-1;
			
			//medindo o tempo de execução
			struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet1.quickSort(pi,pf);
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			qui = (tf-ti);
			
			
			vet1.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< qui<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 2-merge Sort ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "MERGE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			
			double merg;
			Vetor vet2(qtd);
			vet2.VetAleatorio(qtd);
			
			
			
			vet2.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			pi=0;
			pf=qtd-1;
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet2.mergeSort(pi,pf);
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			merg = (tf-ti);
			
			
			vet2.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< merg<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			
			///////////////////////////////////////////////////////////////
			/////////////////// 3-BUBBLE SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "BUBBLE SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double bub;
			Vetor vet3(qtd);
			vet3.VetAleatorio(qtd);
			
			vet3.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet3.bubbleSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			bub = (tf-ti);
			
			
			vet3.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
			///////////////////////////////////////////////////////////////
			/////////////////// 4-INSERT SORT ///////////////////////////////
			//////////////////////////////////////////////////////////////
			tf=0;
			ti=0;
			system("clear");
			cout<< "INSERT SORT:"<<endl<<endl;
			cin.get();cin.get();
			
			double ins;
			Vetor vet4(qtd);
			vet4.VetAleatorio(qtd);
			
			vet4.imprimir();
			cout<<"Antes da ordenação:"<<endl;
			cin.get();cin.get();
			
			//medindo o tempo de execução
			//struct timeval tempo_inicio, tempo_fim;
			gettimeofday(&tempo_inicio,NULL);
			vet4.insertSort();
			gettimeofday(&tempo_fim,NULL);
			tf =(double)tempo_fim.tv_usec+((double)tempo_fim.tv_sec*1000000);
			ti =(double)tempo_inicio.tv_usec+((double)tempo_inicio.tv_sec*1000000);
			ins = (tf-ti);
			
			
			vet4.imprimir();
			cout<<"Depois da ordenação:"<<endl<<endl;
			cout<<"Tempo de execução: "<< bub<<" micro segundos "<<endl<<endl<<endl;
			cin.get();cin.get();
			
		}
		break;
		case 0:{
			Interface:: menuPrincipal();
		}
		break;
	} 

}
		
#endif /*INTERFACE_H_*/
