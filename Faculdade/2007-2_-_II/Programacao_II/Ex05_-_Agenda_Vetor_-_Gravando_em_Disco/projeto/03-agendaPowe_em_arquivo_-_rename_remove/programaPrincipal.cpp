/*
  Name: MARCO TULIO RODRIGUES BRAGA
  Copyright: UNIVERSIDADE CATOLICA DE GOIAS - PROGRAMACAO II
  Author: BRANCOTULIO & CIA
  Description: PROGRAMA DE AGENDA
*/
#include<iostream>
#include<string>
#include"classeInterface.h"
#include"classePersistencia.h"
#include"classeControle.h"
#include"classeIterador.h"
#include"classePessoa.h"
using namespace std;
int main()
{
		Persistencia agenda;
		Controle controleAgenda(agenda);
		Interface::menuPrincipal(controleAgenda);
}

/* QUADRO RESERVADO PARA OPNIOES PARA MELHORIA DO PROGRAMA:


*/
