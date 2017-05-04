#include<iostream>
#include<string>
#include"classeInterface.h"
#include"classePersistencia.h"
#include"classeControle.h"
#include"classeIterador.h"
//#include"classePessoa.h"
using namespace std;
int main()
{		
		Persistencia agenda;
		Controle controleAgenda(agenda);
		Interface::menuPrincipal(controleAgenda);
		std::cout<<std::endl<<std::endl;

}

