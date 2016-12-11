#ifndef ITERATOR_H_
#define ITERATOR_H_

#include"Cliente.h"
#include"Filme.h"
#include"Locacao.h"
#include"ItemPersistencia.h"
#include"Persistencia.h"

//esta classe tem como funcao transportar os dados de uma classe para outra
//esses dados estarao armazenados em um vetor
//essa mesma classe tb tem como responsabilidade "trabalhar" em cima desse vetor
//indo ao inicio, fim, proxima posicao e etc.

class Iterator
{//inicio da classe Iterator
          //atributos
          private:
                  const unsigned int tamanho;
                  const unsigned int indiceUso;
                  //ambos serao const pq sera um valor fixo estipulado 
                  //e inicializado pelo paramentro do construtor
                  unsigned int posicao;
                  unsigned int tipoDaClasse;
                  
                  Cliente *vetCliente;
                  Filme *vetFilme;
                  Locacao *vetLocacao;
                  ItemPersistencia *item;
                  
          //metodos
          public:
                 Iterator(ItemPersistencia *item, unsigned int tamanho, 
                                           unsigned int indiceUso);
                 ~Iterator();
                 bool estaVazio()const;
                 //verifica se o vetor esta vazio, e n tem como objetivo alterar os atributos
                 bool proximo();
                 //alterara o atributo posicao
                 bool anterior();
                 //alterara o atributo posicao
                 void inicio(){
                      
                      posicao=0;
                      //std::cout<<"1 item ID: "<<item[posicao].obterIdentificador()<<std::endl;
                      //std::cout<<"1 ID classe: "<<item[posicao].obterTipoDaClasse()<<std::endl;
                      };
                 //inline implicito alterando o atributo posicao indo par ao inicio do vetor
                 //const ItemPersistencia &obter()const;
                 const Cliente &obterCliente()const{ return vetCliente[posicao];};
                 //void obter( Cliente *cliente) { cliente=vetCliente[posicao];};
                 const Filme &obterFilme()const { return vetFilme[posicao];};
                 const Locacao &obterLocacao()const { return vetLocacao[posicao];};
                 //esse metodo enviara uma referencia do vetor informado da classe ItemPersistencia

};//fim da classe Iterator
//******************************************************************************
Iterator::Iterator(ItemPersistencia *item, unsigned int tamanho, 
                                    unsigned int indiceUso):
                   //iniciando os atributos
                   tamanho(tamanho),
                   indiceUso(indiceUso)
{//inicio do bloco de comandos do construtor
          tipoDaClasse=item->obterTipoDaClasse();
         
         //convertendo o ponteiro do tipo ItemPersistencia 
         //para o tipo desejado(Cliente, Filme ou Locacao)
          if(tipoDaClasse == 0){
               vetCliente = static_cast<Cliente *>(item);
          } 
          if(tipoDaClasse == 1){
               vetFilme = static_cast<Filme *>(item);
          }
          if(tipoDaClasse == 2){
               vetLocacao = static_cast<Locacao *>(item);
          }                                    
          
          //this->item=item;
}//fim do bloco de comandos do construtor

//******************************************************************************
Iterator::~Iterator()
{//inicio do metodo construtor
          if(item) delete[] item;
          //"se o vetor item apontado pelo poteiro item existir, ele sera deletado"
}//fim do metodo destrutor

//******************************************************************************
bool Iterator::estaVazio()const
{//inicio do metodo estaVazio
          return !static_cast<bool>(indiceUso);
          //como o q designa a qtd de posicoes usadas no vetor e o atributo
          //indice de uso, esse comando convertera uma var unsigned int p/ bool
          //e logo apos retornara para o metodo com o comando return
          //Ex: se indiceUso=5, este metodo convertera p/ bool, agora valera 1
          //e com a negacao ele retornara 0(false).
          //pq da negacao? o metodo tem como objetivo verificar se esta vazio
          //entao essa condicao so sera verdadeira qdo o indiceUso ter o valor 0
          // e negando o 0 valera 1 q eh true.  xD    
}//fim do metodo estaVazio

//******************************************************************************
bool Iterator::proximo()
{//inicio do metodo proximo
          if(posicao<(indiceUso-1)){
          //esta verificando se n esta na ultima posicao
                 posicao++;
                 //se n estiver na ultima posica incrementara +1 na posicao
                 return true;
          }
          //se n estiver na ultima posica retornara false
          return false;
}//fim do metodo proximo

//******************************************************************************
bool Iterator::anterior()
{//inicio do metodo anterior
          if(posicao>0){
          //verificara se a posicao nao esta no inicio do vetor
                       posicao--;
                       return true;
                       //se n estiver no inicio do vetor decrementara -1 na posicao 
                       //e returnara true;
          }
          return false;
          //se estiver no inicio do vetor 
          //retornara false
}//fim do metodo anterior

//******************************************************************************
/*const ItemPersistencia& Iterator::obter()const
//este metodo tem como objetivo retornar o objeto na posicao
{//inicio o metodo obter
          //unsigned int tipoDaClasse = item[posicao].obterTipoDaClasse();
          //if(tipoDaClasse==0){
          //                    Cliente cliente;
          //                    cliente = static_cast<Cliente>(item[posicao]);
          //                    return cliente;                   
         // }
          
          return (item[posicao]);
          //ele buscara na posicao do vetor o objeto ira retorna-lo
}//fim do metodo obter
*/

#endif /*ITERATOR_H_*/
