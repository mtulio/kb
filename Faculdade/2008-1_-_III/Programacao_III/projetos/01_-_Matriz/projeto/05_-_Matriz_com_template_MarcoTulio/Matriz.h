#ifndef MATRIZ_H_
#define MATRIZ_H_

//#include<string>

//usando template
template<class tipo>
class Matriz{
//atributos
private:
	unsigned int quantidadeLinhas;
	unsigned int quantidadeColunas;
	tipo *ptMatriz;

//metodos
public:
	//Construtor e destrutor
	Matriz(unsigned int quantidadeLinhas=0, unsigned int quantidadeColunas=0);
	Matriz(const Matriz<tipo> *matriz);
	~Matriz(){if(ptMatriz) delete[] ptMatriz;}
	
	//Operadores
	unsigned int obterQuantidadeLinhas()const {return quantidadeLinhas;};
	unsigned int obterQuantidadeColunas()const{return quantidadeColunas;};
	
	inline tipo obterElementoMatriz(unsigned int linha, unsigned int coluna)const{
				if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
						throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
					tipo elemento = *(ptMatriz+(linha*quantidadeColunas+coluna));
					return elemento;
			}
	
	inline void atribuirElementoMatriz(unsigned int linha, unsigned int coluna, tipo elemento){
				if(linha>=quantidadeLinhas || coluna>=quantidadeColunas)
						throw (std::string("Indice de linha ou coluna fora do intervalo valido"));
					*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
			}
	
	void operator=(const Matriz<tipo> * const matriz);
	
	//Operadores De calculos
	// JULLIANO
	const Matriz<tipo> * const operator+(Matriz<tipo> const &matriz)const;  //ok
	const Matriz<tipo> * const operator-(Matriz<tipo> const &matriz)const;  //ok
	bool eIdentidade()const;
	
	// MARCO TULIO
	const Matriz<tipo> * const operator*(Matriz<tipo> const &matriz)const;
	const Matriz<tipo> *eResultanteDaTransposta()const;
	bool eOrtogonal()const;
	bool eDePermutacao()const;
	
	
	// THIAGO
	bool operator==(Matriz<tipo> const &matriz)const;
	bool operator!=(Matriz<tipo> const &matriz)const;
	const Matriz<tipo> *eResultanteDaPotencia(int expoente)const;
	const Matriz<tipo> *eResultanteMultiplicacaoPorK(int k);
	
	
	// ANDRE
	bool eTriangularSuperior()const;
	bool eTriangularInferior()const;
	bool eSimetrica()const;
	bool eAntiSimetrica()const;
	
};//fim da classe Matriz

//***********************************************************************************************
//construtores
template < class tipo>
Matriz<tipo>::Matriz(unsigned int quantidadeLinhas, unsigned int quantidadeColunas):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
{
	if(quantidadeLinhas==0 || quantidadeColunas==0){
		ptMatriz=0; return;
	}
	//aloca na memoria um vetor, ou seja criando uma matriz, do tipo informado
	ptMatriz = new  tipo[quantidadeLinhas*quantidadeColunas];
	//verifica se o vetor foi criado, se n, starta uma excessao
	if(!ptMatriz) throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
}//fim construtor

//***********************************************************************************************
template<class tipo>
Matriz<tipo>::Matriz(const Matriz<tipo> * const matriz)
{
	try{
		
		unsigned int linha=0,coluna=0;
	   //se a matriz(do parametro) nao apontar pra nenhum espaco na memoria
	   if(!matriz){
	      ptMatriz = 0;
	      quantidadeLinhas=0;
	      quantidadeColunas=0;
	      throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
	   }//fim if
	   
	   //se o vetor existir, vai ser deletado o vetor apontado pelo ponteiro
	   //porque ele vai ser realocado que acontece nas linhas abaixo
	   //if(ptMatriz) delete[] ptMatriz;
	   
	   //reatribuindo valores p os atributos para a criação da nova matriz que esta fazendo a copia
	   quantidadeLinhas=linha = matriz->obterQuantidadeLinhas();
	   quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
	   ptMatriz = new tipo[linha*coluna];
	   
	   //verifica se o vetor foi alocado na memoria
	   if(!ptMatriz){
		   throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
	   }
	   
	   //esse for eh o que mais aparece no programa, tem como objetivo
	   //caminha pela matriz e atribuir o elemento na sua devida posicao
	   for(unsigned int i=0; i<linha; i++){//inicio do for_linha
  	      tipo elemento;
  	      for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
  		     elemento = matriz->obterElementoMatriz(i,j);			
  		     atribuirElementoMatriz(i, j, elemento);
  	      }//fim do for_coluna
	   }//fim do for_linha  
	   
	   //a matriz, passado como parametro, eh deletada pois jah foi feita a copia
	   //que eh o objetivo desse consutrtor
	   //delete matriz;
	}//fim try
	catch(std::string msg){
		delete matriz;
		throw msg;
	}//fim catch 1
}//fim construtor de copia

//***********************************************************************************************
template <class tipo>
void Matriz<tipo>::operator=(const Matriz<tipo> * const matriz)
{
	try{
	      unsigned int linha=0,coluna=0;
			if(!matriz){
				ptMatriz = 0;
				quantidadeLinhas=0;
				quantidadeColunas=0;
				throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
			}
			quantidadeLinhas = linha = matriz->obterQuantidadeLinhas();
			quantidadeColunas=coluna = matriz->obterQuantidadeColunas();
			ptMatriz = new tipo[linha*coluna];
			
			//verifica se o vetor foi alocado na memoria
			if(!ptMatriz){
			   throw (std::string ("Matriz nao pode ser alocada. Falta Memoria Livre"));
			}
			
			for(unsigned int i=0; i<linha; i++){//inicio do for_linha
		  		tipo elemento;
		    	for(unsigned int j=0; j<coluna; j++){//inicio do for_coluna
		  				elemento = matriz->obterElementoMatriz(i,j);			
		  				atribuirElementoMatriz(i,j,elemento);
		    	}//fim do for_coluna
		  }//fim do for_linha
		  delete matriz;
	   }//fim try
	   catch(std::string msg){
		   delete[] ptMatriz;
		   delete matriz;
		   throw msg;
		}//fim catch 1	
}//fim do operator =

//OPERADORES DE CALCULOS
//***********************************************************************************************
// 				JULLIANO
//***********************************************************************************************
template<class tipo>
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
}//fim operator +

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


template <class tipo>
bool Matriz<tipo>::eIdentidade()const
{
   try{
      //verificando condicao de matriz quadrada
      if(quantidadeColunas!=quantidadeLinhas){
    	  throw std::string("Quantidade de Linhas e/ou Quantidade de Colunas diferentes!");
      }
      //lendo os elementos da matriz
      for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
	     for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
	        //verificando se o elemento da diagonal principal eh igual a 1
	        if(linha==coluna){
	           tipo elemento;
	           elemento = obterElementoMatriz(linha,coluna);
	           if(elemento!=1) return false;
	        }//fim if
	        else{
	           //verificando os elementos(exceto da diagonal principal) sao igual a 0
	           if(linha!=coluna){
	              tipo elemento;
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
}//final do metodo identidade

//*****************************************************
// 		MARCO TULIO
//*****************************************************
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

//*****************************************************
//		THIAGO
//*****************************************************

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


template <class tipo>
const Matriz<tipo> *Matriz<tipo>::eResultanteDaPotencia(int expoente)const
// A = |Aij| -> A* = |Aij^expoente|
{
   Matriz<tipo> resultantePotencia;
   //aux criado apenas para fazer a copia do resultado e retornalo 
   Matriz<tipo> *auxPonteiro;
   
   try{
       //resultantePotencia = new Matriz<tipo>(quantidadeLinhas, quantidadeColunas);
      
       Matriz<tipo> copia(quantidadeLinhas, quantidadeColunas);
       
       for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
            for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
               tipo elemento;
               elemento = obterElementoMatriz(linha, coluna);
               copia.atribuirElementoMatriz(linha, coluna, elemento);      
            }//fim for 2
       }//fim for 1     
       
       unsigned int qtLinhas = copia.obterQuantidadeLinhas(), qtColunas = copia.obterQuantidadeColunas();
       
       if(expoente <0 ){
           throw std::string(" Expoente invalido!");
       }//fim if <0
      
       if(expoente==0){                  
           //se o expoente for zero vai retornar ela mesmo
    	   auxPonteiro = new Matriz<tipo>(qtLinhas, qtColunas);
          for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
    	                 for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
    	                    tipo elemento;
    	                    elemento = copia.obterElementoMatriz(linha, coluna);
    	                    auxPonteiro->atribuirElementoMatriz(linha, coluna, elemento);      
    	                 }//fim for 2
    	             }//fim for 1     
    	   
    	   return auxPonteiro;	
       }// fim if 0 
      
       if(expoente==1) {
    	  auxPonteiro = new Matriz<tipo>(qtLinhas, qtColunas);
         for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
    	       	                 for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
    	       	                    tipo elemento;
    	       	                    elemento = copia.obterElementoMatriz(linha, coluna);
    	       	                    auxPonteiro->atribuirElementoMatriz(linha, coluna, elemento);      
    	       	                 }//fim for 2
    	       	             }//fim for 1   
    	   
    	   return auxPonteiro;           
       }//fim if 1
       if(expoente==2) {
           auxPonteiro = new Matriz<tipo>(qtLinhas, qtColunas);
    	   resultantePotencia = copia*copia;
           
           for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
              for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
                 tipo elemento;
                 elemento = resultantePotencia.obterElementoMatriz(linha, coluna);
                 auxPonteiro->atribuirElementoMatriz(linha, coluna, elemento);      
              }//fim for 2
          }//fim for 1     
           
           return auxPonteiro;
       }//fim if 2
       if(expoente>=3){
    	   auxPonteiro = new Matriz<tipo>(qtLinhas, qtColunas);
          Matriz<tipo> resultanteTransposta;
    	   resultanteTransposta = copia;
           for(int i=0; i<expoente; i++) {
               resultanteTransposta = resultanteTransposta*(*this);
           }//fim for
           
           for(unsigned int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
                        for(unsigned int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
                           tipo elemento;
                           elemento = resultantePotencia.obterElementoMatriz(linha, coluna);
                           auxPonteiro->atribuirElementoMatriz(linha, coluna, elemento);      
                        }//fim for 2
                    }//fim for 1     
           return auxPonteiro;
       }
   }
   catch(std::string msg){
       //delete resultantePotencia;
       throw msg;
   }
}//fim do metodo resultante da potencia


template <class tipo>
const Matriz<tipo> * Matriz<tipo>::eResultanteMultiplicacaoPorK(int k)
// A = |Aij| -> A* = |Aij*k|
{
   Matriz<tipo> *resultanteMultiplicacao;
   try{
	  resultanteMultiplicacao = new Matriz(quantidadeLinhas, quantidadeColunas);
	  if(!resultanteMultiplicacao){
		  throw std::string("Ponteiro nao alocado. Memoria cheia");
	  }
	  for(unsigned int linha=0; linha<resultanteMultiplicacao->obterQuantidadeLinhas(); linha++){//for 1
	     for(unsigned int coluna=0; coluna<resultanteMultiplicacao->obterQuantidadeColunas(); coluna++){
	        tipo elementoA;//elemento, 
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
}//fim do metodo multiplicacao por k

//*****************************************************
//		ANDRE
//*****************************************************
template <class tipo>
bool Matriz<tipo>::eTriangularSuperior()const
{
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


template <class tipo>
bool Matriz<tipo>::eTriangularInferior()const
{//inicio
   try { // inicio do try
      //comdicao da matriz quadrada
      if(quantidadeLinhas != quantidadeColunas){
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

template <class tipo>
bool Matriz<tipo>::eAntiSimetrica()const
{
   try{
      //condicao de existencia da matriz quadrada
      if(quantidadeLinhas != quantidadeColunas){
          //throw std::string("Matriz nao e quadrada!");
          return false;
      }

      Matriz<tipo> matTransposta(quantidadeLinhas, quantidadeColunas);
     
      //calculando a transposta
      matTransposta = eResultanteDaTransposta();
      
      //verificar a condicao A^t=-A
      //1 - trocar o sinal dos elementos de aux(obj atual)
      Matriz<tipo> aux(quantidadeLinhas, quantidadeColunas);
      //O EUGENIO DISSE Q ERA *this, MAS NAO EH =/
      aux = *this;
      for(unsigned int linha=0; linha<aux.obterQuantidadeLinhas(); linha++){
         for(unsigned int coluna=0; coluna<aux.obterQuantidadeColunas(); coluna++){
            tipo elemento;
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
}//fim anti simetrica

#endif /*MATRIZ_H_*/
