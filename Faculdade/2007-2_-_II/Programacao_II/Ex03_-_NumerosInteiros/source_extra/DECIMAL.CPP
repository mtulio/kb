#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main ()
{
    int numero,tmp2, temp, i, soma, resto, original,identificador,j, tmp;
   
    cout<<endl<<"Digite o valor de n: ";
    cin>>numero;
/*    original=numero;
    
    //if (numero<2) printf ("Decimal de %i eh %i", numero, numero);
    
    //Descobrindo a qtd de digitos do nro (para n usar vetor)
    i=0;
    //temp eh a variavel q vai calcular a qtd de digitos
    temp=numero;
    while(temp>=10){//descobrindo a qtd de digitos
                    tmp2=temp/10;
                    temp=tmp2;
                    i++;
    }
    i++;
    cout<<endl<<"qtd de dg = "<<i<<endl;*/

    int vetor[100];//criando um vetor de 100 posições
    identificador=0;
    while(numero>0){
                   tmp=numero%2;
                   vetor[identificador]=tmp;
                   numero=numero/2;
                   identificador++;
    }
    cout<<"valor decimal eh: ";
    for(j=0;identificador>j; j++){
                  cout<<vetor[j];
    }                            
    getchar();
    getchar();
}
