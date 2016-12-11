#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<string>
#include<iostream>
#include<fstream>

#include "locale.h"
#include <time.h>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Persistencia
{


public: 
static string gravarNoArquivo(string metodo, int tamanho, double tempo, int indice);   
      
static string verData();
      
      
};// fim classe persistencia

string Persistencia::verData()
{//inicio hora data
      struct tm *local;
      time_t t; //funcao para imprimir a hr atual tempo
      
      t = time(NULL);     /*definir a da data local*/
      local = localtime(&t);
      //printf (asctime(ptr));
//printf ("\n\nHora local e a data: %s", asctime(local));
string hora = asctime(local);
//cout<<endl<<" HORA POR STING"<<hora<<endl;

// FAZENDO O TRATAMENTO DA STRING
//retirando os espacos da string
   for(int i=0;hora[i]!=0 ; i++){//condicao para eliminar o dia da semana do nome das horas
      if((hora[i])==(' ')) 
                       hora[i]='.';
   }//fin for elimina dia da semana
return hora;
}// fim hora data

string Persistencia::gravarNoArquivo(string metodo, int tamanho, double tempo, int indice)
{   
   string nome;
   string data = verData();
   //cout<<" akiii3"<<endl;
   nome = nome+metodo;
   
   //transformando numeros em string
   string tamanhoStr;
   for(int aux = tamanho ; aux ; ){//inicio
      char letra = (aux%10) + 48;
      tamanhoStr = letra + tamanhoStr;
      aux = aux/10;
   }//fim for
   
   string indiceStr;
   for(int aux = indice ; aux ; ){//inicio
      char letra = (aux%10) + 48;
      indiceStr = letra + indiceStr;
      aux = aux/10;
   }//fim for
   
//definindo o nome do arquivo
   // exemplo: "Metodo_nRepeticoes_nElementos.txt
   nome = nome+"_";
   nome = nome+indiceStr;
   nome = nome+"_";
   nome = nome+tamanhoStr;   
   nome = nome+(".txt");
   
   //cout<<" NOME DO ARQUIVO: "<<nome<<endl;
   
   fstream arquivo;
   arquivo.open(nome.c_str(),std::ios::out|std::ios::trunc);
   if(!arquivo.is_open()) arquivo.open(nome.c_str(),std::ios::out|std::ios::trunc);

   arquivo<<"*** METODO: ";
   arquivo<<metodo;
   arquivo<<" ***"<<endl;

   arquivo<<" TAMANHO DO VETOR: ";
   arquivo<<tamanhoStr<<endl;
   
   arquivo<<" Tempo de execucao: "<<endl;
   arquivo<<tempo;
   arquivo<<" microsegundos"<<endl;
   arquivo<<tempo/1000000;
   arquivo<<" segundos"<<endl<<endl;
   arquivo<<data;
                                       
   arquivo.close();
   if(arquivo.is_open()) arquivo.close();
   
   return nome;          
}// fim gravarNoArquivo

#endif /*PERSISTENCIA_H_*/
