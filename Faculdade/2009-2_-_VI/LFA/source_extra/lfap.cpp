#include<iostream>
#include<string>
#include<stdlib.h>
//#include"no.h"
#include"Pilha.h"

using namespace std;

char lerLetra()
{
        char letra[]="X";
        do{
                cout<<"Digite a letra pra empilhar, obs: apenas uma letra e n uma palavra. 0 pra sair: ";
                cin>>letra;
        
                if (((letra[0]) != ('a')) && ((letra[0]) != ('b')) && ((letra[0]) != ('0'))) cout<<"Palavra digitada incorreta, tente novamente"<<endl;
        }while((((letra[0]) != ('a')) && ((letra[0]) != ('b'))) && ((letra[0]) != ('0')));

        return letra[0];
}//fim do metodopara ler e validar o que foi lido no teclado



int main()
{
        
        Pilha pilha;        

        char letra[]="X"; //uma letra qualquer para inicializacao
        for(int i=0; (letra[0]) != ('0'); i++)
        {
         
                letra[0]=lerLetra();                
//                cout<<"Digite a letra pra empilhar, obs: apenas uma letra e n uma palavra. 0 pra sair: ";
//               cin>>letra;
                //cout<<letra[0]<<endl;
                if((letra[0]) != ('0')) {
                             
                        if(!pilha.atribuirPilha(letra[0])) cout<<"Erro ao atribuir na pilha"<<endl;
                }
        }//fim for

        cout<<"***** Empilhamento finalizado ****"<<endl;
        cout<<" Iniciando o Desimpilhamento, tecle qualquer tecla"<<endl;
        cin.get();cin.get();

        if(pilha.estaVazio()) cout<<"Pilha Vazia...nada a desimpilhar"<<endl;
        
        while(!pilha.estaVazio())
        {
                char letra;
                if(!pilha.retirarPilha(letra)) cout<<"Erro ao retirar da pilha"<<endl;
                cout<<letra<<endl;

        }//fim while

        cout<<"****** fim do desimpilhamento"<<endl;

}//fim do programa principal
