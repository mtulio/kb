#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_
#include<iostream>
#include<string>
#include<fstream>
#include"Matriz.h"

class Persistencia{
   public:
      Persistencia();
      Persistencia(std::string const &nomeArquivo);
      ~Persistencia(){};
      
      static void atribuirMatrizArquivo(Matriz const &matriz, 
             std::string const nomeDoArquivo);
      
      static const Matriz * const obterMatrizDoArquivo(std::string 
             const &nomeDoArquivo);    
      
      static bool apagarArquivo(std::string &nomeArquivo);
}; //fim da classe Persistencia

#endif /*PERSISTENCIA_H_*/
