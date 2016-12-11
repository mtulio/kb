#include<iostream>
#include<string>
#include"ItemPersistencia.h"
#include"Veiculo.h"
#include"MapeadorDeDadosCliente.h"
#include"MapeadorDeDadosVeiculo.h"

using namespace std;

int main (void)

{
try{
//std::cout<<" TESTE"<<std::endl;	
	Veiculo vei(0);
	
	cout<<" VEICULO "<<endl;
	cout<<" TESTE ATRIBUIR"<<endl;
	
	vei.atribuirMarca("VOLKS");
	vei.atribuirModelo("GOL");
	vei.atribuirPlaca("KCW-2222");
	vei.atribuirValorDeCompra(10);
	vei.atribuirValorDeVenda(20);

	cout<<" TESTE OBTER"<<endl;

	cout<<" Identificador: "<<vei.obterIdentificador()<<endl; 	
	cout<<" MARCA: "<<vei.obterMarca()<<endl;
	cout<<" MODELO: "<<vei.obterModelo()<<endl;
	cout<<" PLACA: "<<vei.obterPlaca()<<endl;
	cout<<" VALOR DE COMPRA: "<<vei.obterValorDeCompra()<<endl;
	cout<<" VALOR DE VENDA: "<<vei.obterValorDeVenda()<<endl;
	
	std::cout<<" TESTE MATERIALIZAR / DESMATERIALIZAR"<<std::endl;
	
	Veiculo veio(1);
	veio.materializar("2008;VOLKS;GOL;AAA-9999;6544;1234;");
	std::cout<<" TESTE"<<std::endl;	
	cout<<" Identificador: "<<veio.obterIdentificador()<<endl; 	
	cout<<" MARCA: "<<veio.obterMarca()<<endl;
	cout<<" MODELO: "<<veio.obterModelo()<<endl;
	cout<<" PLACA: "<<veio.obterPlaca()<<endl;
	cout<<" VALOR DE COMPRA: "<<veio.obterValorDeCompra()<<endl;
	cout<<" VALOR DE VENDA: "<<veio.obterValorDeVenda()<<endl;
	
	
	cout<<" Desmaterializar: "<<veio.desmaterializar()<<endl;
	
	Veiculo veiculo(2);
	veiculo.materializar("2007;VOLKS;GOL;AAA-9999;6544;1234;");
	std::cout<<" TESTE"<<std::endl;	
	cout<<" Identificador: "<<veiculo.obterIdentificador()<<endl; 	
	cout<<" MARCA: "<<veiculo.obterMarca()<<endl;
	cout<<" MODELO: "<<veiculo.obterModelo()<<endl;
	cout<<" PLACA: "<<veiculo.obterPlaca()<<endl;
	cout<<" VALOR DE COMPRA: "<<veiculo.obterValorDeCompra()<<endl;
	cout<<" VALOR DE VENDA: "<<veiculo.obterValorDeVenda()<<endl;
	
	MapeadorDeDadosVeiculo map;
	
	map.gravarDados(&veio);
	map.gravarDados(&veiculo);
	
	
	
	cin.get();
	cin.get();

}///fim try
catch(string msg){
	cout<<" ERRO PRINCIPAL: "<<msg<<endl;	
	cin.get();	
}
}
