#include "Matriz.h"
#include<iostream>
#include<cmath>

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
}

//CONSTRUTOR DE COPIA
Matriz::Matriz(const Matriz * const matriz)
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
	
	//copia os elementos com o for
	for(unsigned int i=0; i<linha; i++){
		int a;
		for(unsigned int j=0; j<coluna; j++){
			matriz->obterElementoMatriz(i,j,a);
			atribuirElementoMatriz(i,j,a);
		}
	}	
	
	delete matriz;
}

/******************************************************************************/

Matriz::~Matriz()
{
	if(ptMatriz) delete[] ptMatriz;
}

/******************************************************************************/

bool Matriz::obterElementoMatriz(unsigned int linha, unsigned int coluna, int &elemento)const
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	
    elemento= *(ptMatriz+(linha*quantidadeColunas+coluna));
	return true;
}

/******************************************************************************/

bool Matriz::atribuirElementoMatriz(unsigned int linha, unsigned int coluna, int elemento)
{
	if(linha>=quantidadeLinhas || coluna>=quantidadeColunas) return false;
	*(ptMatriz+(linha*quantidadeColunas+coluna))=elemento;
	return true;
}


/******************************************************************************/

//   METODOS A SEREM APRESENTADOS NO DIA 04/03/2008

/******************************************************************************/
/* 01 */
//TESTADO E APROVADO
bool Matriz::adicao(Matriz &matA, Matriz &matB)
/*
C = A + B 
*/
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
                   elemento= elementoA + elementoB;
                   atribuirElementoMatriz(linha, coluna, elemento);
           }//for 2
   }//for 1
   
   return true;
}//fim metodo  

/******************************************************************************/
/* 04 */
//TESTADO E APROVADO
bool Matriz::triangularSuperior()
/*
Aij = 0 p/ i>j
*/
{//inicio
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
      for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
         if(linha>coluna){
            int elemento;
            obterElementoMatriz(linha, coluna, elemento);
            if(elemento!=0) return false;
         }//fim if
      }//fim for 2
   }//fim for 1
   
   return true;
}//fim do metodo tri Superior


/******************************************************************************/
/* 09 */
//OK
void Matriz::resultanteDaTransposta(Matriz &matriz)
/*
A = Aij -> A^t = Aji
*/
{
     if(ptMatriz) delete[] ptMatriz;
     quantidadeLinhas=matriz.obterQuantidadeColunas();
     quantidadeColunas=matriz.obterQuantidadeLinhas();
     //Alterado a ordem da multplicacao, pois a maneira q estava dava certo 
     //so q tva errado
     ptMatriz = new int[quantidadeColunas*quantidadeLinhas];
     
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


/******************************************************************************/
/* 12 */
//TESTADA E APROVADA BY THI and ANDRE SOFREDOR
bool Matriz::igual(Matriz &matriz)
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
           if(elemento!=elementoM) return false;          
        }//fim for 2
     }//fim for 1     
     return true;     
}//fim Igualdade


/******************************************************************************/

//         OS METODOS ABAIXO SAO PARA A SEGUNDA APRESENTA��O E 
//           AINDA ESTAO SOB REVISAO

/*******************************************************************************/


/******************************************************************************/
/* 03 */
//TESTADO E APROVADO
bool Matriz::multiplicacao(Matriz &matA, Matriz &matB)
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
                      soma+= (elementoA*elementoB);
              }
              atribuirElementoMatriz(linha, coluna, soma);
              
      }//2
   }//1

//}//metodo multi tste

/*
// C = A * B
{//inicio
   //verificando se eh possivel a multiplicacao
   if(matA.obterQuantidadeLinhas() != matB.obterQuantidadeColunas()) return false;
   
   //criando a nova matriz segundo as condicoes das operacoes
   if(ptMatriz) delete[] ptMatriz;
   quantidadeLinhas = matA.obterQuantidadeLinhas();
   quantidadeColunas = matB.obterQuantidadeColunas();
   ptMatriz = new int[quantidadeLinhas*quantidadeColunas];   
   
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
      for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
         int soma=0, elemento=0;
         for(int k=0; k<2; k++){//for 3
            int elementoA=0, elementoB=0;
            matA.obterElementoMatriz(linha, k, elementoA);
            matB.obterElementoMatriz(k, coluna, elementoB);
            //std::cout<<"   a["<<linha<<","<<k<<"]="<<elementoA<<std::endl;
            //std::cout<<"   b["<<k<<","<<coluna<<"]="<<elementoB<<std::endl;
            soma+=(elementoA*elementoB);
         }//for 3
         elemento=soma;
         atribuirElementoMatriz(linha, coluna, elemento);
      }//for 2
   }//for 1

 return true;*/
}//fim metodo mult

/******************************************************************************/
/* 05 */
//TESTADO E APROVADO
bool Matriz::triangularInferior()
/*
Aij = 0 p/ i<j
*/
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

/******************************************************************************/
/* 06 */
//TESTADO = OK
bool Matriz::simetrica()
//A^t = A
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
     matTransposta.resultanteDaTransposta(aux);
     
     //verificar se a transposta(mat) eh igual a matriz atual...
    if(igual(matTransposta)) return true;
    else return false;     
}//fim do metodo

/******************************************************************************/
/* 07 */
// NAO FOI ENCONTRADO EXEMPLOS PARA FAZER O TESTE
bool Matriz::antiSimetrica()
/*
A^t = -A
*/
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


/******************************************************************************/
/* 08 */
// TESTADO E APROVADO PELO IMMETRO JAMTT
bool Matriz::identidade()
/*
p/ i=j, Aij=1
*/
{
   if(quantidadeColunas!=quantidadeLinhas)return false;
   for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
     for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){//for 2
       if(linha==coluna){
           int elemento;
           obterElementoMatriz(linha,coluna,elemento);
           if(elemento!=1) return false;
       }//fim if
       else
       if(linha!=coluna){
          int elemento;
          obterElementoMatriz(linha,coluna,elemento);
          if(elemento!=0)return false;
       }//fim if
     }//fim for 2        
   }//fim for 1 
   return true;
}//final do metodo 



/******************************************************************************/
/* 10 */
// RODANDO QUE NEM BALINHA NA BOCA DE BANGUELA   =D
// 
bool Matriz::resultanteDaPotencia(Matriz &matriz, int expoente)
/*
A = |Aij| -> A* = |Aij^expoente|
*/
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
           
           //std::cout<<"elementoOriginal: "<<elementoNovo<<std::endl;
           
           atribuirElementoMatriz(linha, coluna, elementoNovo);
        }//fim for 2
     }//fim for 1    
     return true;    
}//fim do metodo 

/******************************************************************************/
/* 11 */
//ok testado e aprovado por JAMTT
bool Matriz::multiplicacaoPorK(Matriz &matA, int k)
/*
A = |Aij| -> A* = |Aij*k|
*/
{
     if(ptMatriz) delete[] ptMatriz;
     quantidadeLinhas=matA.obterQuantidadeLinhas();
     quantidadeColunas=matA.obterQuantidadeColunas();
     ptMatriz = new int[quantidadeLinhas*quantidadeColunas];
     
      for(int linha=0; linha<obterQuantidadeLinhas(); linha++){//for 1
           for(int coluna=0; coluna<obterQuantidadeColunas(); coluna++){
                   int elemento, elementoA;
                   matA.obterElementoMatriz(linha, coluna, elementoA);
                   elemento=elementoA;
                   elemento=elemento*k;
                   atribuirElementoMatriz(linha,coluna,elemento);    
           }
      }
      return true;
}

/******************************************************************************/
/* 13 */
//ok
bool Matriz::diferente(Matriz &matriz)
/*
A = |Aij| -> A != B p/ Aij != Bij
*/
{
     if(!igual(matriz)) return true;
     else return false;     
}//FIM METODO DIFERENTE

/******************************************************************************/
/* 14 */
//FALTA TESTAR - NAO ENCONTREI EXEMPLOS
bool Matriz::ortogonal()
/*
A * A^t = I, onde A^t eh a transposta de A, I eh a identidade de A
*/
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
     Matriz produto(0,0);
          
     //obtendo a transposta
     matTransp.resultanteDaTransposta(original);
     
     if(!produto.multiplicacao(matTransp, original)) return false;
     
     if(!original.identidade()) return false;
     
     if(original.igual(produto)) return true;
     else return false;     
     
}//Fim do metodo


/******************************************************************************/
/* 15 */
//TESTADO E APROVADO
bool Matriz::permutacao()
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
}
/*******************************************************************************/

/* 01 */
//TESTADO E APROVADO
bool Matriz::subtracao(Matriz &matA, Matriz &matB)
/*
C = A + B 
*/
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
}//fim metodo  
