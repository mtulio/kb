#include<iostream>
#include<string>
#include<stdlib.h>//uso do rand

using namespace std;

/*
void gerarTabela(int tab[],int n)
{//inicio metodo de gerar numeros aleatoros
	tab[n];
	srand(n);
	int num;
	for(int i=0;i<n;i++)
	{//inicio laço de preenchimento do vetor
		num = rand()%n;
		tab[i] = num;
		cout<<endl<<i<<" : "<<num<<" : "<<tab[i]<<endl;
	}//fim for
}///fim do metodo que gera numeros aleatorios

void escreverTabela(int tab[], int n)
{
	for(int i=0;i<n;i++) cout<<"  "<<tab[i]<<endl;
}//fim do metodo de escrever a tabela
*/

int main(void)
{//inicio main
	int n;
	cout<<" Digite o tamanho da tabela: ";
	cin>>n;
	
	int tab[n];
	
	for(int x=0;x<n;x++) tab[x]=0;

	int ch;
	///gerando os numeros aleatorios na tabela atraves do metodo
	//gerarTabela(tab, n);
	
	//tab[n];
	//srand(n);
	int num;
	for(int y=0;y<n;y++)
	{//inicio laço de preenchimento do vetor
		num = rand()%n;
		tab[y] = num;
		//cout<<endl<<y<<" : "<<num<<" : "<<tab[y]<<endl;
	}//fim for

	
	//cout<<" Teste pos 1: "<<tab[0]<<endl;

	//escreverTabela(tab,n);
	for(int j=0;j<n;j++) cout<<"  "<<tab[j]<<endl;

	cout<<"Favor informar um numero inteiro para busca na tabela: ";
	cin>>ch;

	
	int i=0;
	bool achou=false;
	
	for(i=0; (i<n) || (achou=false);i++){
		//cout<<endl<<"tab["<<i<<"]="<<tab[i]<<" : "<<ch<<endl;
		if(tab[i]==ch){
			//cout<<endl<<"Entrou no if"<<endl;
			 achou=true;
			//if(achou==true) cout<<endl<<"Achou alterou seu estado"<<endl;
			//else cout<<" Achou nao alterou seu estado"<<endl;
			break;
		}
	}

	if(achou==true) cout<<endl<<" Numero "<<ch<<" encontrado na tabela na posicao: "<<i<<endl<<endl;
	else cout<<endl<<" Elemento nao encontrado na tabela!"<<endl<<endl;

}//fim main
