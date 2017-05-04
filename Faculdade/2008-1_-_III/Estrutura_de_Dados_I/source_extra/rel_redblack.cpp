//UCG - Departamento de Computacao
//Aluno: Diogor Rodriogues Goncalves
//Turma: C01
//Prof: Gerson
//Relatorio Final
//Arvores Red-Black


#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>
//#include <dos.h>
#include<string.h>


#define VERMELHO 'V'
#define PRETO 'P'

typedef char tcod[10];
typedef char tcor;
typedef struct larvore *parvore;
typedef struct larvore{
	parvore esq;
	parvore dir;
	parvore pai;
	tcor cor;
        tcod cod;
	} arvore;


//prototipo das func---------------------------------------------------------------------------------
int vazia(parvore a);
void imprime(parvore a);
parvore Busca_No(parvore a,tcod x);
void busca(parvore a);
 void Remover(parvore *A);
int tela();
parvore Remove_no(parvore A, tcod X);
int maior(tcod a, tcod b);
int busca_cod(parvore a,tcod x);
void imprime(parvore a,int lin,int col,int desvio);
parvore cria_no(tcod x);
parvore insere_no(parvore *raiz, tcod cod);
void insercao(parvore *raiz, int v);
void inserir(parvore *A);
void rotacao_direita(parvore *x, parvore* raiz);
void rotacao_esquerda (parvore *x, parvore* raiz);
void dica_da_rotacao(parvore raiz, char *lado);
void clrscr();
void lista(parvore a);


main()//programa principal
{
	parvore a;
	int opcao;
        a = NULL;
//	float te;
//	textcolor(15);
//	textbackground(0);
	clrscr();
do
 {
	opcao=tela();
	scanf("%d",&opcao);

	switch(opcao)
	{
		case(1):clrscr();inserir(&a);break;
                case(2):clrscr();lista(a);break;
		case(3):clrscr();imprime(a);break;
		case(4):clrscr();Remover(&a);break;

  //		break;

	 }
}  while(opcao!=5);

	 getchar();
}

int maior(tcod a,tcod b)//verifica se e o maior
{   		if (strcmp(a,b)>0)

		return(1);
	else
		return(0);
}

//------------------------------------------------------------------------------------------------
void lista(parvore a){
     if(a){
	 lista(a->esq);
	 clrscr();
	 printf("\n\n\n\n  Tipo: %s",a->cod);
	 getchar();
	 getchar();
	 lista(a->dir);
     }
}

void clrscr(void){
  system("cls");
}

void imprime(parvore a)
{
	if (!vazia(a))
	 {
		imprime(a->esq);
		 printf("\n\tCODIGO:%S ",a->cod);
		imprime(a->dir);
	 }
}

//------------------------------------------------------------------------------------------------
void imprime(parvore a,int lin,int col,int desvio)//impressao
{ int x;
	if (!vazia(a))
	 {
		x=(col+desvio/2);
		imprime(a->esq,lin+2,col,desvio/2);
//		gotoxy(x,lin);
		printf("%s %c",a->cod, a->cor);
		imprime(a->dir,lin+2,x,desvio/2);
	 }
}

//-------------------------------------------------------------------------------------------------
int busca_cod(parvore a, tcod x)//funcao que busca o codigo
{
  a=((Busca_No(a,x)));
  if (vazia(a))
		 return(1);
  else
	  return(0);
}

//---------------------------------------------------------------------------------------------------------------
parvore Busca_No(parvore a,tcod x)//funcao de busca
{
  if(!vazia(a))
     if(maior(a->cod,x))
	 Busca_No(a->esq,x);
     else
	if(maior(x,a->cod))
		Busca_No(a->dir,x );
		 else
	return(a);
  else
     return(NULL);
}

//--------------------------------------------------------------------------------------------------
int tela()//menuzim basico
{
int x;
printf("\n                UNIVERSIDADE CATOLICA DE GOIAS - Departamento de Computacao ");
printf("\n\n\n -----------------------------------------------------------------------------------------------");
printf("\n                          Digite 1 para inserir");
printf("\n                          Digite 2 para listar");
printf("\n                          Digite 3 para imprimir");
printf("\n                          Digite 4 para remover");
printf("\n                          Digite 5 para sair ");
printf("\n -----------------------------------------------------------------------------------------------");
printf("\n\n   DIGITE UMA OPCAO: ");
}

//procedimento de exclusao na arvore binaria--------------------------------------------------------
parvore Remove_no(parvore A, tcod X){
	parvore Aux,Aux2;

	if (A == NULL)
		return(NULL);
	else {
		if (strcmp (A->cod, X)==0){ //Apagar a Raiz
			if  (A->esq==A->dir) {
				free(A);
				return NULL;
			}  //sai da rotina
			else
				if (A->esq == NULL){ // Sub-arvore vazia
					Aux = A->dir;
					free (A);
					return Aux;
				}  //sai da rotina
				else
					if (A->dir == NULL){
						Aux = A->esq;
						free (A);
						return Aux;
					}
					else{ //As duas subarvores estao presentes
						Aux2 = A->dir;
						Aux = Aux2;
						while (Aux->esq)
							Aux = Aux->esq;
						Aux->esq = A->esq;
						free(A);
						return Aux2;
					}
		}
		if  (maior(X,A->cod))
			  A->dir = Remove_no(A->dir,X);
		else
			  A->esq = Remove_no(A->esq, X);
		return(A);
	}
}

//funcao de exclusao---------------------------------------------------------------------------------------
void Remover(parvore *A){
	tcod X;

	//parvore a;
	clrscr();
	printf("\n digite o valor a ser removido: ");
	scanf("%s", &X);
	*A = Remove_no(*A,X);
	if (vazia(*A))
		printf("\n CODIGO NAO ENCONTRADO!");
	else
	   printf("\n O CODIGO FOI REMOVIDO!");

}


//AUX----------------------------------------------------------------------------------------------
int vazia(parvore a) {
				 if ( a==NULL )
							return (1);
				 else
							return (0);
}

//proc. que cria no--------------------------------------------------------------------------------
parvore cria_no(tcod x) {
				parvore aux;

				aux = (parvore) malloc(sizeof(arvore));
				if (vazia(aux)) {
						 printf (" Nao houve memoria suficente para criar um no da arvore ");
						 return NULL;
			 }
				strcpy(aux->cod,x);
				aux->esq=aux->dir=NULL;
//			 aux -> esq = aux -> dir = NULL;  //atribui NULL aos dois
			 return (aux);
}


//proc. que insere no----------------------------------------------------------------------------------
parvore insere_no(parvore *raiz, tcod cod) {
				parvore ant, atual;

				if (vazia(*raiz)) {
							*raiz = cria_no(cod);
							(*raiz) -> pai = NULL; // a raiz da arvore possui "pai = NULL "
							return((*raiz));
				}
				else {
								atual = (*raiz);
								while (atual != NULL) {
											if (cod == atual -> cod) {
													printf(" O valor e chave ja existe na arvore ");
													return (NULL);
											}
											 else {
															ant = atual;
															if (maior(atual -> cod, cod))
																	atual = atual -> esq;
															else
																	atual = atual -> dir;
											 }
								 }
								 if ( maior(ant -> cod, cod) ) {
												ant -> esq = cria_no(cod);
												ant -> esq -> pai = ant;
												return ( ant -> esq);
								 }
								 else {
												ant -> dir = cria_no(cod);
												ant -> dir -> pai = ant;
												return (ant -> dir);
								 }

				}
 }

//Dica sobre o lado da rotacao da arvore
void dica_da_rotacao(parvore raiz, char *lado)  {

		imprime(raiz,2,0,80);
//		gotoxy(10,25);
		printf(" Vai rodar para %s", lado);
//		delay (3000);
}

void rotacao_esquerda (parvore *x, parvore* raiz) {
		parvore y;
		y = (*x) -> dir;
		(*x) -> dir = y -> esq;
		if ( y -> esq == NULL) {
			 ( y -> esq) -> pai = (*x);
		}
		y -> pai = (*x) -> pai;
		if ( ( (*x) -> pai ) == NULL ) {
			 (*raiz) = y;
		}
		 else {
						 if ( (*x) == ( (*x) -> pai ) -> esq ) {
									 (*x) -> pai -> esq = y;
						 }
						 else {
										(*x) -> pai -> dir = y;
						 }
		}

		y -> esq = (*x);
		(*x) -> pai = y;
}

void rotacao_direita(parvore *x, parvore* raiz) {
		 parvore y;
		 y = (*x) -> esq;
		 (*x) -> esq = y -> dir;
			 if (y -> dir == NULL) {
					( y -> dir) -> pai = (*x);
			 }
			 y -> pai = (*x) -> pai;
			 if ( ( (*x) -> pai) == NULL ) {
						 (*raiz) = y;
			 }
			 else {
							if ( (*x) == ( (*x) -> pai ) -> esq ) {
								 (*x) -> pai -> esq = y;
							}
							else {
									 (*x) -> pai -> dir = y;
							}
			 }
			 y -> dir = (*x);
			 (*x) -> pai = y;
 }

 void insercao(parvore *raiz, tcod v) {

			parvore x, tio, avo;

			if ( (x = insere_no(raiz, v)) == NULL )  {
					return;
			}

			x -> cor = VERMELHO;

				while (x != (*raiz) && (x -> pai -> cor == VERMELHO )) {
							avo = x -> pai -> pai;
									if (x -> pai == avo -> esq) {
										 tio = avo -> dir;
										 if (tio -> cor == VERMELHO)  {
												x -> pai -> cor = PRETO;
												tio -> cor = PRETO;
												avo -> cor = VERMELHO;
												x = avo;
											}
											else { // a cor do tio e negro
														if ( x == x -> pai -> dir) { // x, o filho  direito de seu pai
															 x = x -> pai;
															 dica_da_rotacao(*raiz," esquerda ");
															 rotacao_esquerda(&x, raiz);
														}
															 x -> pai -> cor = PRETO;
															 avo = x -> pai -> pai;
															 avo -> cor = VERMELHO;
															 dica_da_rotacao(*raiz, " direita ");
															 rotacao_direita(&avo, raiz);
										 }
									}
									else {
													// pai de x, o filho direito do avo de x.Este caso
													// semelhante ao anterior.Basta repetir o codigo acima
													// substituindo esq por dir
												 tio = avo -> esq;
												 if (tio -> cor == VERMELHO) {
														x -> pai -> cor = PRETO;
														tio -> cor = PRETO;
														avo -> cor = VERMELHO;
														x = avo;
												 }
												 else {
														 if ( x == x -> pai -> esq)  {
																														// x, o filho direito
																														// de seu pai
																x = x -> pai;
																dica_da_rotacao(*raiz, " direita ");
																rotacao_direita(&x, raiz);
														 }
																x -> pai -> cor = PRETO;
																avo = x -> pai -> pai;
																avo -> cor = VERMELHO;
																dica_da_rotacao(*raiz, " esquerda ");
																rotacao_esquerda (&avo, raiz);
												 }
									}
				}
				(*raiz) -> cor = PRETO;
 }

//modulo principal de insercao------------------------------------------------------------------------------
void inserir(parvore *a) {
	tcod x;

	clrscr();
	printf(" \n Arvore Atual " );
	imprime(*a,2,0,80);
//	gotoxy(20,20);
	printf(" Digite o valor a ser inserido (ou 0 para parar):  ");
	scanf("%s",&x);

	while (strcmp( x,"0")!=0)
	{
		insercao(a,x);
		clrscr();
		printf(" \n Arvore atual " );
		imprime(*a,2,0,80);
//		gotoxy(20,20);
		printf(" Digite o valor a ser inserido (ou 0 para parar) ");
		scanf("%s",&x);
	}
	clrscr();
	getchar();
}//fim programa

