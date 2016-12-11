#ifndef CLASSEMATRIZ_H_
#define CLASSEMATRIZ_H_

class matriz
{ /*inicio da classe matriz */

  private:
          unsigned int qlinha;
          unsigned int qcoluna;
          int *elementos; /*ponteiro */
          
  public:
         int obterLinha();
         bool atribuirLinha(unsigned int linha);
         int obterColuna();
         bool atribuirColuna (unsigned int coluna);
         void obterElemento (unsigned int elemento, unsigned int linha, unsigned int coluna);
         void atribuirElemento (unsigned int elemento, unsigned int linha, unsigned int coluna);
         void adicao(const Matriz &MatA, const Matrriz &MatB);
         void subtracao(const Matriz &MatA, const Matriz &MatB);
         void multiplicao(const Matriz &MatA, const Matriz &MatB);
         bool triangularSuperior();
         bool triangularInferior();
         bool simetrica();
         bool antiSimetrica();
         bool identidade();
         void transposta(const Matriz &MatA, const Matriz &MatB);
         void potenciacao (const Matriz &MatA);
         void multiplicacaoK(const Matriz &MatA, int k);
         bool igual(const Matriz &VetA, const Matriz &VetB);
         bool diferentes(const Matriz &VetA, const Matriz &VetB);
         bool ortogonal ();
         bool permutacao ();
         
         
          Matriz (int qlinha, int qcoluna);
         ~Matriz();
         
}; /*fim da classe Matriz*/

#endif /*CLASSEMATRIZ_H_*/
         
