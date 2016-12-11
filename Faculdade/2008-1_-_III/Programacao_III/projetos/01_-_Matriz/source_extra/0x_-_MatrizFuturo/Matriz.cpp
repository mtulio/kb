#include "Matriz.h"
#include<iostream>
#include<cmath>


Matriz::Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
	{
	if(quantidadeLinhas==0 || quantidadeColunas==0){
		ptMatriz=0; return;
	}
	//criando um vetor com  a quantidade de linhas e colunas
	ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
	if(!ptMatriz){
		//throw std::string("Memoria Principal Cheia");
		int id=0;
		throw id; 
	}
}

Matriz::Matriz(const Matriz * const matriz)
{
	try{
	   unsigned int linha=0,coluna=0;
	   //se a matriz nao apontar pra nenhum espaco na memoria
	   if(!matriz){
	      ptMatriz = 0;
	      quantidadeLinhas=0;
	      quantidadeColunas=0;
	      //throw std::string(" Memoria principal cheia");
	      //duvidas verificar a classe de excessoes
	      int id=0;
	      throw id; 	      
	   }//fim if
	   quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
	   quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
	   ptMatriz = new int[linha*coluna];
	   if(!ptMatriz){
		   int id=0;
		   throw id;
	   }
	   
	   for(unsigned int i=0; i<linha; i++){//inicio do for_linha
  	      int a;
  	      for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
  		     a=matriz->obterElementoMatriz(i,j);			
  		     atribuirElementoMatriz(i,j,a);
  	      }//fim do for_coluna
	   }//fim do for_linha*/	
  
	   delete matriz;
	}//fim try
	catch(std::string msg){
		delete matriz;
		throw msg;
	}//fim catch 1
	catch(int idException){
		delete matriz;
		throw idException;
	}
	
}//fim construtor de copia

Matriz::~Matriz()
{
   if(ptMatriz) delete[] ptMatriz;
}

int Matriz::obterElementoMatriz(unsigned int linha, unsigned int coluna)const
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas){
		//throw std::string("Linha e/ou Coluna fora do intevalo - obter");
		int id=1;
		throw id; 
	}//fim if
	
	int elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
	return elemento;
}//fim obter

void Matriz::atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento)
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas){
		//throw std::string("Linha e/ou Coluna fora do intevalo - atribuir");
		int id=1;
		throw id; 
	}
	*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
}//fim atribuir

void Matriz::operator=(const Matriz * const matriz)
{
	try{
		unsigned int linha=0,coluna=0;
		//se a matriz nao apontar pra nenhum espaco na memoria
		if(!matriz){
			//SE nao estiver apontando pra nenhum espaco na memoria eh pq a memoria esta
			//cheia e logo depois inicializara os atributos com 0
			ptMatriz = 0;
			quantidadeLinhas=0;
			quantidadeColunas=0;
			//throw std::string(" Memoria Principal Cheia");
			int id=0;
			throw id; 
		}
		quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
		quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
		ptMatriz = new int[linha*coluna];
		if(!ptMatriz){
			int id=0;
			throw id;
		}
		
		for(unsigned int i=0; i<linha; i++){//inicio do for_linha
	  		int a;
	    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
	  				a=matriz->obterElementoMatriz(i,j);			
	  				atribuirElementoMatriz(i,j,a);
	    	}//fim do for_coluna
	  }//fim do for_linha*/	
	}
	catch(std::string msg){
		delete matriz;
		throw msg;
	}//fim catch 1
	catch(int idException){
		delete matriz;
		throw idException;
	}
	delete matriz;
}

//*****************************************************************************

const Matriz * const Matriz::operator+(Matriz const &matriz)const
{	
	
	//foi criada e nao construida por causo do try
	Matriz *matrizAux;
	
	try{
		
		//matriz quadrada
		//se a matriz nao for quadrada eh impossivel add
		//entao
		if((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas()) 
			|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas()) ){
			int id=2;
			throw id;
			//std::cout<<"  ERRO MT +"<<std::endl;
			//throw std::string("Quantidade de Linhas e/ou Quantidade de Colunas diferentes!");
		}
		
		unsigned int linhaMatriz,colunaMatriz;
		linhaMatriz = obterQuantidadeLinhas();
		colunaMatriz = obterQuantidadeColunas();
		
		matrizAux = new Matriz(linhaMatriz,colunaMatriz);
		
		for(unsigned int linha=0;linha<linhaMatriz;linha++)
			for(unsigned int coluna=0;coluna<colunaMatriz;coluna++){
				int elementoA,elementoB,elementoC;
				elementoA = obterElementoMatriz(linha,coluna);
				elementoB = matriz.obterElementoMatriz(linha,coluna);
				elementoC = elementoA + elementoB;
				matrizAux->atribuirElementoMatriz(linha,coluna,elementoC);
			}//fim for
			return matrizAux;		
	}//fim try
	catch(std::string msg){
		//se pedir pra deletar da falha de segmentacao
		//delete matrizAux;
		//std::cout<<"  ERRO PP"<<std::endl;
		throw msg;
	}//fim catch 1
	catch(int idException){
		//se pedir pra deletar da falha de segmentacao/
		//delete matrizAux;
		throw idException;
	}//fim catch 2
	
}//fim add

//*****************************************************************************
const Matriz * const Matriz::operator-(Matriz const &matriz)const
//  C = A - B ou C = A +(-B)
{
   unsigned int linhaMatriz, colunaMatriz;
   Matriz *matrizAux;
   
   try{
   	   //matriz quadrada
   		//se a matriz nao for quadrada eh impossivel add
   		//entao
   		if((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas()) 
   				|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas()) ){
   			//throw std::string("Quantidade de Linhas e/ou Quantidade de Colunas diferentes!");
   			int id=2;
   			throw id;	
   		}
   
   		linhaMatriz=matriz.obterQuantidadeLinhas();
   		colunaMatriz=matriz.obterQuantidadeColunas();
   
   		matrizAux = new Matriz(linhaMatriz, colunaMatriz);
   
   		for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {
   			for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
   				int elementoC, elementoA, elementoB;
   				elementoA=obterElementoMatriz(linha, coluna);
   				elementoB=matriz.obterElementoMatriz(linha, coluna);
   				elementoC = elementoA + (elementoB*(-1));
   				matrizAux->atribuirElementoMatriz(linha, coluna, elementoC);
   			}//for 2
   		}//for 1   
   		return matrizAux;
   }//fim try
   catch(std::string msg){
	   //se pedir pra deletar da falha de segmentacao
	   //delete matrizAux;
	   throw msg;
   }//fim catch
   catch(int idException){
	   //se pedir pra deletar da falha de segmentacao
	   //delete matrizAux;
	   throw idException;
   }
}//fim metodo subtracao 

//*****************************************************************************
/* 03 */
//TESTADO E APROVADO
const Matriz * const Matriz::operator*(Matriz const &matriz)const
{
   unsigned int linhaMatriz, colunaMatriz;
   Matriz *matrizAux;
   //verificando a condicao d existencia da multiplicacao matricial
   if(obterQuantidadeColunas()!= matriz.obterQuantidadeLinhas()){
	   //throw std::string("Quantidade de Colunas diferente da Quantidade de Linhas!");  
	   int id=2;
	   throw id; 
   }
   try{
	   linhaMatriz = quantidadeLinhas;
	   colunaMatriz = matriz.obterQuantidadeColunas();
       //construindo a matriz segundo as regras da multiplicacao
	   matrizAux = new Matriz(linhaMatriz, colunaMatriz);

       for(unsigned int linha=0; linha < matrizAux->obterQuantidadeLinhas(); linha++){//for 1
    	   for(unsigned int coluna=0; coluna < matrizAux->obterQuantidadeColunas(); coluna++){//for 2
              int soma=0;
              for(unsigned int i=0; i<quantidadeColunas; i++){//poderia ser i<matB.obterQuantidadeLinhas()  ]
                 int elementoA, elementoB;
                 elementoA = obterElementoMatriz(linha, i);
                 elementoB = matriz.obterElementoMatriz(i, coluna);
                 soma += (elementoA*elementoB);
              }
              matrizAux->atribuirElementoMatriz(linha, coluna, soma);              
    	   }//2
       }//1
       return matrizAux;
   }//fim try
   catch(std::string msg){
	   delete matrizAux;
	   throw msg;
   }
   catch(int idException){
   	   delete matrizAux;
   	   throw idException;
   }
}//fim metodo Multiplicacao


//*****************************************************************************
/* 04 */
//TESTADO E APROVADO
bool Matriz::operator==(Matriz const &matriz)const
{
   try{
      if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
			|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
    	  return false;
	  }//fim if
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
    	  for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	         int elemento, elementoM;
	         elemento=obterElementoMatriz(linha, coluna);
	         elementoM=matriz.obterElementoMatriz(linha, coluna);
	         //verificando cada elemento se eh igual
	         if(elemento!=elementoM) return false;
	      }//fim for 2
      }//fim for 1
      return true;     
	}//fim do try
	catch(std::string msg){
		throw msg;
	}
	catch(int idException){
  	   throw idException;
	}
}//fim do metodo igual

//****************************************************************************
/* 05 */

bool Matriz::operator!=(Matriz const &matriz)const
{
   try{
      if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
    		  || (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
    	  return false;
      }//fim if
      
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
	     for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	        int elemento, elementoM;
	        elemento = obterElementoMatriz(linha, coluna);
	        elementoM = matriz.obterElementoMatriz(linha, coluna);
	        //verificando cada elemento se eh igual
	        if(elemento == elementoM) return false;          
	      }//fim for 2
	   }//fim for 1     
	   return true;
	}//fim try
	catch(std::string msg){
		throw msg;
	}
	catch(int idException){
	   throw idException;
	}
}//fim do metodo diferente

/**************************************************************************/

bool Matriz::eTriangularSuperior()const

{/* inicio do metodo */

  try{
      //comdicao da matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  //throw std::string("Quantidade de linhas e colunas diferentes. Nao eh uma matriz quadrada!");
		  return false;
      }//fim if
	  for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
        for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
           if(linha>coluna){
              int elemento;
              elemento = obterElementoMatriz(linha, coluna);
              if(elemento!=0) return false;
           }//fim if
        }//fim for 2
     }//fim for 1   

	 return true;
  }//fim try
  catch(std::string msg){
	  throw msg;
  }//fim catch
  catch(int idException){
	  throw idException;
  }

}//fim metodo triangular superior

//*****************************************************************************/

bool Matriz::eTriangularInferior()const
{//inicio 
   try { // inicio do try
      //comdicao da matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  //throw std::string("Quantidade de linhas e colunas diferentes. Nao eh uma matriz quadrada!");
		  return false;
	  }
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
         for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
            if(linha<coluna){
               int elemento;
               elemento = obterElementoMatriz(linha, coluna);
               if(elemento!=0) return false;
            }//fim if
         }//fim for 2
      }//fim for 1
      return true;
  
   } // final do try
   catch(std::string msg) {
	   throw msg;
   }
   catch(int idException){
   	  throw idException;
   }
}//Fim triangular Inferior

//*****************************************************************************

bool Matriz::eSimetrica()const
{ // inicio do metodo
   try{
	  //verificando a matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  //throw std::string("Matriz nao e quadrada!");
		  return false;
	  }
      
	  Matriz matTransposta(quantidadeLinhas,quantidadeColunas);
	  matTransposta = eResultanteDaTransposta();  
	  
	  if((*this)==(matTransposta)){
		  return true;
	  }//fim if
	  else {
		 return false;
	  }//fim else

   }//fim try
   catch(std::string msg){
	   throw msg;
   }//fim catch	
   catch(int idException){
   	  throw idException;
   }
} // final do metodo

//*****************************************************************************
bool Matriz::eAntiSimetrica()const
{
   try{
      //condicao de existencia da matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  //throw std::string("Matriz nao e quadrada!");
		  return false; 
	  }

	  Matriz matTransposta(quantidadeLinhas, quantidadeColunas);
	  
	  //calculando a transposta
	  matTransposta = eResultanteDaTransposta();
	   
	  //verificar a condicao A^t=-A
	  //1 - trocar o sinal dos elementos de aux(obj atual)
	  Matriz aux(quantidadeLinhas, quantidadeColunas);
	  //O EUGENIO DISSE Q ERA *this, MAS NAO EH =/
	  aux = *this;
	  for(unsigned int linha=0; linha<aux.obterQuantidadeLinhas(); linha++){
	     for(unsigned int coluna=0; coluna<aux.obterQuantidadeColunas(); coluna++){
	        int elemento;
	        elemento = aux.obterElementoMatriz(linha, coluna);
	        
	        elemento=((elemento)*(-1));
	        //std::cout<<"  elemento depois*: "<<elemento<<std::endl;
	        aux.atribuirElementoMatriz(linha, coluna, elemento);
	     }//fim for 2
	  }//fim for 1
	   
	   //2 - verificando se a transposta eh igual a aux(com o sinal trocado)
	  if(matTransposta==aux){
		  return true;
	  }//fim if
	  else{
	     return false;
	  }//fim else
   
   }//fim try
   catch(std::string msg){
	   throw msg;
   }//fim catch
   catch(int idException){
      throw idException;
   }

}//fim anti simetrica	

//*****************************************************************************
bool Matriz::eIdentidade()const
{
   try{
      //verificando condicao de matriz quadrada
      if(quantidadeColunas!=quantidadeLinhas){
    	  //throw std::string("Matriz nao e quadrada!");
    	  return false;
      }
      //lendo os elementos da matriz
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
	     for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	        //verificando se o elemento da diagonal principal eh igual a 1
	        if(linha==coluna){
	           int elemento;
	           elemento = obterElementoMatriz(linha,coluna);
	           if(elemento!=1) return false;
	        }//fim if
	        else{
	           //verificando os elementos(exceto da diagonal principal) sao igual a 0
	           if(linha!=coluna){
	              int elemento;
	        	  elemento = obterElementoMatriz(linha,coluna);
	        	  if(elemento!=0) return false;
	           	}//fim if
	        }//fim else
	     }//fim for 2        
      }//fim for 1 
	  return true;	  
   }//fim try
   catch(std::string msg){
	   throw msg;
   }
   catch(int idException){
      throw idException;
   }
}//final do metodo identidade

//*****************************************************************************
//calculara a transposta do obj atual e retornara o resultado pelo nome
const Matriz *Matriz::eResultanteDaTransposta()const
	// A = Aij -> A^t = Aji 
{   
   //lembrando que estou dentro do objeto com os dados para ser calculados
   Matriz *resultanteTransposta;
   
   try{
	  resultanteTransposta = new Matriz(quantidadeColunas, quantidadeLinhas);

	  //lendo os elementos e os invertendo dentro do for 2
	  for(unsigned int linha=0; linha<resultanteTransposta->obterQuantidadeLinhas(); linha++){
	     for(unsigned int coluna=0; coluna<resultanteTransposta->obterQuantidadeColunas(); coluna++){
	        int elemento=0;
	        elemento = obterElementoMatriz(linha, coluna);
	        //os paramentros linha e coluna realmente sao invertidos para 
	        //criar a tranposta
	        resultanteTransposta->atribuirElementoMatriz(coluna, linha, elemento);
	     }//fim for 2
	  }//fim for 1
	  return resultanteTransposta;
   }//fim
   catch(std::string msg){
      delete resultanteTransposta;
	  throw msg;
   }
   catch(int idException){
      delete resultanteTransposta;
	  throw idException;
   }
}//fim do metodo tranposta

//*****************************************************************************

const Matriz *Matriz::eResultanteDaPotencia(int expoente)const
// A = |Aij| -> A* = |Aij^expoente|
{
   Matriz *resultantePotencia;
   try{
	   resultantePotencia = new Matriz(quantidadeLinhas, quantidadeColunas);
	   
	   if(expoente <0 ){
		   throw std::string(" Expoente invalido!");
	   }//fim if <0
	   
	   if(expoente==0){
		   
	   }// fim if 0
	   
	   if(expoente==1) {
		   resultantePotencia = *this;
		   return resultanteDaPotencia;
	   }//fim if 1
	   if(expoente==2) {
		   resultanteDaPotencia = (*this)*(*this);
		   return resultanteDaPotencia;
	   }//fim if 2
	   if(expoente>=3){
		   resultanteDaTransposta = *this;
		   for(int i=0); i<expoente; i++) {
			   resultanteDaTransposta = resultanteDaTransposta*(*this);
		   }//fim for
		   return resultanteDaTransposta;
	   }//fim if >=3	   
	   
   }//fim try
   catch(std::string msg){
       delete resultantePotencia;
	   throw msg;
   }
   catch(int idException){
	   delete resultantePotencia;
       throw idException;
   }
}//fim do metodo resultante da potencia

//*****************************************************************************
const Matriz * Matriz::eResultanteMultiplicacaoPorK(int k)
// A = |Aij| -> A* = |Aij*k|
{
   Matriz *resultanteMultiplicacao;
   try{
	  resultanteMultiplicacao = new Matriz(quantidadeLinhas, quantidadeColunas);

	  for(unsigned int linha=0; linha<resultanteMultiplicacao->obterQuantidadeLinhas(); linha++){//for 1
	     for(unsigned int coluna=0; coluna<resultanteMultiplicacao->obterQuantidadeColunas(); coluna++){
	        int elementoA;//elemento, 
	        elementoA = obterElementoMatriz(linha, coluna);
	        elementoA = elementoA*k;
	        resultanteMultiplicacao->atribuirElementoMatriz(linha,coluna,elementoA);    
	     }//fim for 2
      }//fim for 1
	  return resultanteMultiplicacao;
   }//fim try
   catch(std::string msg){
	   delete resultanteMultiplicacao;
	   throw msg;
   }
   catch(int idException){
	   delete resultanteMultiplicacao;
	   throw idException;
   }
}//fim do metodo multiplicacao por k

	
//*****************************************************************************
//FALTA TESTAR - NAO ENCONTREI EXEMPLOS
bool Matriz::eOrtogonal()const
	//  A * A^t = I, onde A^t eh a transposta de A, I eh a identidade de A
	//Uma Matriz Ortogonal eh uma matriz real A Cuja a inversa(A^-1 = A^t) coincide 
	//com a sua transposta
{//inicio ortogonal
   try{
	   //verificando se a matriz eh quadrada
	   if(quantidadeLinhas != quantidadeColunas) return false;
	   
      //calculando a inversa
	  Matriz matTransp(0,0);
	  //obj para receber p resultando do calculo da transposta

      //obtendo a transposta
	  matTransp = eResultanteDaTransposta();

	  Matriz produto(0,0);
	  //se nao for possivel fazer a multiplicacao o tratanento cuidara 
	  produto = (matTransp)*(*this);

	  //verifiacando
	  //se ela eh identidade, se nao for nao ira satisfazer a condicao de ortogonal
	  //Verificando se o produto da original com a transposta eh igual a identidade
	  //essa eh a unica condicao para ser ortogonal
	  if(produto.eIdentidade()) return true;
	  
	  return false;     
   }//fim try
   catch(std::string msg){
	   throw msg;
   }
   catch(int idException){
   	   throw idException;
   }
}//Fim do metodo

//*****************************************************************************/* 14 */
bool Matriz::eDePermutacao()const
	/*
	Aij p/ cada i e j exista j-1 elementos nulos e um unico elemento 1
	Ex.:
	|0  1  0  0 |
	|1  0  0  0 |
	|0  0  1  0 |
	|0  0  0  1 | 
	*/
{  
   try{
      int *vetLinha;
	  int *vetColuna;
	
	  //criando um ponteiro vetor com a qtd de linhas e colunas do atributo do objeto
	  vetLinha = new int[quantidadeLinhas];
	  vetColuna = new int[quantidadeColunas];
	  if(!vetLinha){
		  int id;
		  throw id=0; // throw ("memoria principal cheia"); 
	  }
	  if(!vetLinha){
		  int id;
		  throw id=0; // throw ("memoria principal cheia"); 
	  }
	  
	  //inicializando-os com -1, para q a condicao descrita 
	  //nas proximas linhas sejam aceitas
	  for(unsigned int i=0; i<quantidadeLinhas; i++) vetLinha[i]=-1;
	  for(unsigned int i=0; i<quantidadeColunas; i++) vetColuna[i]=-1;
	    
	  //condicoes exigidas para q exista uma permutacao de matrizes
	  int contVetor=0;
	  int qtdNulosLinha=0;
	  int contUm=0;
	    
	  for(unsigned int linha=0; linha<quantidadeLinhas; linha++){
	     for(unsigned int coluna=0; coluna<quantidadeColunas; coluna++){
	        int elemento;
	        elemento = obterElementoMatriz(linha, coluna);
	         
	         //std::cout<<" ELEMENTO: "<<elemento<<std::endl;
	         
	        //verificando se existem apenas elementos nulos e 1'ns na matriz
	        if((elemento!=0) && (elemento != 1)) return false;
	        if(elemento==0) qtdNulosLinha+=1;
	        if(contUm>1) return false;
	         
	        if(elemento==1){//if 1
	            //verificando se existe 1 na linha e coluna
	            //std::cout<<"   IF 1  "<<std::endl<<std::endl;
	            //std::cout<<"    ["<<linha<<"]["<<coluna<<"]"<<std::endl<<std::endl;
	           
	            for(int i=0; i<contVetor; i++){
	                    //verificando se tem o nro 1 na mesma linha
	                    
	                    if(vetLinha[i]==linha) return false;
	                    //std::cout<<"vetLinha["<<i<<"]=="<<vetColuna[i]<<std::endl<<std::endl;
	            }//fim for
	            
	            
	            for(int i=0; i<contVetor; i++){	                    
	                    if(vetColuna[i]==coluna) return false;                    
	                    //std::cout<<"vetColuna["<<i<<"]=="<<vetColuna[i]<<std::endl<<std::endl;
	            }//fim for
	            
	            vetLinha[contVetor]=linha;
	            vetColuna[contVetor]=coluna;
	            contUm+=1;
	            contVetor+=1;
	         }//fim if 1
	      }//fim for 2 - FIM DE LINHA, VERIFICOU TODAS AS COLUNAS DAS LINHAS
	      //contUm serve para verificar se existe o um na linha
	      contUm=0;
	      //ao fim da linha se n conter n-1 elementos nulos retornara falso
	      if(qtdNulosLinha!=(quantidadeColunas-1)) return false;
	      //zera o contador de nulos dakela linha
	      qtdNulosLinha=0;
	    }//fim for 1   
	     //ao final de toda a verificacao se n foi barrado em nenhum dessas condicoes retornara true
	     return true;
	}
	catch(std::string msg){
		throw msg;
	}
	catch(int idException){
	   throw idException;
	}
}//fim do metodo permutacao
