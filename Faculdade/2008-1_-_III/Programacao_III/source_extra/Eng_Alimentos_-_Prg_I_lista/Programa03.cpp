#include <iostream>
#include <cmath> //BIBLIOTECA PARA O USO DA RAIZ sqrt
int main (void) {
	
	// DECLARANDO AS VARIAVEIS
	int opcao;
	float area,volume,raio,altura;
   
   // LENDO O TIPO DE FIGURA GEOMETRICA
   std::cout<<"Escolha a figura:\n";
	std::cout<<"1-Cone\n";
	std::cout<<"2-Cilindro\n";
	std::cout<<"3-Esfera\n";
	std::cout<<" Digite a opcao: ";
	std::cin>>opcao;
	
   if(opcao==1){
     // LENDO OS DADOS NECESSARIOS PARA O CALCULO
     std::cout<<"Digite o raio: ";
	  std::cin>>raio;
	  std::cout<<"Digite a altura: ";
	  std::cin>>altura;
	  
	  //CALCULANDO O PEDIDO NO EXERCICIO
     volume=(3.14 * (raio * raio) * altura/3 );
	  area=((3.14*raio) * sqrt((raio*raio) + (altura*altura) ));
	  
	  // MOSTRANDO OS RESULTADOS
     std::cout<<"O Volume do cone e: "<<volume<<"\n";
	  std::cout<<"A Area do cone e: "<<area<<"\n";               
   }//fim do if opcao =1
   

   if(opcao==2){
      // LENDO OS DADOS NECESSARIOS PARA O CALCULO
      std::cout<<"Digite o raio do cilindro: ";
		std::cin>>raio;
		std::cout<<"Digite a altura do cilindro: ";
		std::cin>>altura;
		
      volume = (3.14*(raio * raio) * altura);
		area = (2*3.14*raio*altura);
		
		// MOSTRANDO OS RESULTADOS
      std::cout<<"O Volume do cilindro e: "<<volume<<"\n";
		std::cout<<"A Area do cilindro e: "<<area<<"\n";                
   }//fim do if opcao =2


   if(opcao==3){
      // LENDO OS DADOS NECESSARIOS PARA O CALCULO
      std::cout<<"Digite o raio: ";
		std::cin>>raio;
	   
	   //CALCULANDO O PEDIDO NO EXERCICIO
      volume = (4/3 * (3.14 * (raio * raio * raio)));
		area = (4 * (3.14 * (raio * raio)));
		
		// MOSTRANDO OS RESULTADOS
      std::cout<<"O Volume da esfera e: "<<volume<<"\n";
      std::cout<<"A Area da esfera e: "<<area<<"\n";               
   }//fim do if opcao =3
}// fim do main
