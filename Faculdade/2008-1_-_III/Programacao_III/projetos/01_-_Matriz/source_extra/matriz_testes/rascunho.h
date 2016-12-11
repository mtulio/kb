/*EXCESSOES CAP 22
 * SOBRECARGA DE OPERADOR CAP 19
 * 
 * 
 * 
 */




class Persistencia{
public:
	static void atribuirMatrizNoArquivo(Matriz const &matriz, 
			std::string const &nomeDoArquivo);
	
	static const Matriz * const obterMatrizDoArquivo(sd::string &nomeDoArquivo);
	
	
	
	
};


//perssitencia.cpp

const Matriz * const Persistencia::obterMatrizDoArquivo(std::string const &nomeDoArquivo)
{
	ifstream arquivoMatriz(nomeDoArquivo.c_str());
	if(arquivoMatriz.is_open()) return 0;
	arquivoMatriz>>linha;
	arquivoMatriz>>coluna;
	//alocacao dinamica de memoria
	//cria uma nova matriz com qtd de linhas e de colunas
	//cria uma area de memoria
	//retorna um endereço de memoria
	//ponteiro de uma classe Matriz
	//criou uma estrutura do tamanho  q queria e retornou ela
	//new a area de memoria fica reservada para vc... ate q vc digite o delete
	Matriz *matriz = new Matriz(linha,coluna);
	
	
	//ler linha e coluna com 2 for
	//preencher a matriz eemento por elemento
	//area de monte pra fazer alocacao dinamica de memoria
	
	//fechar o arquivo
	//manda o endereço da matriz pra fora;
	return matriz;
	
	
}

//programa principal:
//chamando o metodo atribuir elemento da matriz

//construtor de copia
Matriz MA(Persistencia::obterMatrizDoArquivo("MatrizMA,txt"));





//matriz.h
//construtor de copia
Matriz(const Matriz *const matriz);



//matriz.cpp
//corpo construtor de copia
Matriz(const Matriz *const matriz){
	//a matriz que vc tah mandando ela tah vazia?
	if(!matriz){
		
		ptMatriz=0;
		qtdLinhas=QtdColunas=;
		return
	}
	
	qtdLinhas = linhas = matriz->obtQtdLinhas();
	qtdColunas = colunas  = matriz->obtQtdColuna();
	
	ptMatriz = new int[linha*coluna];
	
	//copia todos os elementos para a nova matriz com os 2 for;

	
	//no fim dos 2 for deleta a matriz
	delete matriz;
}








int opcao;
	do{
      system("cls");
      cout<<" S I S T E M A  D E  M A T R I Z E S"<<endl;
      cout<<endl<<" 1 - Adicao";
      cout<<endl<<" 2 - Subtracao";
      cout<<endl<<" 3 - Multiplicacao";
      cout<<endl<<" 4 - Triangular Superior";
      cout<<endl<<" 5 - Triangular Inferior";
      cout<<endl<<" 6 - Simetrica";
      cout<<endl<<" 7 - Anti-Simetrica";
      cout<<endl<<" 8 - Identidade";
      cout<<endl<<" 9 - Transposta";
      cout<<endl<<"10 - Potencia";
      cout<<endl<<"11 - Mult por K";
      cout<<endl<<"12 - Igualdade";
      cout<<endl<<"13 - Diferenca";
      cout<<endl<<"14 - Ortogonal";
      cout<<endl<<"15 - Permutacao";
      cout<<endl<<" 0 - SAIR";
      //contruir
      cout<<endl<<"Digite a opcao: ";
      cin>>opcao;
      
      switch(opcao){
                    case 1:{//inicio case 1 - Soma                           
                         cout<<endl<<"__SOMA DAS MATRIZES 1__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(!MC.adicao(MA, MB)) cout<<"Imposs�vel ADD"<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 1
                    case 2:{//subtracao
                         cout<<endl<<"__SUBTRACAO DAS MATRIZES 2__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(!MC.subtracao(MA,MB)) cout<<"Impossivel subtrair"<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 2
                    case 3:{//inicio case 3
                         cout<<endl<<"__MULTIPLICACAO DAS MATRIZES 3__"<<endl<<endl;
                         Matriz MC(0,0);
                         if(MC.multiplicacao(MA,MB)==0) cout<<"IMPOSSIVEL EFETUAR MULTIPLICACAI"<<endl<<endl;
                         InterfaceMatriz::escreverMatriz(MC);
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 3
                    case 4:{//
                         cout<<"__TRIANGULAR SUPERIOR 4__"<<endl<<endl;
                         if(MA.triangularSuperior()) cout<<" A eh triangular superior"<<endl;
                            else cout<<" A nao eh triangular superior"<<endl;
                         if(MB.triangularSuperior()) cout<<" B eh triangular superior"<<endl;
                            else cout<<" B nao eh triangular superior"<<endl;
                         
                         cin.get();cin.get();
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 6
                    
                    case 5:{
                         cout<<"__TRIANGULAR INFERIOR 5__"<<endl<<endl;
                         if(MA.triangularInferior()) cout<<" A eh triangular inferior"<<endl;
                            else cout<<" A nao eh triangular inferior"<<endl;
                         if(MB.triangularInferior()) cout<<" B eh triangular inferior"<<endl;
                            else cout<<" B nao eh triangular inferior"<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 7
                    
                    case 6:{// 
                         cout<<"__SIMETRICA 06__"<<endl<<endl;
                         if(MA.simetrica()) cout<<"\t A Matriz A eh simetrica"<<endl<<endl;
                            else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;
                         if(MB.simetrica()) cout<<" \tA Matriz B eh simetrica"<<endl<<endl;
                            else cout<<" \tA Matriz B nao eh simetrica"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 8
                    
                    case 7:{//
                         cout<<"__ANTI SIMETICA 07__"<<endl<<endl;
                         
                         if(MA.antiSimetrica()) cout<<" \tA Matriz A eh anti-Simetrica"<<endl<<endl;
                            else cout<<"\tA matriz A nao eh anti-simetrica"<<endl<<endl;
                         if(MB.antiSimetrica()) cout<<"\tA matriz B eh anti-simetrica"<<endl<<endl;
                            else cout<<"\tA Matriz B nao eh anti simetrica"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                    }//fim case 9
                    case 8:{
                         cout<<"__IDentidade 8__"<<endl<<endl;
                         if(MA.identidade()) cout<<"A matriz A eh identidade"<<endl<<endl;
                            else cout<<"A Matriz A nao eh identidade"<<endl<<endl; 
                         if(MB.identidade()) cout<<"A matriz B eh identidade"<<endl<<endl;
                            else cout<<"A Matriz B nao eh identidade"<<endl<<endl;
                         
                         cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                         cin.get();
                         cin.get();
                         break;
                         
                    }//fim case 10             
                    case 9:{
                       cout<<" __TRANSPOSTA 9__"<<endl<<endl;
                       {
                          cout<<"\t Transposta de A:"<<endl;
                          Matriz MC(0,0);
                          MC.resultanteDaTransposta(MA);
                          InterfaceMatriz::escreverMatriz(MC);
                       }
                       {
                          cout<<"\t Transposta de B:"<<endl;
                          Matriz MC(0,0);
                          MC.resultanteDaTransposta(MB);
                          InterfaceMatriz::escreverMatriz(MC);
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;     
                    }//fim case 11
                    case 10:{
                       cout<<" __POTENCIACAO 10__"<<endl<<endl;
                       {
                          cout<<"Digite a potencia de A: ";
                          int pot;
                          cin>>pot;
                          Matriz MC(0,0);
                          MC.resultanteDaPotencia(MA, pot);
                          InterfaceMatriz::escreverMatriz(MC);   
                          cout<<endl<<endl;
                       }
                       {
                          cout<<"Digite a potencia de B: ";
                          int pot;
                          cin>>pot;
                          Matriz MC(0,0);
                          MC.resultanteDaPotencia(MB, pot);
                          InterfaceMatriz::escreverMatriz(MC);   
                          cout<<endl<<endl;
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 10 
                    case 11:{
                       cout<<"MULTIPLICACAO POR K__11__"<<endl<<endl;  
                       {
                          cout<<"Digite o valor de k p MA: ";
                          int k;
                          cin>>k;
                          Matriz MC(0,0);
                          MC.multiplicacaoPorK(MA, k);
                          InterfaceMatriz::escreverMatriz(MC);
                          cin.get();
                       }
                       {
                          cout<<"Digite o valor de k p MB: ";
                          int k;
                          cin>>k;
                          Matriz MC(0,0);
                          MC.multiplicacaoPorK(MB, k);
                          InterfaceMatriz::escreverMatriz(MC);
                          cin.get();
                       }
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 11 
                    case 12:{
                       cout<<" __IGUALDADE 12__"<<endl<<endl;
                       if(MA.igual(MB)) cout<<"As matrizes sao iguais"<<endl<<endl;
                          else cout<<"as matrizes nao sao iguais"<<endl<<endl;
                         
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;  
                    }//fim case 12
                    case 13:{
                       cout<<"___DIFERENTE 13__"<<endl<<endl;  
                       if(MA.diferente(MB)) cout<<"A matriz A eh diferente de B"<<endl<<endl;
                          else cout<<"A matriz A nao eh diferente de B"<<endl<<endl;
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim   case 13
                     case 14:{
                       cout<<"__MAtriz Ortogonal 14__"<<endl<<endl;
                       if(MA.ortogonal()) cout<<" A Matriz A eh ortogonal"<<endl;
                          else cout<<" A Matriz A nao eh ortogonal "<<endl;
                       cin.get();
                       
                       if(MB.ortogonal()) cout<<" A Matriz B eh ortogonal"<<endl;
                          else cout<<" A Matriz B nao eh ortogonal "<<endl;
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim case 10         
	                 case 15:{
                       cout<<"__PERMUTACAO 15__"<<endl<<endl;
                       if(MA.permutacao())  cout<<" A Matriz A eh de permutacao"<<endl<<endl;
                          else cout<<" A matriz A nao eh de permutacao"<<endl<<endl;
                       cin.get();
                       if(MB.permutacao())  cout<<" A Matriz B eh de permutacao"<<endl<<endl;
                          else cout<<" A matriz B nao eh de permutacao"<<endl<<endl;
                       
                       
                       cout<<" TECLE ENTER PRA CONTINUAR"<<endl;
                       cin.get();
                       cin.get();
                       break;   
                    }//fim case 10
                    case 0:{
                         cout<<"Finalizando Programa... Tecle Enter."<<endl<<endl;
                         cin.get();
                         break;
                    }
                         
                    default:{
                            cout<<"Opcao invalida"<<endl<<endl;
                            cin.get();
                            break;
                    }
      }//fim switch
	
  }while(opcao==0);
