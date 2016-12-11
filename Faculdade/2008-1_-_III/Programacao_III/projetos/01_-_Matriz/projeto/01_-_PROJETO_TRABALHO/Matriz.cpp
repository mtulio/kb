#include "Matriz.h"
#include<iostream>
#include<cmath>

//Construtores
Matriz::Matriz(unsigned int quantidadeLinhas=0, unsigned int quantidadeColunas=0):
	quantidadeLinhas(quantidadeLinhas),
	quantidadeColunas(quantidadeColunas)
{
	if(quantidadeLinhas==0 && quantidadeColunas==0){
		ptMatriz=0; return;
	}
	if(quantidadeLinhas==0){
		ptMatriz = new int[quantidadeColunas]; return;
	}
	if(quantidadeColunas==0){ 
		ptMatriz = new int[quantidadeLinhas]; return;
	}
	ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
}//fim do 1 construtor

//construtor de Copia
Matriz::Matriz(const Matriz * const matriz)
//a responsabilidade desse construtor e fazer a copia dos elementos que foi
//passado por paramentro pelo objeto
{
	unsigned int linha=0, coluna=0;
	if(!matriz){
		ptMatriz=0;
		quantidadeLinhas=quantidadeColunas=0;
		return;
	}
	quantidadeLinhas=linha=matriz->obterQuantidadeLinhas();
	//std::cout<<"  linhas="<<linha<<std::endl;
   quantidadeColunas=coluna=matriz->obterQuantidadeColunas();
	//std::cout<<"  colunas="<<coluna<<std::endl;
   ptMatriz = new int[linha*coluna];
	
	//copiando os elementos com os 2 for's
	for(unsigned int i=0; i<linha; i++){
		int elemento;
		for(unsigned int j=0; j<coluna; j++){
			matriz->obterElementoMatriz(i,j,elemento);
			atribuirElementoMatriz(i,j,elemento);
		}//fim for 2
	}//fim for 1
	
	//deletando o objeto porque a copia jah foi feita
	delete matriz;
}//fim Construtor de copia

//Destrutor
Matriz::~Matriz()
{
	if(ptMatriz) delete[] ptMatriz;
}//fim metodo destrutor

//Atribuindo e obtendo elemento da matriz
//*****************************************************************************
bool Matriz::obterElementoMatriz(unsigned int linha, unsigned int coluna, int &elemento)const
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	
    elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
	return true;
}

bool Matriz::atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento)
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
	return true;
}

//*****************************************************************************
//                METODOS PARA OPERACOES COM MATRIZES
//*****************************************************************************
/* 01 */
bool Matriz::adicao(Matriz const &matA, Matriz const &matB)
//  C = A + B 
{
   if ((matA.obterQuantidadeLinhas() != matB.obterQuantidadeLinhas() ) || 
      (matA.obterQuantidadeColunas() != matB.obterQuantidadeColunas() ) ){
                                     return false;
   }//fim if
   //Deletando o ponteiro existente e criando um novo com as necessidades do metodo
   if(ptMatriz)delete[] ptMatriz;
   quantidadeLinhas=matA.obterQuantidadeLinhas();
   quantidadeColunas=matA.obterQuantidadeColunas();
   ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
   
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++) {
           for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
                   int elemento, elementoA, elementoB;
                   matA.obterElementoMatriz(linha, coluna, elementoA);
                   matB.obterElementoMatriz(linha, coluna, elementoB);
                   elemento= elementoA + elementoB;
                   atribuirElementoMatriz(linha, coluna, elemento);
           }//for 2
   }//for 1
   
   return true;
}//fim metodo adicao

//*****************************************************************************
/* 02 */
bool Matriz::subtracao(Matriz const &matA, Matriz const &matB)
//  C = A - B ou C = A +(-B)
{
   if ((matA.obterQuantidadeLinhas() != matB.obterQuantidadeLinhas() ) || 
      (matA.obterQuantidadeColunas() != matB.obterQuantidadeColunas() ) ){
                                     return false;
   }//fim if
   
   //definindo o tamanho do novo vetor 
   if(ptMatriz)delete[] ptMatriz;
   quantidadeLinhas=matA.obterQuantidadeLinhas();
   quantidadeColunas=matA.obterQuantidadeColunas();
   ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
   
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++) {
           for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
                   int elemento, elementoA, elementoB;
                   matA.obterElementoMatriz(linha, coluna, elementoA);
                   matB.obterElementoMatriz(linha, coluna, elementoB);
                   elemento = elementoA + (elementoB*(-1));
                   atribuirElementoMatriz(linha, coluna, elemento);
           }//for 2
   }//for 1
   
   return true;
}//fim metodo subtracao 

//*****************************************************************************
/* 03 */
//TESTADO E APROVADO
bool Matriz::multiplicacao(Matriz const &matA, Matriz const &matB)
{
   if(matA.obterQuantidadeColunas() != matB.obterQuantidadeLinhas()) return false;
   
   if(ptMatriz) delete[] ptMatriz;
   quantidadeLinhas = matA.obterQuantidadeLinhas();
   quantidadeColunas = matB.obterQuantidadeColunas();
   ptMatriz = new int[quantidadeLinhas*quantidadeColunas];   
   
   
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
      for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
              int soma=0;
              for(int i=0; i<matA.obterQuantidadeColunas(); i++){//poderia ser i<matB.obterQuantidadeLinhas()  ]
                      int elementoA, elementoB;
                      matA.obterElementoMatriz(linha, i, elementoA);
                      matB.obterElementoMatriz(i, coluna, elementoB);
                      soma += (elementoA*elementoB);
              }
              atribuirElementoMatriz(linha, coluna, soma);              
      }//2
   }//1
}//fim metodo Multiplicacao

//*****************************************************************************
/* 05 */
bool Matriz::triangularInferior()const
// Aij = 0 p/ i<j
{
 
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
      for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
         if(linha<coluna){
            int elemento;
            obterElementoMatriz(linha, coluna, elemento);
            if(elemento!=0) return false;
         }//fim if
      }//fim for 2
   }//fim for 1
   
 return true;     
}//fim metodo Inferior

//*****************************************************************************
/* 06 */
bool Matriz::simetrica()const
// A^t = A
// Uma matriz eh simetrica quando a transposta dela eh ela mesma
{
   //verificando a condicao de matriz quadrada
   if(quantidadeLinhas != quantidadeColunas) return false;

   //aux eh a copia do objeto atual
   Matriz aux(quantidadeLinhas, quantidadeColunas);
   //fazendo uma copia do objeto atual e armazenando em aux para ser enviado 
   //por parametro
   for(int linha=0; linha<quantidadeLinhas; linha++){
      for(int coluna=0; coluna<quantidadeColunas; coluna++){
         int elementoOriginal;
         obterElementoMatriz(linha, coluna, elementoOriginal);
         aux.atribuirElementoMatriz(linha, coluna, elementoOriginal);
      }//fim for 2
   }//fim for 1
     
   unsigned int qtdLinhas=quantidadeLinhas,
              qtdColunas=quantidadeColunas;
   Matriz matTransposta(qtdLinhas,qtdColunas);
   
   //foi preciso criar um objeto aux para o envio dos dados do objeto atual
   //pois n tem como enviar um objeto como parametro sendo q vc esta "dentro dele"
   matTransposta.resultanteDaTransposta(this);
     
   //verificar se a transposta(mat) eh igual a matriz atual...
   if(igual(matTransposta)) return true;
     else return false;     
}//fim do metodo

//*****************************************************************************
/* 07 */
bool Matriz::antiSimetrica()const
// A^t = -A
{
   //condicao de existencia da matriz quadrada
   if(quantidadeLinhas != quantidadeColunas) return false;
   
   //aux eh a copia do objeto principal
   Matriz aux(quantidadeLinhas, quantidadeColunas);
   //fazendo a copia do objeto que "estamos dentro" para aux 
   for(int linha=0; linha<quantidadeLinhas; linha++){
      for(int coluna=0; coluna<quantidadeColunas; coluna++){
         int elementoOriginal;
         obterElementoMatriz(linha, coluna, elementoOriginal);
         aux.atribuirElementoMatriz(linha, coluna, elementoOriginal);
      }//fim for 2
   }//fim for 1
   
   Matriz matTransposta(quantidadeLinhas, quantidadeColunas);
   
   //calculando a transposta
   matTransposta.resultanteDaTransposta(aux);
   
   //verificar a condicao A^t=-A
   //1 - trocar o sinal dos elementos de aux
   for(int linha=0; linha<quantidadeLinhas; linha++){
      for(int coluna=0; coluna<quantidadeColunas; coluna++){
         int elemento;
         aux.obterElementoMatriz(linha, coluna, elemento);
         elemento=((-1)*elemento);
         aux.atribuirElementoMatriz(linha, coluna, elemento);
      }
   }//fim for 1
   
   //2 - verificando se a transposta eh igual a aux(com o sinal trocado)
   if(matTransposta.igual(aux)) return true;
     else return false;   
}//fim antiSimetrica

//*****************************************************************************
/* 08 */
bool Matriz::identidade()const
// p/ i=j, Aij=1
{
   //verificando condicao de matriz quadrada
   if(quantidadeColunas!=quantidadeLinhas)return false;
   
   //lendo os elementos da matriz
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
     for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
       
       //verificando se o elemento da diagonal principal eh igual a 1
       if(linha==coluna){
           int elemento;
           obterElementoMatriz(linha,coluna,elemento);
           if(elemento!=1) return false;
       }//fim if
       else
       //verificando os elementos(exceto da diagonal principal) sao igual a 0
       if(linha!=coluna){
          int elemento;
          obterElementoMatriz(linha,coluna,elemento);
          if(elemento!=0)return false;
       }//fim if
     }//fim for 2        
   }//fim for 1 
   
   return true;

}//final do metodo identidade

//*****************************************************************************
/* 09 */
void Matriz::resultanteDaTransposta(Matriz const &matriz)
// A = Aij -> A^t = Aji 
{
     if(ptMatriz) delete[] ptMatriz;
     quantidadeLinhas=matriz.obterQuantidadeColunas();
     quantidadeColunas=matriz.obterQuantidadeLinhas();
     //Alterado a ordem da multplicacao, pois a maneira q estava dava certo 
     //so q tva errado
     ptMatriz = new int[quantidadeColunas*quantidadeLinhas];
     
     //lendo os elementos e os invertendo dentro do for 2
     for(unsigned int linha=0; linha<matriz.obterQuantidadeLinhas(); linha++){
        for(unsigned int coluna=0; coluna<matriz.obterQuantidadeColunas(); coluna++){
            int elemento=0;
            matriz.obterElementoMatriz(linha, coluna, elemento);
            //os paramentros linha e coluna realmente sao invertidos para 
            //criar a tranposta
            atribuirElementoMatriz(coluna, linha, elemento);
        }//fim for 2
     }//fim for 1
      
}//fim do metodo tranposta

//*****************************************************************************
/* 10 */
bool Matriz::resultanteDaPotencia(Matriz const &matriz, int expoente)
// A = |Aij| -> A* = |Aij^expoente|
{
     quantidadeLinhas = matriz.obterQuantidadeLinhas();
     quantidadeColunas = matriz.obterQuantidadeColunas();
     
     if(ptMatriz) delete[] ptMatriz;
     ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
     
     //Matriz objOriginal(quantidadeLinhas, quantidadeColunas);
     //Matriz total(quantidadeLinhas, quantidadeColunas);
     //fazendo a copia do objeto atual
     
     for(int linha=0; linha<quantidadeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeColunas; coluna++){
           int elementoOriginal=0, elementoNovo;
           matriz.obterElementoMatriz(linha, coluna, elementoOriginal);
           //std::cout<<"elementoOriginal: "<<elementoOriginal<<std::endl;
           //A proxima operacao foi feita pq o metodo pow precisa de uma var double
           //para fazer o calculo. depois essa var foi convertida em int segundo 
           //o que esta descrito abaixo.
           double temp;
           temp = elementoOriginal;
           temp = pow(temp, expoente);
           elementoNovo = (int)(temp);
           
           atribuirElementoMatriz(linha, coluna, elementoNovo);
        }//fim for 2
     }//fim for 1    
     return true;    

}//fim do metodo resultante da potencia

//*****************************************************************************
/* 11 */
bool Matriz::multiplicacaoPorK(Matriz const &matA, int k)
// A = |Aij| -> A* = |Aij*k|
{
   if(ptMatriz) delete[] ptMatriz;
   quantidadeLinhas=matA.obterQuantidadeLinhas();
   quantidadeColunas=matA.obterQuantidadeColunas();
   ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
     
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
      for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
         int elementoA;//elemento, 
         matA.obterElementoMatriz(linha, coluna, elementoA);
         elementoA=elementoA*k;
         //elemento=elemento*k;
         atribuirElementoMatriz(linha,coluna,elementoA);    
      }//fim for 2
   }//fim for 1
   return true;
}//fim do metodo multiplicacao por k

//*****************************************************************************
/* 12 */
bool Matriz::igual(Matriz const &matriz)const
//A = |Aij| -> A = B p/ Aij = Bij
{
   if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
   || (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
                                     return false;
   }//fim if

     for(int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
        for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
           int elemento, elementoM;
           obterElementoMatriz(linha, coluna, elemento);
           matriz.obterElementoMatriz(linha, coluna, elementoM);
           //verificando cada elemento se eh igual
           if(elemento!=elementoM) return false;          
        }//fim for 2
     }//fim for 1     
     return true;
     
}//fim Igual

//*****************************************************************************
/* 13 */
bool Matriz::diferente(Matriz const &matriz)const
//A = |Aij| -> A != B p/ Aij != Bij
{
   if ((obterQuantidadeLinhas() != matriz.obterQuantidadeLinhas() ) 
   || (obterQuantidadeColunas() != matriz.obterQuantidadeColunas() ) ){
                                     return false;
   }//fim if

     for(int linha=0; linha<obterQuantidadeLinhas(); linha++) {//for 1
        for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
           int elemento, elementoM;
           obterElementoMatriz(linha, coluna, elemento);
           matriz.obterElementoMatriz(linha, coluna, elementoM);
           //verificando cada elemento se eh igual
           if(elemento==elementoM) return false;          
        }//fim for 2
     }//fim for 1     
     return true;
     
}//fim diferente

//*****************************************************************************/* 14 */
/* 14 */
//FALTA TESTAR - NAO ENCONTREI EXEMPLOS
bool Matriz::ortogonal()const
//  A * A^t = I, onde A^t eh a transposta de A, I eh a identidade de A
//Uma Matriz Ortogonal eh uma matriz real A Cuja a inversa(A^-1 = A^t) coincide 
//com a sua transposta
{
     //calculando a inversa
     Matriz matTransp(0,0);
     //Foi feita a copia do objeto pra ser enviado como parametro,
     // para o calculo da resultante da transposta
     //Pergunta: como fazer esse processo sem precisar criar uma copia do metodo
     Matriz original(quantidadeLinhas, quantidadeColunas);
     //fazendo a copia dos elementos
     for(int linha=0; linha<quantidadeLinhas; linha++){
        for(int coluna=0; coluna<quantidadeColunas; coluna++){
           int elemento;
           obterElementoMatriz(linha, coluna, elemento);
           original.atribuirElementoMatriz(linha, coluna, elemento);        
        }//fim for 2
     }//fim for 1
     
     //obtendo a transposta
     matTransp.resultanteDaTransposta(original);
     
     Matriz produto(0,0);
     if(!produto.multiplicacao(matTransp, original)) return false;
     
     //verifiacando
     if(!original.identidade()) return false;
     
     //Verificando se o produto da original com a transposta eh igual a identidade
     if(original.igual(produto)) return true;
     else return false;     
     
}//Fim do metodo

//*****************************************************************************/* 14 */
/* 15 */
bool Matriz::permutacao()const
/*
Aij p/ cada i e j exista j-1 elementos nulos e um unico elemento 1
Ex.:
|0  1  0  0 |
|1  0  0  0 |
|0  0  1  0 |
|0  0  0  1 | 
*/
{  
    int *vetLinha;
    int *vetColuna;
    
    vetLinha = new int[quantidadeLinhas];
    vetColuna = new int[quantidadeColunas];    
    for(int i=0; i<quantidadeLinhas; i++) vetLinha[i]=-1;
    for(int i=0; i<quantidadeColunas; i++) vetColuna[i]=-1;
    
    int contVetor=0;
    int qtdNulosLinha=0;
    int contUm=0;
    
    for(int linha=0; linha<quantidadeLinhas; linha++){
      for(int coluna=0; coluna<quantidadeColunas; coluna++){
         int elemento;
         obterElementoMatriz(linha, coluna, elemento);
         
         //std::cout<<" ELEMENTO: "<<elemento<<std::endl;
         
         //verificando se existem apenas elementos nulos e 1'ns
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
      if(qtdNulosLinha!=(quantidadeColunas-1)) return false;
      qtdNulosLinha=0;
    }//fim for 1   
     
     return true;
}//fim do metodo permutacao
