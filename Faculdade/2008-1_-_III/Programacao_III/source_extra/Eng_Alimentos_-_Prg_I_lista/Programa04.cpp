#include <iostream>
int main (void)
{
	//DECLARANDO AS VARIAVEIS
	int diaDaSemana, categoria;
	float preco;
	
	// LENDO AS INFORMACOES PARA O CALCULO
	std::cout<<"Insira o dia da semana : \n";
	std::cout<<"1-Domingo"<<std::endl;
	std::cout<<"2-Segunda-Feira"<<std::endl;
	std::cout<<"3-Terca-Feira"<<std::endl;
	std::cout<<"4-Quarta-Feira"<<std::endl;
	std::cout<<"5-Quinta-Feira"<<std::endl;
	std::cout<<"6-Sexta-Feira"<<std::endl;
	std::cout<<"7-Sabado"<<std::endl;

	std::cout<<" Digite o dia da semana: ";
	std::cin>>diaDaSemana;

	std::cout<<"\nPreco da fita :";
	std::cin>>preco;

	std::cout<<"\ncategoria do filme : \n";
	std::cout<<"1-Lancamento"<<std::endl;
	std::cout<<"2-Comum"<<std::endl;
	std::cout<<" Escolha a categoria: ";
	std::cin>>categoria;
	
	// REALIZANDO OS CALCULOS
	if(diaDaSemana == 2 || diaDaSemana == 3 || diaDaSemana == 5)
	{
		preco = preco*0.6;
	   if(categoria == 1) preco = preco*1.15;
	}
	else 
	{
		if(categoria == 1) preco = preco*1.15;
	}
	
	std::cout<<"Preco da fita eh :"<<preco<<std::endl;
	
}// fim do main
