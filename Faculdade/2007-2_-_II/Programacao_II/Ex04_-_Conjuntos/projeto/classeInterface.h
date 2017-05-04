#ifndef CLASSEINTERFACE_H_
#define CLASSEINTERFACE_H_
#include"classeConjunto.h"
#include<string>
#include<iostream>
class Interface
{//inicio da classe Interface
          //metodos
          public:
                 static void lerVetor(Conjunto &Vet);//static: pode ser acessado diretamente sem criar um objeto
                 static void escreverVetor(const Conjunto &Vet);
                 static void escreverTodos(const Conjunto &VetA, const Conjunto &VetB);
};//fim da classe Interface
#endif /*CLASSEINTERFACE_H_*/
