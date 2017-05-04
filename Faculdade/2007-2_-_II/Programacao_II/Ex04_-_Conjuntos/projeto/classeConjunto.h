#ifndef CLASSECONJUNTO_H_
#define CLASSECONJUNTO_H_
class Conjunto
{//inicio da classe Conjuntos
          //atributos
          private:
                  unsigned int tamanho;
                  unsigned int indiceUso;
                  int *ptVetor;                  
          //Metodos
          public:
                 //declarando o construtor com um parametro
                 Conjunto(unsigned int tam);
                 ~Conjunto();
                 bool atribuir(int elemento);
                 bool obter(unsigned int pos, int &elemento)const;// ??? estudar o &
                 /* Metodo obterIndiceUso usando inline implicito pois seu corpo do metodo
                 *   está na sua declaração */
                 inline unsigned int obterIndiceUso()const{return indiceUso;}
                 inline unsigned int obterTamanho()const{return tamanho;}
                 void uniao(const Conjunto &C1, const Conjunto &C2);
                 void interseccao(const Conjunto &C1, const Conjunto &C2);
                 void diferenca(const Conjunto &C1, const Conjunto &C2);
                 bool subConjunto(const Conjunto &Vet1, const Conjunto &Vet2);
                 bool identicos(const Conjunto &Vet1, const Conjunto &Vet2);//ordenar e comparar
                 bool disjuntos(const Conjunto &Vet1,const Conjunto &Vet2);
                 int amplitude()const;
                 bool produtoEscalar(const Conjunto &Vet2, int &resultado)const;//const de fora: não pode alterar o valor dos atributos.
                 bool vazio();
          private:
                  bool busca(int elemento)const;
};//fim da classe Conjunto
#endif /*CLASSECONJUNTO_H_*/
