#include"classeConjunto.h"
#include<iostream>
using namespace std;

Conjunto::Conjunto(unsigned int tam):tamanho(tam),indiceUso(0)
{//inicio do bloco de instruções do construtor
          ptVetor = new int[tam];
}//fim do metodo construtor

Conjunto::~Conjunto()
{//inicio do bloco de comandos do metodo destrutor
          if(ptVetor) delete[] ptVetor; 
}//fim do metodo destrutor

bool Conjunto::atribuir(int elemento)
{//inicio
         if (indiceUso<tamanho){
                                if (!busca(elemento)){
                                	ptVetor[indiceUso]=elemento;
                                	indiceUso++;
                                	return true;
                                }//Condição para nao repetir o elemento em um conjunto
         }
         return false;
}//fim do metodo atribuir

bool Conjunto::obter(unsigned int pos, int &elemento)const
{//inicio 
          if (pos<indiceUso){
                             elemento=ptVetor[pos];
                             return true;
          }
          return false;
}//fim do metodo obter

bool Conjunto::busca(int elemento)const
{//inicio 
          int I;
          for(I=0; I<indiceUso && ptVetor[I]!=elemento; I++);
          if (I>=indiceUso) return false;
          return true;
}//fim do metodo busca

void Conjunto::uniao(const Conjunto &Vet1, const Conjunto &Vet2)
{//inicio 
          for(int I=0; I<Vet1.obterIndiceUso(); I++){//inicio do repita
                  int valor;
                  Vet1.obter(I,valor);
                  ptVetor[indiceUso]=valor; 
                  indiceUso++;
          }//fim do repita (for)
          
          for(int I=0; I<Vet2.obterIndiceUso(); I++){//inicio do repita
                  int valor;
                  Vet2.obter(I, valor);
                  if(!busca(valor)) {
                                    ptVetor[indiceUso]=valor; 
                                    indiceUso++;        
                  }//fim do if
          }//fim do repita 
}//fim do metodo uniao

void Conjunto::interseccao(const Conjunto &Vet1, const Conjunto &Vet2)
/* Os parametros são os mesmos do metodo uniao*/
{//inicio 
          for(int I=0; I<Vet2.obterIndiceUso(); I++){//inicio do repita
                  int valor;
                  Vet2.obter(I,valor);
                  if(Vet1.busca(valor)){//inicio
                                              ptVetor[indiceUso]=valor;
                                              indiceUso++;
                  }//fim do if
          }//fim do repita/for
}//fim do metodo interseccao



void Conjunto::diferenca(const Conjunto &Vet1, const Conjunto &Vet2)
{
     int tamc1=Vet1.obterIndiceUso();
     int tamc2=Vet2.obterIndiceUso();
     for(int pos=0;pos<tamc1;pos++){
             int elemento;
             Vet1.obter(pos, elemento);
             if(!Vet2.busca(elemento))atribuir(elemento);
     }//fim do repita
}//fim do metodo diferenca

bool Conjunto::subConjunto(const Conjunto &Vet1, const Conjunto &Vet2)
{//inicio
    for(int i=0; i<tamanho;i++){//armazenando os valores do obj2 e armazenando em um novo obj
		int elemento;
        Vet2.obter(i, elemento);
		atribuir(elemento);
	}
	for(int i=0; i<Vet1.obterTamanho();i++){//verificando a condição de sub conjunto p/ obj1
            int elemento;
            Vet1.obter(i, elemento);
            if(!busca(elemento)) return false;
    }
    return true;
}//fim do metodo subConjunto

bool Conjunto::identicos(const Conjunto &Vet1, const Conjunto &Vet2)//ordenar e comparar
{
     if(Vet1.obterTamanho() != Vet2.obterTamanho()) return false;
     for(int I=0; I<Vet1.obterTamanho(); I++){//obter os valores de ptVetor do objA
                  int valor;
                  Vet1.obter(I,valor);
                  atribuir(valor);
     }//armazenando no novo vetor C 
     for(int I=0; I<Vet2.obterTamanho(); I++){//buscando os elementos de "B" em "C"
             int valor;
             Vet2.obter(I,valor);
             if(!busca(valor)) return false;
     }
     return true;  
}//fim do metodo identicos

bool Conjunto::disjuntos(const Conjunto &Vet1,const Conjunto &Vet2)
{//qdo A inter B e B inter A sao vazios
     interseccao(Vet1,Vet2);
     if(indiceUso==0) {
                      interseccao(Vet2,Vet1);
                      if(indiceUso==0) return true;
     }
     return false;     
}//fim do metodo disjuntos

int Conjunto::amplitude()const
{//inciio do metodo amplitude
     int maiorElemento=-999, 
         menorElemento=999,
         elemento,
         amplitude;
         
     for(int i=0; i<obterTamanho(); i++){
             obter(i, elemento);
             if(maiorElemento<elemento) maiorElemento=elemento;
             if(menorElemento>elemento) menorElemento=elemento;
     }
     amplitude=maiorElemento-menorElemento;
     return(amplitude);   
}//fim do metodo amplitude

bool Conjunto::produtoEscalar(const Conjunto &Vet2, int &resultado)const
{
     int elementoA, elementoB;
    if(tamanho!=Vet2.obterTamanho()) return false;
    for(int i=0; i<tamanho; i++){
            obter(i,elementoA);
            Vet2.obter(i,elementoB);
            resultado=elementoA*elementoB+resultado;
    }
    return true;   
}//fim do metodo produto escalar

bool Conjunto::vazio()
{//inicio
     if(indiceUso==0){
        return true;
     }
     return false;
}//fim do metodo vazio
