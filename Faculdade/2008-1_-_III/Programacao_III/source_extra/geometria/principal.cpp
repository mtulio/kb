#include "Retangulo.h"
#include "Esfera.h"
#include "Cone.h"
#include "Cilindro.h"
#include <iostream>
using namespace std;

int main()
{
	system("clear");
	int opcao;
	cout<<"Digite a opção:"<<endl;
	cout<<"1-Retangulo: \n2-Esfera \n3-Cone \n4-Cilindro \n5-Triangulo"<<endl;
	cin>>opcao;
	
	switch (opcao){
	case 1:
	{
		system("clear");
		Retangulo ret;
		unsigned int l,c,area, perimetro;
		std::cout<<"informe a largura: ";
		std::cin>>l;
	
		std::cout<<std::endl<<"informe o comprimento: ";
		std::cin>>c;
		ret.atribuirLargura(l);
		ret.atribuirComprimento(c);
	
		area=ret.area(c,l);
		perimetro=ret.perimetro(c,l);
	
		std::cout<<std::endl<<"perimetro:"<<perimetro;
		std::cout<<std::endl<<"area:"<<area<<std::endl;
	}
		break;
		
	case 2:
	{
			Esfera esf;
	        float r,area, volume;
			std::cout<<"informe o raio: ";
			std::cin>>r;
			
			esf.atribuirRaio(r);
			
			area=esf.area(r);
			volume=esf.volume(r);
			
			std::cout<<std::endl<<"volume: "<<volume;
			std::cout<<std::endl<<"area: "<<area<<std::endl;
	}
			break;
	case 3:
	{
		system("clear");
		Cone cone;
		        float r,arealateral,geratriz,altura,area, volume;
				std::cout<<"informe o raio: ";
				std::cin>>r;
				
				cout<<"informe altura";
				cin>>altura;
				
				cone.atribuirAltura(altura);
				cone.atribuirRaio(r);
				
				geratriz=cone.geratriz(r);
				volume=cone.volume(r,altura);
				arealateral=cone.arealateral(r);
				area=cone.areatotal(r,altura);
				
				std::cout<<std::endl<<"volume: "<<volume;
				std::cout<<std::endl<<"geratriz:  "<<geratriz;
				std::cout<<std::endl<<"Area lateral:  "<<arealateral;
				std::cout<<std::endl<<"area Total:  "<<area<<std::endl;
		
	}break;
	
	case 4 :
	{
		Cilindro cili;
			        float r,arealateral,altura,area, volume;
					std::cout<<"informe o raio: ";
					std::cin>>r;
					
					cout<<"informe altura: ";
					cin>>altura;
					
					cili.atribuirAltura(altura);
					cili.atribuirRaio(r);
					
					volume=cili.volume(r,altura);
					arealateral=cili.areaLateral(r);
					area=cili.area(r);
					
					std::cout<<std::endl<<"volume: "<<volume;
					std::cout<<std::endl<<"Area lateral:  "<<arealateral;
					std::cout<<std::endl<<"area Total:  "<<area<<std::endl;
		
	}break;
		
		
		

}
}
