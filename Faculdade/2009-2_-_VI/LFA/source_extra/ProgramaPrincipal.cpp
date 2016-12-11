#include<iostream>
#include<string>
#include<stdlib.h>
//#include"no.h"
#include"Pilha.h"

using namespace std;
int main()
{
    char palavra[]="subinoonibus";
    cout<<" Digite a palavra: ";
    cin>>palavra;
     
    //verificando o tamanho da palavra pra usar no proximo loop
    int tamanho=0;
    for(int i=0;(palavra[i])!= ('\0'); i++){
            tamanho++;
    }
    //criando uma pilha
    Pilha palindroma;
       
    //quebrando a palavra
    for(int i=0; i<tamanho ; i++){
            
            char let;
            let = palavra[i];
            //cout<<"\n Letra MAIN atribuir: "<<let;
            
            if(!palindroma.atribuirPilha(let))cout<<"erro atribuir";
            
            //if(palindroma->atribuirPilha(let)) cout<<" Nao foi possivel atribuir"<<endl;
    }//fim for
    
    //copiando os elementos do topo da pilha para uma pilha aux
    //e assim invertendo a ordem das palavras
    //Pilha pilhaAux;
    
    for(int i=0; !palindroma.estaVazio(); i++){
            char letra;
            
            if(!palindroma.retirarPilha(letra)) cout<<"erro retirar";
            //std::cout<<"\n Letra MAIN RETIRAR: "<<letra;
            
            //comparando cada letra q estava na pilha com a palavra origianal
            if(letra != palavra[i]){
                     cout<<" A palavra nao eh palidroma!!!"<<endl;
                     cin.get();cin.get();
                     exit (0);         
            }
            //  pilhaAux->atribuirPilha(letra);
            
    }//fim for
    
    cout<<"  A palavra eh palindroma!!!"<<endl;
    
    
      exit(1);    
}//fim metodo main
