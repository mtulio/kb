#ifndef MATRIZ_H_
#define MATRIZ_H_

#include<string>
#include<iostream>
template <class tipo>
class Matriz
{
	private:
		unsigned int quantidadeLinhas;
		unsigned int quantidadeColunas;
		tipo *ptMatriz;
	public:
		Matriz(unsigned int quantidadeLinhas=0, unsigned int quantidadeColunas=0);
		~Matriz(){if(ptMatriz) delete[] ptMatriz;}
		unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
		unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
		
		tipo obterElementoMatriz(unsigned int linha, unsigned int coluna)const{
			if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
					throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
				tipo elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
				return elemento;
		}
		
		void atribuirElementoMatriz(unsigned int linha, unsigned int coluna, tipo elemento){
			if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
					throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
				*(ptMatriz+(linha*quantidadeColunas+coluna)) = elemento;
		}
		
		void operator=(const Matriz<tipo> *const matriz);  //ok
		
		const Matriz<tipo> * const operator+(Matriz<tipo> const &matriz)const;  //ok
		const Matriz<tipo> * const operator-(Matriz<tipo> const &matriz)const;  //ok
		const Matriz<tipo> * const operator*(Matriz<tipo> const &matriz)const;  //ok
//		const Matriz * const eTransposta()const;
//		Matriz(const Matriz * const matriz);
		const Matriz<tipo> *eResultanteDaTransposta()const;
		bool eOrtogonal()const;
		bool eDePermutacao()const;
		//bool eTriangularSuperior()const;
		//bool eTriangularInferior()const;
		//bool eSimetrica()const;
		bool operator==(Matriz<tipo> const &matriz)const; //ok
		bool operator!=(Matriz<tipo> const &matriz)const;  //ok
		bool eTriangularSuperior()const;  //ok
		bool eTriangularInferior()const;  //ok
		bool eSimetrica()const;
};

template <class tipo>
Matriz<tipo>::Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
{
	if(quantidadeLinhas==0 || quantidadeColunas==0){
		ptMatriz=0; return;
	}
	ptMatriz = new  tipo[quantidadeLinhas*quantidadeColunas];
	if(!ptMatriz) throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
}

template < class tipo>
void Matriz<tipo>::operator=(const Matriz<tipo> *const matriz)
{
   try{
      unsigned int linha=0,coluna=0;
		if(!matriz){
			ptMatriz = 0;
			quantidadeLinhas=0;
			quantidadeColunas=0;
			throw std::string(" Memoria Principal Cheia");
		}
		quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
		quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
		ptMatriz = new tipo[linha*coluna];

		for(unsigned int i=0; i<linha; i++){//inicio do for_linha
	  		tipo a;
	    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
	  				a = matriz->obterElementoMatriz(i,j);			
	  				atribuirElementoMatriz(i,j,a);
	    	}//fim do for_coluna
	  }//fim do for_linha
	  delete matriz;
   }//fim try
   catch(std::string msg){
	   delete[] ptMatriz;
	   delete matriz;
	   throw msg;
	}//fim catch 1	
}//fim operator=

//***********************************************
template < class tipo>
const Matriz<tipo> * const Matriz<tipo>::operator+(Matriz<tipo> const &matriz)const
{	
	//foi criada e nao construida por causo do try
	Matriz<tipo> *matrizAux;
	try{
		
		//matriz quadrada
		//se a matriz nao f"M"or quadrada eh impossivel add
		//entao
		if((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas()) 
			|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas()) ){
			throw std::string("Quantidade de Linhas e/ou Quantidade de Colunas diferentes!");
		}
		
		unsigned int linhaMatriz,colunaMatriz;
		linhaMatriz = obterQuantidadeLinhas();
		colunaMatriz = obterQuantidadeColunas();
		
		matrizAux = new Matriz<tipo>(linhaMatriz,colunaMatriz);
		
		for(unsigned int linha=0;linha<linhaMatriz;linha++)
			for(unsigned int coluna=0;coluna<colunaMatriz;coluna++){
				tipo elementoA, elementoB, elementoC;
				elementoA = obterElementoMatriz(linha,coluna);
				elementoB = matriz.obterElementoMatriz(linha,coluna);
				elementoC = elementoA + elementoB;
				matrizAux->atribuirElementoMatriz(linha,coluna,elementoC);
			}//fim for
			return matrizAux;		
	}//fim try
	catch(std::string msg){
		//se pedir pra deletar da falha de segmentacao
		delete matrizAux;
		//std::cout<<"  ERRO PP"<<std::endl;
		throw msg;
	}//fim catch 1
}//fim add

//*****************************************************************
template < class tipo>
const Matriz<tipo> * const Matriz<tipo>::operator-(Matriz<tipo> const &matriz)const
//  C = A - B ou C = A +(-B)
{
   unsigned int linhaMatriz, colunaMatriz;
   Matriz<tipo> *matrizAux;
   
   try{
   	   //matriz quadrada
   		//se a matriz nao for quadrada eh impossivel add
   		//entao
   		if((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas()) 
   				|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas()) ){
   			throw std::string("Quantidade de Linhas e/ou Quantidade de Colunas diferentes!");   			
   		}
   
   		linhaMatriz=matriz.obterQuantidadeLinhas();
   		colunaMatriz=matriz.obterQuantidadeColunas();
   
   		matrizAux = new Matriz<tipo>(linhaMatriz, colunaMatriz);
   
   		for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {
   			for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
   				tipo elementoC, elementoA, elementoB;
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
	   delete matrizAux;
	   throw msg;
   }//fim catch
 
}//fim metodo subtracao 

//*********************************************************************
template < class tipo>
const Matriz<tipo> * const Matriz<tipo>::operator*(Matriz<tipo> const &matriz)const
{
   unsigned int linhaMatriz, colunaMatriz;
   Matriz<tipo> *matrizAux;
   //verificando a condicao d existencia da multiplicacao matricial
   if(obterQuantidadeColunas()!= matriz.obterQuantidadeLinhas()){
	   throw std::string("Quantidade de Colunas diferente da Quantidade de Linhas!");  
   }
   try{
	   linhaMatriz = quantidadeLinhas;
	   colunaMatriz = matriz.obterQuantidadeColunas();
       //construindo a matriz segundo as regras da multiplicacao
	   matrizAux = new Matriz<tipo>(linhaMatriz, colunaMatriz);

       for(unsigned int linha=0; linha < matrizAux->obterQuantidadeLinhas(); linha++){//for 1
    	   for(unsigned int coluna=0; coluna < matrizAux->obterQuantidadeColunas(); coluna++){//for 2
              tipo soma=0;
              for(unsigned int i=0; i<quantidadeColunas; i++){//poderia ser i<matB.obterQuantidadeLinhas()  ]
                 tipo elementoA, elementoB;
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
}//fim metodo Multiplicacao

//**********************************************************************
template< class tipo>
const Matriz<tipo> *Matriz<tipo>::eResultanteDaTransposta()const
	// A = Aij -> A^t = Aji 
{   
   //lembrando que estou dentro do objeto com os dados para ser calculados
   Matriz<tipo> *resultanteTransposta;
   
   try{
	  resultanteTransposta = new Matriz<tipo>(quantidadeColunas, quantidadeLinhas);
	  
	  //lendo os elementos e os invertendo dentro do for 2
	  for(unsigned int linha=0; linha<resultanteTransposta->obterQuantidadeLinhas(); linha++){
	     for(unsigned int coluna=0; coluna<resultanteTransposta->obterQuantidadeColunas(); coluna++){
	    	 tipo elemento;
	    	 
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
}//fim do metodo tranposta

//*****************************************************************************
template< class tipo>
bool Matriz<tipo>::eOrtogonal()const
	//  A * A^t = I, onde A^t eh a transposta de A, I eh a identidade de A
	//Uma Matriz Ortogonal eh uma matriz real A Cuja a inversa(A^-1 = A^t) coincide 
	//com a sua transposta
{//inicio ortogonal
   try{
	   //verificando se a matriz eh quadrada
	   if(quantidadeLinhas != quantidadeColunas) return false;
	   
      //calculando a inversa
	  Matriz<tipo> matTransp(0,0);
	  //obj para receber p resultando do calculo da transposta

      //obtendo a transposta
	  matTransp = eResultanteDaTransposta();

	  Matriz<tipo> produto(0,0);
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
}//Fim do metodo

//*****************************************************************************
template<class tipo>
bool Matriz<tipo>::eDePermutacao()const
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
		  throw ("memoria principal cheia"); 
	  }
	  if(!vetLinha){
		  throw ("memoria principal cheia"); 
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
	        tipo elemento;
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
}//fim do metodo permutacao


//**********************************************************************************
//*****************************************************************************
template<class tipo>
bool Matriz<tipo>::operator==(Matriz<tipo> const &matriz)const
{
   try{
      if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
			|| (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
    	  return false;
	  }//fim if
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
    	  for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	         tipo elemento, elementoM;
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
}//fim do metodo igual

//****************************************************************************
template <class tipo>
bool Matriz<tipo>::operator!=(Matriz<tipo> const &matriz)const
{
   try{
      if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
    		  || (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
    	  return false;
      }//fim if
      
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
	     for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	        tipo elemento, elementoM;
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
}//fim do metodo diferente

//****************************************************************************
template<class tipo>
bool Matriz<tipo>::eTriangularSuperior()const

{/* inicio do metodo */

  try{
      //comdicao da matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  return false;
      }//fim if
	  for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
        for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
           if(linha>coluna){
              tipo elemento;
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
}//fim metodo triangular superior

//*****************************************************************************
template<class tipo>
bool Matriz<tipo>::eTriangularInferior()const
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
               tipo elemento;
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
}//Fim triangular Inferior

//*****************************************************************************
template <class tipo>
bool Matriz<tipo>::eSimetrica()const
{ // inicio do metodo
   try{
	  //verificando a matriz quadrada
	  if(quantidadeLinhas != quantidadeColunas){
		  //throw std::string("Matriz nao e quadrada!");
		  return false;
	  }
      
	  Matriz<tipo> matTransposta(quantidadeLinhas,quantidadeColunas);
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
} // final do metodo

#endif /*MATRIZ_H_*/
